#! /bin/bash

echo "main-server"
gcc -o ./bin/main-server main-server.c

echo "main-client"
gcc -o ./bin/main-client main-client.c