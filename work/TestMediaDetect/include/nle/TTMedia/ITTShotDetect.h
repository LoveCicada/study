

#ifndef __TT_DEF_QUERY_IMAGE__HEADER__
#define __TT_DEF_QUERY_IMAGE__HEADER__

#include "./TTMediaUtilityBase.h"

namespace TT
{

struct TTBasicImage
{
    LPBYTE lpBuffer;            /**< 图像数据 */
    int iWidth;                 /**< 宽度  */
    int iHeight;                /**< 高度 */
    int iPitch;                 /**< 一行所占用的字节数 */
    TTPixelFormat ePixelFmt;    /**< 像素格式 */
};

/** 镜头变化检测项 */
struct TTShotCutResult
{
    /** 镜头变化类型 */
    enum CUT_TYPE
    {
        CUT_TYPE_NULL,      /** 非镜头切换 */
        CUT_TYPE_ABRUPT,    /** 切变 */
        CUT_TYPE_GRADUAL,   /** 渐变 */
        CUT_TYPE_FLASH,     /** 闪光 */
        CUT_TYPE_ADDITON,   /** 夹帧 */
    };

	CUT_TYPE eCutType;              /**< 变化类型*/
	unsigned int begin_frame_num;   /**< 变化的开始帧号 */
	unsigned int end_frame_num;     /**< 变化的结束帧号 */
	unsigned int reserved[13];      /**< 保留 */
}; 

/** 关键帧识别参数*/
struct TTShotDetectionParam
{
    int iSensitivity;           /**< 转场识别精度 */
    int iMinLength;             /**< 转场最小帧 */
    int iDistrubClearThreshold; /**< 抗干扰度 */
    int iSlotMergeThreshold;    /**< 融合程度 */
    int iShotMerger;            /**< 是否采取相似融合。0为不采取，1为采取 */
    int iShotDisturbClear;      /**< 是否采取清除干扰。0为不采取，1为采取 */
    int iShotType;              /**< 转场方式,为0时显示结束贞，为1时显示开始贞 */

    TTShotDetectionParam()
    { 
        iSensitivity = 50;
        iMinLength = 5;
        iDistrubClearThreshold = 50;
        iSlotMergeThreshold = 50;
        iShotMerger = 1;
        iShotDisturbClear = 1;
        iShotType = 1;
    }
};

// form TT
struct NovaID
{
    GUID		guidFileType;	//文件格式的GUID
    DWORD		dwFOURCC;		//媒体类型
};
struct SbtID
{
    DWORD		iFileType;	//文件格式的GUID
    DWORD		iMediaId;		//媒体类型
};
struct TTShotDetectItem
{
    enum ID_TYPE
    {
        ID_TYPE_NONE,
        ID_TYPE_NOVA,
        ID_TYPE_SBT,
    };

    wchar_t		szFileName[MAX_PACKAGE_NAME];	//文件路径

    ID_TYPE idType;
    union
    {
        NovaID Nova;
        SbtID Sbt;
    }Id;
    long		lImageWidth;	//幅面宽度
    long		lImageHeight;	//幅面高度
    double		dblFrameRate;	//帧率
    DWORD		dwFileIn;		//文件入点
    DWORD		dwFileOut;	//文件出点
    DWORD		dwTimelineIn;	//时间线入点
    DWORD		dwTimelineOut;//时间线出点
    TTShotDetectItem()
    {
        Reset();
    }
    TTShotDetectItem(const TTShotDetectItem& src)
    {
        Reset();
    }
    TTShotDetectItem& operator = (const TTShotDetectItem& src)
    {
        if (&src != this)
        {
            _tcscpy_s(szFileName, src.szFileName);
            memcpy(&Id, &src.Id, sizeof(Id));
            idType = src.idType;
            lImageWidth = src.lImageWidth;
            lImageHeight = src.lImageHeight;
            dblFrameRate = src.dblFrameRate;
            dwFileIn = src.dwFileIn;
            dwFileOut = src.dwFileOut;
            dwTimelineIn = src.dwTimelineIn;
            dwTimelineOut = src.dwTimelineOut;
        }
        return *this;
    }

