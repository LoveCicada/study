
/**
 * @file waitpid.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * @see https://zhuanlan.zhihu.com/p/484949219
 * @copyright Copyright (c) 2022
 * 
 */

//! （stauts >> 8 ）& 0xFF；获得子进程的退出码
//! stauts & 0x7F; 获得子进程的终止信号；

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
    //打印子进程的stauts退出码信息和终止信号信息，这是在父进获取到子进程的信息
    printf("waitpid 返回的stauts 的退出码信息：%d, 终止信号的信息：%d\n", (status >> 8) & 0xFF, status & 0x7F);
    return 0;
}