
- `udp-server`
```
create socket
bind
recvfrom/sendto
close
```

- `udp-client`
```
create socket
sendto/recvfrom
close
```

- `网络字节序转换成主机字节序`
```
网络字节序一般是二进制，主机字节序一般是字符串
头文件 #include <arpa/inet.h>
inet_ntoa()
ntohs()
struct sockaddr_in
struct sockaddr
上述两个结构体内存大小一致，可相互转换
```