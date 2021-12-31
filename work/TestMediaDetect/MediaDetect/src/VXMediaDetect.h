
#pragma once




#ifdef _MSC_VER
#ifdef _VX_Media_Detect_Export
#define _VX_Media_Detect_Lib __declspec(dllexport)
#else
#define _VX_Media_Detect_Lib __declspec(dllimport)
#endif
#else
#define _VX_Media_Detect_Lib
#endif


#include <vector>
#ifndef _WINDOWS
#include <dlfcn.h>
#endif

#if __cplusplus >= 201103L
#include <functional>
#endif

#include <iostream>
#include "VXMediaDetectErrorCode.h"
#include "VXMediaDetectBaseDefine.h"
#include "../../include/nle/LinuxTTMedia/ITTMediaDetect.h"
using namespace std;

#define WINDOWS_SYS 0

#define LINUX_SYS 1

/**
 * @brief src media info
 * 
 */
class SdkInfo
{
public:

};


/**
 * @brief linux mpc media info
 * 
 */
class LinuxMpcInfo
{
public:
};


/**
 * @brief nonlinear media info
 * 
 */
class NonlinearInfo
{
public:

};

/**
 * @brief 
 * 
 */
class __attribute ((visibility("default"))) IVXMediaDectect
{

public:

    virtual ~IVXMediaDectect(){};

    virtual int Init() = 0;
    virtual int UnInit() = 0;

    virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) = 0;
    virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) = 0;
    virtual int ConvertToNovaInfo() = 0;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo& mediaInfo) = 0;
    virtual int ConvertToNovaInfo(TT::TTMediaInfo2& mediaInfo2) = 0;
    virtual int ConvertMpcInfo() = 0;

#if 0
    virtual SDKVideoStreamInfoVec&  GetVideoStreamInfoVec()  = 0;
    virtual SDKAudioStreamInfoVec&  GetAudioStreamInfoVec()  = 0;
    virtual SDKSystemStreamInfoVec& GetSystemStreamInfoVec() = 0;
    virtual SDKDataStreamInfoVec&   GetDataStreamInfoVec()   = 0;
    
    virtual int GetVideoStreamNum()  = 0;
    virtual int GetAudioStreamNum()  = 0;
    virtual int GetSystemStreamNum() = 0;
    virtual int GetDataStreamNum()   = 0;

#endif 

private:
//     SdkInfo m_sdkInfo;
//     bool m_bLoadOnce;
};

extern "C" _VX_Media_Detect_Lib IVXMediaDectect* CreateMediaDetect();

typedef IVXMediaDectect* (*pfnCreateMediaDectect);

#if 0

#if __cplusplus >= 201103L
std::function<IVXMediaDectect* (*)> pfnMediaDetect;
#endif

#endif
