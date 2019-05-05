
#include <include/arch/arch.h>

#if (__SIMPLEOS_ARCH__ ==  __SIMPLEOS_ARCH_I386__)
#include <arch/i386/include/asm/vga.h>
#else
#error "VGA video driver not implemented for architectures other than x86."
#endif

#endif