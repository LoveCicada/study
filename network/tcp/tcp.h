
/**
 * @file tcp.h
 * 
 * @author dyf (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * 服务端：socket - bind - listen - while(1){accept - recv - send - close} - close
 * 客户端：socket - connect - send - recv - close
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SERVER_IP "192.168.24.137"
#define SERVER_PORT 8888

/**
 * @brief server
 * 
 */
void test_server()
{
    printf("server\n");
    // 1. create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    // 2. bind
    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    // htons()用来将参数指定的16位hostshort转换成网络字符顺序
    // 将my_addr.sin_port置为0，函数会自动为你选择一个未占用的端口来使用
    my_addr.sin_port = htons(SERVER_PORT);
    my_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // 将my_addr.sin_addr.s_addr置为INADDR_ANY，系统会自动填入本机IP地址
    //my_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. listen
    if(listen(sfd, 10) == -1)
    {
        perror("listen");
        close(sfd);
        exit(-1);
    }
    printf("finish listen\n");


    // 4. accept
    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(struct sockaddr));

    int addrLen = sizeof(struct sockaddr);
    int new_fd = accept(sfd, (struct sockaddr*)&clientAddr, (socklen_t*)&addrLen);
    if(new_fd == -1)
    {
        perror("accept");
        close(sfd);
        exit(-1);
    }
    printf("finish accept\n");


    // 5. recv
    char buf[512] = {0};
    if(recv(new_fd, buf, sizeof(buf), 0) == -1)
    {
        perror("recv");
        close(new_fd);
        close(sfd);
        exit(-1);
    }
    puts(buf);

    // 6. send
    if(send(new_fd, "i am server", 12, 0) == -1)
    {
        perror("send");
        close(new_fd);
        close(sfd);
        exit(-1);
    }

    // 7. close
    close(new_fd);
    close(sfd);
    printf("finish server\n");


}


/**
 * @brief client
 * 
 */
void test_client()
{
    printf("client\n");

    // 1. create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        exit(-1);
    }

    // 2. connect
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(struct sockaddr));
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(SERVER_PORT);
    serAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if(connect(sfd, (struct sockaddr*)&serAddr, sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        close(sfd);
        exit(-1);
    }

    // 3. send
    if(send(sfd, "i am client", 12, 0) == -1)
    {
        perror("send");
        close(sfd);
        exit(-1);
    }

    // 4. recv
    char buf[512] = {0};
    if(recv(sfd, buf, sizeof(buf), 0) == -1)
    {
        perror("recv");
        close(sfd);
        exit(-1);
    }
    puts(buf);

    // 5. close
    close(sfd);
    printf("finish client\n");
}