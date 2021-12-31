
#ifndef __def_media_info__header__
#define __def_media_info__header__

#define __STRING__IMPL(x)   #x
#define __STRING__(x)   __STRING__IMPL(x)
#define __DEF_FILE_POS__() __FILE__ "(" __STRING__(__LINE__)"):"
#define __FILE_AND_LINE__(act,msg)  __DEF_FILE_POS__()"*****************************************:"act": "msg 

#define TODO(msg) message("**********interface**********\nTODO:"__FILE__".__line__."__STRING__(__LINE__)":"#msg".")
#define _TODO_(msg) message(__FILE_AND_LINE__("TODO", msg))
#define _FIX_(msg) message(__FILE_AND_LINE__("FIX", msg))
#define _XXX_(msg) message(__FILE_AND_LINE__("XXX", msg))

#ifndef __WFILE__
#define WIDEN2(x) L ## x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#endif

#include <memory>
#include <string>
#include <vector>

#include "TTMediaPlayer/TTMediaPlayerExport.h"

#include <MMSystem.h>
#include <dsound.h>

#include "./TTMediaErrorCode.h"

enum eOPEN_FILE
{
    OPEN_Video = (1),       /**< 视频 */
    OPEN_Audio1 = (1<<1),    /**< 音频 */
    OPEN_Audio2 = (1<<2),    /**< 音频 */
    OPEN_Audio3 = (1<<3),    /**< 音频 */
    OPEN_Audio4 = (1<<4),    /**< 音频 */
    OPEN_Audio5 = (1<<5),    /**< 音频 */
    OPEN_Audio6 = (1<<6),    /**< 音频 */
    OPEN_Audio7 = (1<<7),    /**< 音频 */
    OPEN_Audio8 = (1<<8),    /**< 音频 */
    OPEN_Audio9 = (1<<9),    /**< 音频 */
    OPEN_Audio10 = (1<<10),    /**< 音频 */
    OPEN_Audio11 = (1<<11),    /**< 音频 */
    OPEN_Audio12 = (1<<12),    /**< 音频 */
    OPEN_Audio13 = (1<<13),    /**< 音频 */
    OPEN_Audio14 = (1<<14),    /**< 音频 */
    OPEN_Audio15 = (1<<15),    /**< 音频 */
    OPEN_Audio16 = (1<<16),    /**< 音频 */
    OPEN_Text  = (1<<27),    /**< 文本字幕 */
    OPEN_FOR_INFO = (1<<31),       /**< 取信息 */

    OPEN_VIDEO_ALL = (OPEN_Video),
    OPEN_AUDIO_ALL = (OPEN_Audio1|OPEN_Audio2|OPEN_Audio3|OPEN_Audio4
                    |OPEN_Audio5|OPEN_Audio6|OPEN_Audio7|OPEN_Audio8
                    |OPEN_Audio9|OPEN_Audio10|OPEN_Audio11|OPEN_Audio12
                    |OPEN_Audio13|OPEN_Audio14|OPEN_Audio15|OPEN_Audio16),
};

/** 获取音频索引 */
inline int TTMP_GetAudioChannelIndex(enum eOPEN_FILE eOpenFlag)
{
    int retval = TT_ERR_InvalidOpenMode;
    switch(eOpenFlag&OPEN_AUDIO_ALL)
    {
    case OPEN_Audio1: retval = 0; break;
    case OPEN_Audio2: retval = 1; break;
    case OPEN_Audio3: retval = 2; break;
    case OPEN_Audio4: retval = 3; break;
    case OPEN_Audio5: retval = 4; break;
    case OPEN_Audio6: retval = 5; break;
    case OPEN_Audio7: retval = 6; break;
    case OPEN_Audio8: retval = 7; break;
    case OPEN_Audio9: retval = 8; break;
    case OPEN_Audio10: retval = 9; break;
    case OPEN_Audio11: retval = 10; break;
    case OPEN_Audio12: retval = 11; break;
    case OPEN_Audio13: retval = 12; break;
    case OPEN_Audio14: retval = 13; break;
    case OPEN_Audio15: retval = 14; break;
    case OPEN_Audio16: retval = 15; break;
    }
    return retval;
}

enum eMEDIA_TYPE
{
    Type_Video,         /**< 视频 */
    Type_Audio,         /**< 音频 */
    Type_Text,          /**< 文本字幕 */
    Type_SubPicture,    /**< 图片字幕 */
};
enum eTTMP_FRAME_TYPE
{
    TTMP_FRAME_TYPE_None,
    TTMP_FRAME_TYPE_I,                      /**< i-frame */
    TTMP_FRAME_TYPE_P,                      /**< p-frame */
    TTMP_FRAME_TYPE_B,                      /**< b-frame */

    TTMP_FRAME_TYPE_Uncompressed = 100,     /**< uncompressed-frame */
};

enum eTTMP_SCANMODE_TYPE
{
    TTMP_FRAME_TYPE_Interlaced = 1,             /**< 奇场优先 */
    TTMP_FRAME_TYPE_Progressive,            /**< 帧 */
    TTMP_FRAME_TYPE_InterlacedBottomFirst,  /**< 偶场优先 */
};

struct TTMPlayerTimeBase
{
    int iRate;
    int iScale;
};

struct TTMPlayerFileFormat
{
    TTMediaPlayerFileFormat ttMediaPlayerFormat;
    TTMPlayerTimeBase       ttTimebase;             /**< fps=ttTimebase.iRate/(float)ttTimebase.iScale */
    __int64                 llTimeDuration;         /**< 持续时间，单位100ns, 1s=1000*1000*1000ns */
};

