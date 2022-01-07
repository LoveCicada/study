#!/bin/bash

echo "producer-consumer-simple"
g++ -o ./bin/producer-consumer-simple producer-consumer-simple.cpp -std=c++11 -lpthread
