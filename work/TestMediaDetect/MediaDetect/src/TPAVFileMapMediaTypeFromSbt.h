
#pragma once

// #ifndef __TP__AVFileMapMediaTypeFrom__Sbt__Header__
// #define __TP__AVFileMapMediaTypeFrom__Sbt__Header__

//#include "../include/nle/LinuxTTMedia/File/SBT_TransBaseDefine.h"
//#include "../include/nle/LinuxTTMedia/ITTAdaptWinDefine.h"

//#include "../include/nle/LinuxTTMedia/File/TPBaseFccDef.h"

#include "../include/nle/LinuxTTMedia/ITTAdaptWinDefine.h"

DWORD TPAVFileGetFCC(int iID, int iFileId, BITMAPINFOHEADER* bmpInfo, WAVEFORMATEX* wfxInfo);


DWORD TPAVFileGetFCC(int iID, int iFileId);


// #endif  __TP__AVFileMapMediaTypeFrom__Sbt__Header__