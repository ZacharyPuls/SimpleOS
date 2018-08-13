#ifndef __SIMPLEOS_MEMORY_H__
#define __SIMPLEOS_MEMORY_H__

#include <stdint.h>

#include "stack.h"

unsigned char *__malloc(const size_t size) {
}

void __memcpy(unsigned char *src, unsigned char *dst) {
	
}

void __memmap() {
	uint64_t base_address;
	uint64_t region_length = 24; // Need to set this to 1 to retain compatibility w/ ACPI
	uint32_t region_type;
	/* For ACPI 3.0 Extended Attributes field (only when the 0x15/0xE820 interrupt returns 24 bytes). *
	 * This is not used for now, as ACPI 3.0 is not common in current hardware. 					  *
     * If this field were going to be used, the first bit (bit 0) would indicate whether or not the   *
	 * entry should be ignored (0/clear = ignore), and the second bit (bit 1) would indicate whether  *
	 * or not the entry is NVRAM (1/set = NVRAM)													  */
	uint32_t extended_attributes;

	static uint32_t current_offset = 0;

	__asm__ __volatile__ (
		"movl 0xE820, 	  %%eax" // Interrupt 0xE820, Get System Memory Map
		"movl 0x18,		  %%ecx" // Use a 24-byte return buffer, even though we are expecting 20 bytes. See above about ACPI 3.0.
		"movl 0x534D4150, %%edx" // 'SMAP'
		"int 0x15"
		"mov %%"
		: "=r" (base_address)
		  "+b" (current_offset)
		  "+c" (region_length)
		  "=r" (region_type))
		:
		: "eax", "ebx", "ecx", "edx"
	);
}


#endif