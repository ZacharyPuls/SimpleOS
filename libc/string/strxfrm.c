/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Transforms the string pointed by src according to the current locale,
 *  and copies the first n characters of the transformed string to dest,
 *  returning its length. Alternativelly, the function can be used to only
 *  retrieve the length, by specifying a null pointer for dest and zero for n.
 * 
 * @param dest      A pointer to the string where the content is to be copied,
 *                   or NULL if n == 0
 * @param src       A pointer to the string that is to be transformed
 * @param n         The maximum number of characters to be copied to dest
 * @return size_t   The length of the transformed string, not including the
 *                   null-terminator
 */
size_t strxfrm(char *restrict dest, const char *restrict src, size_t n) {
    return 0;
}
