
#include <iostream>

//
struct RTMP;
struct RTMPPacket;

/**
 * @brief push stream
 * 
 */

/*
推流端：
1. RTMP_Alloc() -创建一个RTMP会话句柄
2. RTMP_Init() -初始化RTMP句柄
3. RTMP_SetupURL() -设置推流RTMP Url
4. RTMP_EnableWrite() -配置该媒体流可进行写操作
5. RTMP_Connect() -建立RTMP网络连接
6. RTMP_ConnectStream() -建立RTMP流连接
7. RTMP_Write() -对该媒体流进行写入流媒体信息
8. RTMP_Close() -关闭RTMP连接
9. RTMP_Free() -释放此次连接的会话句柄
*/

class RtmpPush
{
public:
    RtmpPush();
    ~RtmpPush();
public:
    bool Alloc();
    bool Init();
    bool SetupURL(char* url);
    bool EnableWrite();
    bool Connect();
    bool ConnectStream();
    bool Write();
    bool Close();
    bool Free();

private:
    RTMP* m_pRtmp;
    RTMPPacket* m_pRtmpPkt;
};