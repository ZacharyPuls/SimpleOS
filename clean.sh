#!/bin/sh
# Copyright 2018 Zachary Puls <zach@zachpuls.com>

set -e
. ./config.sh

for PROJECT in $PROJECTS; do
    (cd $PROJECT && $MAKE clean)
done

rm -rf $SYSROOT
rm -rf $ISODIR
rm -rf simpleos.iso
