

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // child
        printf("i am a child process my pid  = %d\n", getpid());
        exit(11); //退出子进程，我们在父进程调用waitpid来获得子进程的退出码信息
    }
    // parent process
    int status;                           //该变量是父进程的变量，为的是在父进程获得子进程的退出状态的信息
    pid_t ret = waitpid(pid, &status, 0); //传入status的地址，获得子进程的退出的信息
    if (ret == -1)
    {
        perror("wait failed\n");
    }
    // waitpid 等待成功
    if (WIFEXITED(status))
    {
        printf("子进程pid = %d 正常退出，父进程获得子进程的退出码为：%d\n", pid, WEXITSTATUS(status));
    }
    else
    {
        printf("WIFEXITED为假，子进程异常退出，非正常退出\n");
    }
    return 0;
}