namespace scl
{
    typedef struct stu_TPVideoFormatDef
    {
        long					m_nFileFormatID;	//文件格式的ID(基础部定义)
        long					m_nMediaTypeID;		//媒体格式的ID(基础部定义)
        long					m_lImageWidth;		//素材画面宽
        long					m_lImageHeight;		//素材画面高
        long					m_lBitsPerPixel;	//每像素位数
        long					m_lPixelFormat;		//像素格式
        double					m_dbFrameRate;		//帧率 15,24,25,29.97,30
        long					m_lCompression;		//图像压缩方式
        long					m_lDataRate;		//码率
        long				    m_lScanMode;        //图像扫描模式
        long					m_lGopSize;			//GOP长度
        long					m_lBFrameCount;		//B帧个数
        long					m_lPFrameCount;		//P帧个数
    }TPVideoFormatDef,*LPTPVideoFormatDef;

    typedef struct stu_TPAudioFormatDef
    {
        long					m_nFileFormatID;	//文件格式的ID(基础部定义)
        long					m_nMediaTypeID;		//媒体格式的ID(基础部定义)
        long					m_lChannels;		//音频通道数
        long					m_lSamplesRate;		//音频采样率
        long					m_lBitsperSample;	//量化位数
    }TPAudioFormatDef,*LPTPAudioFormatDef;
}

struct TTMPlayerCompileFormat
{
    //TP_VIDEO_STANDARD emVideoStandard;
    DWORD emVideoStandard;
    BYTE bHasVideo;
    BYTE bHasAudio;
    scl::TPVideoFormatDef videoFormat;
    scl::TPAudioFormatDef audioFormat;
};

struct TTMPlayerVideoSample
{
    unsigned char*      pVideoData;
    int                 iVideoDataSize;
    eTTMP_FRAME_TYPE    eFrameType;
    TTPixelFormat       ePixelFormat;
    BITMAPINFOHEADER    bmpInfo;
    REFERENCE_TIME      llTiimeStart;
    REFERENCE_TIME      llTiimeDuration;

    void ResetData()
    {
        iVideoDataSize = 0;
        eFrameType = TTMP_FRAME_TYPE_None;
        ePixelFormat = TT_PIX_FMT_UNKNOWN;
        llTiimeStart = 0;
        llTiimeDuration = 0;
        memset(&bmpInfo, 0, sizeof(bmpInfo));
    }
};

struct TTMPlayerAudioSample
{
    unsigned char*      pAudioData;
    int                 iAudioDataSize;
    int                 iSampleCount;
    WAVEFORMATEX        wfxInfo;
    unsigned int        dwChannelClass;
    REFERENCE_TIME      llTiimeStart;
    REFERENCE_TIME      llTiimeDuration;

    void ResetData()
    {
        iAudioDataSize = 0;
        iSampleCount = 0;
        dwChannelClass = 0;
        llTiimeStart = 0;
        llTiimeDuration = 0;
        memset(&wfxInfo, 0, sizeof(wfxInfo));
    }
};

struct TTMPlayerSubSample
{
    unsigned char*      pVideoData;
    int                 iVideoDataSize;
    BITMAPINFOHEADER    bmpInfo;
    REFERENCE_TIME      llTiimeStart;
    REFERENCE_TIME      llTiimeDuration;
};

struct TTMPlayerSample
{
    struct TTMPlayerVideoSample video;
    struct TTMPlayerAudioSample audio;

    void ResetData()
    {
        video.iVideoDataSize = 0;
        video.eFrameType = TTMP_FRAME_TYPE_None;
        video.ePixelFormat = TT_PIX_FMT_UNKNOWN;
        video.llTiimeStart = 0;
        video.llTiimeDuration = 0;
        memset(&video.bmpInfo, 0, sizeof(video.bmpInfo));

        audio.iAudioDataSize = 0;
        audio.iSampleCount = 0;
        audio.dwChannelClass = 0;
        audio.llTiimeStart = 0;
        audio.llTiimeDuration = 0;
        memset(&audio.wfxInfo, 0, sizeof(audio.wfxInfo));
    }
};

struct ITTNotify
{
    enum eNOTIFY
    {
        NTF_Trace, /**< 跟踪信息 */
        NTF_Debug, /**< 调试信息 */
        NTF_Error, /**< 错误信息 */
    };
    virtual void ProcNotify(enum eNOTIFY emNtf, const wchar_t* lpszNotifyInfo, int iNotifyCode, int iIndent = 0)= 0;
};

template<int iLEVEL>
struct TTNotifyOutput : public ITTNotify
{
    static TTNotifyOutput& instance()
    {
        static TTNotifyOutput _self;
        return _self;
    }
    virtual void ProcNotify(enum eNOTIFY emNtf, const wchar_t* lpszNotifyInfo, int iNotifyCode, int iIndent = 0)
    {
        if (emNtf >= iLEVEL)
        {
            ::OutputDebugStringW(lpszNotifyInfo);
        }
    };
};

typedef TTNotifyOutput<ITTNotify::NTF_Trace> TTNotifyTraceOutput;
typedef TTNotifyOutput<ITTNotify::NTF_Debug> TTNotifyDebugOutput;
typedef TTNotifyOutput<ITTNotify::NTF_Error> TTNotifyErrorOutput;


#pragma deprecated(TTMPlayerSample)
#pragma deprecated(TTMPlayerSubSample)
#pragma deprecated(TTMPlayerVideoSample)
#pragma deprecated(TTMPlayerAudioSample)

#endif
