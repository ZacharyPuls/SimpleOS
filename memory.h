#ifndef __SIMPLEOS_MEMORY_H__
#define __SIMPLEOS_MEMORY_H__

#include <stdint.h>

#include "stack.h"

#define KSTACK_BASE_ADDRESS 0x1000
#define KSTACK_SIZE 0x2000

static struct __stack *__kstack;

unsigned char *__malloc(const size_t size) {
	if (!__kstack) {
		__build_stack_frame(__kstack, KSTACK_BASE_ADDRESS, KSTACK_SIZE);
	}

	return (unsigned char *)__push(__kstack, size);
}

void __free(const uint64_t *ptr) {
	// TODO: Stub method
	__pop(__kstack, *ptr);
}

void __memcpy(unsigned char *src, unsigned char *dst) {
	// TODO: Stub method
}

#endif