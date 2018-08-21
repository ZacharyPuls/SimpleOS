SHELL = /bin/sh

DEFAULT_HOST := $(shell ../default-host.sh)
HOST ?= DEFAULT_HOST
HOSTARCH = $(shell ../target-triplet-to-arch.sh $(HOST))

DESTDIR ?=
PREFIX ?= /usr/local
EXEC_PREFIX ?= $(PREFIX)
BOOTDIR ?= $(EXEC_PREFIX)/boot
INCLUDEDIR ?= $(PREFIX)/include
ARCHDIR = arch/$(HOSTARCH)
LIBS ?=

CFLAGS ?= -O2 -g
CXXFLAGS ?=
LDFLAGS ?=

DEFAULT_CFLAGS = -ffreestanding -Wall -Wextra
DEFAULT_CXXFLAGS = -Iinclude

ALL_CFLAGS = $(CFLAGS) $(DEFAULT_CFLAGS)
ALL_CXXFLAGS = $(CXXFLAGS) $(DEFAULT_CXXFLAGS)

include $(ARCHDIR)/configs/$(HOSTARCH).cfg

ALL_CFLAGS += $(KERNEL_ARCH_CFLAGS)
ALL_CXXFLAGS += $(KERNEL_ARCH_CXXFLAGS)

KERNEL_CFLAGS = $(ALL_CFLAGS)
KERNEL_CXXFLAGS = $(ALL_CXXFLAGS) -D__SIMPLEOS_KERNEL__
KERNEL_LDFLAGS = $(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
KERNEL_LIBS = $(LIBS) -nostdlib -lsos -lgcc

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel.o \

OBJS=\
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

LINK_LIST=\
$(KERNEL_LDFLAGS) \
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(KERNEL_LIBS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES:
.SUFFIXES: .c .o .S

all: simpleos.kernel

simpleos.kernel: $(OBJS) $(ARCHDIR)/link.ld 
	$(CC) -T $(ARCHDIR)/link.ld -o $@ $(KERNEL_CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot simpleos.kernel

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o: 
	OBJ=`$(CC) $(KERNEL_CFLAGS) $(KERNEL_LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

.c.o: 
	$(CC) -MD -c $< -o $@ -std=gnu11 $(KERNEL_CFLAGS) $(KERNEL_CXXFLAGS)

.S.o: 
	$(CC) -MD -c $< -o $@ $(KERNEL_CFLAGS) $(KERNEL_CXXFLAGS)

clean:
	rm -f simpleos.kernel
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
	cp -R --preserve=timestamps $(ARCHDIR)/include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: simpleos.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp simpleos.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)
