
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hexstr(unsigned int n) {
	char *buf = (char *)malloc(sizeof(char) * 16); // TODO: better method that doesn't waste memory on the stack
	unsigned int base = 16;
	unsigned int d = 1;
	int x = 0;

	while (n / d >= base) {
		d *= base;
	}

	while (d != 0) {
		int dgt = n / d;
		n %= d;
		d /= base;
		if (x || dgt > 0 || d == 0) {
			*buf++ = dgt + (dgt < 10 ? '0' : 'A' - 10);
			++x;
		}
	}

	*buf = 0;
	return buf;
}

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

	char ch;
	while ((ch = *(fmt++))) {
		if (ch != '%') {
			str[done] = ch;
			++done;
		} else {
			ch = *(fmt++);
			int type = 0;
			switch (ch) {
				case 'x':
				case 'X':
					type = 1;
					break;
				default:
					break;
			}
			if (type == 1) {
				char *buf = hexstr(va_arg(parameters, unsigned int));
				size_t len = strlen(buf);
				for (size_t i = 0; i < len; i++) {
					str[done + i] = buf[i];
				}
				done += len;
			}
		}
	}
    va_end(parameters);

    return done;
}
