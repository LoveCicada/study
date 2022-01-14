
#include <sys/socket.h>
#include <sys/ioctl.h>          // ioctl 命令
#include <netinet/if_ether.h>   // ethhdr 结构
#include <net/if.h>             // ifreq 结构
#include <netinet/in.h>         // in_addr 结构
#include <netinet/ip.h>         // iphdr 结构
#include <netinet/udp.h>        // udphdr 结构
#include <netinet/tcp.h>        // tcphdr 结构
#include <arpa/inet.h>          // inet_addr
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct arppacket
{
    unsigned short ar_hrd;              // 硬件类型
    unsigned short ar_pro;              // 协议类型
    unsigned char  ar_hln;              // 硬件地址长度
    unsigned char  ar_pln;              // 协议地址长度
    unsigned short ar_op;               // ARP操作码
    unsigned char  ar_sha[ETH_ALEN];    // 发送方MAC地址
    unsigned char* ar_sip;              // 发送方IP地址
    unsigned char  ar_tha[ETH_ALEN];    // 目的MAC地址
    unsigned char* ar_tip;              // 目的IP地址

};


int main(int argc, char* argv[])
{
    // 以太帧缓冲区
    char ef[ETH_FRAME_LEN];
    // 以太网头部指针
    struct ethhdr* p_ethhdr;
    // 目的以太网地址
    char eth_dest[ETH_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 
                               0xFF, 0xFF};
    // 源以太网地址
    char eth_source[ETH_ALEN] = {0x00, 0x0C, 0x29, 0x73,
                                0x9D, 0x15};

    int nRet = 0;
    int fd;
    fd = socket(AF_INET, SOCK_PACKET, htons(0x0003));

    // 使p_ethhdr指向以太网帧的帧头
    p_ethhdr = (struct ethhdr*)ef;
    // 复制目的以太网地址
    memcpy(p_ethhdr->h_dest, eth_dest, ETH_ALEN);
    // 复制源以太网地址
    memcpy(p_ethhdr->h_source, eth_source, ETH_ALEN);
    // 设置协议类型, 以太网0x0806
    p_ethhdr->h_proto = htons(0x0806);

    struct arppacket* p_arp;
    // 定位ARP包地址
    p_arp = (struct arppacket*)ef + ETH_HLEN;
    // arp硬件类型
    p_arp->ar_hrd = htons(0x01);
    // 协议类型
    p_arp->ar_pro = htons(0x0800);
    // 硬件地址长度
    p_arp->ar_hln = 6;
    // IP地址长度
    p_arp->ar_pln = 4;

    // 复制源以太网地址
    memcpy(p_arp->ar_sha, eth_source, ETH_ALEN);
    // p_arp->ar_sip = (unsigned char*)inet_addr("192.168.1.152");
    p_arp->ar_sip = "192.168.1.152";

    // 复制目的以太网地址
    memcpy(p_arp->ar_tha, eth_dest, ETH_ALEN);
    // 目的IP地址
    // p_arp->ar_tip = (unsigned char*)inet_addr("192.168.1.1");
    p_arp->ar_tip = "192.168.1.1";

    // 发送ARP请求8次, 间隔1s
    int i = 0;
    for(; i<8; ++i)
    {
        // 发送
        write(fd, ef, ETH_FRAME_LEN);
        // 等待1s
        sleep(1);
    }

    close(fd);
    return 0;
}