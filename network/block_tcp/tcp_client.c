
#include "tcp.h"

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("please input bind ip\n");
        exit(-1);
    }
    
    int sfd = tcp_connect(argv[1]);
    char buf[128];
    while(1)
    {
        memset(buf, 0, sizeof(buf)/sizeof(char));
        if(-1==read(0, buf, sizeof(buf)))
        {
            perror("read");
            close(sfd);
            exit(-1);
        }

        if(-1==send(sfd, buf, sizeof(buf)/sizeof(char), 0))
        {
            perror("send");
            close(sfd);
            exit(-1);
        }

        memset(buf, 0, sizeof(buf)/sizeof(char));
        if(-1==recv(sfd, buf, sizeof(buf)/sizeof(char), 0))
        {
            perror("recv");
            close(sfd);
            exit(-1);
        }
        printf("from server:%s\n", buf);

    }

    close(sfd);
    return 0;
}