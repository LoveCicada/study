#!/bin/bash


if [ -d "build" ];then
  echo "rm old build dir"
  rm -rf build
else
  echo "build dir exist"
fi

echo "create build dir"
mkdir build
echo "cd build/"
cd build
echo "delete old files"
rm -rf ./*

# echo "cmake"
# cmake -G "MinGW Makefiles" ..
# echo "make"

cmake ..
make -j4
./HelloCMake
