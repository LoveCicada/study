
#ifndef __def_media_target_plugin__header__
#define __def_media_target_plugin__header__

#include "../TTMediaReaderBaseDef.hpp"
#include "../ITTMediaSampeAVS.hpp"

struct ITTMediaFileRender;
struct ITTMediaFileRenderDesc;
struct ITTMediaFileRenderManager;

typedef std::tr1::shared_ptr<ITTMediaFileRender> ITTMediaFileRenderSptr;

struct ITTMediaFileRender
{
    virtual int Open( const wchar_t* lpszFilename, const TTMPlayerCompileFormat& ttmpFormat, ITTNotify* pErrorInfo ) = 0;
    virtual int Start() = 0;
    virtual int WriteSamples( IN ITTMPVideoSamplePtr videoSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;
    virtual int WriteSamples( IN ITTMPAudioSamplePtr audioSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;
    virtual int WriteSamples( IN ITTMPSubSamplePtr subSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;
    virtual int Stop() = 0;
    virtual int Close() = 0;
    virtual int Destroy() = 0;
};

/**
@brief 文件信息插件，创建ITTMediaSource
@see ITTMediaSource
*/
struct ITTMediaFileRenderDesc
{
    virtual int                     Init() = 0;
    virtual wchar_t*                GetPluginname() = 0;
    virtual int                     GetEncodeFormat(const TTMPlayerCompileFormat& ttmpFormat, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat) = 0;
    virtual int                     Check(const TTMPlayerCompileFormat& ttmpFormat) = 0;
    virtual ITTMediaFileRender*     Create() = 0;
    virtual int                     Uninit() = 0;
};

/** 
 @brief 源插件管理器，管理ITTMediaSourcePlugin
 */
struct ITTMediaFileRenderManager
{
    /** 
     @brief 注册新的ITTMediaSourcePlugin, 如果ITTMediaSourcePlugin的名字已经使用则返回失败
     @remark 如果ID已经使用，将导致注册失败； 在注册ITTMediaSourceSelector前，一定要先注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit；注册完毕需要调用ITTMediaSourcePluginManager::UpdateMediaSourcePlugin更新信息
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Registe(ITTMediaFileRenderDesc*) = 0;

    /** 
     @brief 取消注册指定的ITTMediaSourcePlugin
     @remark 在反注册ITTMediaSourcePlugin前，一定要先反注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit；注册完毕需要调用ITTMediaSourcePluginManager::UpdateMediaSourcePlugin更新信息
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Unregiste(ITTMediaFileRenderDesc*) = 0;

    /** 
     @brief 返回所有注册的ITTMediaSourceSelector
     */
    virtual ITTMediaFileRenderDesc** GetPlugin() = 0;

    /** 
     @brief 返回注册的ITTMediaSourcePlugin的个数
     */
    virtual int GetPluginCount() = 0;
};

typedef int (*funcRegisteMediaTarget_t)(ITTMediaFileRenderManager*);      /**< registeMediaTargetPlugin */
typedef int (*funcUnregisteMediaTarget_t)(ITTMediaFileRenderManager*);    /**< unregisteMediaTargetPlugin */

#endif
