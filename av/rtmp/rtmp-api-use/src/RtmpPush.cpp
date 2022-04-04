
#include "RtmpPush.h"
#include "../include/librtmp/rtmp.h"

RtmpPush::RtmpPush()
{

}
RtmpPush::~RtmpPush()
{

}

bool RtmpPush::Alloc()
{
    bool bRet = true;
    m_pRtmp = RTMP_Alloc();
    if(!m_pRtmp)
        return false;

    return true;
}

bool RtmpPush::Init()
{
    bool bRet = true;
    RTMP_Init(m_pRtmp);

    return true;
}

bool RtmpPush::SetupURL(char* url)
{
    bool bRet = true;
    RTMP_SetupURL(m_pRtmp, url);

    return true;
}

bool RtmpPush::EnableWrite()
{
    bool bRet = true;
    RTMP_EnableWrite(m_pRtmp);

    return true;
}

bool RtmpPush::Connect()
{
    bool bRet = true;
    RTMP_Connect(m_pRtmp, m_pRtmpPkt);

    return true;
}

bool RtmpPush::ConnectStream()
{
    bool bRet = true;
    int nRet = RTMP_ConnectStream(m_pRtmp, 0);

    return true;
}

bool RtmpPush::Write()
{
    bool bRet = true;
    char buf[] = "data";
    int nSize = sizeof(buf)/sizeof(char);
    int nRet = RTMP_Write(m_pRtmp, buf, nSize);

    return true;
}

bool RtmpPush::Close()
{
    bool bRet = true;
    RTMP_Close(m_pRtmp);

    return true;
}

bool RtmpPush::Free()
{
    bool bRet = true;
    RTMP_Free(m_pRtmp);

    return true;
}
