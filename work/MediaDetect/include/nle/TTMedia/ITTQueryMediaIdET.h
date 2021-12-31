
#ifndef __TT_DEF_MEDIADETECT_ET__HEADER__
#define __TT_DEF_MEDIADETECT_ET__HEADER__

#include "./ITTMediaDetect.h"

// {2AED122D-FB46-44d5-AF5F-862FEE3678BD}
DEFINE_GUID(IID_ITTQueryMediaIdET, 0x2aed122d, 0xfb46, 0x44d5, 0xaf, 0x5f, 0x86, 0x2f, 0xee, 0x36, 0x78, 0xbd);

struct stu_ETMediaFormatDef;

namespace TT
{
    /** 信息查询接口, IID_ITTQueryMediaIdET */
    struct ITTQueryMediaIdET : public ITTQueryMediaId 
    {
        /** 返回sdk file id对应的 guid+fcc，主要依据fileId, mediaId, iAudioMediaId，其他参数只做辅助
        @param fileTypeId       nova文件类型guid 
        @param dwVideoFcc       nova视频编码fcc
        @param dwAudioFcc       nova音频编码fcc
        @param fileId           sbt文件id
        @param mediaId          sbt视频id
        @param iAudioMediaId    sbt音频id
        @param pVideo           et存储的视频信息
        @param pAudio           et存储的音频信息
        @return 错误码
        */    
        virtual int GetNovaId(GUID& fileTypeId, DWORD& dwVideoFcc, DWORD& dwAudioFcc
            , int fileId, int mediaId, int iAudioMediaId
            , stu_ETMediaFormatDef* pVideo = NULL, stu_ETMediaFormatDef* pAudio = NULL
            , intptr_t reserved0 = NULL, intptr_t reserved1 = NULL) = 0;
    };

}

#endif
