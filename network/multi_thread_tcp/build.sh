#! /bin/bash



echo "multi_thread_tcp_server"
gcc -o ./bin/multi_thread_tcp_server multi_thread_tcp_server.c -lpthread

echo "multi_thread_tcp_client"
gcc -o ./bin/multi_thread_tcp_client multi_thread_tcp_client.c -lpthread

# gcc -g -o ./bin/multi_thread_tcp_client multi_thread_tcp_client.c -lpthread

# run
# ./multi_thread_tcp_server test
# ./multi_thread_tcp_client 172.27.95.249

#debug
# gdb ./multi_thread_tcp_client -tui
# set args 172.27.95.249


# package lib
# echo "client"
# gcc -o ./bin/client tcp_client.c tcp_func.c

#gcc –fpic –c tcp_func.c –o tcp_func.o
#gcc –shared tcp_func.o –o libtcp_func.so
#cp lib*.so /lib