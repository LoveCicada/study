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

#define IP_FOUND "IP_FOUND"         /* IP发现命令 */
#define IP_FOUND_ACK "IP_FOUND_ACK" /* IP发现应答命令 */
#define SERVER_PORT 8888
#define IFNAME "eth0"

void IPFound(void* arg)
{
    #define BUFFER_LEN 32
    int ret  = -1;
    int sock = -1;
    int so_broadcast = 1;
    struct ifreq ifr;

    // 本地地址
    struct sockaddr_in local_addr;
    // 服务器地址
    struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof(server_addr);

    int server_len;
    int nCount = -1;
    fd_set readfd;
    char buf[BUFFER_LEN];
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock<0)
    {
        printf("HandleIPFound: socket init error\n");
        return;
    }

    // 将需要使用的网络接口字符串名字复制到结构中
#if 1    
    strncpy(ifr.ifr_name, IFNAME, strlen(IFNAME));
    int nLen = (int)strlen(IFNAME);
    ifr.ifr_name[nLen] = '\0';
    printf("ifr.ifr_name: %s\n strlen(ifr_name): %d\n", 
        ifr.ifr_name, (int)strlen(IFNAME));
#else   
    strcpy(ifr.ifr_name, "eth0");
    printf("ifr.ifr_name: %s\n strlen(ifr_name): %d\n", 
        ifr.ifr_name, (int)strlen(IFNAME));
#endif
    // 发送命令, 获取网络接口的广播地址
    ret = ioctl(sock, SIOCGIFBRDADDR, &ifr);
    if( -1 == ret )
    {
        perror("ioctl error");
        close(sock);
        exit(-1);
    }

    //ifr_ifru.ifru_broadaddr
    // 将获得的广播地址复制给变量broadcast addr
    memcpy(&local_addr, &ifr.ifr_broadaddr,
        sizeof(struct sockaddr_in));
    // 设置广播端口
    local_addr.sin_port = htons(SERVER_PORT);
    
    // 设置套接字文件描述符sock为可进行广播操作
    ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST,
        &so_broadcast, sizeof(struct sockaddr_in));

    if( -1 == ret )
    {
        perror("setsocket error");
        close(sock);
        exit(-1);
    }

    // 主处理过程
    int times = 10;
    int i = 0;
    for(; i<times; ++i)
    {
        // 广播发送服务器地址请求
        ret = sendto(sock, IP_FOUND, strlen(IP_FOUND), 0,
            (struct sockaddr*)&local_addr, sizeof(local_addr));
        if( -1 == ret )
        {
            continue;
        }    

        // 文件描述符集合清零
        FD_ZERO(&readfd);
        // 将套接字文件描述符加入读集合
        FD_SET(sock, &readfd);
        // select侦听是否有数据到来
        ret = select(sock+1, &readfd, NULL, NULL, &timeout);
        switch (ret)
        {
        case -1:
            // 发生错误
            break;
        case 0:
            // 超时
            // 超时所要执行的代码 
        default:
            // 有数据到来
            if(FD_ISSET(sock, &readfd))
            {
                // 接收数据
                nCount = recvfrom(sock, buf, BUFFER_LEN, 0,
                    (struct sockaddr*)&server_addr, &server_addr_len);
                printf("Recv msg is %s\n", buf);
                // 判断是否吻合，是否存在对应的子字符串
                if(strstr(buf, IP_FOUND_ACK))
                {
                    printf("found server, is %s:%d\n",
                        inet_ntoa(server_addr.sin_addr),
                        ntohs(server_addr.sin_port));
                }
            }
            // 成功获得服务器地址, 退出
            break;
        }

    }

    return;
}

int main()
{
    int arg = 1;
    IPFound(&arg);

    return 0;
}