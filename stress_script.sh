#!/bin/bash
g++ FILE_NAME.cpp   # Replace FILE_NAME
g++ gen.cpp -o gen
g++ answer.cpp -o answer

t=1000   # Number of test cases
flag=0
for((i = 1; i <= t; i++)); do
    clear
    echo "Running on test i"
    ./gen i > input.txt
    ./a.out < input.txt > output.txt
    ./answer < input.txt > answer.txt
    diff -Z output.txt answer.txt || flag=1
    if ((flag == 1)); then
        break
    fi
done
clear
if ((flag == 0)); then
    echo "Lag rha h sab sahi h"
else
    echo "WA on test i :"
    cat input.txt
    echo "Expected :"
    cat answer.txt
    echo "Got :"
    cat output.txt
    echo
fi