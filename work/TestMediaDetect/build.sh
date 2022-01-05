
#! /bin/bash

clear
echo "create build dir"
mkdir build
cd build
rm -rf ./*
cmake ..
make -j4
