
#ifndef __define__media_log_helper__header__
#define __define__media_log_helper__header__

#include "../TTMediaReaderBaseDef.hpp"

template<ITTNotify::eNOTIFY iNotifyType>
void Write(ITTNotify* pNotify, int iNotifyCode, const wchar_t* lpszFormat, ...)
{
    if (pNotify)
    {
        wchar_t buffer[1024*2];
        va_list kv;
        va_start(kv, lpszFormat);
        vswprintf_s(buffer, lpszFormat, kv);
        va_end(kv);

        pNotify->ProcNotify(iNotifyType, buffer, iNotifyCode);
    }
}

template<ITTNotify::eNOTIFY iNotifyType>
void Write(ITTNotify* pNotify, int iNotifyCode, const char* lpszFormat, ...)
{
    if (pNotify)
    {
        char buffer[1024*2];
        va_list kv;
        va_start(kv, lpszFormat);
        vsprintf_s(buffer, lpszFormat, kv);
        va_end(kv);

        USES_CONVERSION;
        pNotify->ProcNotify(iNotifyType, A2W(buffer), iNotifyCode);
    }
}


#define NOTIFY_Trace(pNotify,NCode,fmt,...) Write<ITTNotify::NTF_Trace>(pNotify, NCode, fmt, __VA_ARGS__)
#define NOTIFY_Dbg(pNotify,NCode,fmt,...)   Write<ITTNotify::NTF_Debug>(pNotify, NCode, fmt, __VA_ARGS__)
#define NOTIFY_Error(pNotify,NCode,fmt,...) Write<ITTNotify::NTF_Error>(pNotify, NCode, fmt, __VA_ARGS__)

#define NOTIFY_Trace1(pNotify,fmt,...) Write<ITTNotify::NTF_Trace>(pNotify, 0, fmt, __VA_ARGS__)
#define NOTIFY_Dbg1(pNotify,fmt,...)   Write<ITTNotify::NTF_Debug>(pNotify, 0, fmt, __VA_ARGS__)
#define NOTIFY_Error1(pNotify,fmt,...) Write<ITTNotify::NTF_Error>(pNotify, 0, fmt, __VA_ARGS__)

#define NTF_TraceA(pNotify,fmt,...) Write<ITTNotify::NTF_Trace>(pNotify, 0, fmt##", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)
#define NTF_TraceW(pNotify,fmt,...) Write<ITTNotify::NTF_Trace>(pNotify, 0, fmt##L", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)
#define NTF_DbgA(pNotify,fmt,...) Write<ITTNotify::NTF_Debug>(pNotify, 0, fmt##", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)
#define NTF_DbgW(pNotify,fmt,...) Write<ITTNotify::NTF_Debug>(pNotify, 0, fmt##L", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)
#define NTF_ErrA(pNotify,fmt,...) Write<ITTNotify::NTF_Error>(pNotify, 0, fmt##", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)
#define NTF_ErrW(pNotify,fmt,...) Write<ITTNotify::NTF_Error>(pNotify, 0, fmt##L", <%s(%d)>\n", __VA_ARGS__, __WFILE__, __LINE__)

#endif
