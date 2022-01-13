
/**
 * @file multicast-client.c
 * @author dyf name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-11
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
#include <net/if.h>
#include <sys/ioctl.h>

#define MCAST_PORT 8989
#define MCAST_ADDR "224.0.0.88"          // 一个局部连接多播地址，路由不进行转发
#define MCAST_DATA "BROADCAST TEST DATA" // 多播发送的数据
#define MCAST_INTERVAL 5                 // 发送间隔时间
#define BUF_SIZE 256                     // 接收缓冲区大小

int main(int argc, char* arv[])
{   
    int s;
    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;
    int err = -1;
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == s)
    {
        perror("create socket error");
        exit(-1);
    }

    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr(MCAST_ADDR);
    client_addr.sin_port = htons(MCAST_PORT);

    err = bind(s, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if(err < 0)
    {
        perror("bind error");
        close(s);
        exit(-1);
    }

    // 设置回环许可
    int loop = 1;
    err = setsockopt(s, IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop));
    if(err < 0)
    {
        perror("setsockopt():IP_MULTICAST_LOOP error");
        close(s);
        exit(-1);
    }
    printf("set multicast loop success\n"); 

    struct ip_mreq mreq;
    mreq.imr_multiaddr.s_addr = inet_addr(MCAST_ADDR);
    mreq.imr_interface.s_addr = INADDR_ANY;

    // 将本机加入广播组
    err = setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP,
        &mreq, sizeof(mreq));
    if(err < 0)
    {
        perror("setsockopt(): IP_ADD_MEMBERSHIP");
        close(s);
        exit(-1);
    }    
    printf("add membership success\n"); 

    int times = 0;
    int addr_len  = sizeof(server_addr);
    char buff[BUF_SIZE];
    int n = 0;
    // 循环接收广播组的消息, 5此后退出
    for(times = 0; times<5; times++)
    {
        // 清空接收缓冲区
        memset(&buff, 0, BUF_SIZE);
        // 接收数据
        n = recvfrom(s, buff, BUF_SIZE, 0, 
            (struct sockaddr*)&server_addr, &addr_len);
        if(-1 == n)
        {
            perror("recvfrom error");
            sleep(MCAST_INTERVAL);
            continue;
        }

        printf("Recv %dst message from server:%s:%d %s\n", 
            times,
            inet_ntoa(server_addr.sin_addr),
            ntohs(server_addr.sin_port),
            buff);
        sleep(MCAST_INTERVAL);
    }

    // 退出广播组
    err = setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP,
        &mreq, sizeof(mreq));
    if(err < 0)
    {
        perror("setsockopt(): IP_DROP_MEMBERSHIP");
    }
    printf("drop membership success\n"); 
    close(s);
    return 0;
}