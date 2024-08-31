#!/bin/bash

if [ $# -eq 0 ]; then
    echo "no argument!"
else
    g++ -Wall -g -O2 -std=c++17 $1 -o pgm -fsanitize=address
    ./pgm
fi