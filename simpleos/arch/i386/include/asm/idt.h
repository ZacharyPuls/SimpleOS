/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_IDT_H__
#define __SIMPLEOS_IDT_H__

#include <stdint.h>

// IDT Type/Attributes
#define IDT_USED               0x80
#define IDT_UNUSED             0x00
#define IDT_RING_3             0x60
#define IDT_RING_2             0x40
#define IDT_RING_1             0x20
#define IDT_RING_0             0x00
#define IDT_STORAGE            0x10
#define IDT_NONSTORAGE         0x00    // Interrupt or Trap
#define IDT_32BIT_TASK         0x5
#define IDT_16BIT_INTERRUPT    0x6
#define IDT_16BIT_TRAP         0x7
#define IDT_32BIT_INTERRUPT    0xE
#define IDT_32BIT_TRAP         0xF

__attribute__((packed))
typedef struct __idt_descriptor {
    uint16_t size;  // Size is the size of the table, minus one (max of 65535 = 65536 bytes = 8192 entries)
    uint32_t offset;
} __idt_descriptor_t;

__attribute__((packed))
typedef struct __idt_entry {
    uint16_t base;
    uint16_t gdt_entry;
    uint8_t pad;
    uint8_t type_attr;
    uint16_t base_2;
} __idt_entry_t;

__attribute__((packed))
typedef struct __interrupt_frame {
    uint8_t ip;
    uint8_t cs;
    uint8_t flags;
    uint8_t sp;
    uint8_t ss;
} __interrupt_frame_t;

#define __MAKE_IDT_DESCRIPTOR(s, o)         \
    (__idt_descriptor_t)                    \
    {                                       \
        .size = s - 1,                      \
        .offset = o                         \
    }

#define __MAKE_IDT_ENTRY(b, g, ta)                      \
    (__idt_entry_t)                                     \
    {                                                   \
        .base = b,                                      \
        .gdt_entry = g                                  \
        .pad = 0x00                                     \
        .type_attr = ta                                 \
        .base_2 = b >> 16,                              \
    }

extern void __setup_idt();
extern void interrupt_handler(__interrupt_frame_t *);

#endif  // __SIMPLEOS_IDT_H__
