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
	struct __memmap_region *segments;
	struct __stack_elem *elements;
	uint64_t top;
};

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

uint64_t __push(struct __stack *stack, const uint64_t size) {
	uint64_t address = __find_free_segment(stack, size);
	stack->elements[stack->top++] = { address, size };
	return address;
}

void __pop(struct __stack *stack, const uint64_t address) {
	// TODO: Research better ways of freeing memory
	
}

void __build_stack_frame(struct __stack *stack, const uint64_t base_address, const uint64_t size) {
	struct __memmap_region *memmap = (struct __memmap_region *)base_address;
	int count = __memmap(memmap, size / sizeof(__memmap_region));

	if (count == -1) {
		// TODO: PANIC!
		return;
	}

	stack->segments = memmap;
	stack->elements = (struct __stack_elem *)(base_address + count * sizeof(__memmap_region)); 
	stack->top = 0;
}

#endif