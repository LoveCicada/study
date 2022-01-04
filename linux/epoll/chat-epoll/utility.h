
#pragma once

#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// clients_list save all the clients's socket
list<int> g_client_lists;

/****************macro defintion*******************/
// server ip
#define SERVER_IP "127.0.0.1"

// server port
#define SERVER_PORT 8888

// epoll size
#define EPOLL_SIZE 5000

// message buffer size
#define BUF_SIZE 0xFFFF

#define SERVER_WELCOME "Welcome you join to the chat room, \
            you chat ID is: Client #%d"

#define SERVER_MESSAGE "ClientID %d say >> %s"

// exit
#define EXIT "EXIT"

#define CAUTION "There is only one in the chat room!"

/****************some function**************************/

/**
 * @brief 
 * 
 * @param sockfd 
 * @return int 
 */
int setnonBlocking(int sockFd)
{
    fcntl(sockFd, F_SETFL, fcntl(sockFd, F_GETFD, 0)| O_NONBLOCK);
    return 0;
}

/**
 * @brief 
 * 
 * @param epollFd 
 * @param fd 
 * @param enable_et 
 */
void addFd(int epollFd, int fd, bool enable_et)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if(enable_et)
    {
        ev.events = EPOLLIN | EPOLLET;
    }

    epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, &ev);
    setnonBlocking(fd);
    printf("fd added to epoll!\n");
}

int sendBroadcastMessage(int clientFd)
{
    // receive new chat message
    char buf[BUF_SIZE] = {0};
    // save format message
    char message[BUF_SIZE] = {0};

    // receive message
    printf("read from client(clientID = %d)\n", clientFd);
    int len = recv(clientFd, buf, BUF_SIZE, 0);

    if( len <= 0 )
    {
        close(clientFd);
        g_client_lists.remove(clientFd);
        printf("ClientID = %d closed.\n now there are %d \
            client in the chat room\n", clientFd, (int)g_client_lists.size());
    }
    else
    {
        // broadcast message
        if(g_client_lists.size() == 1)
        {
            // this means there is onlye one in the chat room
            send(clientFd, CAUTION, strlen(CAUTION), 0);
            return len;
        }

        // format message to broadcast
        sprintf(message, SERVER_MESSAGE, clientFd, buf);

        list<int>::iterator it;
        for(it = g_client_lists.begin(); it != g_client_lists.end(); ++it)
        {
            if(*it != clientFd){
                if(send(*it, message, BUF_SIZE, 0) < 0){
                    perror("error");
                    exit(-1);
                }
            }
        }
    }
    return len;
}

