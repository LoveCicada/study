

#ifndef __TT_DEF_QUERY_IMAGE__HEADER__
#define __TT_DEF_QUERY_IMAGE__HEADER__

#include "./TTMediaUtilityBase.h"

namespace TT
{

struct TTBasicImage
{
    LPBYTE lpBuffer;            /**< ͼ������ */
    int iWidth;                 /**< ���  */
    int iHeight;                /**< �߶� */
    int iPitch;                 /**< һ����ռ�õ��ֽ��� */
    TTPixelFormat ePixelFmt;    /**< ���ظ�ʽ */
};

/** ��ͷ�仯����� */
struct TTShotCutResult
{
    /** ��ͷ�仯���� */
    enum CUT_TYPE
    {
        CUT_TYPE_NULL,      /** �Ǿ�ͷ�л� */
        CUT_TYPE_ABRUPT,    /** �б� */
        CUT_TYPE_GRADUAL,   /** ���� */
        CUT_TYPE_FLASH,     /** ���� */
        CUT_TYPE_ADDITON,   /** ��֡ */
    };

	CUT_TYPE eCutType;              /**< �仯����*/
	unsigned int begin_frame_num;   /**< �仯�Ŀ�ʼ֡�� */
	unsigned int end_frame_num;     /**< �仯�Ľ���֡�� */
	unsigned int reserved[13];      /**< ���� */
}; 

/** �ؼ�֡ʶ�����*/
struct TTShotDetectionParam
{
    int iSensitivity;           /**< ת��ʶ�𾫶� */
    int iMinLength;             /**< ת����С֡ */
    int iDistrubClearThreshold; /**< �����Ŷ� */
    int iSlotMergeThreshold;    /**< �ںϳ̶� */
    int iShotMerger;            /**< �Ƿ��ȡ�����ںϡ�0Ϊ����ȡ��1Ϊ��ȡ */
    int iShotDisturbClear;      /**< �Ƿ��ȡ������š�0Ϊ����ȡ��1Ϊ��ȡ */
    int iShotType;              /**< ת����ʽ,Ϊ0ʱ��ʾ�����꣬Ϊ1ʱ��ʾ��ʼ�� */

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
    GUID		guidFileType;	//�ļ���ʽ��GUID
    DWORD		dwFOURCC;		//ý������
};
struct SbtID
{
    DWORD		iFileType;	//�ļ���ʽ��GUID
    DWORD		iMediaId;		//ý������
};
struct TTShotDetectItem
{
    enum ID_TYPE
    {
        ID_TYPE_NONE,
        ID_TYPE_NOVA,
        ID_TYPE_SBT,
    };

    wchar_t		szFileName[MAX_PACKAGE_NAME];	//�ļ�·��

    ID_TYPE idType;
    union
    {
        NovaID Nova;
        SbtID Sbt;
    }Id;
    long		lImageWidth;	//������
    long		lImageHeight;	//����߶�
    double		dblFrameRate;	//֡��
    DWORD		dwFileIn;		//�ļ����
    DWORD		dwFileOut;	//�ļ�����
    DWORD		dwTimelineIn;	//ʱ�������
    DWORD		dwTimelineOut;//ʱ���߳���
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

/** ��ͷ�仯�������Դ����ITTShotDetect�������ṩ */
struct ITTShotDetectSource
{
    /** ��������Դ
    @param iIn ��ʼλ��, [iIn, iOut)
    @param iOut ֹͣλ��, [iIn, iOut)
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int Start(int iIn, int iOut) = 0;

    /** ��ȡָ��֡ͼ��
    @param iFrameId ͼ��֡��
    @param ttImage iFrameId��Ӧ��ͼ��Ŀǰ֧��TT_PIX_FMT_RGBA32, TT_PIX_FMT_BGR24, TT_PIX_FMT_YUYV, TT_PIX_FMT_UYVY
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int GetImage(int iFrameId, TTBasicImage& ttImage) = 0;

    /** ֹͣ����Դ
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int Stop() = 0;
};

/** ��ͷ�仯����� */
struct ITTShotDetect
{
    /** ֪ͨ�����Ϣ�Ļص�
    @param pParam �û����� 
    @param iFrameId ��ǰ��֡�� 
    @param bKeyFrame �Ƿ��ǹؼ�֡ 
    @param dblProgress ������Ϣ
    @param image ��ǰ����ͼ��
    @return >= �������
     < 0 ֹͣ���
    */
    typedef BOOL (CALLBACK *FUNC_SHOTDETECT_CB)(void * pParam, int iFrameId, TTShotCutResult* pResult, int iResultCount, double dblProgress, const TTBasicImage* image);

