#ifndef __SIMPLEOS_STRING_H__
#define __SIMPLEOS_STRING_H__

#include <stddef.h>
#include <stdint.h>

// Base 10 only, faster than variable base.
char *__itoa(int32_t value, char *string) {
	char *ptr;
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

	return ptr;
}

uint32_t __strlen(const char *string) {
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
	return len;
}

#endif