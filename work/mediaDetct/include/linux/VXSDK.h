/*********************************************************
* 文件名　：VXSDK.h
* 功能  　：Cutlist加载接口
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_INCLUDE_
#define _VX_SDK_INCLUDE_

#ifdef _MSC_VER
#pragma once
#endif

#include "VXSDKPlatform.h"
#include <string>

VX_SDK_BEGIN_C_DECL

/**
*  SDK初始化函数,在调用其他任何SDK接口前必须先调用此接口
*/
VX_SDK_API int InitializeVXSDK(int nFlags);

VX_SDK_API void FinalizeVXSDK();

//VX_LOG_LEVEL_ERROR
//VX_LOG_LEVEL_WARNING
//VX_LOG_LEVEL_INFO

VX_SDK_API int VXSetSDKLogCallbackC(void(*callback)(void* pUserData, int nLevel, const char* srtFunc, const char* strFile, int nLine, const char* strLog), void* pUserData);

VX_SDK_END_C_DECL

#endif
