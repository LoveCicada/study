
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

/** VFR Reader������ */
#define TTMediaReaderType_VFR    L"VFR"

/** CFR Reader������*/
#define TTMediaReaderType_CFR    L"CFR"

/** Writer������ */
#define TTMEDIAWRITER_Default    L"Default"

// -------------------------------------------------------------------------

/**���ļ��ӿ�*/
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

    /** ���ļ�
    @param lpszFilename ���ļ����ļ���
    @param uiOpenFlags ���ļ�ȡ�ļ����ݵ�����
    @param lpszSelectorName ָ��ѡ����ļ�����ķ���
    @param pErrorInfo ����֪ͨ��Ϣ��ͨ�����ڷ�����ϸ������Ϣ
    @return >=0 �ɹ���<0ʧ��
    @see  eOPEN_FILE, ITTNotify
    */
    virtual int     Open( const wchar_t* lpszFilename, int uiOpenFlags, const wchar_t* lpszSelectorName = NULL, ITTNotify* pErrorInfo = NULL ) = 0;

    /** ��ȡ�ļ���Ϣ
    @return >=0 �ɹ���<0ʧ��
    @see  TTMPlayerFileFormat
    */
    virtual int     GetFileFormat( TTMPlayerFileFormat& fileInfo ) = 0;

    /** ���������֡��(��CFR Reader֧��)����Ƶ��ʽ(��ʱ��֧��)����Ƶ��ʽ(��ʱ��֧��)��
    @return >=0 �ɹ���<0ʧ��
    @see  TTMPlayerFileFormat
    @note Ŀǰ��֧�������������Ƶ����Ƶ��ʽ�����֡�ʽ�CFR Reader֧��
    */
    virtual int     SetOutputFormat( const TTMPlayerTimeBase& ttTimeBase, TTMediaPlayerVideoFormat* stuVideoFormat, TTMediaPlayerAudioFormat* stuAudioFormat ) = 0;
    
    /** ���ö�ȡ�ļ��ķ�Χ��Reader����Playģʽ��[inPos, outPos), pos��ʱ�䣬��λ��100ns, 1s== 1000*1000*1000ns��
    @note ��û�����÷�Χʱ, Reader����Seekģʽ�����ú���Playģʽ
    @return >=0 �ɹ���<0ʧ��
    @Stop
    */
    virtual int     Start(REFERENCE_TIME inPos = NULL, REFERENCE_TIME outPos = NULL) = 0;
    
    /** ��ȡָ��ʱ�̵�sample,
    @param videoSample ��Ƶsample, 
    @param framePos ָ��sample��ʱ�̣���λ��100ns����Playģʽ�����CFR Reader��Ч��
    @param iStreamIdx ��ȡ��ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPVideoSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPVideoSamplePtr& videoSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    /** ��ȡָ��ʱ�̵�sample,
    @param audioSample ��Ƶsample, 
    @param framePos ָ��sample��ʱ�̣���λ��100ns����Playģʽ�����CFR Reader��Ч��
    @param iStreamIdx ��ȡ��ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPVideoSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPAudioSamplePtr& audioSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

    /** ��ȡָ��ʱ�̵�sample,
    @param subSample ��Ļsample, 
    @param framePos ָ��sample��ʱ�̣���λ��100ns����Playģʽ�����CFR Reader��Ч��
    @param iStreamIdx ��ȡ��ý����ID, ��ʱû���� 
    @return >=0 �ɹ���<0ʧ��
    @see ITTMPSubSample
    @note ���Ǿ�ȷ��λ�ã�ʱ�̵�λ��100ns, 1s== 1000*1000*1000ns
    */
    virtual int     ReadSamples( OUT ITTMPSubSamplePtr& subSample, REFERENCE_TIME framePos, int iStreamIdx = -1) = 0;

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



// -------------------------------------------------------------------------

/** ��ʼ��MediaReader��, ����LoadLibrary��ʽ */
#define ADDR_INIT_MEDIA_READER_LIB      "TT_InitMediaReaderLib"

/** ����VFR Reader�ĺ�����, ����LoadLibrary��ʽ*/
#define ADDR_CREATE_MEDIA_READER        "TT_CreateMediaReader"

/** ����VFR Reader, CFR Reader�ĺ�����, ����LoadLibrary��ʽ*/
#define ADDR_CREATE_MEDIA_READEREX      "TT_CreateMediaReaderEx"

/** ����MediaReader��ĺ�����, ����LoadLibrary��ʽ */
#define ADDR_UNINIT_MEDIA_READER_LIB    "TT_UninitMediaReaderLib"


// -------------------------------------------------------------------------

/** ��ʼ��MediaReader�⺯������, ����LoadLibrary��ʽ */
typedef int             (*FUNC_InitMediaReaderLib_t)(const wchar_t* lpszPluginFolder);

/** ����VFR Reader�ĺ�������, ����LoadLibrary��ʽ*/
typedef ITTMediaReader* (*FUNC_CreateMediaReader_t)();

/** ����VFR Reader, CFR Reader�ĺ�������, ����LoadLibrary��ʽ*/
typedef ITTMediaReader* (*FUNC_CreateMediaReaderEx_t)(const wchar_t* TTMediaReaderType);

/** ����MediaReader��ĺ�������, ����LoadLibrary��ʽ */
typedef int             (*FUNC_UninitMediaReaderLib_t)();

#endif
