/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <string.h>

/**
 * @brief Returns a pointer to the first occurrence of c in the string pointed
 *  to by str.
 * 
 * @param str       A pointer to the string to be searched 
 * @param c         The value to search for
 * @return char*    A pointer to the first occurrence of c in str, or NULL, 
 *                   if not found
 */
char *strchr(const char *str, int c) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == (char)c) {
            return &str[i];
        }
    }
    return NULL;
}
