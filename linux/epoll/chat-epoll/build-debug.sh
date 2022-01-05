
#! /bin/bash

echo "epoll_server_debug"
g++ -g -o ./bin/epoll_server_debug epoll_server.cpp

echo "epoll_client_debug"
g++ -g -o ./bin/epoll_client_debug epoll_client.cpp