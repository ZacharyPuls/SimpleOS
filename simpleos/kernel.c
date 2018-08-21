
#include <asm/cpuid.h>
#include <asm/tty.h>

#include <stdio.h>
#include <stdlib.h>

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\nCopyright (c) 2018 Zachary Puls\n";

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

		char *stepping = malloc()
	} else {
		tty_writeln(&console, "CPUID Instruction is not supported.\n");
	}

	tty_flush(&console);
}
