
#ifndef __def_media_source_plugin__helper__header__
#define __def_media_source_plugin__helper__header__

#include <cassert>
#include "./TTMediaLogMsghelper.hpp"
#include "../ITTMediaSourcePlugin.hpp"

/**
\brief 文件信息读取接口
*/
__declspec(novtable) struct ITTMediaSourceCImpl : public ITTMediaSource
{
    ITTMediaSourceCImpl() : m_bIsPlaying(false){}
    virtual ~ITTMediaSourceCImpl(){}
    virtual int Open( const wchar_t* lpszFilename, int uiOpenFlags, ITTNotify* pErrorInfo ){return 0;}
    virtual int GetFileFormat( TTMPlayerFileFormat& fileInfo ){return 0;}
    virtual int SetOutputFormat( TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat ){return 0;}
    virtual int Start( REFERENCE_TIME inPos, REFERENCE_TIME outPos ){return 0;}

    virtual int ReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx)
    {
        videoSample = NULL;
        if (m_bIsPlaying)   return playReadSamples(videoSample, framePos, iStreamIdx);
        else                return seekReadSamples(videoSample, framePos, iStreamIdx);
    }
    virtual int ReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx)
    {
        audioSample = NULL;
        if (m_bIsPlaying)   return playReadSamples(audioSample, framePos, iStreamIdx);
        else                return seekReadSamples(audioSample, framePos, iStreamIdx);
    }
    virtual int ReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx)
    {
        subSample = NULL;
        if (m_bIsPlaying)   return playReadSamples(subSample, framePos, iStreamIdx);
        else                return seekReadSamples(subSample, framePos, iStreamIdx);
    }

    virtual int Stop() {return 0;}
    virtual int Close() {return 0;}
    virtual int Destroy() {delete this; return 0;}

protected:
    virtual int seekReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}
    virtual int seekReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}
    virtual int seekReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}

    virtual int playReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}
    virtual int playReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}
    virtual int playReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx){assert(false && "not implement"); return 0;}

    bool m_bIsPlaying;
};

/**
\brief 文件信息插件，创建ITTMediaSource
\see ITTMediaSource
*/
__declspec(novtable) struct ITTMediaSourcePluginCImpl : public ITTMediaSourcePlugin
{
    virtual ~ITTMediaSourcePluginCImpl(){}
    virtual int             Init() {return 0;}
    virtual wchar_t*        GetPluginname() {return 0;}
    virtual int             GetPriority() {return 0;}
    virtual int             AnalayzeFilename(const wchar_t* pFilename) {return 0;}
    virtual int             Analayze(const wchar_t* pFilename, HANDLE hFile, const BYTE* pBuf, int iBufSize) {return 0;}
    virtual ITTMediaSource* Create() {return 0;}
    virtual int             Uninit() {delete this; return 0;}
};

#endif
