#!/bin/sh
# Copyright 2018 Zachary Puls <zach@zachpuls.com>

set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
	(cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
