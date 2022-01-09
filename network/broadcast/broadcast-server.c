#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define IP_FOUND "IP_FOUND"         /* IP发现命令 */
#define IP_FOUND_ACK "IP_FOUND_ACK" /* IP发现应答命令 */
#define SERVER_PORT 8888

void HandleIPFound(void* arg)
{
    #define BUFFER_LEN 32
    int ret  = -1;
    int sock = -1;
    
    // 本地地址
    struct sockaddr_in local_addr;
    // 客户端地址
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int nCount = -1;
    fd_set readfd;
    char buff[BUFFER_LEN];
    struct timeval timeout;

    // 超时时间2s
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    printf("==>HandleIPFound\n");

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        printf("HandleIPFound: socket init error\n");
        return;
    }

    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(SERVER_PORT);

    ret = bind(sock, (struct sockaddr*)&local_addr, sizeof(local_addr));
    if(ret != 0)
    {
        printf("HandleIPFound: bind error\n");
        close(sock);
        return;
    }

    // 主处理过程
    while(1)
    {
        // 文件描述符集合清零
        FD_ZERO(&readfd);
        // 将套接字文件描述符加入读集合
        FD_SET(sock, &readfd);
        // select侦听是否有数据到来
        ret = select(sock + 1, &readfd, NULL, NULL, &timeout);
        switch (ret)
        {
        case -1:
            // 发生错误
            break;
        case 0:
            // 超时
            // 超时所要执行的代码
            break;
        default:
            // 有数据到来
            if(FD_ISSET(sock, &readfd))
            {
                // 接收数据
                nCount = recvfrom(sock, buff, BUFFER_LEN, 0,
                    (struct sockaddr*)&client_addr, &client_addr_len);
                printf("Recv msg is %s\n", buff);

                // 判断是否吻合
                if(strstr(buff, IP_FOUND))
                {
                    // 将应答数据复制进去
                    memcpy(buff, IP_FOUND_ACK, strlen(IP_FOUND_ACK)+1);
                    // 发生给客户端
                    nCount = sendto(sock, buff, strlen(buff), 0,
                        (struct sockaddr*)&client_addr, client_addr_len);
                    printf("sento suit client, is %s:%d\n",
                        inet_ntoa(client_addr.sin_addr),
                        ntohs(client_addr.sin_port));
                }    
            }
            break;
        }
    }

    printf("<==HandleIPFound\n");
}

int main()
{
    int arg = 1;
    HandleIPFound(&arg);

    return 0;
}