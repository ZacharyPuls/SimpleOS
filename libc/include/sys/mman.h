/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_MMAN_H__
#define __SIMPLEOS_MMAN_H__

#include <sys/types.h>

#define PROT_EXEC   0x1
#define PROT_NONE   0x2
#define PROT_READ   0x4
#define PROT_WRITE  0x8

#define MAP_FIXED   0x1
#define MAP_PRIVATE 0x2
#define MAP_SHARED  0x4

#define MS_ASYNC        0x1
#define MS_INVALIDATE   0x2
#define MS_SYNC         0x4

#define MCL_CURRENT 0x1
#define MCL_FUTURE  0x2

#define MAP_FAILED  ((void *)NULL)

#define POSIX_MADV_DONTNEED     0x1
#define POSIX_MADV_NORMAL       0x2
#define POSIX_MADV_RANDOM       0x4
#define POSIX_MADV_SEQUENTIAL   0x8
#define POSIX_MADV_WILLNEED     0x10

#define POSIX_TYPED_MEM_ALLOCATE        0x1
#define POSIX_TYPED_MEM_ALLOCATE_CONTIG 0x2
#define POSIX_TYPED_MEM_MAP_ALLOCATABLE 0x4

typedef struct posix_typed_mem_info {
    size_t posix_tmi_length;
} posix_typed_mem_info_t;

extern int mlock(const void *, size_t);
extern int mlockall(int);
extern void *mmap(void *, size_t, int, int, int, off_t);
extern int mprotect(void *, size_t, int);
extern int msync(void *, size_t, int);
extern int munlock(const void *, size_t);
extern int munlockall();
extern int munmap(void *, size_t);
extern int posix_madvise(void *, size_t, int);
extern int posix_mem_offset(const void *restrict, size_t, off_t *restrict, size_t *restrict, int *restrict);
extern int posix_typed_mem_get_info(int, posix_typed_mem_info_t *);
extern int posix_typed_mem_open(const char *, int, int);
extern int shm_open(const char *, int, mode_t);
extern int shm_unlink(const char *);

__attribute__((packed))
typedef struct __memmap_region {
  uint64_t base;
  uint64_t length;
  uint32_t type;
  uint32_t acpi_extended_attributes;
  /* For ACPI 3.0 Extended Attributes field (only when the 0x15/0xE820 interrupt returns 24 bytes).*
   * This is not used for now, as ACPI 3.0 is not common in current hardware.                      *
   * If this field were going to be used, the first bit (bit 0) would indicate whether or not the  *
   * entry should be ignored (0/clear = ignore), and the second bit (bit 1) would indicate whether *
   * or not the entry is NVRAM (1/set = NVRAM)													   */
} __memmap_region_t;

#endif  // __SIMPLEOS_MMAN_H__
