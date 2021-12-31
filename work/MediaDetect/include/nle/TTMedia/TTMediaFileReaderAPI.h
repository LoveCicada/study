
#ifndef __def_media_file_reader__header__
#define __def_media_file_reader__header__

#include "./ITTMediaReader.hpp"
#include "./ITTMediaWriter.hpp"

#ifndef TT_MEDIA_SOURCE_API
#   ifdef DEF_MEDIA_SOURCE_EXPORT
#       define TT_MEDIA_SOURCE_API  __declspec(dllexport)
#   else
#       define TT_MEDIA_SOURCE_API  __declspec(dllimport)
#       ifndef _M_X64
#           pragma comment(lib, "MediaReaderManageWin32.lib")
#       else
#           pragma comment(lib, "MediaReaderManageX64.lib")
#       endif
#   endif
#endif

/** 初始化MediaReader库 */
extern"C" TT_MEDIA_SOURCE_API int           TT_InitMediaReaderLib(const wchar_t* lpszPluginFolder = NULL);

/** 
创建VFR Reader
@return ITTMediaReader*
@see ITTMediaReader
*/
extern"C" TT_MEDIA_SOURCE_API ITTMediaReader* TT_CreateMediaReader();

/**
创建VFR Reader, CFR Reader
@param TTMediaReaderType, TTMediaReaderType_VFR变帧率Reader, TTMediaReaderType_CFR固定帧率Reader
@return ITTMediaReader*
@see ITTMediaReader
*/
extern"C" TT_MEDIA_SOURCE_API ITTMediaReader* TT_CreateMediaReaderEx(const wchar_t* TTMediaReaderType = TTMediaReaderType_VFR);

/**
创建Writer
@param TTMediaReaderType, TTMEDIAWRITER_Default缺省Writer
@return ITTMediaWirter*
@see ITTMediaWirter
*/
extern"C" TT_MEDIA_SOURCE_API ITTMediaWriter* TT_CreateMediaWriter(const wchar_t* TTMediaReaderType = TTMEDIAWRITER_Default);

/** 销毁MediaReader库 */
extern"C" TT_MEDIA_SOURCE_API int           TT_UninitMediaReaderLib();

#endif
