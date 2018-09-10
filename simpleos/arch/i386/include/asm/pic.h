/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_PIC_H__
#define __SIMPLEOS_PIC_H__

#include <asm/io.h>

// I/O Ports
#define MASTER_PIC_COMMAND 0x20
#define MASTER_PIC_DATA 0x21
#define SLAVE_PIC_COMMAND 0xA0
#define SLAVE_PIC_DATA 0xA1

// Commands
#define PIC_EOI 0x20

#define ICW1_ICW4 0x01
#define ICW1_SINGLE 0x02
#define ICW1_INTERVAL4 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10

#define ICW4_8086 0x01
#define ICW4_AUTO 0x02
#define ICW4_BUF_SLAVE 0x08
#define ICW4_BUF_MASTER 0x0C
#define ICW4_SFNM 0x10

#define PIC_SEND_EOI(irq) \
    OUTB(irq >= 8 ? SLAVE_PIC_COMMAND : MASTER_PIC_COMMAND, PIC_EOI)

static inline void PIC_REMAP(int offsetMaster, int offsetSlave) {
    uint8_t masterMask;
    uint8_t slaveMask;

    INB(MASTER_PIC_DATA, masterMask);
    INB(SLAVE_PIC_DATA, slaveMask);

    OUTB(MASTER_PIC_COMMAND, ICW1_INIT + ICW1_ICW4);
    IOWAIT();

    OUTB(SLAVE_PIC_COMMAND, ICW1_INIT + ICW1_ICW4);
    IOWAIT();

    OUTB(MASTER_PIC_DATA, offsetMaster);
    IOWAIT();

    OUTB(SLAVE_PIC_DATA, offsetSlave);
    IOWAIT();

    OUTB(MASTER_PIC_DATA, 0x4);
    IOWAIT();

    OUTB(SLAVE_PIC_DATA, 0x2);
    IOWAIT();

    OUTB(MASTER_PIC_DATA, ICW4_8086);
    IOWAIT();

    OUTB(SLAVE_PIC_DATA, ICW4_8086);
    IOWAIT();

    OUTB(MASTER_PIC_DATA, masterMask);
    OUTB(SLAVE_PIC_DATA, slaveMask);
}

static inline void PIC_DISABLE() {
    __asm__ __volatile__(
        "mov $0xFF, %%al\n"
        "out %%al, $0xA1\n"
        "out %%al, $0x21"
    );
}

#endif // __SIMPLEOS_PIC_H__
