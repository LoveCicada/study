
#include "tcp.h"

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("please input ip\n");
        exit(-1);
    }
    //signal_handle();
    int sfd = ftp_init(argv[1]);
    int sfd_new = ftp_accept(sfd, argv[1]);
    char buf[128];

    int ret;
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        ret = recv(sfd_new, buf, sizeof(buf)/sizeof(char), 0);
        if(-1==ret)
        {
            perror("recv");
            close(sfd_new);
            close(sfd);
            exit(-1);
        }

        if(0==ret)
        {
            //如果客户端ctrl+c, ctrl+d, 或者enter, 即recv()没接收到字符
            break;
        }
        printf("from client:%s\n", buf);

        memset(buf, 0, sizeof(buf)/sizeof(char));
        if(-1==read(0, buf, sizeof(buf)/sizeof(char)))
        {
            perror("read");
            close(sfd_new);
            close(sfd);
            exit(-1);
        }

        if(-1==send(sfd_new, buf, sizeof(buf)/sizeof(char), 0))
        {
            perror("send");
            close(sfd_new);
            close(sfd);
            exit(-1);
        }
    }

    close(sfd);
    close(sfd_new);

    return 0;
}