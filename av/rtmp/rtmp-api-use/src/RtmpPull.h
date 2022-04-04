
#include <iostream>

//
struct RTMP;
struct RTMPPacket;

/**
 * @brief push stream
 * 
 */

/*
播放端：
1. RTMP_Alloc() -创建一个RTMP会话句柄
2. RTMP_Init() -初始化RTMP句柄
3. RTMP_SetupURL() -设置拉流RTMP Url
4. RTMP_Connect() -建立RTMP网络连接
5. RTMP_ConnectStream() -建立RTMP流连接
6. RTMP_Read() -读取媒体流数据，返回0时则媒体流读取完毕
7. RTMP_Pause() -暂停读取媒体流数据或取消暂停（options）
8. RTMP_Seek() -可通过它改变流播放的位置（options）
9. RTMP_Close() -当媒体流读取完毕后进行RTMP连接的关闭
10.RTMP_Free() -释放此次连接的会话句柄
*/

class RtmpPull
{
public:
    RtmpPull();
    ~RtmpPull();
public:
    bool Alloc();
    bool Init();
    bool SetupURL(char* url);
    bool EnableWrite();
    bool Connect();
    bool ConnectStream();
    bool Read();
    bool Pause();
    bool Seek();
    bool Close();
    bool Free();

private:
    RTMP* m_pRtmp;
    RTMPPacket* m_pRtmpPkt;
};