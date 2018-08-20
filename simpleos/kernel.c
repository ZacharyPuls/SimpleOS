
#include "multiboot.h"

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include "cpuid.h"
#include "terminal.h"
#include "string.h"

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\nCopyright (c) 2018 Zachary Puls\n";

const char *OS_VERSION = "SimpleOS v0.1.0";
const char *KERNEL_VERSION = "Running SimpleKernel v0.1.0";

static struct __terminal __stdout;

void __println(const char *str) {
	__terminal_writeln(&__stdout, str);
	__terminal_flush(&__stdout);
}

void __kinit(void) {
	__stdout = __terminal_initialize();
}

void __kmain(void) {
	// __init_kstack(0x5DC, 0x1F4); // Start at 1500 KiB, size of 500 KiB
	__kinit();
	__println(OS_VERSION_STRING);

	if (__cpuid_supported() == 1U) {
		__cpuinfo_t cpuinfo = __get_cpuinfo();

		char stepping[32];
		char model[32];
		char family[32];
		__itos(cpuinfo.stepping_id, 16U, stepping);
		__itos(cpuinfo.model_id, 16U, model);
		__itos(cpuinfo.family_id, 16U, family);

		__terminal_write(&__stdout, cpuinfo.brand_string, true);
		__terminal_write(&__stdout, "Stepping: 0x", false);
		__terminal_write(&__stdout, stepping, true);
		__terminal_write(&__stdout, "Model: 0x", false);
		__terminal_write(&__stdout, model, true);
		__terminal_write(&__stdout, "Family: 0x", false);
		__terminal_write(&__stdout, family, true);

		__terminal_flush(&__stdout);
		/*
		__string_t model = __string_create();
		char *model_val = __malloc(sizeof(char) * 4);
		__itos(cpuinfo.model_id, 16, model_val);
		__string_append(&model, "Model: ");
		__string_append(&model, model_val);
		__terminal_writeln(&__stdout, model.buffer);
		
		__string_t family = __string_create();
		char *family_val = __malloc(sizeof(char) * 4);
		__itos(cpuinfo.family_id, 16, family_val);
		__string_append(&family, "Family: ");
		__string_append(&family, family_val);
		__terminal_writeln(&__stdout, family.buffer);
		*/
	} else {
		__println("CPUID Instruction is not supported.\n");
	}
}
