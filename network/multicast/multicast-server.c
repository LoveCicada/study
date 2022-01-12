
/**
 * @file multicast-server.c
 * @author dyf name (you@domain.com)
 * @brief 多播服务程序
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MCAST_PORT 8989
#define MCAST_ADDR "224.0.0.88"          // 一个局部连接多播地址，路由不进行转发
#define MCAST_DATA "BROADCAST TEST DATA" //多播发送的数据
#define MCAST_INTERVAL 5                 //发送间隔时间

int main(int argc, char* arv[])
{
    int s;
    struct sockaddr_in mcast_addr;
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == s)
    {
        perror("create socket error");
        exit(-1);
    }

    // 初始化IP多播地址为0
    memset(&mcast_addr, 0, sizeof(mcast_addr));
    // 设置协议栈类行为AF
    mcast_addr.sin_family = AF_INET;
    // 设置多播IP地址
    mcast_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);
    mcast_addr.sin_port = htons(MCAST_PORT);

    // 向多播地址发送数据
    while (1)
    {
        int n = sendto(s, MCAST_DATA, strlen(MCAST_DATA),
            0, (struct sockaddr*)&mcast_addr,
            sizeof(mcast_addr));
        if(n<0)
        {
            perror("sendto error");
            exit(-2);
        }
        printf("sendto %d bytes data to multicast %s:%d ...\n", 
                n, inet_ntoa(mcast_addr.sin_addr), ntohs(mcast_addr.sin_port));    

        sleep(MCAST_INTERVAL);
    }
    

    return 0;
}