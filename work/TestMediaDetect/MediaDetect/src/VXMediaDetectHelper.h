
#pragma once

#include "../../include/linux/VXSDKMediaDetect.h"
#include "../../include/nle/LinuxTTMedia/ITTMediaDetect.h"
#include "../../include/nle/LinuxTTMedia/File/TPAVFileTypeDefs.h"
#include "./TPAVFileMapFileTypeFromSbt.h"
#include "./TPAVFileMapMediaTypeFromSbt.h"

#define _Media_BIT_(idx) (1<<idx)

//////////////////////////////////////////////////////////////////////////
// 文件类型定义，类型为TP_MEDIA_CLASS_TYPE
#define TP_MEDIA_CLASS_UNKNOWN			0x00000000
#define TP_MEDIA_CLASS_V				0x00000001

// 音频声道数
#define TP_MEDIA_CLASS_A1				0x00000002
#define TP_MEDIA_CLASS_A2				0x00000004
#define TP_MEDIA_CLASS_A3				0x00000008
#define TP_MEDIA_CLASS_A4				0x00000010
#define TP_MEDIA_CLASS_A5				0x00000020
#define TP_MEDIA_CLASS_A6				0x00000040
#define TP_MEDIA_CLASS_A7				0x00000080
#define TP_MEDIA_CLASS_A8				0x00000100

#define TP_MEDIA_CLASS_A9				0x00000200
#define TP_MEDIA_CLASS_A10				0x00000400
#define TP_MEDIA_CLASS_A11				0x00000800
#define TP_MEDIA_CLASS_A12				0x00001000	//0x00200000
#define TP_MEDIA_CLASS_A13				0x00002000	//0x00400000
#define TP_MEDIA_CLASS_A14				0x00004000	//0x00800000
#define TP_MEDIA_CLASS_A15				0x00008000	//0x04000000
#define TP_MEDIA_CLASS_A16				0x00010000	//0x08000000

#define TP_MEDIA_CLASS_A17				0x00020000
#define TP_MEDIA_CLASS_A18				0x00040000
#define TP_MEDIA_CLASS_A19				0x00080000
#define TP_MEDIA_CLASS_A20				0x00100000
#define TP_MEDIA_CLASS_A21				0x00200000
#define TP_MEDIA_CLASS_A22				0x00400000
#define TP_MEDIA_CLASS_A23				0x00800000
#define TP_MEDIA_CLASS_A24				0x01000000
#define TP_MEDIA_CLASS_A25				0x02000000
#define TP_MEDIA_CLASS_A26				0x04000000
#define TP_MEDIA_CLASS_A27				0x08000000
#define TP_MEDIA_CLASS_A28				0x10000000
#define TP_MEDIA_CLASS_A29				0x20000000
#define TP_MEDIA_CLASS_A30				0x40000000
#define TP_MEDIA_CLASS_A31				0x80000000
#define TP_MEDIA_CLASS_A32				0x0000000100000000

#define TP_MEDIA_CLASS_A				(TP_MEDIA_CLASS_A1 | TP_MEDIA_CLASS_A2 | TP_MEDIA_CLASS_A3 | TP_MEDIA_CLASS_A4 | TP_MEDIA_CLASS_A5 | TP_MEDIA_CLASS_A6 | TP_MEDIA_CLASS_A7 | TP_MEDIA_CLASS_A8 |TP_MEDIA_CLASS_A9 | TP_MEDIA_CLASS_A10 | TP_MEDIA_CLASS_A11 | TP_MEDIA_CLASS_A12 | TP_MEDIA_CLASS_A13 | TP_MEDIA_CLASS_A14 | TP_MEDIA_CLASS_A15 | TP_MEDIA_CLASS_A16)

// 视频具体类型
#define TP_MEDIA_CLASS_V_G				0x0000000200000000	//0x00001000
#define TP_MEDIA_CLASS_KEY				0x0000000400000000	//0x00080000
#define TP_MEDIA_CLASS_EFF				0x0000000800000000	//0x00100000
#define TP_MEDIA_CLASS_V_ICGANI			0x0000001000000000	//0x00020000
#define TP_MEDIA_CLASS_V_P				0x0000002000000000	//0x00002000
#define TP_MEDIA_CLASS_V_CC				0x0000004000000000	//0x20000000
#define TP_MEDIA_CLASS_V_SERIAL			0x0000008000000000	//0x00008000
#define TP_MEDIA_CLASS_V_ICG			0x0000010000000000	//0x00010000
#define TP_MEDIA_CLASS_V_ICGCRAWL		0x0000020000000000	//0x00080000
#define TP_MEDIA_CLASS_V_3D				0x0000040000000000	//0x00040000
#define TP_MEDIA_CLASS_ASPECTRATIO_4_3	0x0000080000000000	//0x01000000
#define TP_MEDIA_CLASS_ASPECTRATIO_16_9 0x0000100000000000	//0x02000000

#define TP_MEDIA_CLASS_V_VFR			0x0000200000000000	//0x80000000
#define TP_MEDIA_CLASS_V_RAW			0x0000400000000000	//0x40000000
#define TP_MEDIA_CLASS_V_V				0x0000800000000000	//0x00004000

//////////////////////////////////////////////////////////////////////////

