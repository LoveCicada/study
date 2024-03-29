
#ifndef __def__ttmediautility_base__header__
#define __def__ttmediautility_base__header__

#include "./ITTAdaptWinDefine.h"


// {5A381988-6EFF-4236-8EFA-0FCE9EA160D8}
DEFINE_GUID(IID_TTMediaReader, 0x5a381988, 0x6eff, 0x4236, 0x8e, 0xfa, 0xf, 0xce, 0x9e, 0xa1, 0x60, 0xd8);

// {C5390FB9-D0DB-4a2e-ACCF-C139E05A2499}
DEFINE_GUID(IID_TTMediaReaderVFR, 0xc5390fb9, 0xd0db, 0x4a2e, 0xac, 0xcf, 0xc1, 0x39, 0xe0, 0x5a, 0x24, 0x99);

// {4E2FF40E-B1CE-429f-B0D2-6913ADBAC7B2}
DEFINE_GUID(IID_TTMediaTranscode, 0x4e2ff40e, 0xb1ce, 0x429f, 0xb0, 0xd2, 0x69, 0x13, 0xad, 0xba, 0xc7, 0xb2);

// {7843EAB8-F565-4e12-B355-E20C2AFAC998}
DEFINE_GUID(IID_TTMediaTranscodeEx, 0x7843eab8, 0xf565, 0x4e12, 0xb3, 0x55, 0xe2, 0xc, 0x2a, 0xfa, 0xc9, 0x98);

// {52D75DF9-6FF7-4870-9747-9028D1975BB0}
DEFINE_GUID(IID_TTMediaDetect, 0x52d75df9, 0x6ff7, 0x4870, 0x97, 0x47, 0x90, 0x28, 0xd1, 0x97, 0x5b, 0xb0);

// {D6BB044D-83AC-49c1-8A03-62F2001BB220}
DEFINE_GUID(IID_TTMediaDetect2, 
            0xd6bb044d, 0x83ac, 0x49c1, 0x8a, 0x3, 0x62, 0xf2, 0x0, 0x1b, 0xb2, 0x20);

// {BA46389A-20C2-4c4b-9E50-7588A2B198E6}
DEFINE_GUID(IID_TTQueryInfo, 0xba46389a, 0x20c2, 0x4c4b, 0x9e, 0x50, 0x75, 0x88, 0xa2, 0xb1, 0x98, 0xe6);

// {0526FF22-929B-4cbf-8871-D3BC12377F88}
DEFINE_GUID(IID_TTMediaTCReader, 0x526ff22, 0x929b, 0x4cbf, 0x88, 0x71, 0xd3, 0xbc, 0x12, 0x37, 0x7f, 0x88);

// {3743875B-D0E0-4553-A64B-04582B245C04}
DEFINE_GUID(IID_TTMediaFileTC, 0x3743875b, 0xd0e0, 0x4553, 0xa6, 0x4b, 0x4, 0x58, 0x2b, 0x24, 0x5c, 0x4);

// {391C157E-E5AC-46a1-BE7C-55A4E3FC9A66}
DEFINE_GUID(IID_TTShotDetect, 0x391c157e, 0xe5ac, 0x46a1, 0xbe, 0x7c, 0x55, 0xa4, 0xe3, 0xfc, 0x9a, 0x66);

// {8A8164EB-20BB-42e6-BDCC-4D6FC0953EA0}
DEFINE_GUID(IID_TTAfdProcess, 0x8a8164eb, 0x20bb, 0x42e6, 0xbd, 0xcc, 0x4d, 0x6f, 0xc0, 0x95, 0x3e, 0xa0);

// {778A4584-1B31-4d76-8102-6B476C7E5862}
DEFINE_GUID(IID_ITTVideoStandardInfo, 0x778a4584, 0x1b31, 0x4d76, 0x81, 0x2, 0x6b, 0x47, 0x6c, 0x7e, 0x58, 0x62);

// {62C0E2F9-44D5-44be-87DD-CF7BD47E6936}
DEFINE_GUID(IID_ITTQueryMediaId, 0x62c0e2f9, 0x44d5, 0x44be, 0x87, 0xdd, 0xcf, 0x7b, 0xd4, 0x7e, 0x69, 0x36);

// {D1E1B9A3-CBA1-4681-8CD5-0E527D31D713}
DEFINE_GUID(IID_ITTConvertCCFile, 0xd1e1b9a3, 0xcba1, 0x4681, 0x8c, 0xd5, 0xe, 0x52, 0x7d, 0x31, 0xd7, 0x13);

#define FUNC_NAME_TT_MediaUtility_Init "TT_MediaUtility_Init"
#define FUNC_NAME_TT_MediaUtility_CreateObject "TT_MediaUtility_CreateObject"
#define FUNC_NAME_TUNC_TT_MediaUtility_ErrorInfo "TT_MediaUtility_ErrorInfo"
#define FUNC_NAME_TT_MediaUtility_Uninit "TT_MediaUtility_Uninit"

typedef int (*FUNC_TT_MediaUtility_Init)();
typedef void* (*FUNC_TT_MediaUtility_CreateObject)(const _GUID& guid);
typedef const wchar_t* (*TUNC_TT_MediaUtility_ErrorInfo)(int nErrorCode);
typedef int (*FUNC_TT_MediaUtility_Uninit)();


#endif
