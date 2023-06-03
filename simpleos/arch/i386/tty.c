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

// TODO: make this dynamic, based on which TTY is currently active
tty_t **__active_console = &__primary_console;

void tty_scroll(tty_t *tty) {
    memset(tty->buffer, ' ', tty->width);

	for (size_t y = 0; y < tty->height - 1; ++y) {
		for (size_t x = 0; x < tty->width; ++x) {
			const size_t idxcur = TTY_IDX(x, y, tty->width);
			const size_t idxnext = TTY_IDX(x, y+1, tty->width);
			tty->buffer[idxcur] = tty->buffer[idxnext];
		}
	}

	memset(&tty->buffer[(tty->height - 1) * tty->width], ' ', tty->width);
}

void __tty_printdelim(tty_t *tty) {
	const size_t idx = TTY_IDX(0, tty->cursor.y, tty->width);
	tty->buffer[idx] = tty->delim;
	tty->buffer[idx + 1] = ' ';
}

void tty_advance(tty_t *tty, size_t x, size_t y) {
	// If advancing backwards, clamp tty->cursor.x to >= 2
	size_t x_min = tty->user_has_control ? 2 : 0;
    tty->cursor.x = max(tty->cursor.x + x, x_min);
    
    if (tty->cursor.x == tty->width) {
        ++tty->cursor.y;
		tty->cursor.x = tty->user_has_control ? 2 : 0;
		if (tty->user_has_control) {
			__tty_printdelim(tty);
		}
    }

    tty->cursor.y += y;

	if (y > 0 && tty->user_has_control) {
		__tty_printdelim(tty);
	}

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
		const size_t idx = TTY_IDX(tty->cursor.x, tty->cursor.y, tty->width);
		tty->buffer[idx] = ' ';
		return;
	}
	const size_t idx = TTY_IDX(tty->cursor.x, tty->cursor.y, tty->width);
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
			const size_t idx = TTY_IDX(x, y, tty->width);
			tty->buffer[idx] = ' ';
		}
	}
    tty_advance(tty, -tty->cursor.x, -tty->cursor.y);
}

void tty_flush(tty_t *tty) {
    uint16_t *vga_memory = (uint16_t *)VGA_MEMORY_BASE;

	for (size_t y = 0; y < tty->height; ++y) {
		for (size_t x = 0; x < tty->width; ++x) {
			const size_t idx = TTY_IDX(x, y, tty->width);
			vga_memory[idx] = TTY_ENTRY((unsigned char)tty->buffer[idx], tty->color);
		}
	}
}

void tty_set_user_has_control(tty_t *tty, bool user_has_control) {
	tty->user_has_control = user_has_control;
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
        .buffer = (char *)malloc(sizeof(char) * tty.width * tty.height),
		.delim = '>',
		.user_has_control = false
    };
    tty_clear(&tty);
    return tty;
}

void tty_send_command(tty_t *tty, const char *command) {

}