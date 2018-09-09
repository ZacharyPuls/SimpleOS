/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

char *strerror_l(int errno, locale_t loc) {
    return strerror(errno);
}
