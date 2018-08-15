
#include "multiboot.h"

#include <stddef.h>
#include <stdint.h>

#include "terminal.h"

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\n\nCopyright (c) 2018 Zachary Puls";

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
}
