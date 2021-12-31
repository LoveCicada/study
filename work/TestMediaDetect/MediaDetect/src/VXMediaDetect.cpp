


#include "VXMediaDetect.h"
#include "VXMediaDetectHelper.h"
#include <atomic>
#include <mutex>
#include <memory>
#include <vector>
/*****************************************Windows*********************************************/

//use for load library once
static std::once_flag g_onceFlag;
static std::atomic_bool g_bValid;

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool IsValid();

/**
 * @brief 
 * 
 * @return bool 
 */
bool CheckValid();

bool IsValid()
{   
    bool bRet = true;
    std::call_once(g_onceFlag, CheckValid);
    return g_bValid.load();
}


#if WINDOWS_SYS

/**
 * @brief Windows media Dectect
 * 
 */
class CVXWinMediaDectect : public IVXMediaDectect
{
public:
    CVXWinMediaDectect();
    virtual ~CVXWinMediaDectect() override;
    virtual int Init() override;
    virtual int UnInit() override;

    virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) override;
    virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) override;
    virtual int ConvertToNovaInfo() override;
    virtual int ConvertMpcInfo() override; 

private:

};

CVXWinMediaDectect::CVXWinMediaDectect()
{
    std::cout << " create CVXWinMediaDectect instace " << std::endl;
}

int CVXWinMediaDectect::Init()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXWinMediaDectect::UnInit()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXWinMediaDectect::GetMediaInfo(const char *cFileName, int nDetectMode)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXWinMediaDectect::GetMediaInfo(const std::string& str, int nDetectMode)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}


int CVXWinMediaDectect::ConvertToNovaInfo()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXWinMediaDectect::ConvertMpcInfo()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}


#else

/*****************************************Linux*********************************************/

bool CheckValid()
{
    g_bValid.store(false);
    bool bRet = true;

    /*
    * load library
    */


    g_bValid.store(true);
    
    return bRet;
}


/**
 * @brief Linux media Dectect
 * 
 */
class CVXLinuxMediaDectect : public IVXMediaDectect
{
public:
    
    CVXLinuxMediaDectect();
    virtual ~CVXLinuxMediaDectect() override;
    virtual int Init() override;
    virtual int UnInit() override;

    virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) override;
    virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) override;
    virtual int ConvertToNovaInfo() override;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo) override;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2) override;
    virtual int ConvertMpcInfo() override;

public:
    SDKVideoStreamInfoVec&  GetVideoStreamInfoVec()  const override;
    SDKAudioStreamInfoVec&  GetAudioStreamInfoVec()  const override;
    SDKSystemStreamInfoVec& GetSystemStreamInfoVec() const override;
    SDKDataStreamInfoVec&   GetDataStreamInfoVec()   const override;

    int GetVideoStreamNum()  const override;
    int GetAudioStreamNum()  const override;
    int GetSystemStreamNum() const override;
    int GetDataStreamNum()   const override;

private:
    std::shared_ptr<VXSDKMediaDetect>       m_pSdkMediaDetect;
    std::shared_ptr<VXSDKMediaInfo>         m_pSdkMediaInfo;  
    std::shared_ptr<stVXSDKFileMediaInfo>   m_pSdkFileMediaInfo;

    int m_videoStreamNum;
    int m_audioStreamNum;
    int m_systemStreamNum;
    int m_dataStreamNum;

    SDKVideoStreamInfoVec   m_videoStreamInfoVec;
    SDKAudioStreamInfoVec   m_audioStreamInfoVec;
    SDKSystemStreamInfoVec  m_systemStreamInfoVec;
    SDKDataStreamInfoVec    m_dataStreamInfoVec;

};

CVXLinuxMediaDectect::CVXLinuxMediaDectect()
{
    std::cout << " create CVXLinuxMediaDectect instace " << std::endl;
    m_pSdkMediaDetect.reset(new VXSDKMediaDetect);
    m_pSdkMediaInfo.reset(new VXSDKMediaInfo);
}

int CVXLinuxMediaDectect::Init()
{
    ErrorCode ec = ErrorCode::Success;
    
    

    int nCode = GetErrorCode(ec);
    return nCode;
}

int CVXLinuxMediaDectect::UnInit()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    

    return nCode;
}

