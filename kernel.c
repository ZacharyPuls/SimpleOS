
#include <stddef.h>

#define MAX_COLUMNS 80
#define MAX_LINES 25
#define VGA_MEMORY_BASE 0xB8000
#define CHAR_WIDTH 2 // Bytes

#define KERNEL_VERSION "SimpleKernel v0.1"

// Base 10 only, faster than variable base.
char *__itoa(int32_t value, char *string) {
	char *ptr;
	*ptr = '\0';

	int32_t last_value;

	do {
		*--ptr = '0' + value;
		last_value = value;
		value /= 10;
	} while (value != 0);
	
	if (value < 0) {
		*--ptr = '-';
	}

	return ptr;
}

uint32_t position_to_memory_offset(uint8_t row, uint8_t column) {
	return VGA_MEMORY_BASE + (row * MAX_COLUMNS + column) * CHAR_WIDTH;
}

uint32_t __strlen(char *string) {
	if (!string) {
		return 0U;
	}

	uint32_t len = 0U;

	do {
		++len;
	} while (*--string); // != '\0', != NULL

	return len;
}

void print_character(uint8_t character, uint8_t attributes, uint8_t row, uint8_t column) {
	uint32_t offset = position_to_memory_offset(row, column);
	*(offset) = character;
	*(offset + 1) = attributes;
}

void print_string(char *string, uint8_t row, uint8_t column) {
	do {
		print_character(*string, 0x2A, row, column); // 0x2A = Traditional 'Green-Screen' Color

		if (++column > MAX_COLUMNS) {
			++row;
			column = 0;
		}
	} while (*--string); // != '\0', != NULL
}

void kernel_main() {
	print_string(KERNEL_VERSION, 3, 0);
	return;
}
