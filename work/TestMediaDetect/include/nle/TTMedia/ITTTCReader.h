
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
        int raw_data[4];			//4字节LTC数据
    };
    struct TC_DATA
    {
        BOOL isLtcData;
        BOOL isVitcData;
        TIME_CODE_DATA LtcData;
        TIME_CODE_DATA VitcData;
    };
#include <PopPack.h>

/** 读TC码接口*/
struct ITTMediaFileTC
{
    /** 打开文件
    @param lpszFilename 打开文件的文件名
    @return >=0 成功，<0失败
    */
    virtual int Open(LPCTSTR lpszFile, double fps) = 0;

    /** 获取指定帧的TC码
    @return >=0 成功，<0失败
    */
    virtual int GetTC(__int64& tc) = 0;

    /** 关闭文件
    @return >=0 成功，<0失败
    */
    virtual int Close() = 0;

    /** 销毁对象 */
    virtual int Destroy() = 0;
};

/** 读TC码接口*/
struct ITTMediaTCReader
{
    /** 打开文件
    @param lpszFilename 打开文件的文件名
    @return >=0 成功，<0失败
    */
    virtual int Open(LPCTSTR lpszFile) = 0;

    /** 获取文件总帧数
    @return 文件总帧数
    */
    virtual int GetFramesCount() = 0;

    /** 获取指定帧的TC码
    @return >=0 成功，<0失败
    */
    virtual int GetTC(int frameIndex, TC_DATA& tc) = 0;

    /** 关闭文件
    @return >=0 成功，<0失败
    */
    virtual int Close() = 0;

    /** 销毁对象 */
    virtual int Destroy() = 0;
};

}

#endif
