
#include "utility.h"

int main(int argc, char* argv[])
{
    // server ip + port
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // create listen socket
    int listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if( -1 == listenFd )
    {
        perror("socket");
        exit(-1);
    }

    // bind
    int ret = 0;
    ret = bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if( ret < 0 )
    {
        perror("bind");
        close(listenFd);
        exit(-1);
    }

    // listen
    ret = listen(listenFd, 5);
    if( ret < 0 )
    {
        perror("listen error");
        exit(-1);
    }

    printf("Start to listen: %s %d\n", SERVER_IP, SERVER_PORT);
    
    // create event table at kernel
    int epFd = epoll_create(EPOLL_SIZE);
    if(epFd < 0)
    {
        perror("epoll_create");
        close(listenFd);
        exit(-1);
    }
    printf("epoll created, epollFd = %d\n", epFd);
    
    struct epoll_event events[EPOLL_SIZE];
    // add event to kernel event table
    addFd(epFd, listenFd, true);

    while(1)
    {
        // epoll_events_count is ready event number
        int epoll_events_count = epoll_wait(epFd, events, EPOLL_SIZE, -1);
        if(epoll_events_count < 0){
            perror("epoll failure");
            break;
        }

        printf("epoll_events_count = %d\n", epoll_events_count);
        // process epoll_events_count event
        for( int i = 0; i < epoll_events_count; ++i )
        {
            int sfd = events[i].data.fd;
            // new client connect
            if(sfd == listenFd)
            {
                struct sockaddr_in client_addr;
                socklen_t client_addrLen = sizeof(struct sockaddr_in);
                int client_fd = accept(listenFd, (struct sockaddr*)&client_addr, &client_addrLen);

                printf("client connect from: %s:%d, client_fd = %d\n",
                    inet_ntoa(client_addr.sin_addr),
                    ntohs(client_addr.sin_port),
                    client_fd);

                addFd(epFd, client_fd, true);

                // sever save client at list
                g_client_lists.push_back(client_fd);
                printf("Add new clientfd = %d to epoll\n", client_fd);
                printf("Now there ars %d clients in the chat room\n", (int)g_client_lists.size());

                // sever send welcome message
                printf("Welcome Message\n");
                char msg[BUF_SIZE] = {0};
                sprintf(msg, SERVER_WELCOME, client_fd);
                int nret = send(client_fd, msg, BUF_SIZE, 0);
                if(nret < 0)
                {
                    perror("send error");
                    exit(-1);
                }
            }
            else
            {
                // process client msg, then broadcast
                int nRet = sendBroadcastMessage(sfd);
                if(nRet < 0)
                {
                    perror("error");
                    exit(-1);
                }
            }
        }
    }

    close(listenFd);
    close(epFd);

    return 0;
}