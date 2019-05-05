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

#define IDT_DEFAULT_TYPE_ATTR \
    IDT_USED | IDT_RING_0 | IDT_NONSTORAGE | IDT_32BIT_INTERRUPT

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
/*    uint8_t ip;
    uint8_t cs;
    uint8_t flags;
    uint8_t sp;
    uint8_t ss;*/
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
    uint32_t int_no, err_code;    // Interrupt number and error code (if applicable)
    uint32_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
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
        .base = b & 0xFFFF,                             \
        .gdt_entry = g,                                 \
        .pad = 0x00,                                    \
        .type_attr = ta,                                \
        .base_2 = (b >> 16) & 0xFFFF                    \
    }

extern void __setup_idt();
/*
extern void __isr_divide_error_fault(__interrupt_frame_t *);
extern void __isr_debug_exception_fault(__interrupt_frame_t *);
extern void __isr_nmi_interrupt(__interrupt_frame_t *);
extern void __isr_breakpoint_trap(__interrupt_frame_t *);
extern void __isr_overflow_trap(__interrupt_frame_t *);
extern void __isr_bound_range_exceeded_fault(__interrupt_frame_t *);
extern void __isr_invalid_opcode_fault(__interrupt_frame_t *);
extern void __isr_device_not_available_fault(__interrupt_frame_t *);
extern void __isr_double_fault(__interrupt_frame_t *);
extern void __isr_coprocessor_segment_overrun_fault(__interrupt_frame_t *);
extern void __isr_invalid_tss_fault(__interrupt_frame_t *);
extern void __isr_segment_not_present_fault(__interrupt_frame_t *);
extern void __isr_stack_segment_fault(__interrupt_frame_t *);
extern void __isr_general_protection_fault(__interrupt_frame_t *);
extern void __isr_page_fault(__interrupt_frame_t *);
extern void __isr_math_fault(__interrupt_frame_t *);
extern void __isr_alignment_check_fault(__interrupt_frame_t *);
extern void __isr_machine_check_abort(__interrupt_frame_t *);
extern void __isr_simd_floating_point_exception_fault(__interrupt_frame_t *);
extern void __isr_virtualization_exception_fault(__interrupt_frame_t *);
extern void __isr_keyboard(__interrupt_frame_t *);
extern void __isr_syscall(__interrupt_frame_t *);
*/

void irq0();
void irq1();
void irq2();
void irq3();
void irq4();
void irq5();
void irq6();
void irq7();
void irq8();
void irq9();
void irq10();
void irq11();
void irq12();
void irq13();
void irq14();
void irq15();

#endif  // __SIMPLEOS_IDT_H__
