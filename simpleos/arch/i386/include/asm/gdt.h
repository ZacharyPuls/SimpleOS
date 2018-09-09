#ifndef __SIMPLEOS_GDT_H__
#define __SIMPLEOS_GDT_H__

#include <stdint.h>

// GDT Access Byte
#define GDT_PRESENT             0x80
#define GDT_NOT_PRESENT         0x00
#define GDT_RING_3              0x60
#define GDT_RING_2              0x40
#define GDT_RING_1              0x20
#define GDT_RING_0              0x00
#define GDT_ALWAYS_SET          0x10
#define GDT_EXECUTABLE          0x08
#define GDT_NOT_EXECUTABLE      0x00
#define GDT_DIRECTION_DOWN      0x04    // Direction bit is used on data selectors (GDT_EXECUTABLE = false)
#define GDT_DIRECTION_UP        0x00
#define GDT_CONFORM_CANFJMP     0x04    // Conform bit is used on code selectors (GDT_EXECUTABLE = true)
#define GDT_CONFORM_NOFJMP      0x00
#define GDT_WRITE_ALLOWED       0x02
#define GDT_WRITE_NOT_ALLOWED   0x00
#define GDT_ACCESSED            0x01    // This bit is set automatically by the CPU, do not set manually
#define GDT_NOT_ACCESSED        0x00

#define GDT_EXECUTABLE_READWRITE    \
    GDT_PRESENT | GDT_RING_0 | GDT_ALWAYS_SET | GDT_EXECUTABLE | GDT_CONFORM_NOFJMP | GDT_WRITE_ALLOWED | GDT_NOT_ACCESSED

#define GDT_DATA_READWRITE          \
    GDT_PRESENT | GDT_RING_0 | GDT_ALWAYS_SET | GDT_NOT_EXECUTABLE | GDT_DIRECTION_UP | GDT_WRITE_ALLOWED | GDT_NOT_ACCESSED

// GDT Flags Nibble
#define GDT_PAGE_GRANULARITY    0x80    // Limit is in 4 KiB blocks, cannot be set when GDT_X86_64 is set
#define GDT_BYTE_GRANULARITY    0x00    // Limit is in 1 B blocks
#define GDT_32BIT_PROTECTED     0x40
#define GDT_16BIT_PROTECTED     0x00
#define GDT_X86_64              0x20
#define GDT_X86                 0x00

#define GDT_FLAGS_DEFAULT   \
    GDT_BYTE_GRANULARITY | GDT_32BIT_PROTECTED | GDT_X86

__attribute__((packed))
typedef struct __gdt_descriptor {
    uint16_t size;  // Size is the size of the table, minus one (max of 65535 = 65536 bytes = 8192 entries)
    uint32_t offset;
} __gdt_descriptor_t;

__attribute__((packed))
typedef struct __gdt_entry {
    uint16_t limit;
    uint16_t base;
    uint8_t base_2;
    uint8_t access;
    uint8_t limit_2_flags;
    uint8_t base_3;
} __gdt_entry_t;

#define __MAKE_GDT_DESCRIPTOR(s, o)         \
    (__gdt_descriptor_t)                    \
    {                                       \
        .size = s - 1,                      \
        .offset = o                         \
    }

#define __MAKE_GDT_ENTRY(b, l, a, f)                    \
    (__gdt_entry_t)                                     \
    {                                                   \
        .limit = l & 0xFFFF,                            \
        .base = b & 0xFFFF,                             \
        .base_2 = b & 0xFF0000,                         \
        .access = a & 0xFF,                             \
        .limit_2_flags = (l & 0xF0000) | (f & 0xF),     \
        .base_3 = b & 0xFF000000                        \
    }

extern void __setup_gdt();

#endif