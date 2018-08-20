
#include <string.h>

/**
 * @brief Compares the string pointed to by str1, to the string pointed to by 
 *  str2. This function starts comparing the first character of each string. 
 *  If they are equal to each other, it continues with the following pairs 
 *  until the characters differ, a null-terminator is reached, or until n 
 *  characters match in both strings, whichever happens first.
 * 
 * @param str1      A pointer to the string to be compared
 * @param str2      A pointer to the string to be compared
 * @param n         The maximum number of characters to be compared
 * @return int      < 0, if the first character that does not match has a lower
 *                   value in str1 than in str2, 0, if the contents of both
 *                   strings are equal, or > 0, if the first character that 
 *                   does not match has a greater value in str1 than in str2
 */
int strncmp(const char *str1, const char *str2, size_t n) {
    return 0;
}
