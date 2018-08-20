
#include <string.h>

/**
 * @brief A sequence of calls to this function split the string pointed to by
 *  str into tokens, which are sequences of contiguous characters separated by
 *  any of the characters that are part of delim. On a first call, the function
 *  expects a string as argument for str, whose first character is used as the
 *  starting location to scan for tokens. In subsequent calls, the function
 *  expects a null pointer and uses the position right after the end of the
 *  last token as the new starting location for scanning. To determine the
 *  beginning and the end of a token, the function first scans from the
 *  starting location for the first character not contained in delim
 *  (which becomes the beginning of the token). And then scans starting from
 *  this beginning of the token for the first character contained in delim,
 *  which becomes the end of the token. The scan also stops if the
 *  null-terminator is found. This end of the token is automatically replaced
 *  by a null-terminator, and the beginning of the token is returned by the
 *  function. Once the null-terminator of str is found in a call to strtok, all
 *  subsequent calls to this function (with a null pointer as the first
 *  argument) return a null pointer. The point where the last token was found
 *  is kept internally by the function to be used on the next call (particular
 *  library implementations are not required to avoid data races).
 * 
 * @param str       A pointer to the string to truncate, or NULL 
 * @param delim     A pointer to the string containing the delimiters
 * @return char*    If a token is found, a pointer to the beginning of the
 *                   token, otherwise a null pointer
 */
char *strtok(char *restrict str, const char *restrict delim) {
    return NULL;
}
