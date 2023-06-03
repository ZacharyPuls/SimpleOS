/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_STDDEF_H__
#define __SIMPLEOS_STDDEF_H__

#include <sys/types.h>

#define NULL ((void *)0)
#define offsetof(type, member) ((size_t const)&((type *)0)->member)
// TODO: test this. This is modeled after how linux accomplishes this: ((size_t)&((TYPE *)0)->MEMBER)

typedef int32_t ptrdiff_t;
typedef int32_t wchar_t;

#endif  // __SIMPLEOS_STDDEF_H__
