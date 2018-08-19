#ifndef __SIMPLEOS_STRING_H__
#define __SIMPLEOS_STRING_H__

#include <stddef.h>
#include <stdint.h>

#define __STRING_INITIAL_SIZE__ 64

typedef struct __string {
	char *buffer;
	size_t length;
	size_t size;
} __string_t;

size_t __strlen(const char *string) {
/*
	if (!string) {
		return 0U;
	}

	uint32_t len = 0U;

	do {
		++len;
	} while (*--string); // != '\0', != NULL

	return len;
*/
	size_t len = 0;
	while (string[len++]) {
	}
	return len - 1;
}

// [ '0', 'x', '1', '2', '\0' ] len = 5
// [ 'S', 't', 'e', 'p', 'p', 'i', 'n', 'g', ':', ' ', '\0'] len = 11

// TODO: When proper memory (de-)allocation is in place, maintain a string buffer, and alloc/free memory on the fly.
void __string_append(__string_t *string, const char *value) {
	const size_t len = __strlen(value);
	size_t i = 0;
	do {
		string->buffer[(string->length - 1) + i] = value[i];
	} while (value[++i]);
	string->length += len;
	string->buffer[string->length] = '\0';
}

__string_t __string_create() {
	__string_t string;
	string.length = 0;
	string.size = __STRING_INITIAL_SIZE__;
	string.buffer = __malloc(sizeof(char) * string.size);
	string.buffer[string.length] = '\0';
	return string;
}

// Base 10 only, faster than variable base.
char *__itoa(int32_t value, char *string) {
	char *ptr = "";
	*ptr = '\0';

	// int32_t last_value;

	do {
		*--ptr = '0' + value;
	// 	last_value = value;
		value /= 10;
	} while (value != 0);
	
	if (value < 0) {
		*--ptr = '-';
	}

	string = ptr;
	return string;
}

void __itos(uint8_t i, uint8_t base, char *buf) {
	size_t len = 0U;
	do {
		const char digit = (char)(i % base);
		buf[len++] = digit < 10 ? '0' + digit : 'A' + digit - 10;
		i /= base;
	} while (i && (len < 32));
}

char *__strrev(char *str) {
	size_t len = __strlen(str);
	for (size_t i = len/2-1; i >= 0; --i) {
		char c = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = c;
	}
	return str;
}

void __strapp(char *str, char *str2, size_t len) {
	size_t alen = __strlen(str);
	for (size_t i = 0; i < len; i++) {
		str[alen + i] = str2[i];
	}
}

#endif