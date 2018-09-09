
#include <asm/gdt.h>

#include <stddef.h>
#include <stdlib.h>

static __gdt_entry_t *__gdt;

// For now, just set up 4 GiB of memory, flat layout
void __setup_gdt() {

    if (__gdt) {
        // TODO: GDT has already been initialized, throw exception or PANIC
    }

    __gdt = (__gdt_entry_t *) malloc(sizeof(__gdt_entry_t) * 3);

    __gdt[0] = __MAKE_GDT_ENTRY(0x00000000, 0x00000000, 0x00, 0x00); // Cannot use GDT entry 0
    __gdt[1] = __MAKE_GDT_ENTRY(0x00000000, 0xFFFFFFFF, GDT_EXECUTABLE_READWRITE, GDT_FLAGS_DEFAULT);
    __gdt[2] = __MAKE_GDT_ENTRY(0x00000000, 0xFFFFFFFF, GDT_DATA_READWRITE, GDT_FLAGS_DEFAULT);

    __gdt_descriptor_t __gdtr = __MAKE_GDT_DESCRIPTOR(sizeof(__gdt), (size_t)__gdt);

    __asm__ __volatile__(
        "lgdt (%0)"
        :
        : "r"(&__gdtr)
        :
    );
}