
#include <string.h>

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
