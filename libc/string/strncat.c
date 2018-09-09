/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Appends the first n characters of the string pointed to by src, to
 *  the string pointed to by dest, plus a null-terminator. If the length of the
 *  string pointed to by src is less than n, only the content up to the 
 *  null-terminator is copied.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @param n         The number of characters to be appended
 * @return char*    dest
 */
char *strncat(char *restrict dest, const char *restrict src, size_t n) {
    return dest;
}
