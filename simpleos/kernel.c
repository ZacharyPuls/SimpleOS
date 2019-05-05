/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/cpuid.h>
#include <asm/gdt.h>
#include <asm/idt.h>
#include <asm/iv.h>
#include <asm/pic.h>
#include <asm/tty.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *SIMPLEOS_BANNER = \
"   _____ _                 __     ____  _____\n" \
"  / ___/(_)___ ___  ____  / /__  / __ \\/ ___/\n" \
"  \\__ \\/ / __ `__ \\/ __ \\/ / _ \\/ / / /\\__ \\ \n" \
" ___/ / / / / / / / /_/ / /  __/ /_/ /___/ / \n" \
"/____/_/_/ /_/ /_/ .___/_/\\___/\\____//____/  \n" \
"                /_/                          \n";

// const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\nCopyright (c) 2018 Zachary Puls\n\n";

static tty_t console;

void __kinit(void) {
    PIC_REMAP(IV_KEYBOARD, 0xF9 | 0x08, IV_KEYBOARD + 8, 0xEF);
    console = tty_init();
    __primary_console = &console;
}

void __kmain(void) {
    __kinit();
    tty_writeln(&console, SIMPLEOS_BANNER);

    if (__cpuid_supported() == 1U) {
        __cpuinfo_t cpuinfo = __get_cpuinfo();

        tty_writeln(__primary_console, "CPUID support: Yes\n");

        tty_writeln(__primary_console, "Initializing GDT...");
        load_gdt();
        tty_writeln(__primary_console, "Done.\n");

        tty_writeln(__primary_console, "Initializing IDT...");
        __setup_idt();
        tty_writeln(__primary_console, "Done.\n");

        // tty_writeln(__primary_console, "Initializing Paging...");
        // __init_paging();
        // tty_writeln(__primary_console, "Done.\n");

        tty_writeln(__primary_console, "Enter a command, followed by a newline.\n");
        tty_writeln(__primary_console, "    > ");
        
        __asm__ __volatile__("sti");
    } else {
        tty_writeln(__primary_console, "CPUID support: No\n");
    }

    for (;;) {
        asm("HLT");
    }
}
