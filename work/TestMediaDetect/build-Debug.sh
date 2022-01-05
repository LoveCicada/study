
#! /bin/bash

clear
echo "create build dir"
mkdir build
cd build
rm -rf ./*
cmake ..  -DCMAKE_BUILD_TYPE=Debug
make -j4
