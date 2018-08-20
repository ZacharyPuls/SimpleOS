
#include <string.h>

/**
 * @brief Appends a copy of the string pointed to by src, into the string 
 *  pointed to by dest. The null-terminator in dest is overwritten by the first
 *  character of src, and a null-terminator is included at the end of the new 
 *  string formed by the concatenation of both in dest.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @return char*    dest
 */
char *strcat(char *restrict dest, const char *restrict src) {
    const size_t len = strlen(dest);
    for (size_t i = 0; i < strlen(src); i++) {
        dest[len + i] = src[i];
    }
    return dest;
}
