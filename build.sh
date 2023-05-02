#!/bin/sh

set -xe

mkdir -p build/
clang -Wall -Wextra -o build/twice twice.c -lm
clang -Wall -Wextra -o build/gates gates.c -lm
clang -Wall -Wextra -o build/xor xor.c -lm
