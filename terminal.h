#ifndef __SIMPLEOS_TERMINAL_H__
#define __SIMPLEOS_TERMINAL_H__

#include <stdbool.h>
#include <stdint.h>

#include "memory.h"
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
	char *buffer;
};

void __terminal_scroll(struct __terminal *term) {
	// TODO: Stub method
	__memset_cn(term->buffer, (unsigned char)' ', term->width);
	for (size_t y = 0; y < term->height - 1; ++y) {
		for (size_t x = 0; x < term->width; ++x) {
			const size_t idxcur = y * term->width + x;
			const size_t idxnext = (y+1) * term->width + x;
			term->buffer[idxcur] = term->buffer[idxnext];
		}
	}
	__memset_cn(term->buffer + (term->height - 1) * term->width, (unsigned char)' ', term->width);
}

void __terminal_advance_y(struct __terminal *term) {
	if (++term->cursor.y == term->height) {
		__terminal_scroll(term);
	}
	term->cursor.x = 0;
}

void __terminal_advance_x(struct __terminal *term) {
	if (++term->cursor.x == term->width) {
		term->cursor.x = 0;
		__terminal_advance_y(term);
	}
}

void __terminal_writech(struct __terminal *term, char ch) {
	if (ch == '\n') {
		__terminal_advance_y(term);
		return;
	}
	const size_t idx = term->cursor.y * term->width + term->cursor.x;
	term->buffer[idx] = ch;
	__terminal_advance_x(term);
}

void __terminal_write(struct __terminal *term, const char *line, bool advance) {
	const size_t len = __strlen(line);
	for (size_t i = 0; i < len; i++) {
		__terminal_writech(term, line[i]);
	}
	if (advance) {
		__terminal_advance_y(term);
	}
}

void __terminal_writeln(struct __terminal *term, const char *line) {
	__terminal_write(term, line, true);
}

void __terminal_clear(struct __terminal *term) {
	for (size_t y = 0; y < term->height; y++) {
		for (size_t x = 0; x < term->width; x++) {
			const size_t idx = y * term->width + x;
			term->buffer[idx] = ' ';
		}
	}
}

void __terminal_flush(struct __terminal *term) {
	/*
	uint16_t *vga_memory = (uint16_t *)VGA_MEMORY_BASE;
	__memset16n(vga_memory, __terminal_entry((unsigned char)' ', __terminal_color(COLOR_BLACK, COLOR_BLACK)), term->width * term->height);
	for (size_t y = 0; y < term->height; y++) {
		for (size_t x = 0; x < term->width; x++) {
			const size_t idx = y * term->width + x;
			*(vga_memory + (idx * sizeof(uint8_t))) = __terminal_entry((unsigned char)term->buffer[idx], term->color);
		}
	}
	*/

	uint16_t *vga_memory = (uint16_t *)VGA_MEMORY_BASE;
	for (size_t y = 0; y < term->height; ++y) {
		for (size_t x = 0; x < term->width; ++x) {
			const size_t idx = y * term->width + x;
			*(vga_memory + idx) = __terminal_entry((unsigned char)term->buffer[idx], term->color);
		}
	}
}

inline static struct __terminal __terminal_initialize(void) {
	struct __terminal term;
	term.cursor.x = 0;
	term.cursor.y = 0;
	term.color = __terminal_color(COLOR_GREEN, COLOR_BLACK);
	term.width = 80;
	term.height = 25;
	term.buffer = (char *)__malloc(sizeof(char) * term.width * term.height); // TODO: Actually free the memory used by term.buffer when we're done with it.
	__terminal_clear(&term);
	return term;
}

#endif