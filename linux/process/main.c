#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0) {
        printf("this is child process running execlp\n");
        execlp("python3", "python3", "main.py", (char*) NULL);
        return 0;
    } else {
        wait(NULL);
        printf("end from c program parent process\n");
    }
    return 0;
}
