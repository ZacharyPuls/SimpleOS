/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_SCANCODE_H__
#define __SIMPLEOS_SCANCODE_H__

#include <stddef.h>

#define SC_KEY_ESCAPE           0x01
#define SC_KEY_ONE              0x02
#define SC_KEY_TWO              0x03
#define SC_KEY_THREE            0x04
#define SC_KEY_FOUR             0x05
#define SC_KEY_FIVE             0x06
#define SC_KEY_SIX              0x07
#define SC_KEY_SEVEN            0x08
#define SC_KEY_EIGHT            0x09
#define SC_KEY_NINE             0x0A
#define SC_KEY_ZERO             0x0B
#define SC_KEY_HYPHEN           0x0C
#define SC_KEY_EQUALS           0x0D
#define SC_KEY_BACKSPACE        0x0E
#define SC_KEY_TAB              0x0F
#define SC_KEY_Q                0x10
#define SC_KEY_W                0x11
#define SC_KEY_E                0x12
#define SC_KEY_R                0x13
#define SC_KEY_T                0x14
#define SC_KEY_Y                0x15
#define SC_KEY_U                0x16
#define SC_KEY_I                0x17
#define SC_KEY_O                0x18
#define SC_KEY_P                0x19
#define SC_KEY_LBRACKET         0x1A
#define SC_KEY_RBRACKET         0x1B
#define SC_KEY_ENTER            0x1C
#define SC_MOD_LCTRL            0x1D
#define SC_KEY_A                0x1E
#define SC_KEY_S                0x1F
#define SC_KEY_D                0x20
#define SC_KEY_F                0x21
#define SC_KEY_G                0x22
#define SC_KEY_H                0x23
#define SC_KEY_J                0x24
#define SC_KEY_K                0x25
#define SC_KEY_L                0x26
#define SC_KEY_SEMICOLON        0x27
#define SC_KEY_SINGLEQUOTE      0x28
#define SC_KEY_BACKTICK         0x29
#define SC_MOD_LSHIFT           0x2A
#define SC_KEY_BACKSLASH        0x2B
#define SC_KEY_Z                0x2C
#define SC_KEY_X                0x2D
#define SC_KEY_C                0x2E
#define SC_KEY_V                0x2F
#define SC_KEY_B                0x30
#define SC_KEY_N                0x31
#define SC_KEY_M                0x32
#define SC_KEY_COMMA            0x33
#define SC_KEY_PERIOD           0x34
#define SC_KEY_SLASH            0x35
#define SC_MOD_RSHIFT           0x36
#define SC_NPD_ASTERISK         0x37
#define SC_MOD_LALT             0x38
#define SC_KEY_SPACE            0x39
#define SC_TGL_CAPSLOCK         0x3A
#define SC_FUN_ONE              0x3B
#define SC_FUN_TWO              0x3C
#define SC_FUN_THREE            0x3D
#define SC_FUN_FOUR             0x3E
#define SC_FUN_FIVE             0x3F
#define SC_FUN_SIX              0x40
#define SC_FUN_SEVEN            0x41
#define SC_FUN_EIGHT            0x42
#define SC_FUN_NINE             0x43
#define SC_FUN_TEN              0x44
#define SC_TGL_NUMLOCK          0x45
#define SC_TGL_SCROLLLOCK       0x46
#define SC_NPD_SEVEN            0x47
#define SC_NPD_EIGHT            0x48
#define SC_NPD_NINE             0x49
#define SC_NPD_HYPHEN           0x4A
#define SC_NPD_FOUR             0x4B
#define SC_NPD_FIVE             0x4C
#define SC_NPD_SIX              0x4D
#define SC_NPD_PLUS             0x4E
#define SC_NPD_ONE              0x4F
#define SC_NPD_TWO              0x50
#define SC_NPD_THREE            0x51
#define SC_NPD_ZERO             0x52
#define SC_NPD_PERIOD           0x53
#define SC_FUN_ELEVEN           0x57
#define SC_FUN_TWELVE           0x58

