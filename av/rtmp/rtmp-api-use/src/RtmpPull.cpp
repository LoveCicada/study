
#include "RtmpPull.h"
#include "../include/librtmp/rtmp.h"

RtmpPull::RtmpPull()
{

}
RtmpPull::~RtmpPull()
{

}

bool RtmpPull::Alloc()
{
    bool bRet = true;
    m_pRtmp = RTMP_Alloc();

    if(!m_pRtmp)
        return false;

    return true;
}

bool RtmpPull::Init()
{
    bool bRet = true;
    RTMP_Init(m_pRtmp);

    return true;
}

bool RtmpPull::SetupURL(char* url)
{
    bool bRet = true;
    RTMP_SetupURL(m_pRtmp, url);

    return true;
}

bool RtmpPull::EnableWrite()
{
    bool bRet = true;
    RTMP_EnableWrite(m_pRtmp);

    return true;
}

bool RtmpPull::Connect()
{
    bool bRet = true;
    int nRet = RTMP_Connect(m_pRtmp, m_pRtmpPkt);

    return true;
}

bool RtmpPull::ConnectStream()
{
    bool bRet = true;
    int nRet = RTMP_ConnectStream(m_pRtmp, 0);

    return true;
}   

bool RtmpPull::Read()
{   
    bool bRet = true;
    char buf[1024]={0};
    int nSzie = 1024;
    int nRet = RTMP_Read(m_pRtmp, buf, nSzie);

    return true;
}

bool RtmpPull::Pause()
{
    bool bRet = true;
    int nRet = RTMP_Pause(m_pRtmp, 0);

    return true;
}

bool RtmpPull::Seek()
{
    bool bRet = true;
    // int nRet = RTMP_SendSeek(m_pRtmp, 0);

    return true;
}

bool RtmpPull::Close()
{
    bool bRet = true;
    RTMP_Close(m_pRtmp);

    return true;
}

bool RtmpPull::Free()
{
    bool bRet = true;
    RTMP_Free(m_pRtmp);

    return true;
}