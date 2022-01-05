
#include "VXMediaDetectHelper.h"
#include "../../include/nle/LinuxTTMedia/File/SBT_TransBaseDefine.h"
#include "../../include/nle/LinuxTTMedia/File/TPBaseFccDef.h"
#include "../../include/linux/VX_MediaDetect2.h"
#include "./TPAVFileMapFileTypeFromSbt.h"
#include "./TPAVFileMapMediaTypeFromSbt.h"
#include <string>

bool CopySDKFileMediaInfo(const stVXSDKFileMediaInfo& src, stVXSDKFileMediaInfo& dst)
{
    bool bRet = true;

    dst.cFileName = src.cFileName;
    

    return bRet;
}

/**
 * @brief CopySDKVideoStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySDKVideoStreamInfo(const stVXSDKVideoStreamInfo& src, stVXSDKVideoStreamInfo& dst)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief CopySDKAudioStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySDKAudioStreamInfo(const stVXSDKAudioStreamInfo& src, stVXSDKAudioStreamInfo& dst)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief CopySystemStreamStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySystemStreamStreamInfo(const stVXSDKSystemStreamInfo& src, stVXSDKSystemStreamInfo& dst)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief CopyDataStreamStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopyDataStreamStreamInfo(const stVXSDKDataStreamInfo& src, stVXSDKDataStreamInfo& dst)
{
    bool bRet = true;

    return bRet;
}

//-------------------------------SDK to TTMediaInfo-----------------------------------//
/**
 * @brief SDKFileMediaInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKFileMediaInfo2TTMediaInfo(const stVXSDKFileMediaInfo& src, TT::TTMediaInfo& dst)
{
    bool bRet = true;

    //文件名 const char *
    src.cFileName;
    //文件路径 wchar_t
    dst.wszFilePath;
    //std::string::copy()
    
    // 2. 文件大小
    dst.llFileSize = src.llFileSize;

    // 3. 文件长度单位
    src.nFileTimeScale;
    
    // 4. 文件总长度（以长度单位为基准）
    dst.llDuration = src.llFileTimeDuration;

    dst.llLength = static_cast<__int64>(src.nSegmentDuration);

    // 5. 边采边编标志
    src.nFileGrowing;

    // 6. 文件格式ID
    src.nFileFormatID;

#if 1

    // 音频编码 nova.id important
    dst.guidNovaFileId = GetGUID(src.nFileFormatID);

    // nova 校验出的媒体类型 we need modify
    //dst.dwMediaType = static_cast<ULONGLONG>();
    
    // nova 校验出的媒体子类型 we need modify
    //dst.dwMediaSubType = static_cast<ULONGLONG>();

#endif
    // 7. 文件子类型
    src.nSubFileType;

    // 8. 文件FourCC
    src.nFileFourCC;

    // 9. 文件总码率
    src.nFileBitrate;

    // 10. 
    src.cCompanyName;
    // 11.
    src.cProductName;
    // 12.
    src.cProductVersion;

    // 13. 
    src.nDropTimeCodeFlags;

    // 14.
    src.llStartTimecode;

    // 15. 分段长度（以帧为单位）
    src.nSegmentDuration;

    // 16. 文件public权限
    src.nPublic;

    // 17. 预留字段
    src.nReserved;


    return bRet;
}

/**
 * @brief SDKVideoStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKVideoStreamInfo2TTMediaInfo(const stVXSDKVideoStreamInfo& src, TT::TTMediaInfo& dst)
{
    bool bRet = true;

    dst.bVideo = true;
    dst.ttVideo.iSize;
    dst.ttVideo.iVersion;

    // important
    /* 
    * @brief 视频编码 nova.id fcc
    * dst.ttVideo.fccNovaVideoId;
    * 
    * get at SDKMediaInfo2NovaFcc()
    */
    
    // maybe error
    dst.ttVideo.iSbtVideoId = static_cast<unsigned int>(src.nMediaID);
    dst.ttVideo.dbFrameRate = src.nFrameRateDen / src.nFrameRateNum;
    dst.ttVideo.iWidth = src.nWidth;
    dst.ttVideo.iHeight = src.nHeight;
    dst.ttVideo.iBitrate = src.nBitrate;
    dst.ttVideo.iBits = src.nBitDepth;
    dst.ttVideo.iAFD = src.nAFD;
    dst.ttVideo.llDuration = src.llTimeDuration;
    dst.ttVideo.bIsVBR = (src.nBitrateMode == 1) ? true : false;

    // we need compare TTPixelFormat(windows TTMedia) to eVXSDKVideoColorSpaceFormat(Linux)
    dst.ttVideo.ttPixelFormat = static_cast<TTPixelFormat>(src.nVideoFormat);
    
    //dst.ttVideo.ttVStandard.m_dwVersion;
    dst.ttVideo.ttVStandard.SetEditHeight(static_cast<DWORD>(src.nHeight));
    dst.ttVideo.ttVStandard.SetEditWidth(static_cast<DWORD>(src.nWidth));

    // maybe have error
    dst.ttVideo.ttVStandard.SetFrameRateFrequency(static_cast<DWORD>(src.nFrameRateDen));
    dst.ttVideo.ttVStandard.SetFrameRateScale(static_cast<DWORD>(src.nFrameRateNum));
    dst.ttVideo.ttVStandard.SetWidthAspectRatio(static_cast<short>(src.nSarWidth));
    dst.ttVideo.ttVStandard.SetHeightAspectRatio(static_cast<short>(src.nSarHeight));

    // we need modify
    //dst.ttVideo.ttVStandard.m_sWidthPixRatio;
    //dst.ttVideo.ttVStandard.SetWidthPixRatio(static_cast<short>());
    //dst.ttVideo.ttVStandard.m_sHeightPixRatio;
    //dst.ttVideo.ttVStandard.SetHeightPixtRatio(static_cast<short>());

    //dst.ttVideo.ttVStandard.m_sViewNum;
    //dst.ttVideo.ttVStandard.SetViewNum(static_cast<short>());

    dst.ttVideo.ttVStandard.SetBitCount(static_cast<short>(src.nBitDepth));
    dst.ttVideo.ttVStandard.SetScanMode(static_cast<TTESCANMODE>(src.nScanType));
    dst.ttVideo.ttVStandard.SetDeinterlaceType(static_cast<TTEDEINTERLACETYPE>(src.nScanOrder));

    // maybe we can set null when invalid *****
    src.nHDRColorInfoValid;

    int nColorSpace = src.nColorPrimaries;
    int nOETF = src.nColorTransferCharacteristic;

    TCHAR pColorSpace[MAX_COLORSPACE];
    memset(pColorSpace,0,MAX_COLORSPACE*sizeof(TCHAR));
    E7FormatColorspaceString(pColorSpace, nColorSpace, nOETF);
    dst.ttVideo.ttVStandard.SetColorSpace(pColorSpace);

    //-----GOP-----
    dst.ttVideo.GopInfo.nGopCount           = static_cast<unsigned int>(src.nGopLen) ;
    dst.ttVideo.GopInfo.nGOP_I_FrameCount   = static_cast<unsigned int>(src.nIFrameCount) ;
    dst.ttVideo.GopInfo.nGOP_B_FrameCount   = static_cast<unsigned int>(src.nPFrameCount) ;
    dst.ttVideo.GopInfo.nGOP_P_FrameCount   = static_cast<unsigned int>(src.nBFrameCount) ;

    dst.ttVideo.iVideoFourcc = static_cast<unsigned int>(src.nFourCC);

    dst.ttVideo.iECStartPos;
    dst.ttVideo.lStill;
    dst.ttVideo.iCompression;

    return bRet;
}

