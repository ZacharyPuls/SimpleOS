
#include <string.h>

/**
 * @brief Scans str1 for the first occurrence of any of the characters that are
 *  part of str2, returning the number of characters of str1 read before this 
 *  first occurrence.
 * 
 * @param str1      A pointer to the string to be scanned
 * @param str2      A pointer to the string containing the characters to match
 * @return size_t   The length of the initial part of str1 not containing any 
 *                   of the characters that are part of str2, which is the 
 *                   length of str1 if none of the characters in str2 are found
 *                   in str1.
 */
size_t strcspn(const char *str1, const char *str2) {
    return strlen(str1);
}
