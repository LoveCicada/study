#! /bin/bash

echo "atomic_long"
g++ -o ./bin/atomic_long atomic_long.cpp -lpthread -std=c++11

echo "atomic_flag"
g++ -o ./bin/atomic_flag atomic_flag.cpp -lpthread -std=c++11

echo "atomic_memory_order"
g++ -o ./bin/atomic_memory_order atomic_memory_order.cpp -lpthread -std=c++11

echo "mutexStudy"
g++ -o ./bin/mutexStudy mutexStudy.cpp -lpthread -std=c++11

echo "condition_variable_study"
g++ -o ./bin/condition_variable_study condition_variable_study.cpp -lpthread -std=c++11