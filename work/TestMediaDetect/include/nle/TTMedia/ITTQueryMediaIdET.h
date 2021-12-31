
#ifndef __TT_DEF_MEDIADETECT_ET__HEADER__
#define __TT_DEF_MEDIADETECT_ET__HEADER__

#include "./ITTMediaDetect.h"

// {2AED122D-FB46-44d5-AF5F-862FEE3678BD}
DEFINE_GUID(IID_ITTQueryMediaIdET, 0x2aed122d, 0xfb46, 0x44d5, 0xaf, 0x5f, 0x86, 0x2f, 0xee, 0x36, 0x78, 0xbd);

struct stu_ETMediaFormatDef;

namespace TT
{
    /** ��Ϣ��ѯ�ӿ�, IID_ITTQueryMediaIdET */
    struct ITTQueryMediaIdET : public ITTQueryMediaId 
    {
        /** ����sdk file id��Ӧ�� guid+fcc����Ҫ����fileId, mediaId, iAudioMediaId����������ֻ������
        @param fileTypeId       nova�ļ�����guid 
        @param dwVideoFcc       nova��Ƶ����fcc
        @param dwAudioFcc       nova��Ƶ����fcc
        @param fileId           sbt�ļ�id
        @param mediaId          sbt��Ƶid
        @param iAudioMediaId    sbt��Ƶid
        @param pVideo           et�洢����Ƶ��Ϣ
        @param pAudio           et�洢����Ƶ��Ϣ
        @return ������
        */    
        virtual int GetNovaId(GUID& fileTypeId, DWORD& dwVideoFcc, DWORD& dwAudioFcc
            , int fileId, int mediaId, int iAudioMediaId
            , stu_ETMediaFormatDef* pVideo = NULL, stu_ETMediaFormatDef* pAudio = NULL
            , intptr_t reserved0 = NULL, intptr_t reserved1 = NULL) = 0;
    };

}

#endif
