/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_KEYBOARD_H__
#define __SIMPLEOS_KEYBOARD_H__

#include <stdbool.h>
#include <stdint.h>

#define __SIMPLEOS_SCSET__ 1

#include <input/scancode.h>
#include <input/keycode.h>

extern bool __query_key_state(uint8_t keycode);
extern void __handle_keyboard_input(uint8_t scancode);
extern char __scancode_to_alpha(uint8_t scancode);

#endif  // __SIMPLEOS_KEYBOARD_H__
