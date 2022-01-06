


#include "../../include/iface/VXMediaDetect.h"
#include "VXMediaDetectHelper.h"
#include <atomic>
#include <mutex>
#include <memory>
#include <vector>


#define LOG(info)   do {                                                                    \
        LogFormat(m_pErrorLog, m_pUser, m_logLevel, info, __FILE__, __func__, __LINE__);    \
    } while(0);

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

bool IsValid()
{   
    bool bRet = true;
    std::call_once(g_onceFlag, CheckValid);
    return g_bValid.load();
}


void LogFormat(pfnLog pLog, void* pUser, int logLevel, std::string info,
                const char * codePath, const char* funName, int codeLine)
{
    if(pLog)
    {
        std::string s1 = codePath;
        std::string s2 = funName;
        std::string s3 = std::to_string(codeLine); 
        std::string ss = "| " + s1 + " " + s2 + " " + s3 + " | "; 
        std::string str = ss + info + "\n"; 
        pLog(pUser, str, logLevel);
    }
}

/*****************************************Windows*********************************************/

#ifdef _MSC_VER

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


/**
 * @brief Linux media Dectect
 * 
 */
class __attribute ((visibility("default"))) CVXLinuxMediaDetect : public IVXMediaDectect
{
public:
    
    CVXLinuxMediaDetect();
    virtual ~CVXLinuxMediaDetect() override;
    virtual int Init() override;
    virtual int UnInit() override;

    virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) override;
    virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) override;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo) override;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2) override;
    virtual int ConvertMpcInfo() override;

public:

    SDKVideoStreamInfoVec&  GetVideoStreamInfoVec()  override;
    SDKAudioStreamInfoVec&  GetAudioStreamInfoVec()  override;
    SDKSystemStreamInfoVec& GetSystemStreamInfoVec() override;
    SDKDataStreamInfoVec&   GetDataStreamInfoVec()   override;

    int GetVideoStreamNum()  override;
    int GetAudioStreamNum()  override;
    int GetSystemStreamNum() override;
    int GetDataStreamNum()   override;

    void SetLogCb(pfnLog logCb, void* pUser, int logLevel) override;

protected:

    bool Reset();

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

    // log callback
    pfnLog m_pErrorLog;
    void* m_pUser;
    int m_logLevel;
};

CVXLinuxMediaDetect::CVXLinuxMediaDetect()
{
    std::cout << " create CVXLinuxMediaDetect instance " << std::endl;
    Reset();
    m_pErrorLog = nullptr;
    m_pUser = nullptr;
    m_logLevel = 0;
}

bool CVXLinuxMediaDetect::Reset()
{
    bool bRet = true;

    m_pSdkMediaDetect.reset(new VXSDKMediaDetect);
    m_pSdkMediaInfo.reset(new VXSDKMediaInfo);
    m_pSdkFileMediaInfo.reset(new stVXSDKFileMediaInfo);

    m_videoStreamNum    = 0;
    m_audioStreamNum    = 0;
    m_systemStreamNum   = 0;
    m_dataStreamNum     = 0;

    m_videoStreamInfoVec.clear();
    m_audioStreamInfoVec.clear();
    m_systemStreamInfoVec.clear();
    m_dataStreamInfoVec.clear();

    return bRet;
}

CVXLinuxMediaDetect::~CVXLinuxMediaDetect()
{
    std::cout << " delete CVXLinuxMediaDetect instance " << std::endl;
    
}

int CVXLinuxMediaDetect::Init()
{
    ErrorCode ec = ErrorCode::Success;
    
    std::cout << " load lib success " << std::endl;

    int nCode = GetErrorCode(ec);
    return nCode;
}

int CVXLinuxMediaDetect::UnInit()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    

    return nCode;
}

