
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
    OPEN_Video = (1),       /**< ��Ƶ */
    OPEN_Audio1 = (1<<1),    /**< ��Ƶ */
    OPEN_Audio2 = (1<<2),    /**< ��Ƶ */
    OPEN_Audio3 = (1<<3),    /**< ��Ƶ */
    OPEN_Audio4 = (1<<4),    /**< ��Ƶ */
    OPEN_Audio5 = (1<<5),    /**< ��Ƶ */
    OPEN_Audio6 = (1<<6),    /**< ��Ƶ */
    OPEN_Audio7 = (1<<7),    /**< ��Ƶ */
    OPEN_Audio8 = (1<<8),    /**< ��Ƶ */
    OPEN_Audio9 = (1<<9),    /**< ��Ƶ */
    OPEN_Audio10 = (1<<10),    /**< ��Ƶ */
    OPEN_Audio11 = (1<<11),    /**< ��Ƶ */
    OPEN_Audio12 = (1<<12),    /**< ��Ƶ */
    OPEN_Audio13 = (1<<13),    /**< ��Ƶ */
    OPEN_Audio14 = (1<<14),    /**< ��Ƶ */
    OPEN_Audio15 = (1<<15),    /**< ��Ƶ */
    OPEN_Audio16 = (1<<16),    /**< ��Ƶ */
    OPEN_Text  = (1<<27),    /**< �ı���Ļ */
    OPEN_FOR_INFO = (1<<31),       /**< ȡ��Ϣ */

    OPEN_VIDEO_ALL = (OPEN_Video),
    OPEN_AUDIO_ALL = (OPEN_Audio1|OPEN_Audio2|OPEN_Audio3|OPEN_Audio4
                    |OPEN_Audio5|OPEN_Audio6|OPEN_Audio7|OPEN_Audio8
                    |OPEN_Audio9|OPEN_Audio10|OPEN_Audio11|OPEN_Audio12
                    |OPEN_Audio13|OPEN_Audio14|OPEN_Audio15|OPEN_Audio16),
};

/** ��ȡ��Ƶ���� */
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
    Type_Video,         /**< ��Ƶ */
    Type_Audio,         /**< ��Ƶ */
    Type_Text,          /**< �ı���Ļ */
    Type_SubPicture,    /**< ͼƬ��Ļ */
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
    TTMP_FRAME_TYPE_Interlaced = 1,             /**< �泡���� */
    TTMP_FRAME_TYPE_Progressive,            /**< ֡ */
    TTMP_FRAME_TYPE_InterlacedBottomFirst,  /**< ż������ */
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
    __int64                 llTimeDuration;         /**< ����ʱ�䣬��λ100ns, 1s=1000*1000*1000ns */
};

namespace scl
{
    typedef struct stu_TPVideoFormatDef
    {
        long					m_nFileFormatID;	//�ļ���ʽ��ID(����������)
        long					m_nMediaTypeID;		//ý���ʽ��ID(����������)
        long					m_lImageWidth;		//�زĻ����
        long					m_lImageHeight;		//�زĻ����
        long					m_lBitsPerPixel;	//ÿ����λ��
        long					m_lPixelFormat;		//���ظ�ʽ
        double					m_dbFrameRate;		//֡�� 15,24,25,29.97,30
        long					m_lCompression;		//ͼ��ѹ����ʽ
        long					m_lDataRate;		//����
        long				    m_lScanMode;        //ͼ��ɨ��ģʽ
        long					m_lGopSize;			//GOP����
        long					m_lBFrameCount;		//B֡����
        long					m_lPFrameCount;		//P֡����
    }TPVideoFormatDef,*LPTPVideoFormatDef;

    typedef struct stu_TPAudioFormatDef
    {
        long					m_nFileFormatID;	//�ļ���ʽ��ID(����������)
        long					m_nMediaTypeID;		//ý���ʽ��ID(����������)
        long					m_lChannels;		//��Ƶͨ����
        long					m_lSamplesRate;		//��Ƶ������
        long					m_lBitsperSample;	//����λ��
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
        NTF_Trace, /**< ������Ϣ */
        NTF_Debug, /**< ������Ϣ */
        NTF_Error, /**< ������Ϣ */
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