/**
 * @brief SDKAudioStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKAudioStreamInfo2TTMediaInfo(const stVXSDKAudioStreamInfo& src, TT::TTMediaInfo& dst)
{
    bool bRet = true;

    dst.bAudio = true;
    dst.llSampleCount = src.nSamplesPerFrame;

    dst.ttAudio.iSize;
    dst.ttAudio.iVersion;

    // important
    dst.ttAudio.fccNovaAudioId;

    //maybe error
    dst.ttAudio.iSbtAudioId = static_cast<unsigned int>(src.nMediaID); 
    
    dst.ttAudio.iChannels = src.nChannels;
    dst.ttAudio.iSampleBits =src.nBitsPerSample;
    dst.ttAudio.iSampleRate = src.nSamplesPerSec;
    dst.ttAudio.bIsVBR = (src.nVBR == 1) ? true : false;
    dst.ttAudio.llDuration = src.llTimeDuration;

    return bRet;
}

/**
 * @brief SystemStreamStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SystemStreamStreamInfo2TTMediaInfo(const stVXSDKSystemStreamInfo& src, TT::TTMediaInfo& dst)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief DataStreamStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool DataStreamStreamInfo2TTMediaInfo(const stVXSDKDataStreamInfo& src, TT::TTMediaInfo& dst)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief SDKMediaInfo2NovaFcc
 *  special for nonlinear, get nova video fcc and audio fcc 
 * 视频编码nova.id, 音频编码nova.id
 * 
 * @param fileInfo 
 * @param videoInfo 
 * @param audioInfo 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKMediaInfo2NovaFcc(const stVXSDKFileMediaInfo& fileInfo, const stVXSDKVideoStreamInfo& videoInfo,
                                const stVXSDKAudioStreamInfo& audioInfo, TT::TTMediaInfo& dst)
{
    bool bRet = true;


    {
        if(dst.bVideo)
        {
            BITMAPINFOHEADER bmpInfo; 
            WAVEFORMATEX wfxInfo;
#if 0
            bmpInfo.biSize;
            bmpInfo.biWidth = videoInfo.nWidth;
            bmpInfo.biHeight = videoInfo.nHeight;
            bmpInfo.biPlanes;
            bmpInfo.biBitCount = videoInfo.nBitDepth;
            
            // useful
            bmpInfo.biCompression = ;

            bmpInfo.biSizeImage;
            bmpInfo.biXPelsPerMeter;  
            bmpInfo.biYPelsPerMeter;  
            bmpInfo.biClrUsed;
            bmpInfo.biClrImportant;
#else 

            bRet = VideoFmt2BmpInfo(bmpInfo, videoInfo.nVideoFormat);

#endif

            auto ret = GetFOURCC(videoInfo.nMediaID, fileInfo.nFileFormatID, &bmpInfo, &wfxInfo);
            dst.ttVideo.fccNovaVideoId = static_cast<unsigned int>(ret);
        }
    }
    
    {
        if(dst.bAudio)
        {
            auto ret = GetFOURCC(audioInfo.nMediaID);
            dst.ttVideo.fccNovaVideoId = static_cast<unsigned int>(ret);
        }
    }


    return bRet;
}

//-------------------------------SDK to TTMediaInfo-----------------------------------//

/**
 * @brief VideoFmt2BmpInfo
 * 
 * @param stDstBmpInfo 
 * @param nSrcVideoFormat 
 * @return true 
 * @return false 
 */
