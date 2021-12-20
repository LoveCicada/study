
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
class IVXMediaDectect
{

public:

    virtual ~IVXMediaDectect(){};

    virtual int Init() = 0;
    virtual int UnInit() = 0;

    virtual int GetMediaInfo(const char *cFileName, int nDetectMode = 0) = 0;
    virtual int GetMediaInfo(const std::string& str, int nDetectMode = 0) = 0;
    virtual int ConvertToNonlinearInfo() = 0;
    virtual int ConvertMpcInfo() = 0;

    virtual SDKVideoStreamInfoVec&  GetVideoStreamInfoVec()  const;
    virtual SDKAudioStreamInfoVec&  GetAudioStreamInfoVec()  const;
    virtual SDKSystemStreamInfoVec& GetSystemStreamInfoVec() const;
    virtual SDKDataStreamInfoVec&   GetDataStreamInfoVec()   const;
    
    virtual int GetVideoStreamNum()  const;
    virtual int GetAudioStreamNum()  const;
    virtual int GetSystemStreamNum() const;
    virtual int GetDataStreamNum()   const;

private:
//     SdkInfo m_sdkInfo;
//     bool m_bLoadOnce;
};

extern "C" _VX_Media_Detect_Lib IVXMediaDectect* CreateMediaDectect();

typedef IVXMediaDectect* (*pfnCreateMediaDectect);


#if __cplusplus >= 201103L
std::function<IVXMediaDectect* (*)> pfnMediaDetect;
#endif

