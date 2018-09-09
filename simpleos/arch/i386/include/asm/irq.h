#ifndef __SIMPLEOS_IRQ_H__
#define __SIMPLEOS_IRQ_H__

/**
 * 
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 * | Vector | Mnemonic |                Description                 |    Type    |      Error Code       |                               Source                                |
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 * | 0      | #DE      | Divide Error                               | Fault      | No                    | DIV and IDIV instructions.                                          |
 * | 1      | #DB      | Debug Exception                            | Fault/Trap | No                    | Instruction, data, and I/O breakpoints; single-step; and others.    |
 * | 2      | —        | NMI Interrupt                              | Interrupt  | No                    | Nonmaskable external interrupt.                                     |
 * | 3      | #BP      | Breakpoint                                 | Trap       | No                    | INT3 instruction.                                                   |
 * | 4      | #OF      | Overflow                                   | Trap       | No                    | INTO instruction.                                                   |
 * | 5      | #BR      | BOUND Range Exceeded                       | Fault      | No                    | BOUND instruction.                                                  |
 * | 6      | #UD      | Invalid Opcode (Undefined Opcode)          | Fault      | No                    | UD instruction or reserved opcode.                                  |
 * | 7      | #NM      | Device Not Available (No Math Coprocessor) | Fault      | No                    | Floating-point or WAIT/FWAIT instruction.                           |
 * | 8      | #DF      | Double Fault                               | Abort      | Yes (zero)            | Any instruction that can generate an exception, an NMI, or an INTR. |
 * | 9      | -        | Coprocessor Segment Overrun (reserved)     | Fault      | No                    | Floating-point instruction.                                         |
 * | 10     | #TS      | Invalid TSS                                | Fault      | Yes                   | Task switch or TSS access.                                          |
 * | 11     | #NP      | Segment Not Present                        | Fault      | Yes                   | Loading segment registers or accessing system segments.             |
 * | 12     | #SS      | Stack-Segment Fault                        | Fault      | Yes                   | Stack operations and SS register loads.                             |
 * | 13     | #GP      | General Protection                         | Fault      | Yes                   | Any memory reference and other protection checks.                   |
 * | 14     | #PF      | Page Fault                                 | Fault      | Yes                   | Any memory reference.                                               |
 * | 15     | —        | (Intel reserved. Do not use.)              | No         |                       |                                                                     |
 * | 16     | #MF      | x87 FPU Floating-Point Error (Math Fault)  | Fault      | No                    | x87 FPU floating-point or WAIT/FWAIT instruction.                   |
 * | 17     | #AC      | Alignment Check                            | Fault      | Yes (Zero)            | Any data reference in memory.                                       |
 * | 18     | #MC      | Machine Check                              | Abort      | No                    | Error codes (if any) and source are model dependent.                |
 * | 19     | #XM      | SIMD Floating-Point Exception              | Fault      | No                    | SSE/SSE2/SSE3 floating-point instructions                           |
 * | 20     | #VE      | Virtualization Exception                   | Fault      | No                    | EPT violations                                                      |
 * | 21-31  | —        | Intel reserved. Do not use.                |            |                       |                                                                     |
 * | 32-255 | —        | User Defined (Non-reserved) Interrupts     | Interrupt  | External interrupt or |                                                                     |
 * |        |          |                                            |            | INT n instruction.    |                                                                     |
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 * 
 */

#define IRQ_DIVIDE_ERROR_FAULT                      0x00
#define IRQ_DEBUG_EXCEPTION_FAULT                   0x01
#define IRQ_DEBUG_EXCEPTION_TRAP                    IRQ_DEBUG_EXCEPTION_FAULT
#define IRQ_NMI_INTERRUPT                           0x02
#define IRQ_BREAKPOINT_TRAP                         0x03
#define IRQ_OVERFLOW_TRAP                           0x04
#define IRQ_BOUND_RANGE_EXCEEDED_FAULT              0x05
#define IRQ_INVALID_OPCODE_FAULT                    0x06
#define IRQ_UNDEFINED_OPCODE_FAULT                  IRQ_INVALID_OPCODE_FAULT
#define IRQ_DEVICE_NOT_AVAILABLE_FAULT              0x07
#define IRQ_NO_MATH_COPROCESSOR_FAULT               IRQ_DEVICE_NOT_AVAILABLE_FAULT
#define IRQ_DOUBLE_FAULT                            0x08
#define IRQ_COPROCESSOR_SEGMENT_OVERRUN_FAULT       0x09    // DO NOT USE, RESERVED
#define IRQ_INVALID_TSS_FAULT                       0x0A
#define IRQ_SEGMENT_NOT_PRESENT_FAULT               0x0B
#define IRQ_STACK_SEGMENT_FAULT                     0x0C
#define IRQ_GENERAL_PROTECTION_FAULT                0x0D
#define IRQ_PAGE_FAULT                              0x0E
#define IRQ_RESERVED                                0x0F
#define IRQ_MATH_FAULT                              0x10
#define IRQ_ALIGNMENT_CHECK_FAULT                   0x11
#define IRQ_MACHINE_CHECK_ABORT                     0x12
#define IRQ_SIMD_FLOATING_POINT_EXCEPTION_FAULT     0x13
#define IRQ_VIRTUALIZATION_EXCEPTION_FAULT          0x14

#endif