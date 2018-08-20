
#include <stdio.h>
#include <string.h>

/**
 * @brief Composes a string with the same text that would be printed if fmt was
 *  used on printf, but instead of being printed, the content is stored as a
 *  string in the buffer pointed by str (taking n as the maximum buffer
 *  capacity to fill). If the resulting string would be longer than n-1
 *  characters, the remaining characters are discarded and not stored, but
 *  counted for the value returned by the function. A null-terminator is
 *  automatically appended after the content written. After the fmt parameter,
 *  the function expects at least as many additional arguments as needed for fmt.
 * 
 * @param str       A pointer to a string where the result will be stored
 * @param n         The maximum number of bytes to be used in the buffer
 * @param fmt       A pointer to a string that contains a printf-style format
 * @param ...       The arguments for fmt
 * @return int      The number of characters that would have been written if n
 *                   had been sufficiently large, not counting the null-terminator,
 *                   or if an encoding error occurs, a negative number
 */
int snprintf(char *restrict str, size_t n, const char *restrict fmt, ...) {
    va_list parameters;
    int done = 0;

    va_start(parameters, fmt);

    while (*fmt != '\0') {
        // TODO: Create limits.h, define INT_MAX
		size_t maxrem = 0xFFFFFFFF - done;
 
		if (fmt[0] != '%' || fmt[1] == '%') {
			if (fmt[0] == '%')
				fmt++;
			size_t amount = 1;
			while (fmt[amount] && fmt[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
            for (int i = 0; i < amount; i++) {
                str[done + i] = fmt[i];
            }
			fmt += amount;
			done += amount;
			continue;
		}
 
		const char* fmt_begun_at = fmt++;
 
		if (*fmt == 'c') {
			fmt++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
            str[done] = c;
			done++;
		} else if (*fmt == 's') {
			fmt++;
			const char* str_ = va_arg(parameters, const char*);
			size_t len = strlen(str_);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
            for (int i = 0; i < len; i++) {
                str[done + i] = str_[i];
            }
			done += len;
		} else {
			fmt = fmt_begun_at;
			size_t len = strlen(fmt);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
            for (int i = 0; i < len; i++) {
                str[done + i] = fmt[i];
            }
			done += len;
			fmt += len;
		}
	}

    va_end(parameters);

    return done;
}
