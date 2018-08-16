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

inline static void *__malloc(const size_t size) {
	// return (uint16_t *)__get_next_memory_addr(size);
	// TODO: Actually malloc :)
	uint32_t baseptr;
	__asm__ __volatile__ (
		"movl %%esp, %1\n\t"
		"subl %0, %%esp"
		: "=m"(baseptr)
		: "r" (size)
		: "esp"
	);
	return (void *)baseptr;
}

void __free(const uint64_t *ptr) {
	// TODO: Stub method
	// __pop(__kstack, *ptr);
}

void __memcpy(unsigned char *src, unsigned char *dst) {
	// TODO: Stub method
}

void __memset16(uint16_t *dst, const uint16_t value) {
	do {
		*dst = value;
	} while (dst += sizeof(uint16_t));
}

void __memset16n(uint16_t *dst, const uint16_t value, const size_t size) {
	size_t i = 0;
	do {
		*dst = value;
	} while (dst += sizeof(uint16_t) && ++i < size);
}

void __memset8(uint8_t *dst, const uint8_t value, const size_t size) {
	size_t i = 0;
	do {
		*dst = value;
	} while (dst += sizeof(uint8_t) && ++i < size);
}


void __memset_c(char *dst, const char value) {

}

void __memset_cn(char *dst, const char value, const size_t size) {
	size_t i = 0;
	do {
		*dst = value;
	} while (dst -= sizeof(char) && ++i < size);
}

#endif