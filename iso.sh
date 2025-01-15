#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/iosnh.kernel isodir/boot/iosnh.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "IOSNH v0.0.1" {
	multiboot /boot/iosnh.kernel
}
EOF
grub-mkrescue -o iosnh.iso isodir
