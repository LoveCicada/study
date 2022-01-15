
- `ARP协议数据和结构`
```
struct arphdr
{
  unsigned short int ar_hrd; /* Format of hardware address.  */
  unsigned short int ar_pro; /* Format of protocol address.  */
  unsigned char ar_hln;	     /* Length of hardware address.  */
  unsigned char ar_pln;	     /* Length of protocol address.  */
  unsigned short int ar_op;  /* ARP opcode (command).  */
}
```

- `自定义`
- `以太网的ARP数据结构`
```
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
```