
#include "tcp.h"


/**
 * @brief 
 * socket() + bind() + listen()
 * @return int, 返回socket描述符 
 */
int ftp_init(const char* ip)
{
    int ret;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1==sfd)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    int adr_len = sizeof(struct sockaddr);
    ret = bind(sfd, (struct sockaddr*)&server_addr, (socklen_t)adr_len);
    if(-1==ret)
    {
        perror("bind");
        close(sfd);
        exit(-1);
    }

    ret = listen(sfd, 5);
    if(-1==ret)
    {
        perror("listen");
        exit(1);
    }   

    return sfd;
}


int ftp_accept(int sfd, const char* ip)
{

    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(struct sockaddr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = inet_addr(ip);
    int len = sizeof(struct sockaddr);
    
    int sfd_new = accept(sfd, (struct sockaddr*)&client_addr, (socklen_t*)&len);
    if(-1 == sfd_new)
    {
        perror("accpet");
        close(sfd_new);
        close(sfd);
        exit(-1);
    }

    printf("%s %d success connect...\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
    return sfd_new;

}


int tcp_connect(const char* ip)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1==sfd)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    int len = sizeof(struct sockaddr);

    printf("connecting...\n");
    int ret = 0;
    ret = connect(sfd, (const struct sockaddr*)&server_addr, (socklen_t)len);
    if(-1 == ret)
    {
        perror("connect");
        close(sfd);
        exit(-1);
    }

    printf("connected success!\n");
    return sfd;

}

void signal_handle(void)
{
    sigset_t sigset;
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sigaddset(&sigset, SIGQUIT);
    sigprocmask(SIG_BLOCK, &sigset, NULL);

}

