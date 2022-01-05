
/**
 * @file main-client.c
 * @author dyf (you@domain.com)
 * @brief create socket --> recvfrom/sendto --> close
 * @version 0.1
 * @date 2022-01-02
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

int main(int argc, char* argv[])
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if( -1 == sfd )
    {
        perror("socket");
        exit(-1);
    }

    if(argc < 2)
    {
        printf("please input bind server ip\n");
        close(sfd);
        exit(-1);
    }

    if(argc < 3)
    {
        printf("please input bind server port\n");
        close(sfd);
        exit(-1);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(struct sockaddr));
    serverAddr.sin_family = AF_INET;

    //绑定的IP与服务器的ip保持一致
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    //绑定的端口号与服务器保持一致
    serverAddr.sin_port = htons(atoi(argv[2]));

    ssize_t ret = 0;
    char ch[] = "udp client info";
    int nLen = sizeof(ch)/sizeof(char);
    printf("ch=%s, nLen=%d\n", ch, nLen);

    int serverAddrLen = sizeof(struct sockaddr);
    ret = sendto(sfd, (void*)ch, nLen, 0, 
        (const struct sockaddr*)(&serverAddr), serverAddrLen);
    if( -1 == ret )
    {
        perror("sendto");
        close(sfd);
        exit(-1);
    }    

    char buf[512] = {0};
    struct sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(struct sockaddr));
    int clientAddrLen = sizeof(struct sockaddr);
    ret = recvfrom(sfd, buf, sizeof(buf)/sizeof(char), 0,
        (struct sockaddr*)(&clientAddr), &clientAddrLen);
    if( -1 == ret )
    {
        perror("recvfrom");
        close(sfd);
        exit(-1);
    }

    printf("receive form: %s %d, the message is: %s\n",
        inet_ntoa(clientAddr.sin_addr),ntohs(clientAddr.sin_port), buf);
    close(sfd);    

    return 0;
}