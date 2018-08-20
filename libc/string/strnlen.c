
#include <string.h>

/**
 * @brief Returns the length of the string pointed to by str, but not more than n.
 * 
 * @param str       A pointer to a string
 * @param n         The maximum length to be returned
 * @return size_t   The length of str, up to n
 */
size_t strnlen(const char *str, size_t n) {
    size_t len = 0;
    while (str[len] && len < n) {
        ++len;
    }
    return len;
}
