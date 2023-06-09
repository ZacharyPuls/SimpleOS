#!/bin/sh
# Copyright 2018 Zachary Puls <zach@zachpuls.com>

set -e
. ./build.sh

mkdir -p "$ISODIR/boot/grub"

cp sysroot/boot/simpleos.kernel iso/boot/simpleos.kernel
cat > "$ISODIR/boot/grub/grub.cfg" << EOF
set timeout=0
menuentry "simpleos" {
    multiboot /boot/simpleos.kernel
}
EOF
grub-mkrescue -o simpleos.iso "$ISODIR"
