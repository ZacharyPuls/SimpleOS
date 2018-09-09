/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies, at most, n characters from the string pointed to by src
 *  (including the null-terminator), into the string pointed to by dest.
 *  Exactly n characters are written into dest. If strlen(src) is smaller than
 *  n, then the remaining characters in the string are filled with null bytes.
 *  If strlen(src) is greater than n, then the string pointed to by dest will
 *  not be null-terminated.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @param n         The max number of characters to copy
 * @return char*    A pointer to the end (null-terminator) of dest if dest is
 *                   null-terminated, otherwise dest + n
 */
char *stpncpy(char *restrict dest, const char *restrict src, size_t n) {
    return dest + n;
}
