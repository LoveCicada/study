#! /bin/bash

echo "multicast-server"
gcc -o ./bin/multicast-server multicast-server.c

echo "multicast-client"
gcc -o ./bin/multicast-client multicast-client.c