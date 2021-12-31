
#ifndef __def_media_filerender_plugin__helper__header__
#define __def_media_filerender_plugin__helper__header__

#include <cassert>
#include "./TTMediaLogMsghelper.hpp"
#include "../plugin/IMediaWriterPlugin.hpp"

struct TTMediaFileRenderCImpl : public ITTMediaFileRender
{
    virtual ~TTMediaFileRenderCImpl(){}
    virtual int Open( const wchar_t* lpszFilename, const TTMPlayerCompileFormat& ttmpFormat, ITTNotify* pErrorInfo ){return 0;}
    virtual int Start() {return 0;};
    virtual int WriteSamples( IN ITTMPVideoSamplePtr videoSample, __int64 iiFrameId, int iStreamIdx = -1) {return 0;}
    virtual int WriteSamples( IN ITTMPAudioSamplePtr audioSample, __int64 iiFrameId, int iStreamIdx = -1) {return 0;}
    virtual int WriteSamples( IN ITTMPSubSamplePtr subSample, __int64 iiFrameId, int iStreamIdx = -1)  {return 0;}
    virtual int Stop() {return 0;}
    virtual int Close() {return 0;}
    virtual int Destroy()
    {
        delete this;
        return 0;
    }
};

struct TTMediaFileRenderDescCImpl : ITTMediaFileRenderDesc
{
    virtual ~TTMediaFileRenderDescCImpl(){}
    virtual int                     Init() {return 0;}
    virtual wchar_t*                GetPluginname() {return 0;}
    virtual int                     GetEncodeFormat(const TTMPlayerCompileFormat& ttmpFormat, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat) {return 0;}
    virtual int                     Check(const TTMPlayerCompileFormat& ttmpFormat) {return 0;}
    virtual ITTMediaFileRender*     Create() {return 0;}
    virtual int                     Uninit() {return 0;}
};

#endif
