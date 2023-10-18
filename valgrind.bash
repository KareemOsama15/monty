#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o monty
valgrind --leak-check=full --show-leak-kinds=all -s ./monty $@
