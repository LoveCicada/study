
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void test()
{
    pid_t _pid = fork();
    if(_pid == 0)
    {
        pid_t _pd = getppid();
        printf("pid==0, %d\n", _pd);
    }

    pid_t _pdd = getppid();
    printf("pid!=0, %d\n", _pdd);
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}