int CVXLinuxMediaDetect::GetMediaInfo(const char *cFileName, int nDetectMode)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = 0;

    bool bReset = Reset();
    if(!bReset)
    {
        ec = ErrorCode::ResetFail;
        nCode = GetErrorCode(ec);
        return nCode;
    }

    int nSdkError = m_pSdkMediaDetect->SetInputFile(cFileName, nDetectMode);
    if(nSdkError<0)
    {
        LOG("SetInputFile fail");

        ec = ErrorCode::SetInputFileFail;
        nCode = GetErrorCode(ec);
        return nCode;
    }

    nSdkError = m_pSdkMediaDetect->GetMediaInfo(m_pSdkMediaInfo.get());
    if(nSdkError<0)
    {
        LOG("GetMediaInfo fail");

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
        LOG("CopySDKFileMediaInfo fail");

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

int CVXLinuxMediaDetect::GetMediaInfo(const std::string& str, int nDetectMode)
{

    int nCode = GetMediaInfo(str.c_str(), nDetectMode);

    return nCode;
}

int CVXLinuxMediaDetect::ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    memset(&mediaInfo, 0, sizeof(mediaInfo));
    bool bRet = true;
    // 1.
    const stVXSDKFileMediaInfo& src = *m_pSdkFileMediaInfo;
    bRet = SDKFileMediaInfo2TTMediaInfo(src, mediaInfo);

    if(!bRet)
    {
        LOG("SDKFileMediaInfo2TTMediaInfo");
    }

    // 2.
    {
        // TTMediaInfo currently record first video stream info
        if(!m_videoStreamInfoVec.empty())
        {
            const stVXSDKVideoStreamInfo& src = m_videoStreamInfoVec.at(0);
            bRet = SDKVideoStreamInfo2TTMediaInfo(src, mediaInfo);
            if(!bRet)
            {
                LOG("SDKVideoStreamInfo2TTMediaInfo");
            }
        }
    }
    
    // 3.
    {
        // TTMediaInfo currently record first audio stream info
        if(!m_audioStreamInfoVec.empty())
        {
            const stVXSDKAudioStreamInfo& src = m_audioStreamInfoVec.at(0);
            bRet = SDKAudioStreamInfo2TTMediaInfo(src, mediaInfo);
            if(!bRet)
            {
                LOG("SDKAudioStreamInfo2TTMediaInfo");
            }
        }
    }

    // 4.
    {
        const stVXSDKFileMediaInfo& fileInfo = *m_pSdkFileMediaInfo;

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
        if(!bRet)
        {
            LOG("SDKMediaInfo2NovaFcc");
        }
    }

    // 5.
    {
        bRet = TransformerNovaMediaType(mediaInfo);
        if(!bRet)
        {
            LOG("TransformerNovaMediaType");
        }

        bRet = TransformerNovaMediaSubType(mediaInfo);
        if(!bRet)
        {
            LOG("TransformerNovaMediaSubType");
        }
        
    }

    return nCode;
}

int CVXLinuxMediaDetect::ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2)
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

int CVXLinuxMediaDetect::ConvertMpcInfo()
{
    ErrorCode ec = ErrorCode::Success;
    int nCode = GetErrorCode(ec);

    return nCode;
}

SDKVideoStreamInfoVec& CVXLinuxMediaDetect::GetVideoStreamInfoVec() 
{
    return m_videoStreamInfoVec;
}

SDKAudioStreamInfoVec& CVXLinuxMediaDetect::GetAudioStreamInfoVec() 
{
    return m_audioStreamInfoVec;
}

SDKSystemStreamInfoVec& CVXLinuxMediaDetect::GetSystemStreamInfoVec() 
{
    return m_systemStreamInfoVec;
}

SDKDataStreamInfoVec& CVXLinuxMediaDetect::GetDataStreamInfoVec() 
{
    return m_dataStreamInfoVec;
}

int CVXLinuxMediaDetect::GetVideoStreamNum()
{
    return m_videoStreamNum;
}

int CVXLinuxMediaDetect::GetAudioStreamNum()
{
    return m_audioStreamNum;
}

int CVXLinuxMediaDetect::GetSystemStreamNum()
{
    return m_systemStreamNum;
}

int CVXLinuxMediaDetect::GetDataStreamNum()
{
    return m_dataStreamNum;
}

void CVXLinuxMediaDetect::SetLogCb(pfnLog logCb, void* pUser, int logLevel)
{
    m_pErrorLog = logCb;
    m_pUser = pUser;
    m_logLevel = logLevel;
}

#endif

/**/

/**
 * @brief Create a Media Detect object
 * 
 * @return IVXMediaDetect* 
 */
__attribute ((visibility("default")))  IVXMediaDectect* CreateMediaDetect()
{
    IVXMediaDectect* pfnMediaDetect = nullptr;

#ifdef _MSC_VER
    pfnMediaDetect = new CVXWinMediaDectect();

#else
    pfnMediaDetect = new CVXLinuxMediaDetect();

#endif

    return pfnMediaDetect;
}