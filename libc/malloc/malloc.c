
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct __memory_map {
    uint32_t base;
    uint32_t freebase;
    uint32_t freetop;
} memory_map_t;

static memory_map_t memory_map = {
    .base = 0x171240,
    .freebase = 0x171240,
    .freetop = 0x1EE240
};

uint32_t get_free_addr(size_t size) {
    uint32_t addr = memory_map.freebase;
    memory_map.freebase += size;
    return addr;
}

void *malloc(size_t n) {
    return (void *)get_free_addr(n);
}