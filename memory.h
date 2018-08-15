#ifndef __SIMPLEOS_MEMORY_H__
#define __SIMPLEOS_MEMORY_H__

#include <stdint.h>

#include "stack.h"

#define KSTACK_BASE_ADDRESS 0x5000
#define KSTACK_SIZE 0x2000

// static struct __stack *__kstack;

void __init_kstack(const uint64_t base_address, const uint64_t size) {
	// __build_stack_frame(__kstack, base_address, size); 
}

inline static uint16_t *__malloc(const size_t size) {
	// return (uint16_t *)__get_next_memory_addr(size);
	// TODO: Actually malloc :)
	uint16_t baseptr;
	__asm__  (
		"movl %%esp, %1\n\t"
		"subl %0, %%esp"
		: "=m"(baseptr)
		: "r" (size)
		: "esp"
	);
	return (uint16_t *)baseptr;
}

void __free(const uint64_t *ptr) {
	// TODO: Stub method
	// __pop(__kstack, *ptr);
}

void __memcpy(unsigned char *src, unsigned char *dst) {
	// TODO: Stub method
}

#endif