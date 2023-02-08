


#! /bin/bash

echo "C++11 compile arm64"
g++ -o main11_arm64 main.cpp -std=c++11

echo "C++17 compile arm64"
g++ -o main17_arm64 main.cpp -std=c++17


echo "C++11 compile x86_64"
g++ -o main11_arm64 main.cpp -std=c++11 -march=x86_64
 
echo "C++17 compile x86_64"
g++ -o main17_arm64 main.cpp -std=c++17 -march=x86_64