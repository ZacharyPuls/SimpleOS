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

char __scancode_to_alpha(uint8_t scancode) {
    switch (scancode) {
        case SC_KEY_ONE:
        case SC_NPD_ONE:
            return '1';
        case SC_KEY_TWO:
        case SC_NPD_TWO:
            return '2';
        case SC_KEY_THREE:
        case SC_NPD_THREE:
            return '3';
        case SC_KEY_FOUR:
        case SC_NPD_FOUR:
            return '4';
        case SC_KEY_FIVE:
        case SC_NPD_FIVE:
            return '5';
        case SC_KEY_SIX:
        case SC_NPD_SIX:
            return '6';
        case SC_KEY_SEVEN:
        case SC_NPD_SEVEN:
            return '7';
        case SC_KEY_EIGHT:
        case SC_NPD_EIGHT:
            return '8';
        case SC_KEY_NINE:
        case SC_NPD_NINE:
            return '9';
        case SC_KEY_ZERO:
        case SC_NPD_ZERO:
            return '0';
        case SC_KEY_HYPHEN:
        case SC_NPD_HYPHEN:
            return '-';
        case SC_KEY_EQUALS:
            return '=';
        case SC_KEY_BACKSPACE:
            return '\b';
        case SC_KEY_TAB:
            return '\t';
        case SC_KEY_Q:
            return 'q';
        case SC_KEY_W:
            return 'w';
        case SC_KEY_E:
            return 'e';
        case SC_KEY_R:
            return 'r';
        case SC_KEY_T:
            return 't';
        case SC_KEY_Y:
            return 'y';
        case SC_KEY_U:
            return 'u';
        case SC_KEY_I:
            return 'i';
        case SC_KEY_O:
            return 'o';
        case SC_KEY_P:
            return 'p';
        case SC_KEY_LBRACKET:
            return '[';
        case SC_KEY_RBRACKET:
            return ']';
        case SC_KEY_ENTER:
            return '\n';
        case SC_KEY_A:
            return 'a';
        case SC_KEY_S:
            return 's';
        case SC_KEY_D:
            return 'd';
        case SC_KEY_F:
            return 'f';
        case SC_KEY_G:
            return 'g';
        case SC_KEY_H:
            return 'h';
        case SC_KEY_J:
            return 'j';
        case SC_KEY_K:
            return 'k';
        case SC_KEY_L:
            return 'l';
        case SC_KEY_SEMICOLON:
            return ';';
        case SC_KEY_SINGLEQUOTE:
            return '\'';
        case SC_KEY_BACKTICK:
            return '`';
        case SC_KEY_BACKSLASH:
            return '\\';
        case SC_KEY_Z:
            return 'z';
        case SC_KEY_X:
            return 'x';
        case SC_KEY_C:
            return 'c';
        case SC_KEY_V:
            return 'v';
        case SC_KEY_B:
            return 'b';
        case SC_KEY_N:
            return 'n';
        case SC_KEY_M:
            return 'm';
        case SC_KEY_COMMA:
            return ',';
        case SC_KEY_PERIOD:
            return '.';
        case SC_KEY_SLASH:
            return '/';
        case SC_NPD_ASTERISK:
            return '*';
        case SC_KEY_SPACE:
            return ' ';
        case SC_NPD_PLUS:
            return '+';
        case SC_NPD_PERIOD:
            return '.';
        default:
            return '~';
    }
}