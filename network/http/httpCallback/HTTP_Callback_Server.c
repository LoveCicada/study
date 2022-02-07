
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

void* get_in_addr(struct sockaddr* sa)
{
    if(sa->sa_family == AF_INET)
    {
        return &( ((struct sockaddr_in*)sa)->sin_addr );
    }
    return &( ((struct sockaddr_in6*)sa)->sin6_addr );
}


int main(int argc, char* argv[])
{
    int status;
    struct addrinfo hints, *res;
    int listener;
    int ret = 0;
    int flag = 0;
    char buffer[1024];
    char * testbuffer_all = "HTTP/1.1 200 OK, Success\r\nContent-Type: application/json\r\nAccept-Ranges: bytes\r\nContent-Length: 23\r\nDate: Fri, 31 Dec 2021 08:47:59 GMT\r\nServer: \r\n\r\n{\"code\": 0, \"data\": \"\"}";
	char * testbuffer = "HTTP/1.1 200 OK, Success\r\nContent-Type: application/json\r\nAccept-Ranges: bytes\r\nContent-Length: 23\r\nDate: Fri, 31 Dec 2021 08:47:59 GMT\r\nServer: \r\n\r\n";
	char * testbuffer_body = "{\"code\": 0, \"data\": \"\"}";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    char server_port_default[100] = "6666";
    char* p_server_port = NULL;

    if(argc >= 2)
    {
        flag = atoi(argv[1]);
    }
    p_server_port = server_port_default;
    printf("Server port:%s\n", p_server_port);
    status = getaddrinfo(NULL, p_server_port, &hints, &res);
    if(0 != status)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    }
    listener = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(listener < 0)
    {
        fprintf(stderr, "socket error: %s\n", gai_strerror(status));
    }

    int opt = 1;
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    status = bind(listener, res->ai_addr, res->ai_addrlen);




    return 0;
}