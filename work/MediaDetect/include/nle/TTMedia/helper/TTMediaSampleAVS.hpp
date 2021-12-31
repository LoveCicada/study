
#ifndef __def__media_sample_avs_impl__header__
#define __def__media_sample_avs_impl__header__

#include "./TTMediaLogMsghelper.hpp"
#include "../ITTMediaSampeAVS.hpp"

struct TTMPVideoSample : public ITTMPVideoSample
{
    enum
    {
        BUF_MAX_COUNT = 4,
        BUF_MAX_MASK = 3,
    };
    unsigned char*      arrData[BUF_MAX_COUNT];
    unsigned int        arrLinesize[BUF_MAX_COUNT];
    int                 iVideoDataSize;
    eTTMP_FRAME_TYPE    eFrameType;
    TTPixelFormat       ePxlFmt;
    BITMAPINFOHEADER    bmpInfo;
    REFERENCE_TIME      llTimeStart;
    REFERENCE_TIME      llTimeDuration;

    TTMPVideoSample()
    {
        ResetData();
    }
    virtual ~TTMPVideoSample()
    {

    }

    void ResetData()
    {
        iVideoDataSize = 0;
        eFrameType = TTMP_FRAME_TYPE_None;
        ePxlFmt = TT_PIX_FMT_UNKNOWN;
        llTimeStart = 0;
        llTimeDuration = 0;
        memset(&bmpInfo, 0, sizeof(bmpInfo));
        memset(&arrData, 0, sizeof(arrData));
        memset(&arrLinesize, 0, sizeof(arrLinesize));
    }
    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return arrData[idx&0x3];
    }
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return arrLinesize[idx&0x3];
    }
    virtual TTPixelFormat PixelFormat()
    {
        return ePxlFmt;
    }
    virtual BITMAPINFOHEADER& ImageInfo()
    {
        return bmpInfo;
    }
    virtual eTTMP_FRAME_TYPE FrameType()
    {
        return eFrameType;
    }    
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)
    {
        llStart = llTimeStart;
        llDuration = llTimeDuration;
        return ERR_Success;
    }
    virtual int AddRef()
    {
        return 0;
    }
    virtual int Release()
    {
        delete this;
        return 0;
    }

    virtual int FillData(ITTMPVideoSamplePtr pSample)
    {
        for (int i = 0; i < _countof(arrData); ++i)
        {
            arrData[i] = pSample->Data((TTMP_BUF_IDX)(TTMP_BUF+i));
            arrLinesize[i] = pSample->LineSize((TTMP_BUF_IDX)(TTMP_BUF+i));
        }

        ePxlFmt = pSample->PixelFormat();
        bmpInfo = pSample->ImageInfo();
        eFrameType = pSample->FrameType();
        pSample->Times(llTimeStart, llTimeDuration);
        return 0;
    }
};

struct TTMPAudioSample : public ITTMPAudioSample
{
    enum
    {
        BUF_MAX_COUNT = 16,
        BUF_MAX_MASK = 0xf,
    };
    unsigned char*      arrData[BUF_MAX_COUNT];
    unsigned int        arrLinesize[BUF_MAX_COUNT];
    int                 iSampleCount;
    WAVEFORMATEX        wfxInfo;
    TTMP_AUDIO_BUF_TYPE eAudioBufferType;
    REFERENCE_TIME      llTimeStart;
    REFERENCE_TIME      llTimeDuration;

    TTMPAudioSample()
    {
        ResetData();
    }

    virtual ~TTMPAudioSample()
    {

    }

