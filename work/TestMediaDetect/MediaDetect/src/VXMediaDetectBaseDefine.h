
#pragma once

#include <vector>

#ifdef _MSC_VER
    // load windows sdk include

#else
    //load linux sdk include
#include "../../include/linux/VXSDKMediaDetect.h"

#if __cplusplus >= 201103L 

using SDKVideoStreamInfoVec     = std::vector<stVXSDKVideoStreamInfo>;
using SDKAudioStreamInfoVec     = std::vector<stVXSDKAudioStreamInfo>;
using SDKSystemStreamInfoVec    = std::vector<stVXSDKSystemStreamInfo>; 
using SDKDataStreamInfoVec      = std::vector<stVXSDKDataStreamInfo>; 

#else

typedef std::vector<stVXSDKVideoStreamInfo>    SDKVideoStreamInfoVec;
typedef std::vector<stVXSDKAudioStreamInfo>    SDKAudioStreamInfoVec;
typedef std::vector<stVXSDKSystemStreamInfo>   SDKSystemStreamInfoVec;
typedef std::vector<stVXSDKDataStreamInfo>     SDKDataStreamInfoVec;

#endif



#endif


