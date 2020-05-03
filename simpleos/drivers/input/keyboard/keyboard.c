/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <input/keyboard.h>
#include <asm/tty.h>

static bool __key_state[KC_LAST] = {
    false
};

bool __query_key_state(uint8_t keycode) {
    return __key_state[keycode];
}

void __handle_keyboard_input(uint8_t scancode) {
    // scancode >= SC_KEY_ESCAPE && scancode <= SC_FUN_TWELVE
    uint8_t keycode = __scancode_to_keycode(scancode);
    __key_state[keycode] = KC_IS_TOGGLE(keycode) ? !__key_state[keycode] : scancode <= SC_PRESS;

    if (__key_state[keycode] && scancode <= SC_PRESS && KC_IS_PRINTABLE(keycode)) {
        bool shift_pressed = __key_state[KC_LSHIFT] || __key_state[KC_RSHIFT];
        char ch = __keycode_to_alpha(keycode, shift_pressed);

        tty_write(*__active_console, ch);
        tty_flush(*__active_console);
    }
}

uint8_t __scancode_to_keycode(uint8_t scancode) {
    switch (scancode) {
        case SC_KEY_ONE:
        case SC_KEY_ONE_R:
            return KC_ONE;
        case SC_NPD_ONE:
        case SC_NPD_ONE_R:
            return KC_ONE_NPD;
        case SC_KEY_TWO:
        case SC_KEY_TWO_R:
            return KC_TWO;
        case SC_NPD_TWO:
        case SC_NPD_TWO_R:
            return KC_TWO_NPD;
        case SC_KEY_THREE:
        case SC_KEY_THREE_R:
            return KC_THREE;
        case SC_NPD_THREE:
        case SC_NPD_THREE_R:
            return KC_THREE_NPD;
        case SC_KEY_FOUR:
        case SC_KEY_FOUR_R:
            return KC_FOUR;
        case SC_NPD_FOUR:
        case SC_NPD_FOUR_R:
            return KC_FOUR_NPD;
        case SC_KEY_FIVE:
        case SC_KEY_FIVE_R:
            return KC_FIVE;
        case SC_NPD_FIVE:
        case SC_NPD_FIVE_R:
            return KC_FIVE_NPD;
        case SC_KEY_SIX:
        case SC_KEY_SIX_R:
            return KC_SIX;
        case SC_NPD_SIX:
        case SC_NPD_SIX_R:
            return KC_SIX_NPD;
        case SC_KEY_SEVEN:
        case SC_KEY_SEVEN_R:
            return KC_SEVEN;
        case SC_NPD_SEVEN:
        case SC_NPD_SEVEN_R:
            return KC_SEVEN_NPD;
        case SC_KEY_EIGHT:
        case SC_KEY_EIGHT_R:
            return KC_EIGHT;
        case SC_NPD_EIGHT:
        case SC_NPD_EIGHT_R:
            return KC_EIGHT_NPD;
        case SC_KEY_NINE:
        case SC_KEY_NINE_R:
            return KC_NINE;
        case SC_NPD_NINE:
        case SC_NPD_NINE_R:
            return KC_NINE_NPD;
        case SC_KEY_ZERO:
        case SC_KEY_ZERO_R:
            return KC_ZERO;
        case SC_NPD_ZERO:
        case SC_NPD_ZERO_R:
            return KC_ZERO_NPD;
        case SC_KEY_HYPHEN:
        case SC_KEY_HYPHEN_R:
            return KC_HYPHEN;
        case SC_NPD_HYPHEN:
        case SC_NPD_HYPHEN_R:
            return KC_HYPHEN_NPD;
        case SC_KEY_EQUALS:
        case SC_KEY_EQUALS_R:
            return KC_EQUALS;
        case SC_KEY_BACKSPACE:
        case SC_KEY_BACKSPACE_R:
            return KC_BACKSPACE;
        case SC_KEY_TAB:
        case SC_KEY_TAB_R:
            return KC_TAB;
        case SC_KEY_Q:
        case SC_KEY_Q_R:
            return KC_Q;
        case SC_KEY_W:
        case SC_KEY_W_R:
            return KC_W;
        case SC_KEY_E:
        case SC_KEY_E_R:
            return KC_E;
        case SC_KEY_R:
        case SC_KEY_R_R:
            return KC_R;
        case SC_KEY_T:
        case SC_KEY_T_R:
            return KC_T;
        case SC_KEY_Y:
        case SC_KEY_Y_R:
            return KC_Y;
        case SC_KEY_U:
        case SC_KEY_U_R:
            return KC_U;
        case SC_KEY_I:
        case SC_KEY_I_R:
            return KC_I;
        case SC_KEY_O:
        case SC_KEY_O_R:
            return KC_O;
        case SC_KEY_P:
        case SC_KEY_P_R:
            return KC_P;
        case SC_KEY_LBRACKET:
        case SC_KEY_LBRACKET_R:
            return KC_LBRACKET;
        case SC_KEY_RBRACKET:
        case SC_KEY_RBRACKET_R:
            return KC_RBRACKET;
        case SC_KEY_ENTER:
        case SC_KEY_ENTER_R:
            return KC_ENTER;
        case SC_MOD_LCTRL:
        case SC_MOD_LCTRL_R:
            return KC_LCTRL;
        case SC_KEY_A:
        case SC_KEY_A_R:
            return KC_A;
        case SC_KEY_S:
        case SC_KEY_S_R:
            return KC_S;
        case SC_KEY_D:
        case SC_KEY_D_R:
            return KC_D;
        case SC_KEY_F:
        case SC_KEY_F_R:
            return KC_F;
        case SC_KEY_G:
        case SC_KEY_G_R:
            return KC_G;
        case SC_KEY_H:
        case SC_KEY_H_R:
            return KC_H;
        case SC_KEY_J:
        case SC_KEY_J_R:
            return KC_J;
        case SC_KEY_K:
        case SC_KEY_K_R:
            return KC_K;
        case SC_KEY_L:
        case SC_KEY_L_R:
            return KC_L;
        case SC_KEY_SEMICOLON:
        case SC_KEY_SEMICOLON_R:
            return KC_SEMICOLON;
        case SC_KEY_SINGLEQUOTE:
        case SC_KEY_SINGLEQUOTE_R:
            return KC_SINGLEQUOTE;
        case SC_KEY_BACKTICK:
        case SC_KEY_BACKTICK_R:
            return KC_BACKTICK;
        case SC_MOD_LSHIFT:
        case SC_MOD_LSHIFT_R:
            return KC_LSHIFT;
        case SC_KEY_BACKSLASH:
        case SC_KEY_BACKSLASH_R:
            return KC_BACKSLASH;
        case SC_KEY_Z:
        case SC_KEY_Z_R:
            return KC_Z;
        case SC_KEY_X:
        case SC_KEY_X_R:
            return KC_X;
        case SC_KEY_C:
        case SC_KEY_C_R:
            return KC_C;
        case SC_KEY_V:
        case SC_KEY_V_R:
            return KC_V;
        case SC_KEY_B:
        case SC_KEY_B_R:
            return KC_B;
        case SC_KEY_N:
        case SC_KEY_N_R:
            return KC_N;
        case SC_KEY_M:
        case SC_KEY_M_R:
            return KC_M;
        case SC_KEY_COMMA:
        case SC_KEY_COMMA_R:
            return KC_COMMA;
        case SC_KEY_PERIOD:
        case SC_KEY_PERIOD_R:
            return KC_PERIOD;
        case SC_KEY_SLASH:
        case SC_KEY_SLASH_R:
            return KC_SLASH;
        case SC_MOD_RSHIFT:
        case SC_MOD_RSHIFT_R:
            return KC_RSHIFT;
        case SC_NPD_ASTERISK:
        case SC_NPD_ASTERISK_R:
            return KC_ASTERISK_NPD;
        case SC_MOD_LALT:
        case SC_MOD_LALT_R:
            return KC_LALT;
        case SC_KEY_SPACE:
        case SC_KEY_SPACE_R:
            return KC_SPACE;
        case SC_TGL_CAPSLOCK:
            return KC_CAPSLOCK;
        // TODO:
        // KC_F1 
        // KC_F2 
        // KC_F3 
        // KC_F4 
        // KC_F5 
        // KC_F6 
        // KC_F7 
        // KC_F8 
        // KC_F9 
        // KC_F10
        case SC_TGL_NUMLOCK:
            return KC_NUMLOCK;
        case SC_TGL_SCROLLLOCK:
            return KC_SCROLLLOCK;
        case SC_NPD_PLUS:
        case SC_NPD_PLUS_R:
            return KC_PLUS_NPD;
        case SC_NPD_PERIOD:
        case SC_NPD_PERIOD_R:
            return KC_PERIOD_NPD;
        default:
            return 0x00;
    }
}

