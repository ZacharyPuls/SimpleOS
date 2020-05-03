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
extern uint8_t __scancode_to_keycode(uint8_t scancode);
extern char __keycode_to_alpha(uint8_t keycode, bool shift_pressed);

#endif  // __SIMPLEOS_KEYBOARD_H__