bool VideoFmt2BmpInfo(BITMAPINFOHEADER &stDstBmpInfo, const int &nSrcVideoFormat)
{
    bool bRet = true;

    switch (nSrcVideoFormat)
	{
	case eVXVideoCsFmtBGR:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_RGB;
		stDstBmpInfo.biBitCount = 24;
		break;
	case eVXVideoCsFmtRGB:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_BGR;
		stDstBmpInfo.biBitCount = 24;
		break;
	case eVXVideoCsFmtBGRA:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_RGB;
		stDstBmpInfo.biBitCount = 32;
	case eVXVideoCsFmtRGBA:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_BGR;
		stDstBmpInfo.biBitCount = 32;
		break;
	case eVXVideoCsFmtARGB:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_ARGB;
		stDstBmpInfo.biBitCount = 32;
		break;
	case eVXVideoCsFmtYUV420P:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_YUV6;
		stDstBmpInfo.biBitCount = 12;
		break;
	case eVXVideoCsFmtYUV411P:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_Y411;
		stDstBmpInfo.biBitCount = 12;
		break;
	case eVXVideoCsFmtYUV422P:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_YUV8;
		stDstBmpInfo.biBitCount = 12;
		break;
	case eVXVideoCsFmtYUV444P:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_YUVC;
		stDstBmpInfo.biBitCount = 24;
		break;
	case eVXVideoCsFmtYUYV:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_YUY2;
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtUYVY:
		stDstBmpInfo.biPlanes = 1;
		stDstBmpInfo.biCompression = BI_UYVY;
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtP010BE:
		stDstBmpInfo.biPlanes = 2;
		//stDstBmpInfo.biCompression = '010P';
		stDstBmpInfo.biCompression = mmioFOURCC('P','0','1','0');
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtYUYV10BE:
		stDstBmpInfo.biPlanes = 2;
		stDstBmpInfo.biCompression = BI_YUY2;
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtYUV420P10LE:
		stDstBmpInfo.biPlanes = 3;
		stDstBmpInfo.biCompression = BI_YUV6;
		stDstBmpInfo.biBitCount = 12;
		break;
	case eVXVideoCsFmtYUV422P10LE:
		stDstBmpInfo.biPlanes = 3;
		stDstBmpInfo.biCompression = BI_YUV8;
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtYUV444P10LE:
		stDstBmpInfo.biPlanes = 3;
		stDstBmpInfo.biCompression = BI_YUVC;
		stDstBmpInfo.biBitCount = 24;
		break;
	case eVXVideoCsFmtYUYV10LE:
		stDstBmpInfo.biPlanes = 3;
		stDstBmpInfo.biCompression = BI_YUY2;
		stDstBmpInfo.biBitCount = 16;
		break;
	case eVXVideoCsFmtUYVY10LE:
		stDstBmpInfo.biPlanes = 3;
		stDstBmpInfo.biCompression = BI_UYVY;
		stDstBmpInfo.biBitCount = 16;
		break;
	}

    return bRet;
}

