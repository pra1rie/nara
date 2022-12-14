#!/usr/bin/sh

set -xe

gcc -shared -o libnara.a *.c -fpic

