#! /bin/bash

echo "compile debug udp_client"
gcc -g -o ./bin/udp_client_debug udp_client.c

echo "compile debug udp_server"
gcc -g -o ./bin/udp_server_debug udp_server.c