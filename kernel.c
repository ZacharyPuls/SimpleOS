
#include <stddef.h>
#include <stdint.h>

#include "terminal.h"

const char *OS_VERSION_STRING = "SimpleOS v0.1.0\n    Running SimpleKernel v0.1.0\n\nCopyright (c) 2018 Zachary Puls";

const char *OS_VERSION = "SimpleOS v0.1.0";
const char *KERNEL_VERSION = "Running SimpleKernel v0.1.0";

static struct __terminal __stdout;

void __println(const char *str) {
	__terminal_writeln(&__stdout, str);
}

void __kinit(void) {
	__stdout = __terminal_initialize();
}

void __kmain(void) {
	__kinit();
	__println(OS_VERSION_STRING);
}
