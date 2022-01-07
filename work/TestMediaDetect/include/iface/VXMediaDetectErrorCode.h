
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
    ResetFail = 2,
    SetInputFileFail = 3,
    GetMediaInfoFail = 4,
    CopySDKFileMediaInfoFail = 5,
    CopySDKVideoStreamInfoFail = 6,
    CopySDKAudioStreamInfoFail = 7,
    CopySystemStreamStreamInfoFail = 8,
    CopyDataStreamStreamInfoFail = 9,
    
};

#define GetErrorCode(ec) static_cast<int>(ec);