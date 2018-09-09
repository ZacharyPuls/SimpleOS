/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/idt.h>

void __setup_idt() {

}

__attribute__((interrupt))
void interrupt_handler(__interrupt_frame_t *frame) {
    
}
