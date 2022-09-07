
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
        int count = 10;
        while (count)
        {
            printf("i am a process my pid  = %d\n", getpid());
            count--;
            sleep(1);
        }
        exit(11); //退出子进程，我们在父进程调用waitpid来获得子进程的退出码信息
    }
    // parent process
    int status; //该变量是父进程的变量，为的是在父进程获得子进程的退出状态的信息

    while (1)
    {                                               //这个循环就是继续轮回检测的非阻塞版本的设计，假如子进程没退出，我们一直死循环检测知道直到它退出
        pid_t ret = waitpid(pid, &status, WNOHANG); // WNOHANG:表示父进程非阻塞方式等待子进程退出
        if (ret == 0)
        {
            // ret == 0 表示waitpid等待成功，但是子进程还没有退出，waitpid返回0回到父进程的代码执行
            //做父进程的事情；
            printf("我waitpid返回0，等待子进程成功，但是子进程没有退出，我可做父进程要做的事\n");
        }
        else if (ret > 0)
        {
            // waitpid 等待成功,子进程退出，父进程就可以获取子进程的信息
            printf("waitpid 返回的stauts 的退出码信息：%d,终止信号的信息：%d, ret = %d\n", (status >> 8) & 0xFF, status & 0x7F, ret);
            break;
        }
        else
        {
            printf("waitpid is failed\n");
            break;
        }
        sleep(1); //让父进程每隔一秒去检测
    }
    return 0;
}
