
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>

/**
 * @brief 结构保存获取结果
 * 
 */
typedef union optval
{
    int             val;    // 整型值
    struct linger   linger; // linger结构, 控制tcp连接断开方式
                            // 优雅断开和强制断开
    struct timeval  tv;     // 时间结构
    unsigned char   str[16];// 字符串
}val;

// 用于保存数值
static val optval;

// 数值类型
typedef enum valtype{
    VALINT,     //  int 类型
    VALLINGER,  // struct linger类型
    VALTIMEVAL, // struct timeval类型
    VALUNCHAR,  // 字符串
    VALMAX,     // 错误类型
}valtype;

typedef struct sopts{
    int     level;      // 套接字选项级别
    int     optname;    // 套接字选项名称
    char*   name;       // 套接字名称
    valtype valType;    // 套接字返回参数类型
}sopts;

sopts sockopts[] = {
    {SOL_SOCKET,    SO_BROADCAST,       "SO_BROADCAST",         VALINT},
    {SOL_SOCKET,    SO_DEBUG,           "SO_DEBUG",             VALINT},
    {SOL_SOCKET,    SO_ERROR,           "SO_ERROR",             VALINT},
    {SOL_SOCKET,    SO_KEEPALIVE,       "SO_KEEPALIVE",         VALINT},
    {SOL_SOCKET,    SO_LINGER,          "SO_LINGER",            VALINT},
    {SOL_SOCKET,    SO_OOBINLINE,       "SO_OOBINLINE",         VALINT},
    {SOL_SOCKET,    SO_RCVBUF,          "SO_RCVBUF",            VALINT},
    {SOL_SOCKET,    SO_RCVLOWAT,        "SO_RCVLOWAT",          VALINT},
    {SOL_SOCKET,    SO_RCVTIMEO,        "SO_RCVTIMEO",          VALTIMEVAL},
    {SOL_SOCKET,    SO_SNDTIMEO,        "SO_SNDTIMEO",          VALTIMEVAL},
    {SOL_SOCKET,    SO_TYPE,            "SO_TYPE",              VALINT},
    {SOL_SOCKET,    IP_HDRINCL,         "IP_HDRINCL",           VALINT},
    {SOL_SOCKET,    IP_OPTIONS,         "IP_OPTIONS",           VALINT},
    {SOL_SOCKET,    IP_TOS,             "IP_TOS",               VALINT},
    {SOL_SOCKET,    IP_TTL,             "IP_TTL",               VALINT},
    {SOL_SOCKET,    IP_MULTICAST_TTL,   "IP_MULTICAST_TTL",     VALUNCHAR},
    {SOL_SOCKET,    IP_MULTICAST_LOOP,  "IP_MULTICAST_LOOP",    VALUNCHAR},
    {SOL_SOCKET,    TCP_KEEPCNT,        "TCP_KEEPCNT",          VALINT},
    {SOL_SOCKET,    TCP_MAXSEG,         "TCP_MAXSEG",           VALINT},
    {SOL_SOCKET,    TCP_NODELAY,        "TCP_NODELAY",          VALINT},

    // 结尾, 主程序中判断VALMAX
    {0,             0,              NULL,               VALMAX}
};


/**
 * @brief 显示查询结果
 * 
 * @param sockopt 
 * @param len 
 * @param err 
 */
static void disp_outcome(sopts* sockopt, int len, int err)
{
    if(-1 == err){
        printf("optname %s NOT support\n", sockopt->name);
        return;
    }

    // 根据不同的类型进行信息打印
    switch (sockopt->valType)
    {
    case VALINT:
        printf("optname %s: default is %d\n", sockopt->name,
            optval.val);
        break;
    case VALLINGER:
        printf("optname %s: default is %d(ON/OFF), %d to linger\n",
            sockopt->name,          // 名称
            optval.linger.l_onoff,  // linger打开
            optval.linger.l_linger);// 延时时间
        break;
    case VALTIMEVAL:
        printf("optname %s: default is %.06f\n",
            sockopt->name,
            ((((double)optval.tv.tv_sec*100000+(double)optval.tv.tv_usec))/(double)1000000));
        break;
    case VALUNCHAR:
        {
            int idx = 0;
            printf("optname %s: default is ", sockopt->name);
            // 选项名称
            for(; idx < len; idx++)
            {
                printf("%02x ", optval.str[idx]);
            }
            printf("\n");
        }    
        break;
    default:
        break;
    }
}


int main(int argc, char* argv[])
{
    int err = -1;
    socklen_t len = 0;
    int i = 0;
    // 建立一个流式套接字
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    while (sockopts[i].valType != VALMAX)
    {
        // 计算结构长度
        len = sizeof(sopts[i]);
        err = getsockopt(sfd, sockopts[i].level, sockopts[i].optname,
            &optval, &len);

        // 显示结果    
        disp_outcome(&sockopts[i], len, err);
        
        // 递增
        i++;
    }
    
    close(sfd);

    return 0;
}
