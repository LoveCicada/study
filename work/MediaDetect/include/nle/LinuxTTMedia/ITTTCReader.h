
#ifndef __TT_DEF_TIMECODE_READER__HEADER__
#define __TT_DEF_TIMECODE_READER__HEADER__

#include "./TTMediaUtilityBase.h"

namespace TT
{
#include <PshPack1.h>
    struct TIME_CODE_DATA
    {
        int hour;
        int minute;
        int second;
        int frame;
        BOOL drop_frame_flag;
        BOOL field_id_flag;			//Field identification flag
        int raw_data[4];			//4�ֽ�LTC����
    };
    struct TC_DATA
    {
        BOOL isLtcData;
        BOOL isVitcData;
        TIME_CODE_DATA LtcData;
        TIME_CODE_DATA VitcData;
    };
#include <PopPack.h>

/** ��TC��ӿ�*/
struct ITTMediaFileTC
{
    /** ���ļ�
    @param lpszFilename ���ļ����ļ���
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int Open(LPCTSTR lpszFile, double fps) = 0;

    /** ��ȡָ��֡��TC��
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int GetTC(__int64& tc) = 0;

    /** �ر��ļ�
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int Close() = 0;

    /** ���ٶ��� */
    virtual int Destroy() = 0;
};

/** ��TC��ӿ�*/
struct ITTMediaTCReader
{
    /** ���ļ�
    @param lpszFilename ���ļ����ļ���
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int Open(LPCTSTR lpszFile) = 0;

    /** ��ȡ�ļ���֡��
    @return �ļ���֡��
    */
    virtual int GetFramesCount() = 0;

    /** ��ȡָ��֡��TC��
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int GetTC(int frameIndex, TC_DATA& tc) = 0;

    /** �ر��ļ�
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int Close() = 0;

    /** ���ٶ��� */
    virtual int Destroy() = 0;
};

}

#endif
