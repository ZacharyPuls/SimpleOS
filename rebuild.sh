#!/bin/sh

/mnt/c/Programming/gcc-cross-compiler/bin/i686-elf-as boot_sect.s -o boot_sect.o
/mnt/c/Programming/gcc-cross-compiler/bin/i686-elf-gcc -c cpuid.c kernel.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
/mnt/c/Programming/gcc-cross-compiler/bin/i686-elf-gcc -T link_os.ld -o simpleos.bin -ffreestanding -O2 -nostdlib boot_sect.o cpuid.o kernel.o -lgcc
cp simpleos.bin ./iso/boot/
if grub-file --is-x86-multiboot simpleos.bin; then
	echo Multiboot header is correct, GRUB multiboot is enabled.
else
	echo Multiboot header is corrupt or incorrectly formatted, GRUB multiboot is not enabled.
fi
grub-mkrescue -o simpleos.iso ./iso
qemu-system-i386 -cdrom simpleos.iso