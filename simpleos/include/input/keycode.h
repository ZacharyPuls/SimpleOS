/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_KEYCODE_H__
#define __SIMPLEOS_KEYCODE_H__

#define KC_ESCAPE           0x01
#define KC_ONE              0x02
#define KC_TWO              0x03
#define KC_THREE            0x04
#define KC_FOUR             0x05
#define KC_FIVE             0x06
#define KC_SIX              0x07
#define KC_SEVEN            0x08
#define KC_EIGHT            0x09
#define KC_NINE             0x0A
#define KC_ZERO             0x0B
#define KC_HYPHEN           0x0C
#define KC_EQUALS           0x0D
#define KC_BACKSPACE        0x0E
#define KC_TAB              0x0F
#define KC_Q                0x10
#define KC_W                0x11
#define KC_E                0x12
#define KC_R                0x13
#define KC_T                0x14
#define KC_Y                0x15
#define KC_U                0x16
#define KC_I                0x17
#define KC_O                0x18
#define KC_P                0x19
#define KC_LBRACKET         0x1A
#define KC_RBRACKET         0x1B
#define KC_ENTER            0x1C
#define KC_LCTRL            0x1D
#define KC_A                0x1E
#define KC_S                0x1F
#define KC_D                0x20
#define KC_F                0x21
#define KC_G                0x22
#define KC_H                0x23
#define KC_J                0x24
#define KC_K                0x25
#define KC_L                0x26
#define KC_SEMICOLON        0x27
#define KC_SINGLEQUOTE      0x28
#define KC_BACKTICK         0x29
#define KC_LSHIFT           0x2A
#define KC_BACKSLASH        0x2B
#define KC_Z                0x2C
#define KC_X                0x2D
#define KC_C                0x2E
#define KC_V                0x2F
#define KC_B                0x30
#define KC_N                0x31
#define KC_M                0x32
#define KC_COMMA            0x33
#define KC_PERIOD           0x34
#define KC_SLASH            0x35
#define KC_RSHIFT           0x36
#define KC_ASTERISK_NPD     0x37
#define KC_LALT             0x38
#define KC_SPACE            0x39
#define KC_CAPSLOCK         0x3A
#define KC_F1               0x3B
#define KC_F2               0x3C
#define KC_F3               0x3D
#define KC_F4               0x3E
#define KC_F5               0x3F
#define KC_F6               0x40
#define KC_F7               0x41
#define KC_F8               0x42
#define KC_F9               0x43
#define KC_F10              0x44
#define KC_NUMLOCK          0x45
#define KC_SCROLLLOCK       0x46
#define KC_SEVEN_NPD        0x47
#define KC_EIGHT_NPD        0x48
#define KC_NINE_NPD         0x49
#define KC_HYPHEN_NPD       0x4A
#define KC_FOUR_NPD         0x4B
#define KC_FIVE_NPD         0x4C
#define KC_SIX_NPD          0x4D
#define KC_PLUS_NPD         0x4E
#define KC_ONE_NPD          0x4F
#define KC_TWO_NPD          0x50
#define KC_THREE_NPD        0x51
#define KC_ZERO_NPD         0x52
#define KC_PERIOD_NPD       0x53
#define KC_F11              0x57
#define KC_F12              0x58
#define KC_LAST             KC_F12

#define KC_IS_MODIFIER(kc) (kc == KC_LCTRL || kc == KC_LSHIFT || kc == KC_RSHIFT || kc == KC_LALT)
#define KC_IS_TOGGLE(kc) (kc == KC_CAPSLOCK || kc == KC_NUMLOCK || kc == KC_SCROLLLOCK)
#define KC_IS_FUNCTION(kc) ((kc >= KC_F1 && kc <= KC_F10) || kc == KC_F11 || kc == KC_F12)
#define KC_IS_PRINTABLE(kc) (!KC_IS_MODIFIER(kc) && !KC_IS_TOGGLE(kc) && !KC_IS_FUNCTION(kc))

#define KC_IS_ALPHA(kc) ((kc >= KC_Q && kc <= KC_P) || (kc >= KC_A && kc <= KC_L) || (kc >= KC_Z && kc <= KC_M))

#endif  // __SIMPLEOS_KEYCODE_H__
