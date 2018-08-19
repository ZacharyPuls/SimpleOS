
#include <string.h>

/**
 * @brief Copy bytes from {src} to {dest}, stopping after the first occurrence
 *  of value {val} or after {n} bytes are copied, whichever comes first.
 * 
 * @param dest      A pointer to the location of the destination string
 * @param src       A pointer to the location of the source string
 * @param val       The value to search for, and copy
 * @param n         The number of bytes to be copied
 * @return void*    A pointer to the next byte in dest after val, or NULL 
 *                   if val was not found in the first n bytes of src
 */
void *memccpy(void *restrict dest, const void *restrict src, int val, size_t n) {
    return NULL;
}

/**
 * @brief Searches within the first n bytes of the block of memory pointed by
 *  ptr for the first occurrence of val (interpreted as an unsigned char), 
 *  and returns a pointer to it.
 * 
 * @param ptr       A pointer to the block of memory where the search is performed
 * @param val       The value to search for
 * @param n         The number of bytes to be searched
 * @return void*    A pointer to the first occurrence of val in the block of 
 *                   memory pointed by ptr, or NULL if val was not found in the
 *                   first n bytes of ptr
 */
void *memchr(const void *ptr, int val, size_t n) {
    return NULL;
}

/**
 * @brief Compares the first n bytes of the block of memory pointed by ptr1 to
 *  the first n bytes pointed by ptr2, returning zero if they all match or a 
 *  value different from zero representing which is greater if they do not.
 * 
 * @param ptr1      A pointer to a block of memory
 * @param ptr2      A pointer to a block of memory
 * @param n         The number of bytes to be compared
 * @return int      < 0, if the first byte that does not match in both memory 
 *                  blocks has a lower value in ptr1 than in ptr2, 0, if the 
 *                  contents of both memory blocks are equal, or > 0, if the 
 *                  first byte that does not match in both memory blocks has 
 *                  a greater value in ptr1 than in ptr2
 */
int memcmp(const void *ptr1, const void *ptr2, size_t n) {
    return 0;
}

/**
 * @brief Copies the values of n bytes from the location pointed to by src 
 *  directly to the memory block pointed to by dest.
 * 
 * @param dest      A pointer to the destination where the content is to be copied 
 * @param src       A pointer to the source of data to be copied
 * @param n         The number of bytes to copy
 * @return void*    dest
 */
void *memcpy(void *restrict dest, const void *restrict src, size_t n) {
    return dest;
}

/**
 * @brief Copies the values of n bytes from the location pointed to by src to 
 *  the memory block pointed by destination. Copying takes place as if an 
 *  intermediate buffer were used, allowing the destination and source to overlap.
 * 
 * @param dest      A pointer to the destination where the content is to be copied
 * @param src       A pointer to the source of data to be copied
 * @param n         The number of bytes to copy
 * @return void*    dest
 */
void *memmove(void *dest, const void *src, size_t n) {
    return dest;
}

/**
 * @brief Sets the first n bytes of the block of memory pointed by ptr to the specified val.
 * 
 * @param ptr       A pointer to the block of memory to fill
 * @param val       The value to be set
 * @param n         The number of bytes to be set to val
 * @return void*    ptr
 */
void *memset(void *ptr, int val, size_t n) {
    return ptr;
}

/**
 * @brief Copies the string pointed to by src (including the null-terminator), 
 *  into the string pointed to dest.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @return char*    A pointer to the end (null-terminator) of dest
 */
char *stpcpy(char *restrict dest, const char *restrict src) {
    return dest + strlen(dest);
}

/**
 * @brief Copies, at most, n characters from the string pointed to by src
 *  (including the null-terminator), into the string pointed to by dest.
 *  Exactly n characters are written into dest. If strlen(src) is smaller than
 *  n, then the remaining characters in the string are filled with null bytes.
 *  If strlen(src) is greater than n, then the string pointed to by dest will
 *  not be null-terminated.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @param n         The max number of characters to copy
 * @return char*    A pointer to the end (null-terminator) of dest if dest is
 *                   null-terminated, otherwise dest + n
 */
char *stpncpy(char *restrict dest, const char *restrict src, size_t n) {
    return dest + n;
}

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

/**
 * @brief Compares the string pointed to by str1, to the string pointed to by 
 *  str2. This function starts comparing the first character of each string. 
 *  If they are equal to each other, it continues with the following pairs 
 *  until the characters differ, or until a null-terminator is reached.
 * 
 * @param str1      A pointer to the string to be compared
 * @param str2      A pointer to the string to be compared
 * @return int      < 0, if the first character that does not match has a lower
 *                   value in str1 than in str2, 0, if the contents of both
 *                   strings are equal, or > 0, if the first character that 
 *                   does not match has a greater value in str1 than in str2
 */
