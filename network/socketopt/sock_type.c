
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
    int so_type = -1;
    socklen_t optlen = -1;

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

    optlen = sizeof(so_type);
    err = getsockopt(sfd, SOL_SOCKET, SO_TYPE,
            &so_type, &optlen);
    if(-1 == err)
    {
        perror("getsockopt SO_TYPE error");
        close(sfd);
        return -1;
    }        

    printf("socket fd: %d\n", sfd);
    printf("SO_TYPE: %d\n", so_type);
    close(sfd);

    return 0;
}

/**
 * @brief result
 * 
 *  socket fd: 3
    SO_TYPE: 1
 */