/**
 * @brief CopySDKFileMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySDKFileMediaInfo(const stVXSDKFileMediaInfo& src, stVXSDKFileMediaInfo& dst);


/**
 * @brief CopySDKVideoStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySDKVideoStreamInfo(const stVXSDKVideoStreamInfo& src, stVXSDKVideoStreamInfo& dst);


/**
 * @brief CopySDKAudioStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySDKAudioStreamInfo(const stVXSDKAudioStreamInfo& src, stVXSDKAudioStreamInfo& dst);


/**
 * @brief CopySystemStreamStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopySystemStreamStreamInfo(const stVXSDKSystemStreamInfo& src, stVXSDKSystemStreamInfo& dst);

/**
 * @brief CopyDataStreamStreamInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool CopyDataStreamStreamInfo(const stVXSDKDataStreamInfo& src, stVXSDKDataStreamInfo& dst);

//-------------------------------SDK to TTMediaInfo-----------------------------------//
/**
 * @brief SDKFileMediaInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKFileMediaInfo2TTMediaInfo(const stVXSDKFileMediaInfo& src, TT::TTMediaInfo& dst);


/**
 * @brief SDKVideoStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKVideoStreamInfo2TTMediaInfo(const stVXSDKVideoStreamInfo& src, TT::TTMediaInfo& dst);


/**
 * @brief SDKAudioStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKAudioStreamInfo2TTMediaInfo(const stVXSDKAudioStreamInfo& src, TT::TTMediaInfo& dst);


/**
 * @brief SystemStreamStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SystemStreamStreamInfo2TTMediaInfo(const stVXSDKSystemStreamInfo& src, TT::TTMediaInfo& dst);

/**
 * @brief DataStreamStreamInfo2TTMediaInfo
 * 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool DataStreamStreamInfo2TTMediaInfo(const stVXSDKDataStreamInfo& src, TT::TTMediaInfo& dst);

/**
 * @brief SDKMediaInfo2NovaFcc
 *  special for nonlinear, get nova video fcc and audio fcc 
 * 
 * @param fileInfo 
 * @param videoInfo 
 * @param audioInfo 
 * @param dst 
 * @return true 
 * @return false 
 */
bool SDKMediaInfo2NovaFcc(const stVXSDKFileMediaInfo& fileInfo, const stVXSDKVideoStreamInfo& videoInfo,
                                const stVXSDKAudioStreamInfo& audioInfo, TT::TTMediaInfo& dst);

//-------------------------------SDK to TTMediaInfo-----------------------------------//
/**
 * @brief VideoFmt2BmpInfo
 * 
 * @param stDstBmpInfo 
 * @param nSrcVideoFormat 
 * @return true 
 * @return false 
 */
bool VideoFmt2BmpInfo(BITMAPINFOHEADER &stDstBmpInfo, const int &nSrcVideoFormat);

/**
 * @brief uuid2string
 * 
 * @param uu 
 * @param out 
 * @return true 
 * @return false 
 */
bool guid2string(GUID guid, char* out);

/**
 * @brief uuid2string
 * 
 * @param uu 
 * @param out 
 * @return true 
 * @return false 
 */
bool guid2string(GUID uu, std::string& out);


/**
 * @brief GetGUID
 * 
 * @param iID 
 * @return GUID 
 */
GUID GetGUID(int iID);


/**
 * @brief GetFOURCC
 * 
 * @param iID 
 * @param iFileId 
 * @param bmpInfo 
 * @param wfxInfo 
 * @return DWORD 
 */
DWORD GetFOURCC(int iID, int iFileId, BITMAPINFOHEADER* bmpInfo, WAVEFORMATEX* wfxInfo);

/**
 * @brief GetFOURCC
 * 
 * @param iID 
 * @param iFileId 
 * @return DWORD 
 */
DWORD GetFOURCC(int iID, int iFileId = 0);

/**
 * @brief E7FormatColorspaceString
 * 
 * @param chColorsSpace 
 * @param nColorSpace 
 * @param nOETF 
 */
void E7FormatColorspaceString(TCHAR chColorsSpace[MAX_COLORSPACE], int nColorSpace, int nOETF);

/**
 * @brief TransformerAspectRatio
 * 
 * @param aspectRatio 
 * @param w 
 * @param h 
 * @return true 
 * @return false 
 */
bool TransformerAspectRatio(const eVXSDKVideoAspectRatio& aspectRatio, int& w, int& h);

/**
 * @brief IsPicture
 * 
 * @param fileFormatID 
 * @return true 
 * @return false 
 */
bool IsPicture(int fileFormatID);

/**
 * @brief TransformerNovaMediaType
 * 
 * @param src 
 * @return true 
 * @return false 
 */
bool TransformerNovaMediaType(TT::TTMediaInfo& src);

/**
 * @brief TransformerNovaMediaSubType
 * 
 * @param src 
 * @return true 
 * @return false 
 */
bool TransformerNovaMediaSubType(TT::TTMediaInfo& src);

//-----------------------------------------------00


/**
 * @brief Test
 * 
 * @param dst 
 * @return true 
 * @return false 
 */
bool Test(TT::TTMediaInfo& dst);



//-----------------------------------------------00

