/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copy bytes from {src} to {dest}, stopping after the first occurrence
 *  of value {val} or after {n} bytes are copied, whichever comes first.
 * 
 * @param dest      A pointer to the location of the destination string
 * @param src       A pointer to the location of the source string
 * @param val       The value to search for, and copy
 * @param n         The number of bytes to be copied
 * @return void*    A pointer to the next byte in dest after val, or NULL 
 *                   if val was not found in the first n bytes of src
 */
void *memccpy(void *restrict dest, const void *restrict src, int val, size_t n) {
    return NULL;
}
