
#ifndef __def__transcode__header__
#define __def__transcode__header__

#include "./TTMediaTranscodeBaseDef.hpp"

// -------------------------------------------------------------------------

/** ����ת���ÿһ֡���ݻص� */
struct ISampleTransform
{
    virtual int Transform(ITTMPVideoSamplePtr pVideoSample, int iFrameIdx) = 0;
    virtual int Transform(ITTMPAudioSamplePtr pAudioSample, int iFrameIdx) = 0;
};

/** ת����ƽӿ� */
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

/** ��ʼ��MediaTranscode��ĺ�����, ����LoadLibrary��ʽ */
#define ADDR_INIT_MEDIA_TRANSCODE_LIB       "TT_InitMediaTranscodeLib"

/** ����ת�����ĺ�����, ����LoadLibrary��ʽ */
#define ADDR_CREATE_MEDIA_TRANSCODE         "TT_CreateTranscode"

/** ����MediaTranscode��ĺ�����, ����LoadLibrary��ʽ */
#define ADDR_UNINIT_MEDIA_TRANSCODE_LIB     "TT_UnnitMediaTranscodeLib"


/** ��ʼ��MediaTranscode�⺯������, ����LoadLibrary��ʽ */
typedef int (*FUNC_TT_InitMediaTranscodeLib)(const wchar_t* wszPluginFolder);

/** ����ת�����ĺ�������, ����LoadLibrary��ʽ */
typedef ITTTranscode* (*FUNC_TT_CreateTranscode)();

/** ����MediaTranscode��ĺ�������, ����LoadLibrary��ʽ */
typedef int (*FUNC_TT_UnnitMediaTranscodeLib)();


#endif
