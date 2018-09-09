/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_TTY_H__
#define __SIMPLEOS_TTY_H__

#include <stddef.h>

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHT_GREY 7
#define COLOR_DARK_GREY 8
#define COLOR_LIGHT_BLUE 9
#define COLOR_LIGHT_GREEN 10
#define COLOR_LIGHT_CYAN 11
#define COLOR_LIGHT_RED 12
#define COLOR_LIGHT_MAGENTA 13
#define COLOR_LIGHT_BROWN 14
#define COLOR_WHITE 15

#define VGA_MEMORY_BASE 0xB8000

#define TTY_ENTRY(ch, color) ((uint16_t)ch | ((uint16_t)color << 8))
#define TTY_COLOR(fg, bg) (fg | (bg << 4))

#define TTY_DEFAULT_WIDTH 80
#define TTY_DEFAULT_HEIGHT 25

typedef struct point {
	size_t x;
	size_t y;
} point_t;

typedef struct tty {
	point_t cursor;
	size_t width;
	size_t height;
	uint8_t color;
	char *buffer;
} tty_t;

extern void tty_scroll(tty_t *);
extern void tty_advance(tty_t *, size_t, size_t);
extern void tty_write(tty_t *, char);
extern void tty_writeln(tty_t *, const char *);
extern void tty_clear(tty_t *);
extern void tty_flush(tty_t *);
extern tty_t tty_init();

#endif  // __SIMPLEOS_TTY_H__
