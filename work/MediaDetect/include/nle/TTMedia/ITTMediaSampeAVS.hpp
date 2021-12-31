
#ifndef __def_media_source_samples__header__
#define __def_media_source_samples__header__

#include "./TTMediaReaderBaseDef.hpp"

/** Buffer index type */
enum TTMP_BUF_IDX
{
    TTMP_BUF,               /**< video buffer index*/
    TTMP_BUF_Y = TTMP_BUF,  /**< video buffer, Y index*/
    TTMP_BUF_U,             /**< video buffer, U index*/
    TTMP_BUF_V,             /**< video buffer, V index*/
    TTMP_BUF_A,             /**< video buffer, A index*/

    TTMP_BUF_CH_0 = TTMP_BUF,   /**< audio buffer index*/
    TTMP_BUF_CH_1,              /**< audio buffer index in channels*/
    TTMP_BUF_CH_2,
    TTMP_BUF_CH_3,
    TTMP_BUF_CH_4,
    TTMP_BUF_CH_5,
    TTMP_BUF_CH_6,
    TTMP_BUF_CH_7,
    TTMP_BUF_CH_8,
    TTMP_BUF_CH_9,
    TTMP_BUF_CH_10,
    TTMP_BUF_CH_11,
    TTMP_BUF_CH_12,
    TTMP_BUF_CH_13,
    TTMP_BUF_CH_14,
    TTMP_BUF_CH_15,
};

/** 音频sample存放方式 */
enum TTMP_AUDIO_BUF_TYPE
{
    /**
    普通音频sample存放方式，ch1|ch2|ch3|ch4| ch1|ch2|ch3|ch4| ch1|ch2|ch3|ch4
    */
    TTMP_AUDIO_BUF_TYPE_normal,
    /**
    平面方式存放音频sample,每个channel在单独的planner，ch1|ch1|ch1|ch1| ch2|ch2|ch2|ch2| ch3|ch3|ch3|ch3| ch4|ch4|ch4|ch4
    */
    TTMP_AUDIO_BUF_TYPE_planer,
};

typedef struct ITTMPVideoSample*    ITTMPVideoSamplePtr;
typedef struct ITTMPAudioSample*    ITTMPAudioSamplePtr;
typedef struct ITTMPSubSample*      ITTMPSubSamplePtr;


//---------------------------------------------------------------------------------------

/** 视频sample */
struct ITTMPVideoSample
{
    /**
    获取idx对应分量的视频数据
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取idx对应分量的行宽，in BYTES
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取Sample的颜色空间类型
    */
    virtual TTPixelFormat PixelFormat() = 0;

    /**
    获取视频的宽高信息
    @note BITMAPINFOHEADER里边会含有场帧信息，通过TTMP_SetScanMode设置，TTMP_GetScanMode获取
    @see \TTMedia\helper\TTMediaSampleUtility.hpp
    */
    virtual BITMAPINFOHEADER& ImageInfo() = 0;

    /** 帧类型, 为压缩数据预留 */
    virtual eTTMP_FRAME_TYPE FrameType() = 0;

    /**
    获取sample的时间信息
    @param llStart 起始时间
    @param llDuraion 持续时间
    @reutrn <0 失败，>=0 成功
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** 增加引用计数 */
    virtual int AddRef() = 0;   /**< 暂时不支持引用计数 */

    /** 减少引用计数，计数<=0时，销毁sample */
    virtual int Release() = 0;
};


//---------------------------------------------------------------------------------------

/** 音频sample */
struct ITTMPAudioSample
{
    /**
    获取字音频数据，通过idx指定buffer
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取音频idx对应的buffer大小
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取音频sample数量
    */
    virtual int SampleCount() = 0;

    /**
    获取音频sample信息
    */
    virtual WAVEFORMATEX& AudioInfo() = 0;

    /**
    音频smaple存放类型, 目前仅支持TTMP_AUDIO_BUF_TYPE_normal
    @see TTMP_AUDIO_BUF_TYPE
    */
    virtual TTMP_AUDIO_BUF_TYPE BufferType() = 0;

    /**
    获取sample的时间信息
    @param llStart 起始时间
    @param llDuraion 持续时间
    @reutrn <0 失败，>=0 成功
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** 增加引用计数 */
    virtual int AddRef() = 0;   /**< 暂时不支持引用计数 */

    /** 减少引用计数，计数<=0时，销毁sample */
    virtual int Release() = 0;
};


//---------------------------------------------------------------------------------------

/** 字幕sample, 目前不支持 */
struct ITTMPSubSample
{
    /**
    获取字幕图片的数据
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取字幕图片的行宽
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    获取字幕图片的宽高信息
    */
    virtual BITMAPINFOHEADER& ImageInfo() = 0;

    /**
    获取sample的时间信息
    @param llStart 起始时间
    @param llDuraion 持续时间
    @reutrn <0 失败，>=0 成功
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** 增加引用计数 */
    virtual int AddRef() = 0;   /**< 暂时不支持引用计数 */

    /** 减少引用计数，计数<=0时，销毁sample */
    virtual int Release() = 0;
};

#endif
