/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

/* Multiboot header - definitions */
.set ALIGN,	1<<0
.set MEMINFO,	1<<1
.set FLAGS, 	ALIGN | MEMINFO
.set MAGIC,	0x1BADB002
.set CHECKSUM,	-(MAGIC + FLAGS)

/* Multiboot header - data */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Allocate 16KiB for stack */
.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

/* Kernel entry point */
.section .text
.global __kstart
.type __kstart, @function
__kstart:
	/* GRUB has loaded us into x86 protected mode, w/ interrupts/paging disabled, ring 0 */
	/* Init stack */
	mov $stack_top, %esp

	/* TODO: Load GDT, enable paging, C++ exceptions, etc while still in ring 0 and kernel is unloaded */

	/* call __init_paging */

	/* Enter the kernel. ABI requires a 16-byte aligned stack at the time of the call instruction,
	   return pointer of size 4bytes will be pushed. */
	call __kmain

	/* Enter an infinite loop, kernel should never exit. */
	/* To do an infinite loop, disable interrupts (cli), wait for the next interrupt (hlt), and
	   just in case, jmp back to the hlt instruction if it ever breaks due to a non-maskable interrupt */
	cli
1:	hlt
	jmp 1

.size __kstart, . - __kstart
