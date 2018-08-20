
#include <string.h>

char *strerror_l(int errno, locale_t loc) {
    return strerror(errno);
}
