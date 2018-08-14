#ifndef __SIMPLEOS_MEMMAP_H__
#define __SIMPLEOS_MEMMAP_H__

#include <stdint.h>

inline uint32_t __loword(uint64_t __x) {
  return __x & 0x00000000FFFFFFFF;
}

inline uint32_t __hiword(uint64_t __x) {
  return __x & 0xFFFFFFFF00000000;
}

struct __memmap_region {
  uint64_t base;
  uint64_t length;
  uint32_t type;
  uint32_t acpi_extended_attributes;
  /* For ACPI 3.0 Extended Attributes field (only when the 0x15/0xE820 interrupt returns 24 bytes). *
	 * This is not used for now, as ACPI 3.0 is not common in current hardware. 					  					*
   * If this field were going to be used, the first bit (bit 0) would indicate whether or not the   *
	 * entry should be ignored (0/clear = ignore), and the second bit (bit 1) would indicate whether  *
	 * or not the entry is NVRAM (1/set = NVRAM)													  													*/
};

int __memmap(struct __memmap_region *region_buffer, int max_entries) {
  int i = 0;
	uint32_t current_offset = 0;
  int interrupt_signature = 0x534D4150;
  
  do {
    region_buffer->acpi_extended_attributes = 1; // Preserve ACPI 3.0 compatibility
    int expected_bytes = 24;

		__asm__ __volatile__ (
			"int 0x15"
			: "=a" (interrupt_signature) // [EAX] 'SMAP'
			  "+b" (current_offset)      // [EBX]
        "+c" (expected_bytes)      // [ECX] Use a 24-byte return buffer, even though we are expecting 20 bytes. See __memmap_region::acpi_extended_attributes.
				// "=@ccc" (carry_flag)       TODO: Check if CF is set
			: "a" (0xE820)               // [EAX] Interrupt 0xE820, Get System Memory Map
        "d" (interrupt_signature)  // [EDX] 'SMAP'
        "D" (region_buffer)
			/* : "eax", "ebx", "ecx", "edx" TODO: Figure out if we really need to mark these registers as clobbered */
		);

    if (interrupt_signature != 0x534D4150) {
      return -1;
    }

    if (expected_bytes > 20 && (region_buffer->acpi_extended_attributes & 0x0001) == 0) {
      // Ignore
    } else {
      ++region_buffer;
      ++i;
    }
	} while (i < max_entries && current_offset != 0);

  return i;
}

#endif