bool guid2string(GUID uu, char* out)
{
    bool bRet = true;

    return bRet;
}

bool guid2string(GUID uu, std::string& out)
{
    bool bRet = true;

    return bRet;
}

/**
 * @brief GetGUID
 * 
 * @param iID 
 * @return uuid_t 
 */
GUID GetGUID(int iID)
{
#if 1
    return TPAVFileGetGUID(iID);
#else
    GUID guid;
    return guid;
#endif

}



/**
 * @brief GetFOURCC
 * 
 * @param iID 
 * @param iFileId 
 * @param bmpInfo 
 * @param wfxInfo 
 * @return DWORD 
 */
DWORD GetFOURCC(int iID, int iFileId, BITMAPINFOHEADER* bmpInfo, WAVEFORMATEX* wfxInfo)
{
#if 0 //we need modify
    return TPAVFileGetFCC(iID, iFileId, bmpInfo, wfxInfo);
#else

    return 0;
#endif

}

/**
 * @brief GetFOURCC
 * 
 * @param iID 
 * @param iFileId 
 * @return DWORD 
 */
DWORD GetFOURCC(int iID, int iFileId)
{
#if 1 // we need modify
    return TPAVFileGetFCC(iID, iFileId, NULL, NULL);
#else

    return 0;
#endif
}

/**
 * @brief E7FormatColorspaceString
 * 
 * @param chColorsSpace 
 * @param nColorSpace 
 * @param nOETF 
 */