    void Reset()
    {
        memset(szFileName, 0, sizeof(szFileName));
        memset(&Id, 0, sizeof(Id));
        idType = ID_TYPE_NONE;
        lImageWidth = 0;
        lImageHeight = 0;
        dblFrameRate = 0;
        dwFileIn = 0;
        dwFileOut = -1;
        dwTimelineIn = 0;
        dwTimelineOut = -1;
    }
};

/** 镜头变化检测数据源，由ITTShotDetect调用者提供 */
struct ITTShotDetectSource
{
    /** 启动数据源
    @param iIn 起始位置, [iIn, iOut)
    @param iOut 停止位置, [iIn, iOut)
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int Start(int iIn, int iOut) = 0;

    /** 获取指定帧图像
    @param iFrameId 图像帧号
    @param ttImage iFrameId对应的图像，目前支持TT_PIX_FMT_RGBA32, TT_PIX_FMT_BGR24, TT_PIX_FMT_YUYV, TT_PIX_FMT_UYVY
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int GetImage(int iFrameId, TTBasicImage& ttImage) = 0;

    /** 停止数据源
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int Stop() = 0;
};

/** 镜头变化检测器 */
struct ITTShotDetect
{
    /** 通知检测信息的回调
    @param pParam 用户数据 
    @param iFrameId 当前的帧号 
    @param bKeyFrame 是否是关键帧 
    @param dblProgress 进度信息
    @param image 当前检测的图像
    @return >= 继续检测
     < 0 停止检测
    */
    typedef BOOL (CALLBACK *FUNC_SHOTDETECT_CB)(void * pParam, int iFrameId, TTShotCutResult* pResult, int iResultCount, double dblProgress, const TTBasicImage* image);

    /** 初始化镜头变化检测器
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int Init() = 0;

    /** 镜头变化检测数据源，以文件方式提供
    @param wszFilename 需要检测的文件名 
    @return >= 0 成功
    < 0 失败错误码
    @remark 和SetImageSource(ITTShotDetectSource*)不能同时调用
    */
    virtual int SetImageSource(const TTShotDetectItem* arrItem, int iItemCount) = 0;

    /** 镜头变化检测数据源，由调用者设置的接口，以buffer方式获取数据源
    @param pShotDetectSource 数据源接口
    @return >= 0 成功
    < 0 失败错误码
    @remark 和SetImageSource(const wchar_t*)不能同时调用
    */
    virtual int SetImageSource(ITTShotDetectSource* pShotDetectSource) = 0;

    /** 设置镜头变化检测参数
    @param ttDetectionParam 镜头变化检测参数
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int SetShotDetectParam(const TTShotDetectionParam& ttDetectionParam) = 0;

    /** 设置镜头变化检测的幅面信息
    @param iWidth 图像宽度
    @param iHeight 图像高度
    @param ePixelFmt 图像像素格式
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int SetProcessFormat(int iWidth, int iHeight, TTPixelFormat ePixelFmt) = 0;

    /** 设置检测的回调
    @param pShotCallback 回调函数
    @param pShotCallbackParam 回调用户数据
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int SetShotCallback(FUNC_SHOTDETECT_CB pShotCallback, void* pShotCallbackParam) = 0;

    /** 启动数据源
    @param iIn 起始位置, [iIn, iOut)
    @param iOut 停止位置, [iIn, iOut)
    @return >= 0 启动数据源成功
    < 0 启动数据源失败
    */
    virtual int Start(int iIn, int iOut) = 0;

    /** 启动数据源
    @return >= 0 当前已经处理的位置
    < 0 启动数据源失败
    */
    virtual int GetProgress() = 0;

    /** 停止数据源
    @return >= 0 停止数据源成功
    < 0 停止数据源失败
    */
    virtual int Stop() = 0;

    /** 获取场景检测结果
    @param reports 返回的检测结果，数量由GetShotReprotsNum()得到
    @param iReportCount 返回的检测结果，获取场景检测结果的数量
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int GetShotReprots( TTShotCutResult*& reports, int& iReportCount ) = 0;	

    /** 反初始化，释放资源
    @return >= 0 成功
    < 0 失败错误码
    */
    virtual int Uninit() = 0;

    /** 获取指定错误码的错误信息
    @param error_code 错误码
    @param info_buffer 返回错误码信息的buffer
    @param buffer_len 返回错误码信息的buffer的长度 
    @return 错误信息本身长度，包含'\0'
    */
    virtual int GetErrorInfo(int error_code, char *info_buffer, int buffer_len) = 0;

    /** 销毁对象 */
    virtual int Destroy() = 0;
};

}

#endif
