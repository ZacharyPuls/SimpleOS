#ifndef __SIMPLEOS_TERMINAL_H__
#define __SIMPLEOS_TERMINAL_H__

#include <stdint.h>

#include "string.h"
#include "terminal_colors.h"

#define VGA_MEMORY_BASE 0xB8000

#define TERMINAL_ENTRY(ch, color) ((uint16_t)ch | (uint16_t)color << 8)

static inline uint8_t __terminal_color(uint8_t fg, uint8_t bg) {
	return fg | bg << 4;
}

static inline uint16_t __terminal_entry(unsigned char ch, uint8_t color) {
	return (uint16_t) ch | (uint16_t) color << 8;
}

struct __point {
	size_t x;
	size_t y;
};

struct __terminal {
	struct __point cursor;
	size_t width;
	size_t height;
	uint8_t color;
	uint16_t *buffer;
};

void __terminal_advance_y(struct __terminal *term) {
	if (++term->cursor.y == term->height) {
		term->cursor.y = 0;
	}
	term->cursor.x = 0;
}

void __terminal_advance_x(struct __terminal *term) {
	if (++term->cursor.x == term->width) {
		term->cursor.x = 0;
		__terminal_advance_y(term);
	}
}

void __terminal_scroll(struct __terminal *term) {
	
}

void __terminal_write(struct __terminal *term, char ch) {
	if (ch == '\n') {
		__terminal_advance_y(term);
		return;
	}
	const size_t idx = term->cursor.y * term->width + term->cursor.x;
	term->buffer[idx] = __terminal_entry((unsigned char)ch, term->color);
	__terminal_advance_x(term);
}

void __terminal_writeln(struct __terminal *term, const char *line) {
	const size_t len = __strlen(line);
	for (size_t i = 0; i < len; i++) {
		__terminal_write(term, line[i]);
	}
	__terminal_advance_y(term);
}

void __terminal_clear(struct __terminal *term) {
	const size_t cursor_x = term->cursor.x;
	const size_t cursor_y = term->cursor.y;
	term->cursor.x = 0;
	term->cursor.y = 0;
	for (size_t y = 0; y < term->height; y++) {
		for (size_t x = 0; x < term->width; x++) {
			__terminal_write(term, ' ');
		}
	}
	term->cursor.x = cursor_x;
	term->cursor.y = cursor_y;
}

struct __terminal __terminal_initialize(void) {
	struct __terminal term;
	term.cursor.x = 0;
	term.cursor.y = 0;
	term.color = __terminal_color(COLOR_GREEN, COLOR_BLACK);
	term.buffer = (uint16_t *) VGA_MEMORY_BASE;
	term.width = 80;
	term.height = 25;
	__terminal_clear(&term);
	return term;
}

#endif