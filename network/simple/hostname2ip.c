
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    char*ptr, **pptr;
    struct hostent *hptr;
    char str[32] = {'\0'};

    /* 取得命令后第一个参数，即要解析的域名或主机名 */
    ptr = argv[1];
    if( (hptr = gethostbyname(ptr)) == NULL )
    {
        printf(" gethostbyname error for host:%s\n", ptr);
        return -1;
    }

    /* 将主机的规范名打出来 */
    printf("official hostname:%s\n", hptr->h_name);

    /* 主机可能有多个别名，将所有别名分别打出来 */
    for(pptr = hptr->h_aliases; *pptr!=NULL; pptr++)
    {
        printf(" alias:%s\n", *pptr);
    }

    /* 根据地址类型，将地址打印出来 */
    switch (hptr->h_addrtype)
    {
    case AF_INET:
    case AF_INET6:
        pptr = hptr->h_addr_list;
        for(; *pptr!=NULL; pptr++)
        {
            inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str));
            printf("address:%s\n", str);
        }
        inet_ntop(hptr->h_addrtype, *hptr->h_addr_list, str, sizeof(str));
        printf("The first address:%s\n", str);
        break;
    
    default:
        printf("unknown address type\n");
        break;
    }

    return 0;
}