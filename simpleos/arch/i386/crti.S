/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

.section .init
.global _init
.type _init, @function
_init:
    push %ebp
    movl %esp, %ebp
    /* crtbegin.o .init */

.section .fini
.global _fini
.type _fini, @function
_fini:
    push %ebp
    movl %esp, %ebp
    /* crtbegin.o .fini */
    