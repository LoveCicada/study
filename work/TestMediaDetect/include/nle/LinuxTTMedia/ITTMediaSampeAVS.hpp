
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

/** ��Ƶsample��ŷ�ʽ */
enum TTMP_AUDIO_BUF_TYPE
{
    /**
    ��ͨ��Ƶsample��ŷ�ʽ��ch1|ch2|ch3|ch4| ch1|ch2|ch3|ch4| ch1|ch2|ch3|ch4
    */
    TTMP_AUDIO_BUF_TYPE_normal,
    /**
    ƽ�淽ʽ�����Ƶsample,ÿ��channel�ڵ�����planner��ch1|ch1|ch1|ch1| ch2|ch2|ch2|ch2| ch3|ch3|ch3|ch3| ch4|ch4|ch4|ch4
    */
    TTMP_AUDIO_BUF_TYPE_planer,
};

typedef struct ITTMPVideoSample*    ITTMPVideoSamplePtr;
typedef struct ITTMPAudioSample*    ITTMPAudioSamplePtr;
typedef struct ITTMPSubSample*      ITTMPSubSamplePtr;


//---------------------------------------------------------------------------------------

/** ��Ƶsample */
struct ITTMPVideoSample
{
    /**
    ��ȡidx��Ӧ��������Ƶ����
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡidx��Ӧ�������п�in BYTES
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡSample����ɫ�ռ�����
    */
    virtual TTPixelFormat PixelFormat() = 0;

    /**
    ��ȡ��Ƶ�Ŀ����Ϣ
    @note BITMAPINFOHEADER��߻Ậ�г�֡��Ϣ��ͨ��TTMP_SetScanMode���ã�TTMP_GetScanMode��ȡ
    @see \TTMedia\helper\TTMediaSampleUtility.hpp
    */
    virtual BITMAPINFOHEADER& ImageInfo() = 0;

    /** ֡����, Ϊѹ������Ԥ�� */
    virtual eTTMP_FRAME_TYPE FrameType() = 0;

    /**
    ��ȡsample��ʱ����Ϣ
    @param llStart ��ʼʱ��
    @param llDuraion ����ʱ��
    @reutrn <0 ʧ�ܣ�>=0 �ɹ�
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** �������ü��� */
    virtual int AddRef() = 0;   /**< ��ʱ��֧�����ü��� */

    /** �������ü���������<=0ʱ������sample */
    virtual int Release() = 0;
};


//---------------------------------------------------------------------------------------

/** ��Ƶsample */
struct ITTMPAudioSample
{
    /**
    ��ȡ����Ƶ���ݣ�ͨ��idxָ��buffer
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡ��Ƶidx��Ӧ��buffer��С
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡ��Ƶsample����
    */
    virtual int SampleCount() = 0;

    /**
    ��ȡ��Ƶsample��Ϣ
    */
    virtual WAVEFORMATEX& AudioInfo() = 0;

    /**
    ��Ƶsmaple�������, Ŀǰ��֧��TTMP_AUDIO_BUF_TYPE_normal
    @see TTMP_AUDIO_BUF_TYPE
    */
    virtual TTMP_AUDIO_BUF_TYPE BufferType() = 0;

    /**
    ��ȡsample��ʱ����Ϣ
    @param llStart ��ʼʱ��
    @param llDuraion ����ʱ��
    @reutrn <0 ʧ�ܣ�>=0 �ɹ�
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** �������ü��� */
    virtual int AddRef() = 0;   /**< ��ʱ��֧�����ü��� */

    /** �������ü���������<=0ʱ������sample */
    virtual int Release() = 0;
};


//---------------------------------------------------------------------------------------

/** ��Ļsample, Ŀǰ��֧�� */
struct ITTMPSubSample
{
    /**
    ��ȡ��ĻͼƬ������
    */
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡ��ĻͼƬ���п�
    */
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF) = 0;

    /**
    ��ȡ��ĻͼƬ�Ŀ����Ϣ
    */
    virtual BITMAPINFOHEADER& ImageInfo() = 0;

    /**
    ��ȡsample��ʱ����Ϣ
    @param llStart ��ʼʱ��
    @param llDuraion ����ʱ��
    @reutrn <0 ʧ�ܣ�>=0 �ɹ�
    */
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)  = 0;

    /** �������ü��� */
    virtual int AddRef() = 0;   /**< ��ʱ��֧�����ü��� */

    /** �������ü���������<=0ʱ������sample */
    virtual int Release() = 0;
};

#endif
