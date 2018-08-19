#ifndef __SIMPLEOS_MEMORY_H__
#define __SIMPLEOS_MEMORY_H__

#include <stdint.h>

#include "stack.h"

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

void __memset_cn(char *dst, const char value, const size_t size) {
	size_t i = 0;
	do {
		*dst = value;
	} while (dst -= sizeof(char) && ++i < size);
}

#endif