#!/bin/sh

set -e
. ./build.sh

mkdir -p isodir/boot/grub

cp sysroot/boot/simpleos.kernel isodir/boot/simpleos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "simpleos" {
    multiboot /boot/simpleos.kernel
}
EOF
grub-mkrescue -o simpleos.iso isodir
