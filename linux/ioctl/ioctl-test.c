#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "ioctl-test.h"

int main(int argc, char* argv[])
{
    int fd;
    int ret;
    struct msg my_msg;

    //char ch[] = "/dev/ioctl-test";
    char ch[] = "/mnt/d/code/private/loveCicada_test/linux/ioctl/ioctl-test.h";
    fd = open(ch, O_RDWR);
    if(fd<0)
    {
        perror("open");
        exit(-2);
    }

    /*初始化设备*/
    ret = ioctl(fd, IOCINIT);
    if(ret)
    {
        perror("ioctl init:");
        exit(-3);
    }

    /*往寄存器0x01写入数据0xef*/
    memset(&my_msg, 0, sizeof(struct msg));
    my_msg.addr = 0x01;
    my_msg.data = 0xefl;

#if 0
    /*读寄存器0x01*/
    memset(&my_msg, 0, sizeof(struct msg));
    my_msg.addr = 0x01;
    ret = ioctl(fd, IOCGREG, &my_msg);
    if(ret)
    {
        perror("ioctl write");
        exit(-5);
    }
#endif

    printf("read: %#x\n", my_msg.data);

    return 0;
}