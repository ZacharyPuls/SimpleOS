/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies the values of n bytes from the location pointed to by src 
 *  directly to the memory block pointed to by dest.
 * 
 * @param dest      A pointer to the destination where the content is to be copied 
 * @param src       A pointer to the source of data to be copied
 * @param n         The number of bytes to copy
 * @return void*    dest
 */
void *memcpy(void *restrict dest, const void *restrict src, size_t n) {
    return dest;
}
