
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888   // 服务器侦听端口为8888
#define BACKLOG 8   // 最大侦听排队数量为8

/* 用于处理SIGPIP和SIGINT信号的函数 */
static int alive = 1;

static void sigpipe(int signo)
{
    alive = 0;
}

int main(int argc, char* argv[])
{
    /* 
    s为服务器的侦听套接字描述符, 
    sc为客户端连接成功返回的描述符 
    */
   int s, sc;
   /**
    * @brief local_addr本地地址, client_addr客户端的地址
    * 
    */
   struct sockaddr_in local_addr, client_addr;
   int err = -1;
   socklen_t optlen = -1;
   int optval = -1;
   // 截取SIGPIPE和SIGINT由函数sigpipe处理
   signal(SIGPIPE, sigpipe);
   signal(SIGINT, sigpipe);

   // 创建本地监听套接字
   s = socket(AF_INET, SOCK_STREAM, 0);
   if(s == -1)
   {
       perror("create socket fail!\n");
       return -1;
   }

    // 设置地址和端口重用
    optval = 1;
    optlen = sizeof(optval);
    err = setsockopt(s, SOL_SOCKET, SO_REUSEADDR,
        (char*)&optval, optlen);
    if(err == -1)
    {
        perror("setsockopt reuseaddr fail\n");
        close(s);
        return -1;
    }    

    // 初始化本地协议族, 端口和IP地址
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);

    err = bind(s, (struct sockaddr*)&local_addr, sizeof(struct sockaddr));
    if(err == -1)
    {
        perror("bind fail\n");
        close(s);
        return -1;
    }

    // 设置最大接收缓冲区和最大发送缓冲区
    optval = 128 * 1024;
    optlen = sizeof(optval);
    err = setsockopt(s, SOL_SOCKET, SO_SNDBUF, &optval, optlen);
    if(err == -1)
    {
        perror("setsockopt send buff size fail\n");
        close(s);
        return -1;
    }
    err = setsockopt(s, SOL_SOCKET, SO_RCVBUF, &optval, optlen);
    if(err == -1)
    {
        perror("setsockopt recv buff size fail\n");
        close(s);
        return -1;
    }

    // 设置发送和接收超时时间
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 200000;
    optlen = sizeof(tv);
    err = setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv, optlen);
    if(err == -1)
    {
        perror("setsockopt recv time fail\n");
        close(s);
        return -1;
    }

    err = setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, &tv, optlen);
    if(err == -1)
    {
        perror("setsockopt send time fail\n");
        close(s);
        return -1;
    }

    err = listen(s, BACKLOG);
    if(err == -1)
    {
        perror("listen fail\n");
        close(s);
        return -1;
    }

    printf("wait connect...\n");
    fd_set fd_r;
    tv.tv_sec = 0;
    tv.tv_usec = 200000;
    while (alive)
    {
        // 有连接请求时进行连接
        socklen_t sin_size = sizeof(struct sockaddr_in);
        // 此处每次会轮询是否有客户端连接到来, 间隔时间为200ms
        
        // 清除文件描述符集
        FD_ZERO(&fd_r);
        // 将侦听描述符放入
        FD_SET(s, &fd_r);

        switch (select(s+1, &fd_r, NULL, NULL, &tv))
        {
        case -1:        // 错误发生
        case 0:         // 超时
            continue;
            break;
        default:        // 有连接到来
            break;
        }
        // 有连接到来, 接收
        sc = accept(s, (struct sockaddr*)&client_addr, &sin_size);
        if(sc == -1)
        {
            perror("accept fail\n");
            continue;
        }

    }
    

    return 0;
}



