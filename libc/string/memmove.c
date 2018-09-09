/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies the values of n bytes from the location pointed to by src to 
 *  the memory block pointed by destination. Copying takes place as if an 
 *  intermediate buffer were used, allowing the destination and source to overlap.
 * 
 * @param dest      A pointer to the destination where the content is to be copied
 * @param src       A pointer to the source of data to be copied
 * @param n         The number of bytes to copy
 * @return void*    dest
 */
void *memmove(void *dest, const void *src, size_t n) {
    return dest;
}
