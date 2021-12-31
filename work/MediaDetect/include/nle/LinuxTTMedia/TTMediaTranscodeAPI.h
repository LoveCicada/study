
#ifndef __def__media_transcode_api_header__
#define __def__media_transcode_api_header__

#include "./ITTMediaTranscode.hpp"

#ifdef DEF_MEDIA_TRANSCODE_EXPORT
#   define TT_MEDIA_TRANSCODE_API __declspec(dllexport)
#else
#   define TT_MEDIA_TRANSCODE_API __declspec(dllimport)
#   ifndef _M_X64
#       pragma comment(lib, "MediaTranscodeWin32.lib")
#   else
#       pragma comment(lib, "MediaTranscodeX64.lib")
#   endif
#endif

extern "C" TT_MEDIA_TRANSCODE_API int TT_InitMediaTranscodeLib(const wchar_t* wszPluginFolder);
extern "C" TT_MEDIA_TRANSCODE_API ITTTranscode* TT_CreateTranscode();
extern"C" TT_MEDIA_TRANSCODE_API int TT_UnnitMediaTranscodeLib();


#endif
