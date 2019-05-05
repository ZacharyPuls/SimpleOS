/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/paging.h>

static __pde_t __page_directory[1024] __attribute__((aligned(4096)));
static __pte_t __page_table_0[1024] __attribute__((aligned(4096)));

void __init_paging() {
    for (int i = 0; i < 1024; i++) {
        __page_directory[i] = PDE_NOT_PRESENT | PDE_READWRITE | PDE_ACCESS_SUPERVISOR;
    }

    for (uint32_t i = 0; i < 1024; i++) {
        __page_table_0[i] = (i * 4096) | (PTE_PRESENT | PTE_READWRITE | PTE_ACCESS_SUPERVISOR);
    }

    __page_directory[0] = ((__pde_t)__page_table_0) | (PDE_PRESENT | PDE_READWRITE | PDE_ACCESS_SUPERVISOR);

    // May still have to push cr0/cr3 into a scratch register, set val, then pop onto cr0/cr3
    
    __asm__ __volatile__("mov %%eax, %%cr3" : : "a"(__page_directory));
    __asm__ __volatile__("mov %cr0, %eax");
    __asm__ __volatile__("orl $0x80000000, %eax");
    __asm__ __volatile__("mov %eax, %cr0");
    
    /*
    __asm__ __volatile__ (
        "mov %0, %%eax\n"
        "mov %%eax, %%cr3\n"
        "mov %%cr0, %%eax\n"
        "or $0x80000000, %%eax\n"
        "mov %%eax, %%cr0\n"
        :
        : "r" (__page_directory)
        : "eax"
    );
    */
}

uint32_t __get_physical_address(const uint32_t logical_address) {
    uint32_t physical_address = 0;
    // __pde_t pde = __get_pde(logical_address);
    // __pte_t pte = __get_pte(logical_address, pde);
    
    return physical_address;
}

inline __pde_t __get_pde(const uint32_t logical_address) {
    const void *pd_base_addr = (void *)(&__page_directory[0]);
    const uint32_t pde_address = ((uint32_t)pd_base_addr) + LOGICALADDR_PDE_OFFSET(logical_address);

    uint32_t out_pde_address;
    __asm__ __volatile__ (
        "mov (%0), %1\n"
        : "=&r" (out_pde_address)
        : "r" (pde_address)
        :
    );

    return out_pde_address;
}

inline __pte_t __get_pte(const uint32_t logical_address, const __pde_t pde) {
    const uint32_t pt_base_addr = PDE_PTE(pde);
    const uint32_t pte_address = pt_base_addr + LOGICALADDR_PTE_OFFSET(logical_address);

    uint32_t out_pte_address;
    __asm__ __volatile__ (
        "mov (%0), %1\n"
        : "=&r" (out_pte_address)
        : "r" (pte_address)
        :
    );

    return out_pte_address;
}

inline void *__get_page(const uint32_t logical_address, const __pte_t pte) {
    const uint32_t pg_base_addr = PTE_ADDR(pte);
    const uint32_t pg_address = pg_base_addr + LOGICALADDR_PGE_OFFSET(logical_address);

    uint32_t out_pg_address; 

    __asm__ __volatile__ (
        "mov (%0), %1\n"
        : "=&r" (out_pg_address)
        : "r" (pg_address)
        :
    );

    return out_pg_address;
}

void __toggle_page_dirty(const uint32_t physical_address) {
    for (uint32_t i = 0; i < 1024; i++) {
        if (PTE_ADDR(__page_table_0[i]) == physical_address) {
            __page_table_0[i] &= ~PTE_DIRTY;
        }
    }
}

uint32_t __get_free_page(const uint32_t size) {
    // TODO: Scan the rest of the page tables, after we allocate more than just one
    // TODO: Optimization
    // TODO: If size > 4096, allocate two or more pages.
    uint32_t free_page_addr;

    for (uint32_t i = 0; i < 1024; i++) {
        if (PTE_D(__page_table_0[i])) {
            continue;
        }
        free_page_addr = PTE_ADDR(__page_table_0[i]);
        break;
    }

    return free_page_addr;
}
