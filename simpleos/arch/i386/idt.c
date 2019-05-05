/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/idt.h>
#include <asm/iv.h>
#include <asm/pic.h>
#include <asm/tty.h>

#include <input/keyboard.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t idt_offset = 0x1410;
uint32_t idtr_offset = 0x500;

__attribute__((interrupt))
void irq0(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq1(__interrupt_frame_t *frame) {
    uint8_t val;
    INB(0x60, val);
    if (val <= SC_KEY_ESCAPE_R) {
        tty_write(__primary_console, __scancode_to_alpha(val));
        tty_flush(__primary_console);
    }
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq2(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq3(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq4(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq5(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq6(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq7(__interrupt_frame_t *frame) {
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq8(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq9(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq10(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq11(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq12(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq13(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq14(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
}

__attribute__((interrupt))
void irq15(__interrupt_frame_t *frame) {
    OUTB(0xA0, 0x20);
    OUTB(0x20, 0x20);
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

void register_interrupt_handler(uint8_t i, uint32_t address) {
    *(uint16_t *)(idt_offset + (i * 8)) = address & 0xFFFF;
    *(uint16_t *)(idt_offset + (i * 8) + 2) = 0x0008;
    *(uint16_t *)(idt_offset + (i * 8) + 4) = 0x8E00;
    *(uint16_t *)(idt_offset + (i * 8) + 6) = (address >> 16) & 0xFFFF;
}

void __setup_idt() {
    register_interrupt_handler(0, (uint32_t)&__isr_divide_error_fault);
    register_interrupt_handler(1, (uint32_t)&__isr_debug_exception_fault);
    register_interrupt_handler(2, (uint32_t)&__isr_nmi_interrupt);
    register_interrupt_handler(3, (uint32_t)&__isr_breakpoint_trap);
    register_interrupt_handler(4, (uint32_t)&__isr_overflow_trap);
    register_interrupt_handler(5, (uint32_t)&__isr_bound_range_exceeded_fault);
    register_interrupt_handler(6, (uint32_t)&__isr_invalid_opcode_fault);
    register_interrupt_handler(7, (uint32_t)&__isr_device_not_available_fault);
    register_interrupt_handler(8, (uint32_t)&__isr_double_fault);
    register_interrupt_handler(10, (uint32_t)&__isr_invalid_tss_fault);
    register_interrupt_handler(11, (uint32_t)&__isr_segment_not_present_fault);
    register_interrupt_handler(12, (uint32_t)&__isr_stack_segment_fault);
    register_interrupt_handler(13, (uint32_t)&__isr_general_protection_fault);
    register_interrupt_handler(14, (uint32_t)&__isr_page_fault);
    register_interrupt_handler(16, (uint32_t)&__isr_math_fault);
    register_interrupt_handler(17, (uint32_t)&__isr_alignment_check_fault);
    register_interrupt_handler(18, (uint32_t)&__isr_machine_check_abort);
    register_interrupt_handler(19, (uint32_t)&__isr_simd_floating_point_exception_fault);
    register_interrupt_handler(20, (uint32_t)&__isr_virtualization_exception_fault);

    register_interrupt_handler(32, (uint32_t)&irq0);
    register_interrupt_handler(33, (uint32_t)&irq1);
    register_interrupt_handler(34, (uint32_t)&irq2);
    register_interrupt_handler(35, (uint32_t)&irq3);
    register_interrupt_handler(36, (uint32_t)&irq4);
    register_interrupt_handler(37, (uint32_t)&irq5);
    register_interrupt_handler(38, (uint32_t)&irq6);
    register_interrupt_handler(39, (uint32_t)&irq7);
    register_interrupt_handler(40, (uint32_t)&irq8);
    register_interrupt_handler(41, (uint32_t)&irq9);
    register_interrupt_handler(42, (uint32_t)&irq10);
    register_interrupt_handler(43, (uint32_t)&irq11);
    register_interrupt_handler(44, (uint32_t)&irq12);
    register_interrupt_handler(45, (uint32_t)&irq13);
    register_interrupt_handler(46, (uint32_t)&irq14);
    register_interrupt_handler(47, (uint32_t)&irq15);

    *(uint16_t *)(idtr_offset) = 0x7FF; // 0x0800 - 0x0001
	*(uint32_t *)(idtr_offset + 2) = idt_offset;

    __asm__ __volatile__(
        "push %%ebp\n\t"
        "mov %%esp, %%ebp\n\t"
        "lidt (%0)\n\t"
        "mov %%ebp, %%esp\n\t"
        "pop %%ebp" : : "r"(idtr_offset)
    );
}