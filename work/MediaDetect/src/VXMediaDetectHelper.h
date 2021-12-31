
#pragma once

#include "include/linux/VXSDKMediaDetect.h"
#include "../include/nle/LinuxTTMedia/ITTMediaDetect.h"
#include "../include/nle/LinuxTTMedia/File/TPAVFileTypeDefs.h"
#include "../include/nle/LinuxTTMedia/File/TPAVFileMapFileTypeFromSbt.h"
#include "../include/nle/LinuxTTMedia/File/TPAVFileMapMediaTypeFromSbt.h"

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
 * @brief guid2uuid
 * 
 * @return true 
 * @return false 
 */
bool guid2uuid(CONST GUID& src, uuid& dst);

/**
 * @brief uuid2guid
 * 
 * @return true 
 * @return false 
 */
bool uuid2guid(const uuid& src, GUID& guid);

/**
 * @brief uuid2string
 * 
 * @param uu 
 * @param out 
 * @return true 
 * @return false 
 */
bool uuid2string(uuid_t uu, char* out);

/**
 * @brief uuid2string
 * 
 * @param uu 
 * @param out 
 * @return true 
 * @return false 
 */
bool uuid2string(uuid_t uu, std::string& out);


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
DWORD GetFOURCC(int iID, int iFileId);

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