#define SC_KEY_ESCAPE_R         0x81
#define SC_KEY_ONE_R            0x82
#define SC_KEY_TWO_R            0x83
#define SC_KEY_THREE_R          0x84
#define SC_KEY_FOUR_R           0x85
#define SC_KEY_FIVE_R           0x86
#define SC_KEY_SIX_R            0x87
#define SC_KEY_SEVEN_R          0x88
#define SC_KEY_EIGHT_R          0x89
#define SC_KEY_NINE_R           0x8A
#define SC_KEY_ZERO_R           0x8B
#define SC_KEY_HYPHEN_R         0x8C
#define SC_KEY_EQUALS_R         0x8D
#define SC_KEY_BACKSPACE_R      0x8E
#define SC_KEY_TAB_R            0x8F
#define SC_KEY_Q_R              0x90
#define SC_KEY_W_R              0x91
#define SC_KEY_E_R              0x92
#define SC_KEY_R_R              0x93
#define SC_KEY_T_R              0x94
#define SC_KEY_Y_R              0x95
#define SC_KEY_U_R              0x96
#define SC_KEY_I_R              0x97
#define SC_KEY_O_R              0x98
#define SC_KEY_P_R              0x99
#define SC_KEY_LBRACKET_R       0x9A
#define SC_KEY_RBRACKET_R       0x9B
#define SC_KEY_ENTER_R          0x9C
#define SC_MOD_LCTRL_R          0x9D
#define SC_KEY_A_R              0x9E
#define SC_KEY_S_R              0x9F
#define SC_KEY_D_R              0xA0
#define SC_KEY_F_R              0xA1
#define SC_KEY_G_R              0xA2
#define SC_KEY_H_R              0xA3
#define SC_KEY_J_R              0xA4
#define SC_KEY_K_R              0xA5
#define SC_KEY_L_R              0xA6
#define SC_KEY_SEMICOLON_R      0xA7
#define SC_KEY_SINGLEQUOTE_R    0xA8
#define SC_KEY_BACKTICK_R       0xA9
#define SC_MOD_LSHIFT_R         0xAA
#define SC_KEY_BACKSLASH_R      0xAB
#define SC_KEY_Z_R              0xAC
#define SC_KEY_X_R              0xAD
#define SC_KEY_C_R              0xAE
#define SC_KEY_V_R              0xAF
#define SC_KEY_B_R              0xB0
#define SC_KEY_N_R              0xB1
#define SC_KEY_M_R              0xB2
#define SC_KEY_COMMA_R          0xB3
#define SC_KEY_PERIOD_R         0xB4
#define SC_KEY_SLASH_R          0xB5
#define SC_MOD_RSHIFT_R         0xB6
#define SC_NPD_ASTERISK_R       0xB7
#define SC_MOD_LALT_R           0xB8
#define SC_KEY_SPACE_R          0xB9
#define SC_TGL_CAPSLOCK_R       0xBA
#define SC_FUN_ONE_R            0xBB
#define SC_FUN_TWO_R            0xBC
#define SC_FUN_THREE_R          0xBD
#define SC_FUN_FOUR_R           0xBE
#define SC_FUN_FIVE_R           0xBF
#define SC_FUN_SIX_R            0xC0
#define SC_FUN_SEVEN_R          0xC1
#define SC_FUN_EIGHT_R          0xC2
#define SC_FUN_NINE_R           0xC3
#define SC_FUN_TEN_R            0xC4
#define SC_TGL_NUMLOCK_R        0xC5
#define SC_TGL_SCROLLLOCK_R     0xC6
#define SC_NPD_SEVEN_R          0xC7
#define SC_NPD_EIGHT_R          0xC8
#define SC_NPD_NINE_R           0xC9
#define SC_NPD_HYPHEN_R         0xCA
#define SC_NPD_FOUR_R           0xCB
#define SC_NPD_FIVE_R           0xCC
#define SC_NPD_SIX_R            0xCD
#define SC_NPD_PLUS_R           0xCE
#define SC_NPD_ONE_R            0xCF
#define SC_NPD_TWO_R            0xD0
#define SC_NPD_THREE_R          0xD1
#define SC_NPD_ZERO_R           0xD2
#define SC_NPD_PERIOD_R         0xD3
#define SC_FUN_ELEVEN_R         0xD7
#define SC_FUN_TWELVE_R         0xD8

#endif  // __SIMPLEOS_SCANCODE_H__