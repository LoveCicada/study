
#include <sys/socket.h>
#include <sys/ioctl.h>          // ioctl 命令
#include <netinet/if_ether.h>   // ethhdr 结构
#include <net/if.h>             // ifreq 结构
#include <netinet/in.h>         // in_addr 结构
#include <netinet/ip.h>         // iphdr 结构
#include <netinet/udp.h>        // udphdr 结构
#include <netinet/tcp.h>        // tcphdr 结构
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int nRet = 0;
    int fd;
    fd = socket(AF_INET, SOCK_PACKET, htons(0x0003));
    
    char* ethname = "eth0";

    // 网络接口结构
    struct ifreq ifr;
    strcpy(ifr.ifr_name, ethname);
    printf("ifr.ifr_name: %s\n", ifr.ifr_name);

    // 获得eth0的标志位值
    nRet = ioctl(fd, SIOCGIFFLAGS, &ifr);
    if(-1 == nRet)
    {
        perror("ioctl get SIOCGIFFLAGS error");
        close(fd);
        exit(-1);
    }

    // 保留原来设置的情况下, 在标志位中加入"混杂"方式
    ifr.ifr_flags |= IFF_PROMISC;
    
    // 将标志位设置写入
    nRet = ioctl(fd, SIOCSIFFLAGS, &ifr);
    if(nRet<0)
    {
        perror("promiscuous set error\n");
        close(fd);
        exit(-2);
    }

    return 0;
}