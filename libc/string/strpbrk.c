/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Returns a pointer to the first occurrence in str1 of any of the
 *  characters that are part of str2, or a null pointer if there are no matches.
 *  The search does not include the null-terminators of either strings, but
 *  ends there.
 * 
 * @param str1      A pointer to the string to be searched
 * @param str2      A pointer to the string containing the characters to match
 * @return char*    A pointer to the first occurrence in str1 of any of the
 *                   characters that are part of str2, or a null pointer if
 *                   none of the characters of str2 is found in str1 before the
 *                   null-terminator, or a null pointer if none of the
 *                   characters in str2 are found in str1
 */
char *strpbrk(const char *str1, const char *str2) {
    return NULL;
}
