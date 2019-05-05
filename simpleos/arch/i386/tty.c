/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#include <asm/tty.h>

#include <stdlib.h>
#include <string.h>

/*
tty_t *__stdout;
tty_t *__stdin;
*/

tty_t *__primary_console;

void tty_scroll(tty_t *tty) {
    memset(tty->buffer, ' ', tty->width);

	for (size_t y = 0; y < tty->height - 1; ++y) {
		for (size_t x = 0; x < tty->width; ++x) {
			const size_t idxcur = y * tty->width + x;
			const size_t idxnext = (y+1) * tty->width + x;
			tty->buffer[idxcur] = tty->buffer[idxnext];
		}
	}

	memset(&tty->buffer[(tty->height - 1) * tty->width], ' ', tty->width);
}

void tty_advance(tty_t *tty, size_t x, size_t y) {
    tty->cursor.x += x;
    
    if (tty->cursor.x == tty->width) {
        ++tty->cursor.y;
        tty->cursor.x = 0;
    }

    tty->cursor.y += y;

    if (tty->cursor.y == tty->height) {
		tty_scroll(tty);
	}
}

void tty_write(tty_t *tty, char ch) {
    if (ch == '\n') {
		tty_advance(tty, -tty->cursor.x, 1);
		return;
	}
	if (ch == '\t') {
		tty_advance(tty, 4, 0);
		return;
	}
	if (ch == '\b') {
		tty_advance(tty, -1, 0);
		const size_t idx = tty->cursor.y * tty->width + tty->cursor.x;
		tty->buffer[idx] = ' ';
		return;
	}
	const size_t idx = tty->cursor.y * tty->width + tty->cursor.x;
	tty->buffer[idx] = ch;
	tty_advance(tty, 1, 0);
}

void tty_writeln(tty_t *tty, const char *line) {
    const size_t len = strlen(line);

	for (size_t i = 0; i < len; i++) {
		tty_write(tty, line[i]);
	}

	tty_flush(tty);
}

void tty_clear(tty_t *tty) {
    for (size_t y = 0; y < tty->height; y++) {
		for (size_t x = 0; x < tty->width; x++) {
			const size_t idx = y * tty->width + x;
			tty->buffer[idx] = ' ';
		}
	}
    tty_advance(tty, -tty->cursor.x, -tty->cursor.y);
}

void tty_flush(tty_t *tty) {
    uint16_t *vga_memory = (uint16_t *)VGA_MEMORY_BASE;

	for (size_t y = 0; y < tty->height; ++y) {
		for (size_t x = 0; x < tty->width; ++x) {
			const size_t idx = y * tty->width + x;
			vga_memory[idx] = TTY_ENTRY((unsigned char)tty->buffer[idx], tty->color);
		}
	}
}

tty_t tty_init() {
    tty_t tty = {
        .cursor = {
            .x = 0,
            .y = 0
        },
        .color = TTY_COLOR(COLOR_CYAN, COLOR_BLACK),
        .width = TTY_DEFAULT_WIDTH,
        .height = TTY_DEFAULT_HEIGHT,
        .buffer = (char *)malloc(sizeof(char) * tty.width * tty.height)
    };
    tty_clear(&tty);
    return tty;
}
