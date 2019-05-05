#!/bin/sh
# Copyright 2018 Zachary Puls <zach@zachpuls.com>

set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -monitor stdio -cdrom simpleos.iso
