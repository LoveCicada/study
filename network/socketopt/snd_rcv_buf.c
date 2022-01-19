
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>

int main(int argc, char* argv[])
{
    int err = -1;
    int sfd = -1;
    int snd_size = 0;
    int rcv_size = 0;
    socklen_t optlen;

    /**
     * @brief 建立一个TCP套接字
     * 
     */
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd)
    {
        perror("create socket fail");
        return -1;
    }

    /**
     * @brief 先读取缓冲区设置的情况
     * 获得原始发送缓冲区大小
     */
    optlen = sizeof(snd_size);
    err = getsockopt(sfd, SOL_SOCKET, SO_SNDBUF, 
            &snd_size, &optlen);
    if(-1 == err)
    {
        perror("getsockopt SO_SNDBUF size fail");
    }       

    /**
     * @brief 先读取缓冲区设置的情况
     * 获得原始接收缓冲区大小
     */
    optlen = sizeof(rcv_size);
    err = getsockopt(sfd, SOL_SOCKET, SO_RCVBUF, 
            &rcv_size, &optlen);
    if(-1 == err)
    {
        perror("getsockopt SO_RCVBUF size fail");
    } 

    /**
     * @brief 打印原始缓冲区设置情况
     * 
     */
    printf(" send buf size is: %d byte\n", snd_size);
    printf(" recv buf size is: %d byte\n", rcv_size);

    /**
     * @brief 设置发送缓冲区大小
     * 
     */
    snd_size = 4096;
    optlen = sizeof(snd_size);
    err = setsockopt(sfd, SOL_SOCKET, SO_SNDBUF, 
            &snd_size, optlen);
    if(-1 == err)
    {
        perror("setsockopt SO_SNDBUF size fail");
    }

    /**
     * @brief 设置接收缓冲区大小
     * 
     */
    rcv_size = 8192;
    optlen = sizeof(rcv_size);
    err = setsockopt(sfd, SOL_SOCKET, SO_RCVBUF, 
            &rcv_size, optlen);
    if(-1 == err)
    {
        perror("setsockopt SO_SNDBUF size fail");
    }

    /**
     * @brief 获得修改后发送缓冲区大小
     * 
     */
    optlen = sizeof(snd_size);
    err = getsockopt(sfd, SOL_SOCKET, SO_SNDBUF,
            &snd_size, &optlen);
    if(-1 == err)
    {
        perror("getsockopt SO_SNDBUF size faile");
    }  

    /**
     * @brief 获得修改后接收缓冲区大小
     * 
     */
    optlen = sizeof(rcv_size);
    err = getsockopt(sfd, SOL_SOCKET, SO_RCVBUF,
            &rcv_size, &optlen);
    if(-1 == err)
    {
        perror("getsockopt SO_RCVBUF size faile");
    }        

    /**
     * @brief 打印修改缓冲区设置情况
     * 
     */
    printf(" send buf size is: %d byte\n", snd_size);
    printf(" recv buf size is: %d byte\n", rcv_size);
    close(sfd);

    return 0;
}

/**
 * @brief result
 * 
 *  send buf size is: 16384 byte
    recv buf size is: 131072 byte
    send buf size is: 8192 byte
    recv buf size is: 16384 byte
 */