    /** ��ʼ����ͷ�仯�����
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int Init() = 0;

    /** ��ͷ�仯�������Դ�����ļ���ʽ�ṩ
    @param wszFilename ��Ҫ�����ļ��� 
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    @remark ��SetImageSource(ITTShotDetectSource*)����ͬʱ����
    */
    virtual int SetImageSource(const TTShotDetectItem* arrItem, int iItemCount) = 0;

    /** ��ͷ�仯�������Դ���ɵ��������õĽӿڣ���buffer��ʽ��ȡ����Դ
    @param pShotDetectSource ����Դ�ӿ�
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    @remark ��SetImageSource(const wchar_t*)����ͬʱ����
    */
    virtual int SetImageSource(ITTShotDetectSource* pShotDetectSource) = 0;

    /** ���þ�ͷ�仯������
    @param ttDetectionParam ��ͷ�仯������
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int SetShotDetectParam(const TTShotDetectionParam& ttDetectionParam) = 0;

    /** ���þ�ͷ�仯���ķ�����Ϣ
    @param iWidth ͼ����
    @param iHeight ͼ��߶�
    @param ePixelFmt ͼ�����ظ�ʽ
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int SetProcessFormat(int iWidth, int iHeight, TTPixelFormat ePixelFmt) = 0;

    /** ���ü��Ļص�
    @param pShotCallback �ص�����
    @param pShotCallbackParam �ص��û�����
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int SetShotCallback(FUNC_SHOTDETECT_CB pShotCallback, void* pShotCallbackParam) = 0;

    /** ��������Դ
    @param iIn ��ʼλ��, [iIn, iOut)
    @param iOut ֹͣλ��, [iIn, iOut)
    @return >= 0 ��������Դ�ɹ�
    < 0 ��������Դʧ��
    */
    virtual int Start(int iIn, int iOut) = 0;

    /** ��������Դ
    @return >= 0 ��ǰ�Ѿ������λ��
    < 0 ��������Դʧ��
    */
    virtual int GetProgress() = 0;

    /** ֹͣ����Դ
    @return >= 0 ֹͣ����Դ�ɹ�
    < 0 ֹͣ����Դʧ��
    */
    virtual int Stop() = 0;

    /** ��ȡ���������
    @param reports ���صļ������������GetShotReprotsNum()�õ�
    @param iReportCount ���صļ��������ȡ���������������
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int GetShotReprots( TTShotCutResult*& reports, int& iReportCount ) = 0;	

    /** ����ʼ�����ͷ���Դ
    @return >= 0 �ɹ�
    < 0 ʧ�ܴ�����
    */
    virtual int Uninit() = 0;

    /** ��ȡָ��������Ĵ�����Ϣ
    @param error_code ������
    @param info_buffer ���ش�������Ϣ��buffer
    @param buffer_len ���ش�������Ϣ��buffer�ĳ��� 
    @return ������Ϣ�����ȣ�����'\0'
    */
    virtual int GetErrorInfo(int error_code, char *info_buffer, int buffer_len) = 0;

    /** ���ٶ��� */
    virtual int Destroy() = 0;
};

}

#endif
