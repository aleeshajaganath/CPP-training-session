#!/bin/sh
cd build
cmake .
make 
./Exec
./testSll
make clean
echo "cleaned ..!"