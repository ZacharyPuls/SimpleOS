
#include <asm/cpuid.h>
#include <asm/tty.h>
#include <asm/gdt.h>
#include <asm/idt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\nCopyright (c) 2018 Zachary Puls\n\n";

static tty_t console;

void __kinit(void) {
	console = tty_init();
}

void __kmain(void) {
	__kinit();
	tty_writeln(&console, OS_VERSION_STRING);

	if (__cpuid_supported() == 1U) {
		__cpuinfo_t cpuinfo = __get_cpuinfo();

		/*
		char stepping[32];
		char model[32];
		char family[32];
		snprintf(stepping, 32, "Stepping: %x", cpuinfo.stepping_id);
		snprintf(model, 32, "Model: %x", cpuinfo.model_id);
		snprintf(family, 32, "Family: %x", cpuinfo.family_id);
		*/

		tty_writeln(&console, "CPUID Instruction is supported, retrieving CPUID info...\n");

		/*
		tty_writeln(&console, stepping);
		tty_writeln(&console, model);
		tty_writeln(&console, family);		
		*/

		char *family = (char *)malloc(sizeof(char) * 32);
		snprintf(family, 32, "\tFamily: 0x%x\n", cpuinfo.family_id);
		tty_writeln(&console, family);

		char *model = (char *)malloc(sizeof(char) * 32);
		snprintf(model, 32, "\tModel: 0x%x\n", cpuinfo.model_id);
		tty_writeln(&console, model);

		char *stepping = (char *)malloc(sizeof(char) * 32);
		snprintf(stepping, 32, "\tStepping: 0x%x\n", cpuinfo.stepping_id);
		tty_writeln(&console, stepping);

		tty_writeln(&console, "\tBrand: ");
		tty_writeln(&console, cpuinfo.brand_string);
		tty_writeln(&console, "\n\n");

		tty_writeln(&console, "Booting user-mode O/S...\n\n");
		tty_writeln(&console, "Initializing GDT...");
		__setup_gdt();
		tty_writeln(&console, "Done!\n");

		tty_writeln(&console, "Initializing IDT...");
		__setup_idt();
		tty_writeln(&console, "Done!\n");

		tty_writeln(&console, "\n");

		tty_writeln(&console, "Enter a command, followed by a newline.\n");
		tty_writeln(&console, "    > ");


	} else {
		tty_writeln(&console, "CPUID Instruction is not supported.\n");
	}

	// tty_flush(&console);
}