int CVXLinuxMediaDectect::GetMediaInfo(const char *cFileName, int nDetectMode)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = 0;
    int nSdkError = m_pSdkMediaDetect->SetInputFile(cFileName, nDetectMode);
    if(nSdkError<0)
    {
        ec = ErrorCode::SetInputFileFail;
        nCode = GetErrorCode(ec);
        return nCode;
    }

    nSdkError = m_pSdkMediaDetect->GetMediaInfo(m_pSdkMediaInfo.get());
    if(nSdkError<0)
    {
        ec = ErrorCode::GetMediaInfoFail;
        nCode = GetErrorCode(ec);
        return nCode;
    }

    // file detail
    auto sdkFileMediaInfo = m_pSdkMediaInfo->FileMediaInfo();
    /*
    * manual deep copy
    * sDKFileMediaInfo -> pSDKFileMediaInfo
    */
    auto bCopyFileMediaInfo = CopySDKFileMediaInfo(sdkFileMediaInfo, *m_pSdkFileMediaInfo);
    if(!bCopyFileMediaInfo)
    {
        ec = ErrorCode::CopySDKFileMediaInfoFail;
        nCode = GetErrorCode(ec);
        return nCode;
    }

    m_videoStreamNum    = m_pSdkMediaInfo->VideoStreamNum();
    m_audioStreamNum    = m_pSdkMediaInfo->AudioStreamNum();
    m_systemStreamNum   = m_pSdkMediaInfo->SystemStreamNum();
    m_dataStreamNum     = m_pSdkMediaInfo->DataStreamNum();

    // video detail
    for (int i=0; i<m_videoStreamNum; ++i)
    {
        stVXSDKVideoStreamInfo vsInfo = m_pSdkMediaInfo->VideoMediaInfo(i);
        //whether need deep copy?
        m_videoStreamInfoVec.push_back(vsInfo);
    }
    
    // audio detail
    for (int i=0; i<m_audioStreamNum; ++i)
    {
        stVXSDKAudioStreamInfo asInfo = m_pSdkMediaInfo->AudioMediaInfo(i);
        //whether need deep copy?
        m_audioStreamInfoVec.push_back(asInfo);
    }

    // system detail
    for (int i=0; i<m_systemStreamNum; ++i)
    {
        stVXSDKSystemStreamInfo systemInfo = m_pSdkMediaInfo->SystemMediaInfo(i);
        //whether need deep copy?
        m_systemStreamInfoVec.push_back(systemInfo);
    }

    // data detail
    for (int i=0; i<m_dataStreamNum; ++i)
    {
        stVXSDKDataStreamInfo dataMediaInfo = m_pSdkMediaInfo->DataMediaInfo(i);
        //whether need deep copy?
        m_dataStreamInfoVec.push_back(dataMediaInfo);
    }

    nCode = GetErrorCode(ec);
    return nCode;
}

int CVXLinuxMediaDectect::GetMediaInfo(const std::string& str, int nDetectMode)
{

    int nCode = GetMediaInfo(str.c_str(), nDetectMode);

    return nCode;
}

int CVXLinuxMediaDectect::ConvertToNovaInfo()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXLinuxMediaDectect::ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    bool bRet = true;
    // 1.
    const stVXSDKFileMediaInfo& src = *m_pSdkFileMediaInfo;
    bRet = SDKFileMediaInfo2TTMediaInfo(src, mediaInfo);

    // 2.
    {
        // TTMediaInfo currently record first video stream info
        if(!m_videoStreamInfoVec.empty())
        {
            const stVXSDKVideoStreamInfo& src = m_videoStreamInfoVec.at(0);
            bRet = SDKVideoStreamInfo2TTMediaInfo(src, mediaInfo);
        }
    }
    
    // 3.
    {
        // TTMediaInfo currently record first audio stream info
        if(!m_audioStreamInfoVec.empty())
        {
            const stVXSDKAudioStreamInfo& src = m_audioStreamInfoVec.at(0);
            bRet = SDKAudioStreamInfo2TTMediaInfo(src, mediaInfo);
        }
    }

    // 4.
    {
        const stVXSDKFileMediaInfo& fileInfo = *m_pSdkMediaInfo;

        stVXSDKVideoStreamInfo videoInfoTmp;
        stVXSDKAudioStreamInfo audioInfoTmp;

        // TTMediaInfo currently record first video stream info
        if(!m_videoStreamInfoVec.empty())
        {
            const stVXSDKVideoStreamInfo& src = m_videoStreamInfoVec.at(0);
            videoInfoTmp.nMediaID = src.nMediaID;
            videoInfoTmp.nVideoFormat = src.nVideoFormat;
        }

        // TTMediaInfo currently record first audio stream info
        if(!m_audioStreamInfoVec.empty())
        {
            const stVXSDKAudioStreamInfo& src = m_audioStreamInfoVec.at(0);
            audioInfoTmp.nMediaID = src.nMediaID;
        }

        bRet = SDKMediaInfo2NovaFcc(fileInfo, videoInfoTmp, audioInfoTmp, mediaInfo);
    }


    // 5.
    {

        
    }
    

    return nCode;
}

int CVXLinuxMediaDectect::ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXLinuxMediaDectect::ConvertMpcInfo()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

#endif

/**/

/**
 * @brief Create a Media Dectect object
 * 
 * @return IVXMediaDectect* 
 */
IVXMediaDectect* CreateMediaDectect()
{
    IVXMediaDectect* pfnMediaDetect = nullptr;

#if WINDOWS_SYS
    pfnMediaDetect = new CVXWinMediaDectect();

#else
    pfnMediaDetect = new CVXLinuxMediaDectect();

#endif

    return pfnMediaDetect;
}