
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * @brief 从fd中接收消息, 并将文件描述符放在指针recvfd中
 * 
 * @param fd 
 * @param data 
 * @param bytes 
 * @param recvfd 
 * @return ssize_t 
 */

ssize_t recv_fd(int fd, void* data, size_t bytes, int* recvfd)
{

    // 消息接收
    struct msghdr msghdr_recv;
    // 接收数据的向量
    struct iovec iov[1];
    size_t n;

    union deliver_B
    {
        struct cmsghdr cm;
        char control[CMSG_SPACE(sizeof(int))];
    }control_un;

    // 消息头部
    struct cmsghdr* pCMsgHdr;
    // 控制消息
    msghdr_recv.msg_control = control_un.control;
    // 控制消息的长度
    msghdr_recv.msg_controllen = sizeof(control_un.control);

    // 消息的名称为空
    msghdr_recv.msg_name = NULL;
    // 消息的长度为空
    msghdr_recv.msg_namelen = 0;

    iov[0].iov_base = data;
    iov[0].iov_len = bytes;

    msghdr_recv.msg_iov = iov;
    msghdr_recv.msg_iovlen = 1;

    if( (n = recvmsg(fd, &msghdr_recv, 0)) <= 0 )
    {
        return n;
    }

    if( ( ( pCMsgHdr = CMSG_FIRSTHDR(&msghdr_recv) ) != NULL )
        && ( pCMsgHdr->cmsg_len == CMSG_LEN(sizeof(int)) ) )
    {
        // 消息的level应该为SOL_SOCKET
        if( pCMsgHdr->cmsg_level != SOL_SOCKET )
        {
            printf("control level != SOL_SOCKET\n");
        }

        // 消息的类型判断
        if( pCMsgHdr->cmsg_type != SCM_RIGHTS )
        {
            printf("control type != SCM_RIGHTS\n");
        }

        // 获得打开文件的描述符
        *recvfd = *( (int*)CMSG_DATA(pCMsgHdr) );
    }
    else{
        *recvfd = -1;
    }

    // 返回接收消息的长度
    return n;
}

/**
 * @brief 
 * 
 * @param pathName 
 * @param mode 
 * @return int 
 */
int my_open(const char* pathName, int mode)
{
    int fd, sockfd[2], status;
    pid_t childpid;
    char c, argssockfd[10], argmode[10];

    int res;
    // 建立socket
    res = socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd);
    
    childpid = fork();
    if( -1 == childpid )
    {
        perror("fork");
        return -1;
    }

    // 子进程
    if( 0 == childpid )
    {
        close(sockfd[0]);
        
        // socket描述符
        snprintf(argssockfd, sizeof(argssockfd), "%d", sockfd[1]);

        // 打开文件的方式
        snprintf(argmode, sizeof(argmode), "%d", mode);

        // 执行进程A
        execl("./openfil", "openfile", argssockfd, 
            pathName, argmode, (char*)NULL);
        printf("execl error\n");    
    }
    
    // 父进程
    close(sockfd[1]);
    // 等待子进程结束
    waitpid(childpid, &status, 0);

    // 判断子进程是否结束
    if(WIFEXITED(status) == 0)
    {
        printf("child did not terminate\n");
    }

    // 子进程结束
    if( (status = WEXITSTATUS(status)) == 0 )
    {
        // 接收进程A打开的文件描述符
        recv_fd(sockfd[0], &c, 1, &fd);
    }
    else
    {
        errno = status;
        fd = -1;
    }

    close(sockfd[0]);

    // 返回进程A打开文件的描述符
    return fd;
}

#define BUF_SIZE 256

int main(int argc, char* argv[])
{
    int fd, n;
    
    // 接收缓冲区
    char buf[BUF_SIZE];

    if(argc != 2)
    {
        printf("error argc\n");
    }

    // 获得进程A打开的文件描述符
    if( (fd = my_open(argv[1], O_RDONLY)) < 0 )
    {
        printf("cant't open %s\n", argv[1]);
    }

    // 读取数据
    while ( (n = read(fd, buf, BUF_SIZE)) > 0 )
    {   
        // 写入标准输出
        write(1, buf, n);
    }
    
    return 0;
}