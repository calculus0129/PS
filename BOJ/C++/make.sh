#!/bin/bash

function manual()
{
echo "Usage: $0 <c++17 source code> [OPTION]

Compiles a c++17 source code and executes when successfully compiled.

If there are more than one argument, then we use address sanitizer (ASAN) during compilation.
Only the first argument is treated as the compile target."
}

if [ $# -eq 0 ]; then
    manual
else
    echo "Compiling..."
    if [ $# -ge 2 ]; then
        echo "ASAN mode activated"
        g++ -Wall -g -O2 -std=c++17 $1 -o pgm -fsanitize=address
    else
        g++ -Wall -g -O2 -std=c++17 $1 -o pgm
    fi

    if [ $? -eq 0 ]; then
        echo "Compile SUCCESS!"
        ./pgm
    else
        echo "Compile FAILED!"
    fi
fi