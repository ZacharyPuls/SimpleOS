
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void *malloc(size_t n) {
    void *ptr;

    __asm__ __volatile__(
        "mov %%esp, %1\n"
        "sub %0, %%esp\n"
        : "=&m" (ptr)
        : "i" (n)
        : "esp"
    );

    return ptr;
}