/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/idt.h>
#include <asm/iv.h>
#include <asm/pic.h>
#include <asm/tty.h>

#include <stddef.h>
#include <stdlib.h>

static __idt_entry_t *__idt;

void __setup_idt() {

    if (__idt) {
        // TODO: IDT has already been initialized, throw exception (LOL) or PANIC
    }

    const size_t idt_size = sizeof(__idt_entry_t) * (IV_MAX + 1);

    __idt = (__idt_entry_t *) malloc(idt_size);

    /**
     * TODO: If we ever end up changing the layout of the GDT, update the GDT
     * selector index here as well. Currently just using selector 1, which is {
     * 0x00000000, 0xFFFFFFFF, GDT_EXECUTABLE_READWRITE, GDT_FLAGS_DEFAULT }
     */

    __idt[0] = __MAKE_IDT_ENTRY((uint32_t)&__isr_divide_error_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[1] = __MAKE_IDT_ENTRY((uint32_t)&__isr_debug_exception_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[2] = __MAKE_IDT_ENTRY((uint32_t)&__isr_nmi_interrupt, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[3] = __MAKE_IDT_ENTRY((uint32_t)&__isr_breakpoint_trap, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[4] = __MAKE_IDT_ENTRY((uint32_t)&__isr_overflow_trap, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[5] = __MAKE_IDT_ENTRY((uint32_t)&__isr_bound_range_exceeded_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[6] = __MAKE_IDT_ENTRY((uint32_t)&__isr_invalid_opcode_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[7] = __MAKE_IDT_ENTRY((uint32_t)&__isr_device_not_available_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[8] = __MAKE_IDT_ENTRY((uint32_t)&__isr_double_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[9] = __MAKE_IDT_ENTRY((uint32_t)&__isr_coprocessor_segment_overrun_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[10] = __MAKE_IDT_ENTRY((uint32_t)&__isr_invalid_tss_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[11] = __MAKE_IDT_ENTRY((uint32_t)&__isr_segment_not_present_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[12] = __MAKE_IDT_ENTRY((uint32_t)&__isr_stack_segment_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[13] = __MAKE_IDT_ENTRY((uint32_t)&__isr_general_protection_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[14] = __MAKE_IDT_ENTRY((uint32_t)&__isr_page_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[15] = __MAKE_IDT_ENTRY((uint32_t)&__isr_math_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[16] = __MAKE_IDT_ENTRY((uint32_t)&__isr_alignment_check_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[17] = __MAKE_IDT_ENTRY((uint32_t)&__isr_machine_check_abort, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[18] = __MAKE_IDT_ENTRY((uint32_t)&__isr_simd_floating_point_exception_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[19] = __MAKE_IDT_ENTRY((uint32_t)&__isr_virtualization_exception_fault, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[20] = __MAKE_IDT_ENTRY((uint32_t)&__isr_keyboard, 1, IDT_DEFAULT_TYPE_ATTR);
    __idt[21] = __MAKE_IDT_ENTRY((uint32_t)&__isr_syscall, 1, IDT_DEFAULT_TYPE_ATTR);

    __idt_descriptor_t __idtr = __MAKE_IDT_DESCRIPTOR(idt_size, (size_t)__idt);

    __asm__ __volatile__(
        "lidt (%0)"
        :
        : "r"(&__idtr)
        :
    );

    tty_writeln(__primary_console, "IDT successfully initialized.\n");
    tty_flush(__primary_console);
}

__attribute__((interrupt))
void __isr_divide_error_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_DIVIDE_ERROR_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_DIVIDE_ERROR_FAULT);
}

__attribute__((interrupt))
void __isr_debug_exception_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_DEBUG_EXCEPTION_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_DEBUG_EXCEPTION_FAULT);
}

__attribute__((interrupt))
void __isr_nmi_interrupt(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_NMI_INTERRUPT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_NMI_INTERRUPT);
}

__attribute__((interrupt))
void __isr_breakpoint_trap(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_BREAKPOINT_TRAP triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_BREAKPOINT_TRAP);
}

__attribute__((interrupt))
void __isr_overflow_trap(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_OVERFLOW_TRAP triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_OVERFLOW_TRAP);
}

__attribute__((interrupt))
void __isr_bound_range_exceeded_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_BOUND_RANGE_EXCEEDED_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_BOUND_RANGE_EXCEEDED_FAULT);
}

__attribute__((interrupt))
void __isr_invalid_opcode_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_INVALID_OPCODE_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_INVALID_OPCODE_FAULT);
}

__attribute__((interrupt))
void __isr_device_not_available_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_DEVICE_NOT_AVAILABLE_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_DEVICE_NOT_AVAILABLE_FAULT);
}

__attribute__((interrupt))
void __isr_double_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_DOUBLE_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_DOUBLE_FAULT);
}

__attribute__((interrupt))
void __isr_coprocessor_segment_overrun_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_COPROCESSOR_SEGMENT_OVERRUN_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_COPROCESSOR_SEGMENT_OVERRUN_FAULT);
}

__attribute__((interrupt))
void __isr_invalid_tss_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_INVALID_TSS_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_INVALID_TSS_FAULT);
}

__attribute__((interrupt))
void __isr_segment_not_present_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_SEGMENT_NOT_PRESENT_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_SEGMENT_NOT_PRESENT_FAULT);
}

__attribute__((interrupt))
void __isr_stack_segment_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_STACK_SEGMENT_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_STACK_SEGMENT_FAULT);
}

__attribute__((interrupt))
void __isr_general_protection_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_GENERAL_PROTECTION_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_GENERAL_PROTECTION_FAULT);
}

__attribute__((interrupt))
void __isr_page_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_PAGE_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_PAGE_FAULT);
}

__attribute__((interrupt))
void __isr_math_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_MATH_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_MATH_FAULT);
}

__attribute__((interrupt))
void __isr_alignment_check_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_ALIGNMENT_CHECK_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_ALIGNMENT_CHECK_FAULT);
}

__attribute__((interrupt))
void __isr_machine_check_abort(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_MACHINE_CHECK_ABORT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_MACHINE_CHECK_ABORT);
}

__attribute__((interrupt))
void __isr_simd_floating_point_exception_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_SIMD_FLOATING_POINT_EXCEPTION_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_SIMD_FLOATING_POINT_EXCEPTION_FAULT);
}

__attribute__((interrupt))
void __isr_virtualization_exception_fault(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_VIRTUALIZATION_EXCEPTION_FAULT triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_VIRTUALIZATION_EXCEPTION_FAULT);
}

__attribute__((interrupt))
void __isr_keyboard(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_KEYBOARD triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_KEYBOARD);
}

__attribute__((interrupt))
void __isr_syscall(__interrupt_frame_t *frame) {
    tty_writeln(__primary_console, "IV_SYSCALL triggered\n");
    tty_flush(__primary_console);
    PIC_SEND_EOI(IV_SYSCALL);
}
