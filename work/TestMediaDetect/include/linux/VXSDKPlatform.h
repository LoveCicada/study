/*********************************************************
* 文件名　：VXSDKPlatform.h
* 功能  　：VXSDK编译宏定义与参数定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_PLATFORM_
#define _VX_SDK_PLATFORM_

#ifdef _MSC_VER
#pragma once
#endif

#if __GNUC__ >= 4
#define VX_SDK_API_EXPORT_DECL __attribute__ ((visibility("default")))
#define VX_SDK_API_IMPORT_DECL
#elif defined _MSC_VER
#define VX_SDK_API_EXPORT_DECL __declspec(dllexport)
#define VX_SDK_API_IMPORT_DECL __declspec(dllimport)
#else
#define VX_SDK_API_EXPORT_DECL
#define VX_SDK_API_IMPORT_DECL
#endif


#ifdef VX_SDK_API_COMPILE
#define VX_SDK_API VX_SDK_API_EXPORT_DECL
#else
#define VX_SDK_API VX_SDK_API_IMPORT_DECL
#endif

#ifdef __cplusplus

#define VX_SDK_DEFAULT(X) = X
#define VX_SDK_EXTERN_C     extern "C"
#define VX_SDK_BEGIN_C_DECL extern "C" {
#define VX_SDK_END_C_DECL              }

#else

#define VX_SDK_DEFAULT(X)
#define VX_SDK_EXTERN_C
#define VX_SDK_BEGIN_C_DECL
#define VX_SDK_END_C_DECL

#endif


#ifndef NULL
#if defined __GNUG__
#define NULL          __null
#else
#ifndef __cplusplus
#define NULL          ((void *)0)
#else
#define NULL          0
#endif
#endif
#endif



#endif