    void ResetData()
    {
        eAudioBufferType = TTMP_AUDIO_BUF_TYPE_normal;
        iSampleCount = 0;
        llTimeStart = 0;
        llTimeDuration = 0;
        memset(&wfxInfo, 0, sizeof(wfxInfo));
        memset(&arrData, 0, sizeof(arrData));
        memset(&arrLinesize, 0, sizeof(arrLinesize));
    }

    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return arrData[idx&BUF_MAX_MASK];
    }
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return arrLinesize[idx&BUF_MAX_MASK];
    }
    virtual int SampleCount()
    {
        return iSampleCount;
    }
    virtual WAVEFORMATEX& AudioInfo()
    {
        return wfxInfo;
    }
    virtual TTMP_AUDIO_BUF_TYPE BufferType()
    {
        return eAudioBufferType;
    }
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)
    {
        llStart = llTimeStart;
        llDuration = llTimeDuration;
        return 0;
    }
    virtual int AddRef()
    {
        return 0;
    }
    virtual int Release()
    {
        delete this;
        return 0;
    }
    virtual int FillData(ITTMPAudioSamplePtr pSample)
    {
        for (int i = 0; i < _countof(arrData); ++i)
        {
            arrData[i] = pSample->Data((TTMP_BUF_IDX)(TTMP_BUF+i));
            arrLinesize[i] = pSample->LineSize((TTMP_BUF_IDX)(TTMP_BUF+i));
        }

        wfxInfo = pSample->AudioInfo();
        iSampleCount = pSample->SampleCount();
        eAudioBufferType = pSample->BufferType();
        pSample->Times(llTimeStart, llTimeDuration);
        return ERR_Success;
    }
};

struct TTMPSubSample: public ITTMPSubSample
{
    unsigned char*      pVideoData;
    int                 iVideoDataSize;
    BITMAPINFOHEADER    bmpInfo;
    REFERENCE_TIME      llTimeStart;
    REFERENCE_TIME      llTimeDuration;

    TTMPSubSample()
    {
    }

    virtual ~TTMPSubSample()
    {

    }

    virtual unsigned char* Data(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return pVideoData;
    }
    virtual int LineSize(TTMP_BUF_IDX idx = TTMP_BUF)
    {
        return iVideoDataSize;
    }
    virtual BITMAPINFOHEADER& ImageInfo()
    {
        return bmpInfo;
    }
    virtual int Times(REFERENCE_TIME& llStart, REFERENCE_TIME& llDuration)
    {
        llStart = llTimeStart;
        llDuration = llTimeDuration;
    }
    virtual int AddRef()
    {
        return 0;
    }
    virtual int Release()
    {
        delete this;
        return 0;
    }
    virtual int FillData(ITTMPSubSamplePtr pSample)
    {
        pVideoData = pSample->Data();
        iVideoDataSize = pSample->LineSize();
        bmpInfo = pSample->ImageInfo();
        pSample->Times(llTimeStart, llTimeDuration);
        return ERR_Success;
    }
};


// ---------------------------------------------------------------------------------

inline void add_cas(LONG volatile* target, int valude)
{
    while (true)
    {
        LONG lOldValue = *target;
        if (lOldValue  == InterlockedCompareExchange(target, lOldValue + valude, lOldValue))
        {
            break;
        }
    }
}

inline void tp_atom_add(LONG volatile* target, int valude)
{
#ifdef InterlockedAdd
    InterlockedAdd(target, valude);
#else
    add_cas(target, valude);
#endif
}

template <typename TSample>
struct /*__declspec(novtable)*/ RefSampleIH: TSample
{
    volatile long iRefCount;
    RefSampleIH():iRefCount(1){}
    virtual ~RefSampleIH(){}
    virtual int AddRef()
    {
        tp_atom_add(&iRefCount, 1);
        return iRefCount;
    }
    virtual int Release()
    {
        tp_atom_add(&iRefCount, -1);
        const int refcount = iRefCount;
        if (refcount <= 0)
            delete this;
        return refcount;
    }
};

typedef RefSampleIH<TTMPVideoSample> TTMPVideoSampleRef; 
typedef RefSampleIH<TTMPAudioSample> TTMPAudioSampleRef; 
typedef RefSampleIH<TTMPSubSample>   TTMPSubSampleRef; 

#endif
