#! /bin/bash

echo "broadcast-server"
gcc -o ./bin/broadcast-server broadcast-server.c

echo "broadcast-client"
gcc -o ./bin/broadcast-client broadcast-client.c