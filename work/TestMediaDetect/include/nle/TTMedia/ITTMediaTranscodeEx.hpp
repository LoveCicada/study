
#ifndef __def_TTMediaTranscodeEx__header__
#define __def_TTMediaTranscodeEx__header__

#include "./TTMediaTranscodeBaseDef.hpp"
#include "./ITTMediaTranscode.hpp"

// -------------------------------------------------------------------------

struct TTFileTranItem
{
    const wchar_t* wszFilename;
    ULONGLONG       iMediaType;
    double      dbFrameRate;                    /**< ��ǰ�ز�֡�� */
    __int64     llFileIn;                       /**< �ļ���ʼ��Χ [llFileIn, llFileOut) */
    __int64     llFileOut;                      /**< �ļ���ʼ��Χ [llFileIn, llFileOut) */
    __int64     llClipIn;                       /**< �ز���ʼ��Χ [llClipIn, llClipOut) */
    __int64     llClipOut;                      /**< �ز���ʼ��Χ [llClipIn, llClipOut) */
};

struct TTTranscodeExSource
{
    enum 
    {
        MAX_AUDIO_CHANNEL = 16,
        MAX_FILE = MAX_AUDIO_CHANNEL+1,
        VIDEO_ID = 0,
    };

    TTFileTranItem*             arrVideoFileItem;
    int                         iVideoFileItemCount;
    TTFileTranItem*             arrAudioFileItem[MAX_AUDIO_CHANNEL];
    int                         iAudioFileItemCount[MAX_AUDIO_CHANNEL];
    int                         iFileItemChannelCount;
    TTMediaPlayerVideoFormat    stuVideoFormat;
    TTMediaPlayerAudioFormat    stuAudioFormat;
    double                      dbFrameRate;                        /**< ��ǰ�ز�֡�� */
    __int64                     llClipIn;                           /**< �ز���ʼ��Χ [llClipIn, llClipOut) */
    __int64                     llClipOut;                          /**< �ز���ʼ��Χ [llClipIn, llClipOut) */
    intptr_t                    reserved[16];
};

struct TTTranscodeExTarget
{
    enum
    {
        MAX_AUDIO_FILE_COUNT = 16,
    };
    wchar_t wszFilenameV[MAX_PATH];                                 /**< Ŀ���ļ��� */
    wchar_t wszFilenameA[MAX_AUDIO_FILE_COUNT][MAX_PATH];           /**< Ŀ���ļ��� */
    TTMPlayerCompileFormat ttCompileFormatV;                        /**< ��ƵĿ���ļ���ʽ������Ƶ��һ�ļ���ʽ */
    TTMPlayerCompileFormat ttCompileFormatA;                        /**< ��ƵĿ���ļ���ʽ������Ƶ��һ�������ֻ����ttCompileFormatV���� */
    int nAudioFileCount;                                            /**< Ŀ���ļ����� */

    enum TT_HDSD_COMPILE_MODE   eAdapMode;                          /**< �������� */
    enum TT_DEINTERLACE_MODE    eDeinterlaceType;                   /**< ���������� */
    enum TT_AUDIO_RESAMPLE_TYPE eAudioResampleMode;                 /**< ��Ƶ�ز������� */
    __int64     reserved[8];
};


/** ת����ƽӿ� */
struct ITTTranscodeEx
{
    virtual int Init(ITTNotify* pNotify) = 0;
    virtual int GetFunc(const GUID& iid, LPVOID* ppInterface) = 0;    
    virtual int SetFunc(const GUID& iid, LPVOID ppInterface) = 0;    
    virtual int SetSourceInfo(TTTranscodeExSource* arrSource, int iCount) = 0;
    virtual int SetOutputFile(TTTranscodeExTarget& ttTarget) = 0;
    virtual int Start(ISampleTransform* pMediaProc = NULL) = 0;
    virtual int Stop() = 0;
    virtual int GetProgress() = 0; /**< [0, 10000]*/
    virtual int Uninit() = 0;
    virtual int Destroy() = 0;
};

// -------------------------------------------------------------------------

#endif
