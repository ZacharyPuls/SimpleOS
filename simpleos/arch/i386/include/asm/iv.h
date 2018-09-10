/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_IV_H__
#define __SIMPLEOS_IV_H__

/**
 *
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 * | Vector | Mnemonic |                Description                 |    Type    |      Error Code       |                               Source                                |
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 * | 0      | #DE      | Divide Error                               | Fault      | No                    | DIV and IDIV instructions.                                          |
 * | 1      | #DB      | Debug Exception                            | Fault/Trap | No                    | Instruction, data, and I/O breakpoints; single-step; and others.    |
 * | 2      | -        | NMI Interrupt                              | Interrupt  | No                    | Nonmaskable external interrupt.                                     |
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
 * | 15     | -        | (Intel reserved. Do not use.)              | No         |                       |                                                                     |
 * | 16     | #MF      | x87 FPU Floating-Point Error (Math Fault)  | Fault      | No                    | x87 FPU floating-point or WAIT/FWAIT instruction.                   |
 * | 17     | #AC      | Alignment Check                            | Fault      | Yes (Zero)            | Any data reference in memory.                                       |
 * | 18     | #MC      | Machine Check                              | Abort      | No                    | Error codes (if any) and source are model dependent.                |
 * | 19     | #XM      | SIMD Floating-Point Exception              | Fault      | No                    | SSE/SSE2/SSE3 floating-point instructions                           |
 * | 20     | #VE      | Virtualization Exception                   | Fault      | No                    | EPT violations                                                      |
 * | 21-31  | -        | Intel reserved. Do not use.                |            |                       |                                                                     |
 * | 32-255 | -        | User Defined (Non-reserved) Interrupts     | Interrupt  | External interrupt or |                                                                     |
 * |        |          |                                            |            | INT n instruction.    |                                                                     |
 * +--------+----------+--------------------------------------------+------------+-----------------------+---------------------------------------------------------------------+
 *
 */

#define IV_DIVIDE_ERROR_FAULT                      0x00
#define IV_DEBUG_EXCEPTION_FAULT                   0x01
#define IV_DEBUG_EXCEPTION_TRAP                    IV_DEBUG_EXCEPTION_FAULT
#define IV_NMI_INTERRUPT                           0x02
#define IV_BREAKPOINT_TRAP                         0x03
#define IV_OVERFLOW_TRAP                           0x04
#define IV_BOUND_RANGE_EXCEEDED_FAULT              0x05
#define IV_INVALID_OPCODE_FAULT                    0x06
#define IV_UNDEFINED_OPCODE_FAULT                  IV_INVALID_OPCODE_FAULT
#define IV_DEVICE_NOT_AVAILABLE_FAULT              0x07
#define IV_NO_MATH_COPROCESSOR_FAULT               IV_DEVICE_NOT_AVAILABLE_FAULT
#define IV_DOUBLE_FAULT                            0x08
#define IV_COPROCESSOR_SEGMENT_OVERRUN_FAULT       0x09     // Should not be asserted by any processor after the i386
#define IV_INVALID_TSS_FAULT                       0x0A
#define IV_SEGMENT_NOT_PRESENT_FAULT               0x0B
#define IV_STACK_SEGMENT_FAULT                     0x0C
#define IV_GENERAL_PROTECTION_FAULT                0x0D
#define IV_PAGE_FAULT                              0x0E
#define IV_RESERVED                                0x0F
#define IV_MATH_FAULT                              0x10
#define IV_ALIGNMENT_CHECK_FAULT                   0x11     // Introduced with the i486 processor
#define IV_MACHINE_CHECK_ABORT                     0x12     // Introduced with the Pentium processor, updated with the P6 family
#define IV_SIMD_FLOATING_POINT_EXCEPTION_FAULT     0x13     // Introduced with the P3 processor
#define IV_VIRTUALIZATION_EXCEPTION_FAULT          0x14     // Can only occur on processors that support the 1-setting of the "EPT Violation #VE" VM-execution control
//      IV_INTEL_RESERVED                          0x15
//      IV_INTEL_RESERVED                          0x16
//      IV_INTEL_RESERVED                          0x17
//      IV_INTEL_RESERVED                          0x18
//      IV_INTEL_RESERVED                          0x19
//      IV_INTEL_RESERVED                          0x1A
//      IV_INTEL_RESERVED                          0x1B
//      IV_INTEL_RESERVED                          0x1C
//      IV_INTEL_RESERVED                          0x1D
//      IV_INTEL_RESERVED                          0x1E
//      IV_INTEL_RESERVED                          0x1F

// User-defined interrupt vectors
#define IV_KEYBOARD                                0x20
#define IV_SYSCALL                                 0x80

#define IV_MAX                                     0xFF

#endif  // __SIMPLEOS_IV_H__
