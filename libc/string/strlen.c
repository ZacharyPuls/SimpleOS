
#include <string.h>

/**
 * @brief Returns the length of the string pointed to by str.
 * 
 * @param str       A pointer to a string
 * @return size_t   The length of str
 */
size_t strlen(const char *str) {
    size_t len = 0;
    while (str[len]) {
        ++len;
    };
}
