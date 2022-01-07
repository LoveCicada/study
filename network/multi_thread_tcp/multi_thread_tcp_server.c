
/**
 * @file multi_thread_tcp_server.c
 * @author dyf (you@domain.com)
 * @brief multi thread file tcp server
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>
#include <unistd.h>

#define DEFAULT_SVR_PORT 2828
#define FILE_MAX_LEN 64
char fileName[FILE_MAX_LEN+1];

static void* handle_client(void* arg)
{
    int sock = *(int*)arg;
    char buff[1024];
    int len;
    printf("begin send\n");
    FILE* file = fopen(fileName, "r");
    if(NULL == file)
    {
        close(sock);
        exit;
    }

    int ret = 0;
    //发文件名
    ret = send(sock, fileName, FILE_MAX_LEN, 0);
    if(-1 == ret)
    {
        perror("send file name\n");
        goto EXIT_THREAD;
    }
    printf("begine send file %s...\n", fileName);
    //发文件内容
    while(!feof(file))
    {
        len = fread(buff, 1, sizeof(buff)/sizeof(char), file);
        printf("server read %s, len %d\n", fileName, len);
        ret = send(sock, buff, len, 0);
        if(ret < 0)
        {
            perror("send file\n");
            goto EXIT_THREAD;
        }
    }

EXIT_THREAD:
    if(file){
        fclose(file);
    }
    close(sock);


}


int main(int argc, char* argv[])
{
    int sockfd, new_fd;
    // 定义两个ipv4地址
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size, numbytes;
    pthread_t client_thread;
    unsigned short port;
    if(argc < 2)
    {
        perror("need a filename without path\n");
        exit(-1);
    }

    strncpy(fileName, argv[1], FILE_MAX_LEN);
    port = DEFAULT_SVR_PORT;
    if(argc >= 3)
    {
        port = (unsigned short)atoi(argv[2]);
    }

    int ret = 0;
    // 1. 建立tcp套接字socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd == -1 )
    {
        perror("socket");
        exit(-1);
    } 

    // 2. 设置监听端口
    memset(&my_addr, 0, sizeof(struct sockaddr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. 绑定套接口, 把socket队列与端口关联起来
    int len = sizeof(struct sockaddr);
    ret = bind(sockfd, (const struct sockaddr*)&my_addr, (socklen_t)len);    
    if( ret<0 )
    {
        perror("bind");
        goto EXIT_MAIN;
    }

    // 4. 在2828端口侦听，是否有客户端发来连接
    ret = listen(sockfd, 10);
    if( ret == -1 )
    {
        perror("listen");
        goto EXIT_MAIN;
    }
    printf("#@ listen port %d\n", port);
    // 5. 循环与客户端通讯
    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        printf("server waiting...\n");
        //如果有客户端建立连接, 将产生一个全新的套接字new_fd, 
        //专门用于跟这个客户端通信
        new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &sin_size);
        if( -1 == new_fd )
        {
            perror("accept");
            goto EXIT_MAIN;
        }

        printf("---client (ip=%s:port=%d) request \n", 
            inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));
        // 生成一个线程来完成和客户端的会话，主线程继续监听
        pthread_create(&client_thread, NULL, handle_client, (void*)&new_fd);    
    }

EXIT_MAIN:
    printf("#### server finish #### \n");
    close(sockfd);

    return 0;
}


