
#ifndef __TT_DEF_AFD_PRCESS__HEADER__
#define __TT_DEF_AFD_PRCESS__HEADER__

#include "./TTMediaUtilityBase.h"

/** 打开文件，设置读取、修改AFD信息 */
struct ITTAfdProcess
{
    /** 打开文件
    @param lpszFilename 打开文件的文件名
    @return >=0 成功，<0失败
    */
    virtual int Open(const wchar_t* strFile) = 0;

    /** 读写AFD信息
    @param bAFD [out]读取的AFD值
    @return >0 成功，== 0 不存在AFD信息，<0失败
    */
    virtual int ReadAFD(BYTE& bAFD) = 0;

    /** 读写AFD信息
    @param bAFD [out]读取的AFD值
    @return >0 成功，== 0 不存在AFD信息，<0失败
    */
    virtual int WriteAFD(BYTE bAFD) = 0;

    /** 关闭文件
    @return >=0 成功，< 0 失败
    */
    virtual int CloseFile() = 0;

    /** 销毁对象 */
    virtual int Destroy() = 0;
};

#endif
