/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies the string pointed to by src (including the null-terminator), 
 *  into the string pointed to dest.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @return char*    A pointer to the end (null-terminator) of dest
 */
char *stpcpy(char *restrict dest, const char *restrict src) {
    return dest + strlen(dest);
}
