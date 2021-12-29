
/**
 * @file multi_thread_tcp_client.c
 * @author your name (you@domain.com)
 * @brief TCP 文件接收客户端
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>


#define FILE_MAX_LEN 64
#define DEFAULT_SVR_PORT 2828

int main(int argc, char* argv[])
{
    int sockfd, numbytes;
    char buf[1024], filename[FILE_MAX_LEN+1];
    char ip_addr[64];
    struct hostent *he;
    struct sockaddr_in their_addr;
    int i = 0, len, total;
    unsigned short port;

    FILE* file = NULL;
    if(argc<2)
    {
        perror("need a server ip \n");
        exit(-1);
    }

    strncpy(ip_addr, argv[1], sizeof(ip_addr));
    port = DEFAULT_SVR_PORT;
    if(argc >= 3)
    {
        port = (unsigned short)atoi(argv[2]);
    }

    //做域名解析(DNS)
    // he = gethostname(argv[1], sizeof(argv[1])/sizeof(char));

    // 1. 建立tcp套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( -1 == sockfd )
    {
        perror("socket");
        exit(-1);
    }

    // 2. 设置服务器地址和端口2828
    memset(&their_addr, 0 , sizeof(their_addr));
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(port);
    their_addr.sin_addr.s_addr = inet_addr(ip_addr);
    printf("connect server %s:%d\n", ip_addr, port);

    int ret = 0;
    // 3. 与服务器建立连接
    ret = connect(sockfd, (struct sockaddr*)&their_addr, sizeof(struct sockaddr));
    if( -1 == ret )
    {
        perror("connect");
        close(sockfd);
        exit(-1);
    }

    ret = send(sockfd, "hello", 6, 0);
    if(ret < 0)
    {
        perror("send");
        close(sockfd);
        exit(-1);
    }

    /* 接收文件名,为编程简单,假设前64字节固定是文件名,不足用0来增充 */
    total = 0;
    while( total < FILE_MAX_LEN )
    {
        /* 注意这里的接收buffer长度，始终是未接收文件名剩下的长度 */
        len = recv(sockfd, filename+total, (FILE_MAX_LEN - total), 0);
        if(len <=0 )
        {
            break;
        }
        total += len;
    }

    /* 接收文件名出错 */
    if( total != FILE_MAX_LEN )
    {
        perror("failure file name");
        close(sockfd);
        exit(-1);
    }

    printf("recv file %s......\n", filename);
    file = fopen(filename, "wb");
    if( NULL == file )
    {
        printf("create file %s failure \n", filename);
        perror("create");
        exit(-1);
    }

    //接收文件数据
    printf("recv begin\n");
    total = 0;
    while(1)
    {
        len = recv(sockfd, buf, sizeof(buf), 0);
        if(-1 == len)
        {
            break;
        }

        total += len;
        //写入本地文件
        fwrite(buf, 1, len, file);
    }
    fclose(file);
    printf("recv file %s success total length %d\n", filename, total);
    printf("#### client finish #### \n");
    close(sockfd);


    return 0;
}