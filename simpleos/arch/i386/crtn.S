/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

.section .init
    /* crtend.o .init */
    popl %ebp
    ret

.section .fini
    /* crtend.o .fini */
    