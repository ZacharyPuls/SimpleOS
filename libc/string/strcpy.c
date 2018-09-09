/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies the string pointed to by src, into the string pointed to by 
 *  dest, including the null-terminator.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @return char*    dest
 */
char *strcpy(char *restrict dest, const char *restrict src) {
    for (size_t i = 0; i < strlen(src); i++) {
        dest[i] = src[i];
    }
    return dest;
}