#!/bin/sh

set -xe

clang -Wall -Wextra -o twice twice.c -lm
clang -Wall -Wextra -o gates gates.c -lm
clang -Wall -Wextra -o xor xor.c -lm
