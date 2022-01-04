
#! /bin/bash

echo "epoll_server"
g++ -o ./bin/epoll_server epoll_server.cpp

echo "epoll_client"
g++ -o ./bin/epoll_client epoll_client.cpp