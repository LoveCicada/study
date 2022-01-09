
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>


ssize_t send_fd(int fd, void* data, size_t bytes, int sendfd)
{
    struct msghdr msghdr_send;
    struct iovec iov[1];

    union 
    {
        struct cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];
    }control_un;
    
    struct cmsghdr* pCMsgHdr = NULL;
    msghdr_send.msg_control = control_un.control;
    msghdr_send.msg_controllen = sizeof(control_un.control);

    pCMsgHdr = CMSG_FIRSTHDR(&msghdr_send);
    pCMsgHdr->cmsg_len = CMSG_LEN(sizeof(int));
    pCMsgHdr->cmsg_level = SOL_SOCKET;
    pCMsgHdr->cmsg_type = SCM_RIGHTS;
    *((int*)CMSG_DATA(pCMsgHdr)) = sendfd;

    msghdr_send.msg_name = NULL;
    msghdr_send.msg_namelen = 0;

    iov[0].iov_base = data;
    iov[0].iov_len = bytes;

    msghdr_send.msg_iov = iov;
    msghdr_send.msg_iovlen = 1;

    return (sendmsg(fd, &msghdr_send, 0));
}

int main(int argc, char* argv[])
{
    int fd;
    ssize_t n;

    if(argc != 4){
        printf("socketpair error\n");
    }

    // 打开输入的文件名称
    if( ( fd = open(argv[2], atoi(argv[3])  ) ) < 0 ){
        return 0;
    }

    // 发送文件描述符
    if( (fd = send_fd(atoi(argv[1]), "", 1, fd)) < 0 ){
        return 0;
    }

    return 0;
}
