
#include <sys/mman.h>
#include <stddef.h>

__attribute__((noinline))
__attribute__((regparm(3)))
int __memmap(__memmap_region_t *region_buffer, int max_entries) {
  int i = 0;
  uint32_t current_offset = 0;
  uint32_t interrupt_signature = 0x534D4150;

  do {
    region_buffer->acpi_extended_attributes = 1; // Preserve ACPI 3.0 compatibility
    uint32_t expected_bytes = 24;

    /* Input                                                                                                                    *
     * [EAX] interrupt_signature, 'SMAP'                                                                                        *
     * [EBX] Requested offset                                                                                                   *
     * [ECX] Use a 24-byte return buffer, even though we are expecting 20 bytes. See __memmap_region::acpi_extended_attributes. *
     * TODO: Check to see if CF is set                                                                                          *
     * Output                                                                                                                   *
     * [EAX] Interrupt 0xE820, Get System Memory Map                                                                            *
     * [EDX] interrupt_signature, 'SMAP'                                                                                        *
     */

    __asm__ __volatile__(
      "int $0x15\n"
      : "=a" (interrupt_signature), "+b" (current_offset), "+c" (expected_bytes)
      : "a" (0xE820), "d" (interrupt_signature), "D" (region_buffer)
    );

    if (interrupt_signature != 0x534D4150) {
      return -1;
    }

    if (expected_bytes > 20 && (region_buffer->acpi_extended_attributes & 0x0001) == 0) {
      // Ignore
    }
    else {
      ++region_buffer;
      ++i;
    }
  } while (i < max_entries && current_offset != 0);

  return i;
}

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset) {
  return NULL;
}
