
#include <string.h>

/**
 * @brief Returns the length of the initial portion of the string pointed to by
 *  str1, which consists only of characters that are part of the string pointed
 *  to by str2. The search does not include the null-terminators of either
 *  strings, but ends there.
 * 
 * @param str1      A pointer to the string to be searched
 * @param str2      A pointer to the string containing the characters to match
 * @return size_t   The length of the initial portion of the string pointed to
 *                   by str1 containing only characters that appear in the
 *                   string poitned to by str2, or 0, if the first character in
 *                   str1 does not appear in str2
 */
size_t strspn(const char *str1, const char *str2) {
    return 0;
}
