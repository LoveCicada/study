
#ifndef __def__ttmediautility__header__
#define __def__ttmediautility__header__

#include "./TTMediaUtilityBase.h"
#include "./ITTMediaDetect.h"
#include "./ITTShotDetect.h"
#include "./ITTTcReader.h"
#include "./ITTAfdProcess.h"

#ifdef DEF_TT_MEDIA_UTILITY_EXPORT
#define TT_MEDIA_UTILITY_C_API extern "C" __declspec(dllexport)
#define TT_MEDIA_UTILITY_API __declspec(dllexport)
#else
#define TT_MEDIA_UTILITY_C_API extern "C" __declspec(dllimport)
#define TT_MEDIA_UTILITY_API __declspec(dllimport)

#ifdef _M_X64
#pragma comment(lib, "TTMediaUtilityX64.lib")
#else
#pragma comment(lib, "TTMediaUtilityWin32.lib")
#endif
#endif

TT_MEDIA_UTILITY_C_API int TT_MediaUtility_Init();
TT_MEDIA_UTILITY_C_API void* TT_MediaUtility_CreateObject(const _GUID& guid);
TT_MEDIA_UTILITY_C_API const wchar_t* TT_MediaUtility_ErrorInfo(int nErrorCode);
TT_MEDIA_UTILITY_C_API int TT_MediaUtility_Uninit();

#if 0

extern "C"
{

    typedef int            (*TT_MediaUtility_Init_Type)();
    typedef void*          (*TT_MediaUtility_CreateObject_Type)(const _GUID& guid);
    typedef const wchar_t* (*TT_MediaUtility_ErrorInfo_Type)(int nErrorCode);
    typedef int            (*TT_MediaUtility_Uninit_Type)();
    
    TT_MediaUtility_Init_Type         TT_MediaUtility_Init_Func;
    TT_MediaUtility_CreateObject_Type TT_MediaUtility_CreateObject_Func;
    TT_MediaUtility_ErrorInfo_Type    TT_MediaUtility_ErrorInfo_Func;
    TT_MediaUtility_Uninit_Type       TT_MediaUtility_Uninit_Func;

    HMODULE initTTMediaLoadFuncs(LPCTSTR pDllPath)
    {
        HMODULE hDll = LoadLibrary(pDllPath);
        if (hDll)
        {
            TT_MediaUtility_Init_Func         = (TT_MediaUtility_Init_Type)GetProcAddress(hDll, "TT_MediaUtility_Init");
            TT_MediaUtility_CreateObject_Func = (TT_MediaUtility_CreateObject_Type)GetProcAddress(hDll, "TT_MediaUtility_CreateObject");
            TT_MediaUtility_ErrorInfo_Func    = (TT_MediaUtility_ErrorInfo_Type)GetProcAddress(hDll, "TT_MediaUtility_ErrorInfo");
            TT_MediaUtility_Uninit_Func       = (TT_MediaUtility_Uninit_Type)GetProcAddress(hDll, "TT_MediaUtility_Uninit"); 
        }
        return hDll;
    }

};

#endif

#endif
