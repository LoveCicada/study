#!/bin/bash

echo "concurrencyDataStruct"
g++ -o ./bin/concurrencyDataStruct concurrencyDataStruct.cpp -std=c++17 -lpthread -g -O0
