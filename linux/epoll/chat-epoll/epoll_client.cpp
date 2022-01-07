
#include "utility.h"

int main(int argc, char* argv[])
{
    // server ip + port
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // create socket
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sfd < 0)
    {
        perror("socket");
        exit(-1);
    }

    int ret = 0;
    ret = connect(sfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if( ret < 0 )
    {
        perror("connect");
        close(sfd);
        exit(-1);
    }

    // create pipe, fd[0] use for father process read, fd[1] user for child process write
    int pipe_fd[2];
    int pret = pipe(pipe_fd);
    if(ret == -1)
    {
        perror("pipe error");
        close(sfd);
        exit(-1);
    }

    // create epoll
    int epfd = epoll_create(EPOLL_SIZE);
    if(epfd < 0)
    {
        perror("epfd error");
        close(sfd);
        exit(-1);
    }
    
    struct epoll_event events[2];
    // add sock and pipe read fd to kernel table
    addFd(epfd, sfd, true);
    addFd(epfd, pipe_fd[0], true);

    // 
    bool isClientWork = true;

    char msg[BUF_SIZE];

    // fork
    int pid = fork();
    if(pid < 0)
    {
        perror("fork error");
        close(sfd);
        //close();
        exit(-1);
    }
    else if( pid == 0 )
    {
        // child process
        // child process write data to pipe
        // so we close read pipe
        close(pipe_fd[0]);
        printf("Please input 'exit' to exit chat room\n");

        while(isClientWork){
            memset(&msg, 0, BUF_SIZE);
            fgets(msg, BUF_SIZE, stdin);

            // client output exit
            if(strncasecmp(msg, EXIT, strlen(EXIT))==0){
                isClientWork = false;
            }
            else{
                //child process write info to pipe
                if(write(pipe_fd[1], msg, strlen(msg) - 1) < 0){
                    perror("fork error");
                    exit(-1);
                }
            }
        }
    }
    else
    {
        // pid > 0 father process
        // father process read pipe data, 
        // so we close write pipe
        close(pipe_fd[1]);

        // epoll_wait
        while(isClientWork)
        {
            int epoll_events_count = epoll_wait(epfd, events, 2, -1);
            // process ready event
            for(int i = 0; i < epoll_events_count; ++i)
            {
                memset(&msg, 0, BUF_SIZE);
                // server send msg
                if(events[i].data.fd == sfd)
                {
                    // recv server msg
                    int sret = recv(sfd, msg, BUF_SIZE, 0);
                    if( 0 == ret )
                    {
                        // server close
                        printf("server closed connection: %d\n", sfd);
                        close(sfd);
                        isClientWork = false;
                    }
                    else if( -1 == ret )
                    {
                        perror("recv error");
                        close(sfd);
                        exit(-1);
                    }
                    else
                    {
                        printf("%s\n", msg);
                    }
                }
                else
                {
                    // father process read data from pipe
                    int rret = read(events[i].data.fd, msg, BUF_SIZE);
                    if( 0 == ret ){
                        isClientWork = false;
                    }
                    else{
                        send(sfd, msg, BUF_SIZE, 0);
                    }
                }
            }
        }
    }

    if(pid){
        // close father process and sock
        close(pipe_fd[0]);
        close(sfd);
    }
    else{
        // close child process
        close(pipe_fd[1]);

    }


    return 0;
}