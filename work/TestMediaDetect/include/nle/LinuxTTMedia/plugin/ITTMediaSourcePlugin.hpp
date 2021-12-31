
#ifndef __def_media_source_plugin__header__
#define __def_media_source_plugin__header__

#include "../TTMediaReaderBaseDef.hpp"
#include "../ITTMediaSampeAVS.hpp"

struct ITTMediaSource;
struct ITTMediaSourcePlugin;

typedef std::tr1::shared_ptr<struct ITTMediaSource> ITTMediaSourceSptr;


/**
@brief 文件信息读取接口
*/
struct ITTMediaSource
{
    virtual int Open( const wchar_t* lpszFilename, int uiOpenFlags, ITTNotify* pErrorInfo ) = 0;
    virtual int GetFileFormat( TTMPlayerFileFormat& fileInfo ) = 0;
    virtual int SetOutputFormat( TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat ) = 0;
    virtual int Start( REFERENCE_TIME inPos = NULL, REFERENCE_TIME outPos = NULL ) = 0;

    virtual int ReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;
    virtual int ReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;
    virtual int ReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    virtual int Stop() = 0;
    virtual int Close() = 0;
    virtual int Destroy() = 0;
};

/**
@brief 文件信息插件，创建ITTMediaSource
@see ITTMediaSource
*/
struct ITTMediaSourcePlugin
{
    virtual int             Init() = 0;
    virtual wchar_t*        GetPluginname() = 0;
    virtual int             GetPriority() = 0;
    virtual int             AnalayzeFilename(const wchar_t* pFilename) = 0;
    virtual int             Analayze(const wchar_t* pFilename, HANDLE hFile, const BYTE* pBuf, int iBufSize) = 0;

    virtual ITTMediaSource* Create() = 0;
    virtual int             Uninit() = 0;
};

#endif