char __keycode_to_alpha(uint8_t keycode, bool shift_pressed) {
    char alpha;

    switch (keycode) {
        case KC_ONE:
            alpha = shift_pressed ? '!' : '1';
            break;
        case KC_ONE_NPD:
            alpha = '1';
            break;
        case KC_TWO:
            alpha = shift_pressed ? '@' : '2';
            break;
        case KC_TWO_NPD:
            alpha = '2';
            break;
        case KC_THREE:
            alpha = shift_pressed ? '#' : '3';
            break;
        case KC_THREE_NPD:
            alpha = '3';
            break;
        case KC_FOUR:
            alpha = shift_pressed ? '$' : '4';
            break;
        case KC_FOUR_NPD:
            alpha = '4';
            break;
        case KC_FIVE:
            alpha = shift_pressed ? '%' : '5';
            break;
        case KC_FIVE_NPD:
            alpha = '5';
            break;
        case KC_SIX:
            alpha = shift_pressed ? '^' : '6';
            break;
        case KC_SIX_NPD:
            alpha = '6';
            break;
        case KC_SEVEN:
            alpha = shift_pressed ? '&' : '7';
            break;
        case KC_SEVEN_NPD:
            alpha = '7';
            break;
        case KC_EIGHT:
            alpha = shift_pressed ? '*' : '8';
            break;
        case KC_EIGHT_NPD:
            alpha = '8';
            break;
        case KC_NINE:
            alpha = shift_pressed ? '(' : '9';
            break;
        case KC_NINE_NPD:
            alpha = '9';
            break;
        case KC_ZERO:
            alpha = shift_pressed ? ')' : '0';
            break;
        case KC_ZERO_NPD:
            alpha = '0';
            break;
        case KC_HYPHEN:
            alpha = shift_pressed ? '_' : '-';
            break;
        case KC_HYPHEN_NPD:
            alpha = '-';
            break;
        case KC_EQUALS:
            alpha = shift_pressed ? '+' : '=';
            break;
        case KC_BACKSPACE:
            alpha = '\b';
            break;
        case KC_TAB:
            alpha = '\t';
            break;
        case KC_Q:
            alpha = 'q';
            break;
        case KC_W:
            alpha = 'w';
            break;
        case KC_E:
            alpha = 'e';
            break;
        case KC_R:
            alpha = 'r';
            break;
        case KC_T:
            alpha = 't';
            break;
        case KC_Y:
            alpha = 'y';
            break;
        case KC_U:
            alpha = 'u';
            break;
        case KC_I:
            alpha = 'i';
            break;
        case KC_O:
            alpha = 'o';
            break;
        case KC_P:
            alpha = 'p';
            break;
        case KC_LBRACKET:
            alpha = '[';
            break;
        case KC_RBRACKET:
            alpha = ']';
            break;
        case KC_ENTER:
            alpha = '\n';
            break;
        case KC_A:
            alpha = 'a';
            break;
        case KC_S:
            alpha = 's';
            break;
        case KC_D:
            alpha = 'd';
            break;
        case KC_F:
            alpha = 'f';
            break;
        case KC_G:
            alpha = 'g';
            break;
        case KC_H:
            alpha = 'h';
            break;
        case KC_J:
            alpha = 'j';
            break;
        case KC_K:
            alpha = 'k';
            break;
        case KC_L:
            alpha = 'l';
            break;
        case KC_SEMICOLON:
            alpha = ';';
            break;
        case KC_SINGLEQUOTE:
            alpha = '\'';
            break;
        case KC_BACKTICK:
            alpha = '`';
            break;
        case KC_BACKSLASH:
            alpha = '\\';
            break;
        case KC_Z:
            alpha = 'z';
            break;
        case KC_X:
            alpha = 'x';
            break;
        case KC_C:
            alpha = 'c';
            break;
        case KC_V:
            alpha = 'v';
            break;
        case KC_B:
            alpha = 'b';
            break;
        case KC_N:
            alpha = 'n';
            break;
        case KC_M:
            alpha = 'm';
            break;
        case KC_COMMA:
            alpha = ',';
            break;
        case KC_PERIOD:
            alpha = '.';
            break;
        case KC_SLASH:
            alpha = '/';
            break;
        case KC_ASTERISK_NPD:
            alpha = '*';
            break;
        case KC_SPACE:
            alpha = ' ';
            break;
        case KC_PLUS_NPD:
            alpha = '+';
            break;
        case KC_PERIOD_NPD:
            alpha = '.';
            break;
        default:
            return '~';
    }

    if (shift_pressed && KC_IS_ALPHA(keycode)) {
        alpha = alpha - 'a' + 'A';
    }

    return alpha;
}