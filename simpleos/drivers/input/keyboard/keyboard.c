/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <input/keyboard.h>

static bool __key_state[KC_LAST] = {
    false
};

bool __query_key_state(uint8_t keycode) {
    return __key_state[keycode];
}

void __handle_keyboard_input(uint8_t scancode) {
    // scancode >= SC_KEY_ESCAPE && scancode <= SC_FUN_TWELVE
    __key_state[scancode] = scancode <= SC_MAX;
}
