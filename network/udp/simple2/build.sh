#! /bin/bash

echo "udp_client"
gcc -o ./bin/udp_client udp_client.c

echo "udp_server"
gcc -o ./bin/udp_server udp_server.c