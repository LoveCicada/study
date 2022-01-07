
#pragma once

#include <vector>

#ifdef _MSC_VER
    // load windows sdk include

#else
    //load linux sdk include
#include "../linux/VXSDKMediaDetect.h"

typedef std::vector<stVXSDKVideoStreamInfo>    SDKVideoStreamInfoVec;
typedef std::vector<stVXSDKAudioStreamInfo>    SDKAudioStreamInfoVec;
typedef std::vector<stVXSDKSystemStreamInfo>   SDKSystemStreamInfoVec;
typedef std::vector<stVXSDKDataStreamInfo>     SDKDataStreamInfoVec;

#endif