void E7FormatColorspaceString(TCHAR chColorsSpace[MAX_COLORSPACE], int nColorSpace, int nOETF)
{
    TCHAR cs[MAX_COLORSPACE];
    memset(cs, 0, MAX_COLORSPACE*sizeof(TCHAR));
    TCHAR tf[MAX_COLORSPACE];
    memset(tf, 0, MAX_COLORSPACE*sizeof(TCHAR));

    if      (nColorSpace == eVXColourPrimaries_BT_709     )			wcsncpy( cs, L"Rec.709", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_BT_601_625 )			wcsncpy( cs, L"Rec.601", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_BT_601_525 )			wcsncpy( cs, L"Rec.601", MAX_COLORSPACE);
    else if (nColorSpace == eVXColourPrimaries_BT_2020    )			wcsncpy( cs, L"Rec.2020", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_SGamut     )			wcsncpy( cs, L"S-Gamut", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_SGamut3    )			wcsncpy( cs, L"S-Gamut3", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_SGamut3Cine)			wcsncpy( cs, L"S-Gamut3.Cine", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_VGamut)				wcsncpy( cs, L"Panasonic V-Gamut", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_Arri_Wide_Gamut)		wcsncpy( cs, L"ARRI Wide Gamut", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_RED_Wide_Gamut)      wcsncpy( cs, L"REDWideGamutRGB", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_Canon_Cinema_Gamut)	wcsncpy( cs, L"Canon Cinema Gamut", MAX_COLORSPACE );
    else if (nColorSpace == eVXColourPrimaries_DJI_DGamut)			wcsncpy( cs, L"DJI D-Gamut", MAX_COLORSPACE );
    else wcsncpy( cs, L"Unknown", MAX_COLORSPACE );


    if      (nOETF == eVXTransferCharacteristic_BT_709)        wcsncpy( tf, L"", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_Unspecified)   wcsncpy( tf, L"", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_GAMMA22)       wcsncpy( tf, L"Gamma2.2", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_GAMMA28)       wcsncpy( tf, L"Gamma2.8", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_GAMMA24)       wcsncpy( tf, L"Gamma2.4", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_GAMMA26)       wcsncpy( tf, L"Gamma2.6", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_LINEAR)        wcsncpy( tf, L"Linear", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_LOG)           wcsncpy( tf, L"Log", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_LOG_SQRT)      wcsncpy( tf, L"LogSqrt", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_BT_2020_10BIT) wcsncpy( tf, L"", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_BT_2020_12BIT) wcsncpy( tf, L"", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_BT_2100_PQ)    wcsncpy( tf, L"ST2084", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_BT_2100_HLG)   wcsncpy( tf, L"HLG", MAX_COLORSPACE );
    else if	(nOETF == eVXTransferCharacteristic_BT_2100_HLG_SCENE) wcsncpy( tf, L"HLG(Scene)", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_SLog2)         wcsncpy( tf, L"S-Log2", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_SLog3)         wcsncpy( tf, L"S-Log3", MAX_COLORSPACE );
    else if (nOETF == eVXVXTransferCharacteristic_SLog3_Live)  wcsncpy( tf, L"S-Log3(Live HDR)", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_Alexa_LogC_3)  wcsncpy( tf, L"LogC", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_VLog)          wcsncpy( tf, L"V-Log", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_Clog_2)		   wcsncpy( tf, L"CLog2", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_Clog_3)        wcsncpy( tf, L"CLog3", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_DJI_DLog)	   wcsncpy( tf, L"DJI-DLog", MAX_COLORSPACE );
    else if (nOETF == eVXTransferCharacteristic_RED_LOG3G10)   wcsncpy( tf, L"Log3G10", MAX_COLORSPACE );
    else                                                       wcsncpy( tf, L"", MAX_COLORSPACE );
    //Canon CLOG 特殊处理。其实他是709 +clgo
    if (nOETF == eVXVXTransferCharacteristic_CLog)			   wcsncpy( cs, L"Canon C-Log", MAX_COLORSPACE );

    if(wcscmp(tf, L"") != 0)
        swprintf( chColorsSpace, MAX_COLORSPACE,L"%s/%s", cs, tf);
    else if (wcslen(cs) > 0)
        swprintf( chColorsSpace, MAX_COLORSPACE,L"%s", cs);
}

//-----------------------------------------------00


/**
 * @brief Test
 * 
 * @param dst 
 * @return true 
 * @return false 
 */
bool Test(TT::TTMediaInfo& dst)
{
    bool bRet = true;
    dst.guidNovaFileId;
    dst.ttAudio.fccNovaAudioId;
    dst.ttVideo.fccNovaVideoId;
    dst.dwMediaType;
    dst.dwMediaSubType;

    dst.wszFilePath;
    dst.iSize;
    dst.iVersion;
    dst.iFileState;

    dst.iSbtFileId;
    dst.iFileState;


    return bRet;
}

//-----------------------------------------------00