
#ifndef __def__media_writer__hpp_header__
#define __def__media_writer__hpp_header__

struct ParamAny
{
};

/**д�ļ��ӿ�*/
struct ITTMediaWriter
{
    virtual int     GetEncodeFormat(const TTMPlayerCompileFormat& ttmpFormat, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat) = 0;

    /** ���ļ�
    @param lpszFilename д���ļ����ļ���
    @param ttmpFormat д���ļ���ʽ
    @param pErrorInfo ����֪ͨ��Ϣ��ͨ�����ڷ�����ϸ������Ϣ
    @return >=0 �ɹ���<0ʧ��
    @see ITTNotify
    */
    virtual int     Open( const wchar_t* lpszFilename, const TTMPlayerCompileFormat& ttmpFormat, ITTNotify* pErrorInfo = NULL ) = 0;

    virtual int     Start() = 0;
    
    /** д����Ƶ��sample,
    @param videoSample ��Ƶsample, 
    @param iiFrameId ��Ƶ֡��
    @param iStreamIdx д���ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPVideoSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPVideoSamplePtr videoSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

    /** д����Ƶ��sample,
    @param audioSample ��Ƶsample, 
    @param iiFrameId ��Ƶ֡��
    @param iStreamIdx д���ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPAudioSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPAudioSamplePtr audioSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

    /** д����Ļ��sample,
    @param subSample ��Ļsample, 
    @param iStreamIdx д���ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPSubSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s == 1000*1000*1000ns
    */
    virtual int     WriteSample( IN ITTMPSubSamplePtr subSample, __int64 iiFrameId, int iStreamIdx = -1) = 0;

    /** ֹͣ��Playģʽ��ȡ�ļ���Reader����Seekģʽ
    @return >=0 �ɹ���<0ʧ��
    @note ʹReader����Seekģʽ
    @Start
    */
    virtual int     Stop() = 0;

    /** �ر��ļ�
    @return >=0 �ɹ���<0ʧ��
    @see Open
    */
    virtual int     Close() = 0;

    /** ����Reader����
    @return >=0 �ɹ���<0ʧ��
    */
    virtual int     Destroy() = 0;
};

#endif

