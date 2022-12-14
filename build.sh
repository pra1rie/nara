#!/usr/bin/sh

set -xe

gcc -shared -o libnara.a -I include/ sauce/*.c -fpic

