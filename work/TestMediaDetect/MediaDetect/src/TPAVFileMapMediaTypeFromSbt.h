
#pragma once


#include "../include/nle/LinuxTTMedia/ITTAdaptWinDefine.h"

/**
 * @brief TPAVFileGetFCC
 * 
 * @param iID 
 * @param iFileId 
 * @param bmpInfo 
 * @param wfxInfo 
 * @return DWORD 
 */
DWORD TPAVFileGetFCC(int iID, int iFileId, BITMAPINFOHEADER* bmpInfo, WAVEFORMATEX* wfxInfo);

/**
 * @brief TPAVFileGetFCC
 * 
 * @param iID 
 * @param iFileId 
 * @return DWORD 
 */
DWORD TPAVFileGetFCC(int iID, int iFileId);


