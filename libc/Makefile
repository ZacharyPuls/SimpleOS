DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib
ARCHDIR=arch/$(HOSTARCH)

CFLAGS?=-O2 -g
CXXFLAGS?=

DEFAULT_CFLAGS=-ffreestanding -Wall -Wextra
DEFAULT_CXXFLAGS=-Iinclude

ALL_CFLAGS = $(CFLAGS) $(DEFAULT_CFLAGS)
ALL_CXXFLAGS = $(CXXFLAGS) $(DEFAULT_CXXFLAGS)

include $(ARCHDIR)/configs/$(HOSTARCH).cfg

ALL_CFLAGS += $(ARCH_CFLAGS)
ALL_CXXFLAGS += $(ARCH_CXXFLAGS)

LIBC_CFLAGS = $(ALL_CFLAGS)
LIBC_CXXFLAGS = $(ALL_CXXFLAGS) -D__SIMPLEOS_LIBC__

LIBSOS_CFLAGS = $(ALL_CFLAGS)
LIBSOS_CXXFLAGS = $(ALL_CXXFLAGS) -D__SIMPLEOS_LIBSOS__

FREEOBJS=\
$(ARCH_FREEOBJS) \
locale/duplocale.o \
locale/freelocale.o \
locale/localeconv.o \
locale/newlocale.o \
locale/setlocale.o \
locale/uselocale.o \
malloc/malloc.o \
mman/mlock.o \
mman/mlockall.o \
mman/mmap.o \
mman/mprotect.o \
mman/msync.o \
mman/munlock.o \
mman/munlockall.o \
mman/munmap.o \
mman/posix_madvise.o \
mman/posix_mem_offset.o \
mman/posix_typed_mem_get_info.o \
mman/posix_typed_mem_open.o \
mman/shm_open.o \
mman/shm_unlink.o \
stdio/snprintf.o \
string/memccpy.o \
string/memchr.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/stpcpy.o \
string/stpncpy.o \
string/strcat.o \
string/strchr.o \
string/strcmp.o \
string/strcoll_l.o \
string/strcoll.o \
string/strcpy.o \
string/strcspn.o \
string/strdup.o \
string/strerror_l.o \
string/strerror_r.o \
string/strerror.o \
string/strlen.o \
string/strncat.o \
string/strncmp.o \
string/strncpy.o \
string/strndup.o \
string/strnlen.o \
string/strpbrk.o \
string/strrchr.o \
string/strsignal.o \
string/strspn.o \
string/strstr.o \
string/strtok_r.o \
string/strtok.o \
string/strxfrm_l.o \
string/strxfrm.o \

HOSTEDOBJS=\
$(ARCH_HOSTEDOBJS) \

OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBSOS_OBJS=$(FREEOBJS:.o=.libsos.o)

BINARIES=libsos.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES:
.SUFFIXES: .o .libsos.o .c .S

all: $(BINARIES)

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)

libsos.a: $(LIBSOS_OBJS)
	$(AR) rcs $@ $(LIBSOS_OBJS)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBC_CFLAGS) $(LIBC_CXXFLAGS)

.c.S:
	$(CC) -MD -c $< -o $@ $(LIBC_CFLAGS) $(LIBC_CXXFLAGS)

.c.libsos.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBSOS_CFLAGS) $(LIBSOS_CXXFLAGS)

.S.libsos.o:
	$(CC) -MD -c $< -o $@ $(LIBSOS_CFLAGS) $(LIBSOS_CXXFLAGS)

clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBSOS_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBSOS_OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-libs

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
-include $(LIBSOS_OBJS:.o=.d)