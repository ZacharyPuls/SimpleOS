
#include <string.h>

/**
 * @brief Sets the first n bytes of the block of memory pointed by ptr to the specified val.
 * 
 * @param ptr       A pointer to the block of memory to fill
 * @param val       The value to be set
 * @param n         The number of bytes to be set to val
 * @return void*    ptr
 */
void *memset(void *ptr, int val, size_t n) {
    unsigned char *buf = (unsigned char *)ptr;
    size_t i = 0;

    do {
        *buf = (unsigned char)val;
    } while (++buf && ++i < n);

    return ptr;
}
