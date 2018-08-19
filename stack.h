#ifndef __SIMPLEOS_STACK_H__
#define __SIMPLEOS_STACK_H__

#include <stdbool.h>
#include <stdint.h>

#include "memmap.h"

#define __between(x, min, max) ((x - min) <= (max - min))

struct __stack_elem {
	uint64_t address;
	uint64_t size;
};

struct __stack {
	uint64_t base_addr;
	struct __stack_elem *elements;
	uint64_t top;
};
/*
bool __is_segment_occupied(struct __stack *stack, const uint64_t offset, const uint64_t size) {
	do {
		// TODO: first make sure offset and size are within the bounds of the stack
		if (__between(stack->elements->address, offset, size) || __between(stack->elements->address + stack->elements->size, offset, size)) {
			return true;
		}
	} while (++stack->elements);

	return false;
}

uint64_t __find_free_segment(struct __stack *stack, const uint64_t size) {
	uint64_t offset = 0;
	do {
			if (__between(offset, stack->segments->base, stack->segments->length)) {
			// Requested address is between segment base and max length
			if (__between(offset + size, stack->segments->base, stack->segments->length)) {
				// Requested block of memory is in bounds for this segment
				return stack->segments->base + offset;
			}
		}
	} while (++stack->segments && ++offset);

	return -1;
}

inline uint64_t __push(struct __stack *stack, const uint64_t size) {
	uint64_t address = __find_free_segment(stack, size);
	stack->elements[stack->top++] = (struct __stack_elem) { .address = address, .size = size };
	return address;
}*/

inline uint64_t __push(struct __stack *stack, const uint64_t size) {
	const uint64_t offset = stack->base_addr - stack->top;
	stack->top += size;
	return offset;
}

inline void __pop(struct __stack *stack, const uint64_t address) {
	// TODO: Research better ways of freeing memory
	stack->base_addr = address;
	stack->top -= sizeof(uint64_t);
}

inline void __build_stack_frame(struct __stack *stack, const uint64_t base_address, const uint64_t size) {
	/*struct __memmap_region *memmap = (struct __memmap_region *)&base_address;
	int count = __memmap(memmap, size / sizeof(struct __memmap_region));

	if (count == -1) {
		// TODO: PANIC!
		return;
	}

	stack->segments = memmap;*/
	stack->base_addr = base_address;
	uint64_t stack_elem_address = base_address - size;
	stack->elements = (struct __stack_elem *)&stack_elem_address; 
	stack->top = 0;
}

inline static uint16_t __get_next_memory_addr(const size_t size) {
	static uint16_t cursor = 1500;
	uint16_t addr = cursor;
	cursor += size;
	return addr;
}

#endif