#!/bin/bash

if [ $# -eq 0 ]; then
    echo "no argument!"
else
    if [ $# -gt 2 ]; then
        g++ -Wall -g -O2 -std=c++17 $1 -o pgm -fsanitize=address
    else
        g++ -Wall -g -O2 -std=c++17 $1 -o pgm
    fi
    ./pgm
fi