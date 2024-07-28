#!/bin/bash

if [ $# -eq 0 ]; then
    echo "no argument!"
else
    g++-14 -Wall -g -O2 -std=c++17 $1 -o pgm
    ./pgm
fi