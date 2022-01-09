#! /bin/bash

echo "net"
g++ -o ./bin/net net.cpp

echo "hostname2ip"
gcc -o ./bin/hostname2ip hostname2ip.c

echo "getsockname"
gcc -o ./bin/getsockname getsockname.c

echo "socketpair_test"
gcc -o ./bin/socketpair_test socketpair_test.c

echo "deliver_A"
gcc -o ./bin/deliver_A deliver_B.c

echo "deliver_B"
gcc -o ./bin/deliver_B deliver_B.c