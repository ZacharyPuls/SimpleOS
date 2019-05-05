/**
 * Copyright 2019 Zachary Puls <zach@zachpuls.com>
 */
 
gdt_start:
gdt_zero:
    .int 0x00000000
    .int 0x00000000
gdt_cs:
    .int 0x0000FFFF
    .int 0x00CF9A00
gdt_ds:
    .int 0x0000FFFF
    .int 0x00CF9200
gdt_end:
    .int .

gdt_descriptor:
    .short gdt_end - gdt_start - 1
    .int gdt_start

.global load_gdt
.type load_gdt STT_FUNC
load_gdt:
    lgdt gdt_descriptor
    jmp $0x08,$.reload_registers
.reload_registers:
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
    mov %ax, %ss
    ret
