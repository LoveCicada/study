
#pragma once

#include <iostream>

/**
 * @brief define error code
 * 
 */


enum ErrorCode
{
    Success = 0,    
    LoadSdkLibraryFail = 1,
    SetInputFileFail = 2,
    GetMediaInfoFail = 3,
    CopySDKFileMediaInfoFail = 4,
    CopySDKVideoStreamInfoFail = 5,
    CopySDKAudioStreamInfoFail = 6,
    CopySystemStreamStreamInfoFail = 7,
    CopyDataStreamStreamInfoFail = 8,
    
};

#define GetErrorCode(ec) static_cast<int>(ec);