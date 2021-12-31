
#ifndef __TT_DEF_AFD_PRCESS__HEADER__
#define __TT_DEF_AFD_PRCESS__HEADER__

#include "./TTMediaUtilityBase.h"

/** ���ļ������ö�ȡ���޸�AFD��Ϣ */
struct ITTAfdProcess
{
    /** ���ļ�
    @param lpszFilename ���ļ����ļ���
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int Open(const wchar_t* strFile) = 0;

    /** ��дAFD��Ϣ
    @param bAFD [out]��ȡ��AFDֵ
    @return >0 �ɹ���== 0 ������AFD��Ϣ��<0ʧ��
    */
    virtual int ReadAFD(BYTE& bAFD) = 0;

    /** ��дAFD��Ϣ
    @param bAFD [out]��ȡ��AFDֵ
    @return >0 �ɹ���== 0 ������AFD��Ϣ��<0ʧ��
    */
    virtual int WriteAFD(BYTE bAFD) = 0;

    /** �ر��ļ�
    @return >=0 �ɹ���< 0 ʧ��
    */
    virtual int CloseFile() = 0;

    /** ���ٶ��� */
    virtual int Destroy() = 0;
};

#endif
