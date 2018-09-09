/**
 * Copyright (c) 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_STRING_H__
#define __SIMPLEOS_STRING_H__

#include <stddef.h>
#include <locale.h>

extern void *memccpy(void *restrict, const void *restrict, int, size_t);
extern void *memchr(const void *, int, size_t);
extern int memcmp(const void *, const void *, size_t);
extern void *memcpy(void *restrict, const void *restrict, size_t);
extern void *memmove(void *, const void *, size_t);
extern void *memset(void *, int, size_t);
extern char *stpcpy(char *restrict, const char *restrict);
extern char *stpncpy(char *restrict, const char *restrict, size_t);
extern char *strcat(char *restrict, const char *restrict);
extern char *strchr(const char *, int);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strcoll_l(const char *, const char *, locale_t);
extern char *strcpy(char *restrict, const char *restrict);
extern size_t strcspn(const char *, const char *);
extern char *strdup(const char *);
extern char *strerror(int);
extern char *strerror_l(int, locale_t);
extern int strerror_r(int, char *, size_t);
extern size_t strlen(const char *);
extern char *strncat(char *restrict, const char *restrict, size_t);
extern int strncmp(const char *, const char *, size_t);
extern char *strncpy(char *restrict, const char *restrict, size_t);
extern char *strndup(const char *, size_t);
extern size_t strnlen(const char *, size_t);
extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);
extern char *strsignal(int);
extern size_t strspn(const char *, const char *);
extern char *strstr(const char *, const char *);
extern char *strtok(char *restrict, const char *restrict);
extern char *strtok_r(char *restrict, const char *restrict, char **restrict);
extern size_t strxfrm(char *restrict, const char *restrict, size_t);
extern size_t strxfrm_l(char *restrict, const char *restrict, size_t, locale_t);

#endif  // __SIMPLEOS_STRING_H__
