#! /bin/bash

echo "compile debug main-server"
gcc -g -o ./bin/main-server main-server.c

echo "compile debug main-client"
gcc -g -o ./bin/main-client main-client.c