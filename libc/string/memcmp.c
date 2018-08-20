
#include <string.h>

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
