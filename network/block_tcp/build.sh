#! /bin/bash




echo "server"
gcc -o ./bin/server tcp_server.c tcp_func.c

echo "client"
gcc -o ./bin/client tcp_client.c tcp_func.c

#gcc –fpic –c tcp_func.c –o tcp_func.o
#gcc –shared tcp_func.o –o libtcp_func.so
#cp lib*.so /lib