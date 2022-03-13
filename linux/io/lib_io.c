
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fd = -1;
    char buf[100] = {0};
    char writerBuf[20] = "lib_io_test";
    int ret;

    //! open
    fd = open("a.txt", O_CREAT | O_RDWR | O_TRUNC);
    if(-1 == fd){
        perror("file open error\n");
        return -1;
    }else{
        printf("file open success, fd = %d\n", fd);
    }

    //! write
    ret = write(fd, writerBuf, strlen(writerBuf));
    if(-1 == ret){
        perror("write error\n");
        close(fd);
        return -1;
    }

    //! read
    lseek(fd, 0, SEEK_SET);
    ret = read(fd, buf, 20);
    if(-1 == ret){
        perror("read error");
        close(fd);
        return -1;
    }else{
        printf("ret = %d, a.txt = %s\n", ret, buf);
    }

    close(fd);
    return 0;
}
/**
 * @brief result
 * 
 * ./bin/lib_io
 * file open success, fd = 3
 * ret = 11, a.txt = lib_io_test
 * 
 */