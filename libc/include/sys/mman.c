
#include <sys/mman.h>
#include <stddef.h>

int mlock(const void *addr, size_t len) {
    return 0;
}

int mlockall(int flags) {
    return 0;
}

void *mmap(void * addr, size_t len, int prot, int flags, int fd, off_t offset) {
    return NULL;
}

int mprotect(void *addr, size_t len, int prot) {
    return 0;
}

int msync(void *addr, size_t len, int flags) {
    return 0;
}

int munlock(const void *addr, size_t len) {
    return 0;
}

int munlockall() {
    return 0;
}

int munmap(void *addr, size_t len) {
    return 0;
}

int posix_madvise(void *addr, size_t len, int flags) {
    return 0;
}

int posix_mem_offset(const void *restrict addr, size_t len, off_t *restrict offset, size_t *restrict config_len, int *restrict fildes) {
    return 0;
}

int posix_typed_mem_get_info(int fildes, posix_typed_mem_info_t *info) {
    return 0;
}

int posix_typed_mem_open(const char *name, int oflag, int tflag) {
    return 0;
}

int shm_open(const char *name, int oflag, mode_t mode) {
    return 0;
}

int shm_unlink(const char *name) {
    return 0;
}
