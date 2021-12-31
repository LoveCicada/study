
#ifndef __def_media_source__header__
#define __def_media_source__header__

#include "./TTMediaReaderBaseDef.hpp"
#include "./ITTMediaSampeAVS.hpp"

// -------------------------------------------------------------------------

#define TTMP_SELECTOR_None      L"select.none"
#define TTMP_SELECTOR_Specific  L"select.specific"
#define TTMP_SELECTOR_Order     L"select.order"
#define TTMP_SELECTOR_Config    L"select.ByConfigurations"


// -------------------------------------------------------------------------

/** VFR Reader类型名 */
#define TTMediaReaderType_VFR    L"VFR"

/** CFR Reader类型名*/
#define TTMediaReaderType_CFR    L"CFR"

/** Writer类型名 */
#define TTMEDIAWRITER_Default    L"Default"

// -------------------------------------------------------------------------

/**读文件接口*/
struct ITTMediaReader
{
    enum eOPEN_FILE
    {
        Video = OPEN_Video,
        Audio1 = OPEN_Audio1,
        Audio2 = OPEN_Audio2,
        Audio3 = OPEN_Audio3,
        Audio4 = OPEN_Audio4,
        Audio5 = OPEN_Audio5,
        Audio6 = OPEN_Audio6,
        Audio7 = OPEN_Audio7,
        Audio8 = OPEN_Audio8,
        Audio9 = OPEN_Audio9,
        Audio10 = OPEN_Audio10,
        Audio11 = OPEN_Audio11,
        Audio12 = OPEN_Audio12,
        Audio13 = OPEN_Audio13,
        Audio14 = OPEN_Audio14,
        Audio15 = OPEN_Audio15,
        Audio16 = OPEN_Audio16,
        Text = OPEN_Text,
    };

    /** 打开文件
    @param lpszFilename 打开文件的文件名
    @param uiOpenFlags 打开文件取文件内容的类型
    @param lpszSelectorName 指定选择读文件插件的方法
    @param pErrorInfo 用于通知信息，通常用于返回详细错误信息
    @return >=0 成功，<0失败
    @see  eOPEN_FILE, ITTNotify
    */
    virtual int     Open( const wchar_t* lpszFilename, int uiOpenFlags, const wchar_t* lpszSelectorName = NULL, ITTNotify* pErrorInfo = NULL ) = 0;

    /** 获取文件信息
    @return >=0 成功，<0失败
    @see  TTMPlayerFileFormat
    */
    virtual int     GetFileFormat( TTMPlayerFileFormat& fileInfo ) = 0;

    /** 设置输出的帧率(仅CFR Reader支持)，音频格式(暂时不支持)，视频格式(暂时不支持)，
    @return >=0 成功，<0失败
    @see  TTMPlayerFileFormat
    @note 目前不支持设置输出的音频，视频格式，输出帧率仅CFR Reader支持
    */
    virtual int     SetOutputFormat( const TTMPlayerTimeBase& ttTimeBase, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat ) = 0;
    
    /** 设置读取文件的范围，Reader进入Play模式，[inPos, outPos), pos是时间，单位是100ns, 1s== 1000*1000*1000ns；
    @note 在没有设置范围时, Reader处于Seek模式，设置后处于Play模式
    @return >=0 成功，<0失败
    @Stop
    */
    virtual int     Start(REFERENCE_TIME inPos = NULL, REFERENCE_TIME outPos = NULL) = 0;
    
    /** 读取指定时刻的sample,
    @param videoSample 视频sample, 
    @param framePos 指定sample的时刻，单位是100ns，在Play模式下面仅CFR Reader有效，
    @param iStreamIdx 读取的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPVideoSample
    @note 不是精确的位置，时刻单位是100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    /** 读取指定时刻的sample,
    @param audioSample 音频sample, 
    @param framePos 指定sample的时刻，单位是100ns，在Play模式下面仅CFR Reader有效，
    @param iStreamIdx 读取的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPVideoSample
    @note 不是精确的位置，时刻单位是100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    /** 读取指定时刻的sample,
    @param subSample 字幕sample, 
    @param framePos 指定sample的时刻，单位是100ns，在Play模式下面仅CFR Reader有效，
    @param iStreamIdx 读取的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPSubSample
    @note 不是精确的位置，时刻单位是100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    /** 停止以Play模式读取文件，Reader进入Seek模式
    @return >=0 成功，<0失败
    @note 使Reader处于Seek模式
    @Start
    */
    virtual int     Stop() = 0;

    /** 关闭文件
    @return >=0 成功，<0失败
    @see Open
    */
    virtual int     Close() = 0;

    /** 销毁Reader对象
    @return >=0 成功，<0失败
    */
    virtual int     Destroy() = 0;
};



// -------------------------------------------------------------------------

/** 初始化MediaReader库, 用于LoadLibrary方式 */
#define ADDR_INIT_MEDIA_READER_LIB      "TT_InitMediaReaderLib"

/** 创建VFR Reader的函数名, 用于LoadLibrary方式*/
#define ADDR_CREATE_MEDIA_READER        "TT_CreateMediaReader"

/** 创建VFR Reader, CFR Reader的函数名, 用于LoadLibrary方式*/
#define ADDR_CREATE_MEDIA_READEREX      "TT_CreateMediaReaderEx"

/** 销毁MediaReader库的函数名, 用于LoadLibrary方式 */
#define ADDR_UNINIT_MEDIA_READER_LIB    "TT_UninitMediaReaderLib"


// -------------------------------------------------------------------------

/** 初始化MediaReader库函数类型, 用于LoadLibrary方式 */
typedef int             (*FUNC_InitMediaReaderLib_t)(const wchar_t* lpszPluginFolder);

/** 创建VFR Reader的函数类型, 用于LoadLibrary方式*/
typedef ITTMediaReader* (*FUNC_CreateMediaReader_t)();

/** 创建VFR Reader, CFR Reader的函数类型, 用于LoadLibrary方式*/
typedef ITTMediaReader* (*FUNC_CreateMediaReaderEx_t)(const wchar_t* TTMediaReaderType);

/** 销毁MediaReader库的函数类型, 用于LoadLibrary方式 */
typedef int             (*FUNC_UninitMediaReaderLib_t)();

#endif
