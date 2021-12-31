
#ifndef __def__media_writer__hpp_header__
#define __def__media_writer__hpp_header__

struct ParamAny
{
};

/**写文件接口*/
struct ITTMediaWriter
{
    virtual int     GetEncodeFormat(const TTMPlayerCompileFormat& ttmpFormat, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat) = 0;

    /** 打开文件
    @param lpszFilename 写入文件的文件名
    @param ttmpFormat 写入文件格式
    @param pErrorInfo 用于通知信息，通常用于返回详细错误信息
    @return >=0 成功，<0失败
    @see ITTNotify
    */
    virtual int     Open( const wchar_t* lpszFilename, const TTMPlayerCompileFormat& ttmpFormat, ITTNotify* pErrorInfo = NULL ) = 0;

    virtual int     Start() = 0;
    
    /** 写入视频的sample,
    @param videoSample 视频sample, 
    @param iiFrameId 视频帧号
    @param iStreamIdx 写入的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPVideoSample
    @note 不是精确的位置，时刻单位是100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPVideoSamplePtr videoSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

    /** 写入音频的sample,
    @param audioSample 音频sample, 
    @param iiFrameId 音频帧号
    @param iStreamIdx 写入的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPAudioSample
    @note 不是精确的位置，时刻单位是100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPAudioSamplePtr audioSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

    /** 写入字幕的sample,
    @param subSample 字幕sample, 
    @param iStreamIdx 写入的媒体流ID, 暂时没有用 
    @return >=0 成功，<0失败
    @see ITTMPSubSample
    @note 不是精确的位置，时刻单位是100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPSubSamplePtr subSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

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

#endif

