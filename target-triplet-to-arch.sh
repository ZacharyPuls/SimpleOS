#!/bin/sh
# Copyright 2018 Zachary Puls <zach@zachpuls.com>

if echo "$1" | grep -Eq "i[[:digit:]]86-"; then
    echo i386
else
    echo "$1" | grep -Eo "^[[:alnum:]_]*"
fi
