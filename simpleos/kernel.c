
#include <simpleos/cpuid.h>
#include <simpleos/tty.h>

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\nCopyright (c) 2018 Zachary Puls\n";

const char *OS_VERSION = "SimpleOS v0.1.0";
const char *KERNEL_VERSION = "Running SimpleKernel v0.1.0";

static tty_t stdout;

void __println(const char *str) {
	tty_writeln(&stdout, str);
	tty_flush(&stdout);
}

void __kinit(void) {
	stdout = tty_init();
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

		tty_write(&stdout, cpuinfo.brand_string, true);
		tty_write(&stdout, "Stepping: 0x", false);
		tty_write(&stdout, stepping, true);
		tty_write(&stdout, "Model: 0x", false);
		tty_write(&stdout, model, true);
		tty_write(&stdout, "Family: 0x", false);
		tty_write(&stdout, family, true);

		tty_flush(&stdout);
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
