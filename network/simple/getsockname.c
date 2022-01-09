

/**
 * @file getsockname.c
 * @author dyf (you@domain.com)
 * @brief 获取当前客户端与服务器连接的IP端口. (getsockname())
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVE_PORT 8888

int main(int argc, char* argv[])
{
    int s;
    struct sockaddr_in serv_addr;
    struct sockaddr_in local_addr;
    socklen_t len = sizeof(local_addr);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family  =AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(SERVE_PORT);

    connect(s, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    getsockname(s, (struct sockaddr*)&local_addr, &len);

    printf("UDP local addr:%s:%d\n", 
        inet_ntoa(local_addr.sin_addr), ntohs(local_addr.sin_port));

    close(s);
   
    return 0;
}