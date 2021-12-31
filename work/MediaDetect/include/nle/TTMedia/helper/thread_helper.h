
#ifndef __def__thread_helper__header__
#define __def__thread_helper__header__

// ------------------------------------------------------------------------------------------

template<class TType, unsigned int (TType::*pm)()>
static inline unsigned int __stdcall Call_ThreadWrapper(void* lpContext)
{
    if (lpContext)
    {
        return (((TType*)lpContext)->*pm)();
    }
    return 0;
}

#define ThreadWrapper(TClass,TMemFunc) \
    Call_ThreadWrapper<TClass,&TClass::TMemFunc>

// ------------------------------------------------------------------------------------------

__if_exists(DWORD)
{

#define MS_VC_EXCEPTION 0x406D1388

#pragma pack(push,8)
    typedef struct tagTHREADNAME_INFO
    {
        DWORD dwType; // Must be 0x1000.
        LPCSTR szName; // Pointer to name (in user addr space).
        DWORD dwThreadID; // Thread ID (-1=caller thread).
        DWORD dwFlags; // Reserved for future use, must be zero.
    } THREADNAME_INFO;
#pragma pack(pop)

    inline void SetThreadName( DWORD dwThreadID, char* threadName)
    {
        Sleep(10);
        THREADNAME_INFO info;
        info.dwType = 0x1000;
        info.szName = threadName;
        info.dwThreadID = dwThreadID;
        info.dwFlags = 0;
        __try
        {
            RaiseException( MS_VC_EXCEPTION, 0, sizeof(info)/sizeof(ULONG_PTR), (ULONG_PTR*)&info );
        }
        __except(EXCEPTION_EXECUTE_HANDLER)
        {
        }
    }

};

// ------------------------------------------------------------------------------------------

#endif


