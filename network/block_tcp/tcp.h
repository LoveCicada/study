
#ifndef __TCP_H__
#define __TCP_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<arpa/inet.h>
#define IP "192.168.20.228"
#define PORT 1234


int ftp_init(const char* ip);

int ftp_accept(int sfd, const char* ip);

int tcp_connect(const char* ip);

void signal_handle(void);


#endif
