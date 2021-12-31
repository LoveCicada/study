
#ifndef __def_TTMediaTranscodeEx__header__
#define __def_TTMediaTranscodeEx__header__

#include "./TTMediaTranscodeBaseDef.hpp"
#include "./ITTMediaTranscode.hpp"

// -------------------------------------------------------------------------

struct TTFileTranItem
{
    const wchar_t* wszFilename;
    ULONGLONG       iMediaType;
    double      dbFrameRate;                    /**< 当前素材帧率 */
    __int64     llFileIn;                       /**< 文件起始范围 [llFileIn, llFileOut) */
    __int64     llFileOut;                      /**< 文件起始范围 [llFileIn, llFileOut) */
    __int64     llClipIn;                       /**< 素材起始范围 [llClipIn, llClipOut) */
    __int64     llClipOut;                      /**< 素材起始范围 [llClipIn, llClipOut) */
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
    double                      dbFrameRate;                        /**< 当前素材帧率 */
    __int64                     llClipIn;                           /**< 素材起始范围 [llClipIn, llClipOut) */
    __int64                     llClipOut;                          /**< 素材起始范围 [llClipIn, llClipOut) */
    intptr_t                    reserved[16];
};

struct TTTranscodeExTarget
{
    enum
    {
        MAX_AUDIO_FILE_COUNT = 16,
    };
    wchar_t wszFilenameV[MAX_PATH];                                 /**< 目标文件名 */
    wchar_t wszFilenameA[MAX_AUDIO_FILE_COUNT][MAX_PATH];           /**< 目标文件名 */
    TTMPlayerCompileFormat ttCompileFormatV;                        /**< 视频目标文件格式，音视频合一文件格式 */
    TTMPlayerCompileFormat ttCompileFormatA;                        /**< 音频目标文件格式，音视频合一的情况下只设置ttCompileFormatV即可 */
    int nAudioFileCount;                                            /**< 目标文件个数 */

    enum TT_HDSD_COMPILE_MODE   eAdapMode;                          /**< 适配类型 */
    enum TT_DEINTERLACE_MODE    eDeinterlaceType;                   /**< 反交错类型 */
    enum TT_AUDIO_RESAMPLE_TYPE eAudioResampleMode;                 /**< 音频重采样方法 */
    __int64     reserved[8];
};


/** 转码控制接口 */
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
