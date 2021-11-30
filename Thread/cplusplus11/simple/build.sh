#! /bin/bash

echo "atomic_long"
g++ -o ./bin/atomic_long atomic_long.cpp -lpthread -std=c++11

echo "atomic_flag"
g++ -o ./bin/atomic_flag atomic_flag.cpp -lpthread -std=c++11
