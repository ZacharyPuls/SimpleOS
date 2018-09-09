/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_LOCALE_H__
#define __SIMPLEOS_LOCALE_H__

#include <stddef.h>
#include <stdint.h>

// setlocale()
#define LC_ALL      0x01
#define LC_COLLATE  0x02
#define LC_CTYPE    0x04
#define LC_MESSAGES 0x08
#define LC_MONETARY 0x10
#define LC_NUMERIC  0x20
#define LC_TIME     0x40

// newlocale()
#define LC_COLLATE_MASK     0x01
#define LC_CTYPE_MASK       0x02
#define LC_MESSAGES_MASK    0x04
#define LC_MONETARY_MASK    0x08
#define LC_NUMERIC_MASK     0x10
#define LC_TIME_MASK        0x20
#define LC_ALL_MASK         LC_COLLATE_MASK | LC_CTYPE_MASK | LC_MESSAGES_MASK | \
                            LC_MONETARY_MASK | LC_NUMERIC_MASK | LC_TIME_MASK

// duplocale(), uselocale()
#define LC_GLOBAL_LOCALE NULL

typedef struct lconv {
    char *currency_symbol;
    char *decimal_point;
    char frac_digits;
    char *grouping;
    char *int_curr_symbol;
    char int_frac_digits;
    char int_n_cs_precedes;
    char int_n_sep_by_space;
    char int_n_sign_posn;
    char int_p_cs_precedes;
    char int_p_sep_by_space;
    char int_p_sign_posn;
    char *mon_decimal_point;
    char *mon_grouping;
    char *mon_thousands_sep;
    char *negative_sign;
    char n_cs_precedes;
    char n_sep_by_space;
    char n_sign_posn;
    char *positive_sign;
    char p_cs_precedes;
    char p_sep_by_space;
    char p_sign_posn;
    char *thousands_sep;
} lconv_t;

typedef uint32_t locale_t;

extern locale_t duplocale(locale_t);
extern void freelocale(locale_t);
extern lconv_t *localeconv();
extern locale_t newlocale(int, const char *, locale_t);
extern char *setlocale(int, const char *);
extern locale_t uselocale(locale_t);

#endif  // __SIMPLEOS_LOCALE_H__
