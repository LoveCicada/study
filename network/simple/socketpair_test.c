
/**
 * @file socketpair_test.c
 * @author dyf (you@domain.com)
 * @brief socketpair(), 父子进程在通信的时候, 必须关闭一个描述符,
 *  是因为一个在写的时候另外一个只能读
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char* argv[])
{
    int sv[2];
    int res = socketpair(PF_LOCAL, SOCK_STREAM, 0, sv);

    if( res < 0 )
    {
        perror("socketpair");
        exit(-1);
    }

    pid_t pid = fork();
    if( -1 == pid)
    {
        perror("fork");
        exit(-1);
    }

    if( 0 == pid )
    {
        // child process
        close(sv[1]);
        const char* msg = "I am child";
        char buf[128];
        while(1)
        {
            write(sv[0], msg, strlen(msg));
            sleep(1);

            int n = read(sv[0], buf, sizeof(buf)-1);
            if(n > 0)
            {
                buf[n] = '\0';
                printf("child:%s\n", buf);
            }
        }
    }
    else
    {
        // father process
        close(sv[0]);
        const char* msg = "I AM FATHER";
        char buf[128];
        while (1)
        {
            int n = read(sv[1], buf, sizeof(buf)-1);
            if(n>0)
            {
                buf[n] = '\0';
                printf("FATHER:%s\n", buf);
                sleep(1);
            }
            write(sv[1], msg, strlen(msg));
        }
    }

    return 0;
}