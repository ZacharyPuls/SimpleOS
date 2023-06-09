# Copyright 2018 Zachary Puls <zach@zachpuls.com>

DEFAULT_HOST!=../default-host.sh
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch.sh $(HOST)

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include
ARCHDIR=arch/$(HOSTARCH)
OBJDIR:=obj
BINDIR:=bin
LIBS?=

CFLAGS?=-O2 -g
CXXFLAGS?=
LDFLAGS?=-nostdlib -lsos -lgcc

DEFAULT_CFLAGS:=-ffreestanding -Wall -Wextra -Wno-unused-parameter -mgeneral-regs-only
DEFAULT_CXXFLAGS:=-Iinclude

ALL_CFLAGS=$(CFLAGS) $(DEFAULT_CFLAGS)
ALL_CXXFLAGS=$(CXXFLAGS) $(DEFAULT_CXXFLAGS)

include $(ARCHDIR)/configs/$(HOSTARCH).cfg

KERNEL_CFLAGS:=$(ALL_CFLAGS) $(KERNEL_ARCH_CFLAGS)
KERNEL_CXXFLAGS:=$(ALL_CXXFLAGS) $(KERNEL_ARCH_CXXFLAGS) -D__SIMPLEOS_KERNEL__
KERNEL_LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
KERNEL_LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS:=\
	$(KERNEL_ARCH_OBJS) \
	drivers/input/keyboard/keyboard.o \
	kernel.o

OBJS:=\
$(addprefix $(OBJDIR)/, \
	$(ARCHDIR)/crti.o \
	$(ARCHDIR)/crtbegin.o \
	$(KERNEL_OBJS) \
	$(ARCHDIR)/crtend.o \
	$(ARCHDIR)/crtn.o \
)

LINK_LIST=\
$(addprefix $(OBJDIR)/, \
	$(ARCHDIR)/crti.o \
	$(ARCHDIR)/crtbegin.o \
	$(KERNEL_OBJS) \
	$(KERNEL_LIBS) \
	$(ARCHDIR)/crtend.o \
	$(ARCHDIR)/crtn.o \
) \
$(KERNEL_LDFLAGS) \

BINS:=$(addprefix $(BINDIR)/, \
	simpleos.kernel \
)

.PHONY: all clean install install-headers install-kernel
.SUFFIXES:
.SUFFIXES: .o .c .S

all: $(BINS)

$(BINDIR)/simpleos.kernel: $(OBJS) $(ARCHDIR)/link.ld
	$(CC) -T $(ARCHDIR)/link.ld -o $@ $(KERNEL_CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot $(BINDIR)/simpleos.kernel

$(BINS): | $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)

$(OBJDIR)/$(ARCHDIR)/crtbegin.o $(OBJDIR)/$(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(KERNEL_CFLAGS) $(KERNEL_LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

$(OBJDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) -MD -c $< -o $@ -std=gnu11 $(KERNEL_CFLAGS) $(KERNEL_CXXFLAGS)

$(OBJDIR)/%.o: %.S
	mkdir -p $(@D)
	$(CC) -MD -c $< -o $@ $(KERNEL_CFLAGS) $(KERNEL_CXXFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
	cp -R --preserve=timestamps $(ARCHDIR)/include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: $(BINDIR)/simpleos.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp $(BINDIR)/simpleos.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)
