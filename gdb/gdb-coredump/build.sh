#!/bin/bash

echo "test-debug"
g++ -g -o ./bin/test-debug test.cpp -lpthread

echo "test-release"
g++ -o ./bin/test-release test.cpp -lpthread