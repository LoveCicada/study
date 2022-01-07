
/**
 * @file main-server.c
 * @author dyf (you@domain.com)
 * @brief create socket --> bind --> recvfrom/sendto --> close
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

#define PORT 8888

int main(int argc, char* argv[])
{
    int sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if( -1 == sfd )
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(PORT);
    saddr.sin_addr.s_addr = INADDR_ANY;

    int ret = 0;
    ret = bind(sfd, (const struct sockaddr*)(&saddr), sizeof(struct sockaddr));
    if( -1 == ret )
    {
        perror("bind");
        close(sfd);
        exit(-1);
    }

    char buf[512] = {0};
    while(1)
    {
        struct sockaddr_in clientAddr;
        memset(&clientAddr, 0, sizeof(struct sockaddr));
        int clientAddrLen = sizeof(struct sockaddr);
        ret = recvfrom(sfd, buf, sizeof(buf)/sizeof(char), 
            0, (struct sockaddr*)(&clientAddr), &clientAddrLen);
        if( -1 == ret )
        {
            perror("recvfrom");
            close(sfd);
            exit(-1);
        }    

        printf("receive from: %s %d, the message is: %s\n",
            inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port),
            buf);

        char ch[] = "udp server info";
        int nLen = sizeof(ch)/sizeof(char);
        printf("ch=%s, nLen=%d\n", ch, nLen);

        ssize_t nSendNum = sendto(sfd, (void*)ch, nLen, 0, 
            (const struct sockaddr*)(&clientAddr), sizeof(struct sockaddr));
        //ssize_t nSendNum = sendto(sfd, "world", 6, 0, (const struct sockaddr*)(&clientAddr), sizeof(struct sockaddr));   
        if( -1 == nSendNum )
        {
            perror("sendto");
            close(sfd);
            exit(-1);
        }
    }

    close(sfd);
    return 0;
}