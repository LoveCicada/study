#! /bin/bash

echo "net"
g++ -o ./bin/net net.cpp

echo "hostname2ip"
gcc -o ./bin/hostname2ip hostname2ip.c