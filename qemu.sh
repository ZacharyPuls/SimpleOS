#!/bin/sh

set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -cpu SandyBridge -cdrom simpleos.iso
