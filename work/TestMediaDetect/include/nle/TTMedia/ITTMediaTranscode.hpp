
#ifndef __def__transcode__header__
#define __def__transcode__header__

#include "./TTMediaTranscodeBaseDef.hpp"

// -------------------------------------------------------------------------

/** 正在转码的每一帧数据回调 */
struct ISampleTransform
{
    virtual int Transform(ITTMPVideoSamplePtr pVideoSample, int iFrameIdx) = 0;
    virtual int Transform(ITTMPAudioSamplePtr pAudioSample, int iFrameIdx) = 0;
};

/** 转码控制接口 */
struct ITTTranscode
{
    virtual int Init(ITTNotify* pNotify) = 0;
    virtual int GetFunc(const GUID& iid, LPVOID* ppInterface) = 0;    
    virtual int SetSourceFile(const wchar_t* wszFilename) = 0;
    virtual int GetSourceFormat(TTMPlayerFileFormat& fileInfo) = 0;
    virtual int SetOutputFile(TTTargetFileInfo& target) = 0;
    virtual int Start(ISampleTransform* pMediaProc = NULL) = 0;
    virtual int Pause(bool bPause) = 0;
    virtual int Stop() = 0;
    virtual int GetProgress() = 0; /**< [0, 10000]*/
    virtual int Uninit() = 0;
    virtual int Destroy() = 0;
};

// -------------------------------------------------------------------------

/** 初始化MediaTranscode库的函数名, 用于LoadLibrary方式 */
#define ADDR_INIT_MEDIA_TRANSCODE_LIB       "TT_InitMediaTranscodeLib"

/** 创建转码器的函数名, 用于LoadLibrary方式 */
#define ADDR_CREATE_MEDIA_TRANSCODE         "TT_CreateTranscode"

/** 销毁MediaTranscode库的函数名, 用于LoadLibrary方式 */
#define ADDR_UNINIT_MEDIA_TRANSCODE_LIB     "TT_UnnitMediaTranscodeLib"


/** 初始化MediaTranscode库函数类型, 用于LoadLibrary方式 */
typedef int (*FUNC_TT_InitMediaTranscodeLib)(const wchar_t* wszPluginFolder);

/** 创建转码器的函数类型, 用于LoadLibrary方式 */
typedef ITTTranscode* (*FUNC_TT_CreateTranscode)();

/** 销毁MediaTranscode库的函数类型, 用于LoadLibrary方式 */
typedef int (*FUNC_TT_UnnitMediaTranscodeLib)();


#endif
