/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_IO_H__
#define __SIMPLEOS_IO_H__

#define INB(port, val)          \
    __asm__ __volatile__(       \
        "inb %1, %0"            \
        : "=a"(val)             \
        : "Nd"(port)            \
    )

#define INW(port, val)          \
    __asm__ __volatile__(       \
        "inw %1, %0"            \
        : "=a"(val)             \
        : "d"(port)             \
    )

#define INL(port, val)          \
    __asm__ __volatile__(       \
        "inl %1, %0"            \
        : "=a"(val)             \
        : "d"(port)             \
    )

static inline void OUTB(uint16_t port, uint8_t val) {
    __asm__ __volatile__(
            "outb %0, %1"
            :
            : "a"(val), "Nd"(port)
            );
}
/*#define OUTB(port, val)         \
    __asm__ __volatile__(       \
        "outb %0, %1"           \
        :                       \
        : "a"(val), "Nd"(port)  \
    )*/

#define OUTW(port, val)         \
    __asm__ __volatile__(       \
        "outw %0, %1"           \
        :                       \
        : "a"(val), "d"(port)   \
    )

#define OUTL(port, val)         \
    __asm__ __volatile__(       \
        "outl %0, %1"           \
        :                       \
        : "a"(val), "d"(port)   \
    )

/**
 * Force the CPU to wait for an I/O operation to complete. We accomplish this by
 * attempting to read from an unused port (0x80, used for checkpoints during
 * POST).
 */
#define IOWAIT()                \
    OUTB(0x80, 0)

#endif // __SIMPLEOS_IO_H__
