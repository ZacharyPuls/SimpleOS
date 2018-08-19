
#include <locale.h>

locale_t duplocale(locale_t locale) {
    return (locale_t)NULL;
}

void freelocale(locale_t locale) {

}

lconv_t *localeconv() {
    return (lconv_t *)NULL;
}

locale_t newlocale(int n, const char *loc, locale_t locale) {
    return (locale_t)NULL;
}

char *setlocale(int n, const char *loc) {
    return (char *)NULL;
}

locale_t uselocale(locale_t locale) {
    return (locale_t)NULL;
}