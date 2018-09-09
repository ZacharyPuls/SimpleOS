#ifndef __SIMPLEOS_PAGING_H__
#define __SIMPLEOS_PAGING_H__

#include <stdint.h>

#define PDE_BASEADDR    0x0

#define PDE_PRESENT             0x00000001
#define PDE_NOT_PRESENT         0x00000000
#define PDE_READWRITE           0x00000002
#define PDE_READONLY            0x00000000
#define PDE_ACCESS_USER         0x00000004
#define PDE_ACCESS_SUPERVISOR   0x00000000
#define PDE_WRITETHROUGH        0x00000008
#define PDE_NO_WRITETHROUGH     0x00000000
#define PDE_CACHE_DISABLE       0x00000010
#define PDE_NO_CACHE_DISABLE    0x00000000
#define PDE_ACCESSED            0x00000020
#define PDE_NOT_ACCESSED        0x00000000
#define PDE_4MBYTE_PAGE         0x00000080
#define PDE_4KBYTE_PAGE         0x00000000

#define PDE_DEFAULT             (PDE_NOT_PRESENT | PDE_READONLY | PDE_ACCESS_SUPERVISOR | \
                                PDE_NO_WRITETHROUGH | PDE_NO_CACHE_DISABLE | PDE_NOT_ACCESSED | \
                                PDE_4KBYTE_PAGE)

#define PDE_P(pde)      (pde & 0x00000001)
#define PDE_RW(pde)     (pde & 0x00000002)
#define PDE_US(pde)     (pde & 0x00000004)
#define PDE_PWT(pde)    (pde & 0x00000008)
#define PDE_PCD(pde)    (pde & 0x00000010)
#define PDE_A(pde)      (pde & 0x00000020)
#define PDE_PS(pde)     (pde & 0x00000080)
#define PDE_PTE(pde)    (pde & 0xFFFFF000)

#define PTE_PRESENT             0x00000001
#define PTE_NOT_PRESENT         0x00000000
#define PTE_READWRITE           0x00000002
#define PTE_READONLY            0x00000000
#define PTE_ACCESS_USER         0x00000004
#define PTE_ACCESS_SUPERVISOR   0x00000000
#define PTE_WRITETHROUGH        0x00000008
#define PTE_NO_WRITETHROUGH     0x00000000
#define PTE_CACHE_DISABLE       0x00000010
#define PTE_NO_CACHE_DISABLE    0x00000000
#define PTE_ACCESSED            0x00000020
#define PTE_NOT_ACCESSED        0x00000000
#define PTE_DIRTY               0x00000040
#define PTE_NOT_DIRTY           0x00000000
#define PTE_PAT                 0x00000080
#define PTE_NOT_PAT             0x00000000
#define PTE_GLOBAL              0x00000100
#define PTE_NOT_GLOBAL          0x00000000

#define PTE_DEFAULT             (PTE_NOT_PRESENT | PTE_READONLY | PTE_ACCESS_SUPERVISOR | \
                                PTE_NO_WRITETHROUGH | PTE_NO_CACHE_DISABLE | PTE_NOT_ACCESSED | \
                                PTE_NOT_DIRTY | PTE_NOT_PAT | PTE_NOT_GLOBAL)

#define PTE_P(pte)      (pte & 0x00000001)
#define PTE_RW(pte)     (pte & 0x00000002)
#define PTE_US(pte)     (pte & 0x00000004)
#define PTE_PWT(pte)    (pte & 0x00000008)
#define PTE_PCD(pte)    (pte & 0x00000010)
#define PTE_A(pte)      (pte & 0x00000020)
#define PTE_D(pte)      (pte & 0x00000040)
#define PTE_PAT(pte)    (pte & 0x00000080)
#define PTE_G(pte)      (pte & 0x00000100)
#define PTE_ADDR(pte)   (pte & 0xFFFFF000)


#define LOGICALADDR_PDE_OFFSET(addr)    (addr & 0xFFC00000)
#define LOGICALADDR_PTE_OFFSET(addr)    (addr & 0x003FF000)
#define LOGICALADDR_PGE_OFFSET(addr)    (addr & 0x00000FFF)

// Page directory entry
typedef uint32_t __pde_t;
// Page table entry
typedef uint32_t __pte_t;

extern void __init_paging();
extern uint32_t __get_physical_address(const uint32_t);
extern void __toggle_page_dirty(const uint32_t);
extern uint32_t __get_free_page(const uint32_t);

#endif