int strcmp(const char *str1, const char *str2) {
    return 0;
}

int strcoll(const char *str1, const char *str2) {
    return 0;
}

int strcoll_l(const char *str1, const char *str2, locale_t loc) {
    return 0;
}

/**
 * @brief Copies the string pointed to by src, into the string pointed to by 
 *  dest, including the null-terminator.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @return char*    dest
 */
char *strcpy(char *restrict dest, const char *restrict src) {
    for (size_t i = 0; i < strlen(src); i++) {
        dest[i] = src[i];
    }
    return dest;
}

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

/**
 * @brief Returns a pointer to a string, which is a duplicate of the string 
 *  pointed to by str.
 * 
 * @param str       A pointer to the string to be duplicated
 * @return char*    A pointer to a duplicate of str, which must be freed
 */
char *strdup(const char *str) {
    return NULL;
}

/**
 * @brief Interprets the value of errno, generating a string with a message 
 *  that describes the error condition as if set to errno by a function of the
 *  library.
 * 
 * @param errno     The error number to be translated
 * @return char*    A pointer to the error string describing errno
 */
char *strerror(int errno) {
    return "";
}

char *strerror_l(int errno, locale_t loc) {
    return strerror(errno);
}

int strerror_r(int errno, char *str, size_t n) {
    return 0;
}

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

/**
 * @brief Appends the first n characters of the string pointed to by src, to
 *  the string pointed to by dest, plus a null-terminator. If the length of the
 *  string pointed to by src is less than n, only the content up to the 
 *  null-terminator is copied.
 * 
 * @param dest      A pointer to the destination string
 * @param src       A pointer to the source string
 * @param n         The number of characters to be appended
 * @return char*    dest
 */
char *strncat(char *restrict dest, const char *restrict src, size_t n) {
    return dest;
}

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

}

/**
 * @brief Returns a pointer to a string, which is a duplicate of the string 
 *  pointed to by str with, at most, n characters.
 * 
 * @param str       A pointer to the string to be duplicated
 * @param n         The maximum number of characters to be duplicated
 * @return char*    A pointer to a duplicate of str, which must be freed
 */
char *strndup(const char *str, size_t n) {
    return NULL;
}

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

/**
 * @brief Returns a pointer to the last occurrence of c in the string pointed 
 *  to by str. The null-terminator is considered part of the string. Therefore,
 *  it can also be located to retrieve a pointer to the end of a string.
 * 
 * @param str       A pointer to the string to be searched
 * @param c         The character to search for
 * @return char*    A pointer to the last occurrence of c in the string pointed
 *                   to by str, or a null pointer if c is not found in str
 */
char *strrchr(const char *str, int c) {
    return NULL;
}

/**
 * @brief Returns a string describing the signal number sig.
 * 
 * @param sig       The signal number
 * @return char*    A pointer to a string describing sig
 */
char *strsignal(int sig) {
    return "";
}

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

/**
 * @brief Returns a pointer to the first occurrence of the string pointed to by
 *  str2 in the string pointed to by str1, or a null pointer if str2 is not
 *  part of str1. The matching process does not include the null-terminators,
 *  but it stops there.
 * 
 * @param str1      A pointer to the string to be searched
 * @param str2      A pointer to the string containing the characters to match
 * @return char*    A pointer to the first occurrence in str1 of the entire
 *                   sequence of characters specified in str2, or a null
 *                   pointer if the sequence is not present in str1.
 */
char *strstr(const char *str1, const char *str2) {
    return NULL;
}

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

/**
 * @brief 
 * 
 * @param str 
 * @param delim 
 * @param saveptr 
 * @return char* 
 */
char *strtok_r(char *restrict str, const char *restrict delim, char **restrict saveptr) {
    return NULL;
}

/**
 * @brief Transforms the string pointed by src according to the current locale,
 *  and copies the first n characters of the transformed string to dest,
 *  returning its length. Alternativelly, the function can be used to only
 *  retrieve the length, by specifying a null pointer for dest and zero for n.
 * 
 * @param dest      A pointer to the string where the content is to be copied,
 *                   or NULL if n == 0
 * @param src       A pointer to the string that is to be transformed
 * @param n         The maximum number of characters to be copied to dest
 * @return size_t   The length of the transformed string, not including the
 *                   null-terminator
 */
size_t strxfrm(char *restrict dest, const char *restrict src, size_t n) {
    return 0;
}


size_t strxfrm_l(char *restrict dest, const char *restrict src, size_t n, locale_t loc) {
    return 0;
}
