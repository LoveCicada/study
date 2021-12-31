
#ifndef __def__transcode_render_interface__header__
#define __def__transcode_render_interface__header__

#include "./TTMediaTranscodeBaseDef.hpp"
#include <InitGuid.h>
// -------------------------------------------------------------------------

struct ITTTranscodeRender
{
    virtual int GetEncodeFormat(TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat) = 0;
    virtual int Start() = 0;
    virtual int WriteSample(ITTMPVideoSamplePtr pVideoSample, __int64 iiFrameid) = 0;
    virtual int WriteSample(ITTMPAudioSamplePtr pAudioSample, __int64 iiFrameid) = 0;
    virtual int Stop() = 0;
};

struct TTTargetRender
{
    enum
    {
        MAX_AUDIO_FILE_COUNT = 8,
    };
    __int64 llStartTime;                        /**< 起始时间, 单位100ns, 1s == 1000*1000*1000ns */
    __int64 llStopTime;                         /**< 结束时间, 单位100ns, 1s == 1000*1000*1000ns */

    struct RenderEntry
    {
        struct
        {
            bool bWithAudio;
            int iChannelStart;
            int iSampleRate;
            int iSampleBits;
            int iSampleChannel;
        }audio;
        struct
        {
            bool bWithVideo;
            int iWidth;
            int iHeight;
            int iPixelFormat;
        }video;
        ITTTranscodeRender* pRender;
    };

    struct AudioRender  
    {
        int iChannelStart;
        int iSampleRate;
        int iSampleBits;
        int iSampleChannel;
        ITTTranscodeRender* pAudioRender;
    };

    enum TT_HDSD_COMPILE_MODE   eAdapMode;
    enum TT_DEINTERLACE_MODE    eDeinterlaceType;
    
    double dFrameRate;

    RenderEntry videoRender;
    RenderEntry videoRenderProxy;
	RenderEntry videoRenderStream;
	RenderEntry	videoKeyRender[3];
    AudioRender arrAudioRender[4*16];
    int iAudioRenderCount;
};

// {9E778B19-71B5-4c5a-A694-2E6389F506E3}
DEFINE_GUID(IID_ISetTranscodeRender, 0x9e778b19, 0x71b5, 0x4c5a, 0xa6, 0x94, 0x2e, 0x63, 0x89, 0xf5, 0x6, 0xe3);
struct ISetTranscodeRender
{
    virtual int SetRender(TTTargetRender& render) = 0;
    virtual int ClearRender() = 0;
};

// -------------------------------------------------------------------------

#endif
