
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    // 读文件集合
    fd_set rd;

    // 时间间隔
    struct timeval tv;
    
    // 错误值
    int err;

    // 文件描述符, 0代表biao
    int fd = 0;

    FD_ZERO(&rd);
    FD_SET(fd, &rd);

    // 设置5s的等待超时
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    err = select(fd+1, &rd, NULL, NULL, &tv);

    if( -1 == err )
    {
        perror("select");
    }
    else if(err)
    {
        // 标准输入有数据输入，可读
        printf("Data is available now. \n");
    }
    else
    {
        // 超时，没有数据到达
        printf("No data within five seconds.\n");
    }



    return 0;
}