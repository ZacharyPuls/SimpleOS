#ifndef __SIMPLEOS_STACK_H__
#define __SIMPLEOS_STACK_H__

struct __stack {
	unsigned char *data;
	size_t top;
	size_t __cursize;
};


#endif