/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Copies the first n characters of the string pointed to by src, into 
 *  the string pointed to by dest. If the end of src (null-terminator) is found
 *  before n characters have been copied, dest is padded with null-terminators,
 *  until a total of n characters have been written to it. No null-terminator
 *  is implicitly appended at the end of dest if src is longer than n. Thus, in
 *  this case, dest shall not be considered a null-terminated string.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @param n         The number of characters to be copied
 * @return char*    dest
 */
char *strncpy(char *restrict dest, const char *restrict src, size_t n) {
    return dest;
}
