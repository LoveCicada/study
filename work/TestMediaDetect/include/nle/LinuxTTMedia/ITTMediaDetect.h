
#ifndef __TT_DEF_MEDIADETECT__HEADER__
#define __TT_DEF_MEDIADETECT__HEADER__

#include "./ITTAdaptWinDefine.h"
#include "./TTMediaUtilityBase.h"

struct stu_ETMediaFormatDef;
struct tagBITMAPINFOHEADER;
struct tWAVEFORMATEX;

namespace TT
{
#define _BIT_(idx) (1<<idx)

#define TT_MEDIA_INFO_VFR               _BIT_(0)    /**< VFR��־λ��~TT_MEDIA_INFO_VFRΪ CFR */
//#define TT_MEDIA_INFO_VBR             _BIT_(1)    /**< VBR��׼λ��~TT_MEDIA_INFO_VBRΪ CBR */
#define TT_MEDIA_INFO_DF                _BIT_(2)    /**< DF��׼λ��~TT_MEDIA_INFO_DFΪ NDF */
#define TT_MEDIA_INFO_ClosedCaption     _BIT_(3)    /**< mxf closed caption */
#define TT_MEDIA_INFO_WithCC            _BIT_(3)    /**< ý���ļ��ں���CC��Ļ */
#define TT_MEDIA_INFO_DV_AVITYPE1       _BIT_(4)    /**< DV AVI TYPE1; */
#define TT_MEDIA_INFO_Raw               _BIT_(31)   /**< RAW��ʽ; */

#define TT_FILE_STATE_ReadAble          _BIT_(0)
#define TT_FILE_STATE_WriteAble         _BIT_(1)
#define TT_FILE_STATE_NeedIndex         _BIT_(2)	/**< �ļ���Ҫ�������� */
#define TT_FILE_STATE_WithIndex         _BIT_(3)	/**< �ļ��������� */
#define TT_FILE_STATE_WithXmlCC         _BIT_(4)    /**< �ļ�����XML CC��Ļ */
#define TT_FILE_STATE_NOVA              _BIT_(29)   /**< SBT֧�ָ��ļ� */
#define TT_FILE_STATE_SBT               _BIT_(30)   /**< SBT֧�ָ��ļ� */
#define TT_FILE_STATE_NeedTranscode     _BIT_(31)   /**< nova ����ֱ�Ӵ��������͵��ļ�����Ҫת�� */


#define TT_AudioChannel_Unknown		    0x00000000
#define TT_AudioChannel_1				0x00000001
#define TT_AudioChannel_2				0x00000002
#define TT_AudioChannel_4				0x00000004	
#define TT_AudioChannel_8				0x00000008
#define TT_AudioChannel_16              0x00000010	//16 
#define TT_AudioChannel_2_DM			0x00000020	//only for AC3,E-AC3: dual mono (2 seperate mono)
#define TT_AudioChannel_3_0_LCR			0x00000040	//only for AC3,E-AC3: 2.1:L,C,R
#define TT_AudioChannel_2_1_LRS			0x00000080	//only for AC3,E-AC3: 2.1:L,R,S
#define TT_AudioChannel_3_1_LCRS		0x00000100	//only for AC3,E-AC3: 3.1:L,C,R,S
#define TT_AudioChannel_3_2_LCRLsRs		0x00000200	//only for AC3,E-AC3: 3.2:L,C,R,Ls,Rs
#define TT_AudioChannel_2_2_LCRS		0x00000400	//only for AC3,E-AC3: 2.2:L,C,R,S
#define TT_AudioChannel_2_1				0x00000800	//only for AC3,E-AC3: 2.1:L,R,Lfe(����)
#define TT_AudioChannel_2_0				0x00001000	// stereo audio
#define TT_AudioChannel_7_1				0x00002000	// 7.1
#define TT_AudioChannel_6		        0x00004000
#define TT_AudioChannel_5_1				0x00008000	//only for DTS:5.1channal; for AC3,EAC3: 5.1.

    struct TTMediaRawData
    {
        enum{RAW_DATA_NAME_SIZE=128,};
        enum eRAW_TYPE                                                          /**< Raw ��Ϣ���� */
        {
            RAW_TYPE_Red,                                                       /**< Red Raw ��Ϣ���� */
            RAW_TYPE_Sony,                                                      /**< Sony ��Ϣ���� */
        };
        eRAW_TYPE						    eRawType;							/**< Raw���ݸ�ʽ���� */
        float								fKelvin;                            /**< ɫ�� */
        float								fTint;                              /**< ɫ�� */
        float								fExposure;                          /**< �ع� */
        float								fGainR;                             /**< Red ���� */
        float								fGainG;                             /**< Green ���� */
        float								fGainB;                             /**< Blue ���� */
        float								fSaturation;                        /**< ���Ͷ� */
        float								fContrast;                          /**< �Աȶ� */
        float								fBrightness;                        /**< ���� */
        float								fDRX;
        float								fShadow;
        float								fFLUT;
        __int64								iISO;
        TCHAR								ptszGammaCurve[RAW_DATA_NAME_SIZE]; /**< Gamma�������� */
        TCHAR								ptszColorSpace[RAW_DATA_NAME_SIZE]; /**< ��ɫ�ռ����� */
        int									iMaxDisplayLum;
        int									iMinDisplayLum;
    };

    struct TTMediaInfo_SBTReserved
    {
	    DWORD dwReserved[8];	//extend use
							    //dwReserved[0]: for video yuv sample mode,1 for 420,2 for 422,3 for 411,4 for 444
							    //dwReserved[1]:	for video bitrate,in bps unit
							    //dwReserved[2]: for EC StartPos,in edit unit
							    //dwReserved[3]: for VBR MP3, 0 for CBR , 1 for VBR
							    //				 bit1-bit5 for wav dolbyE ContainerBitWidth(16,20 or 24)
							    //				 mxf StartTimecode(TimecodeComponent) (for mxf)
							    //dwReserved[4]: if = 1, DV AVI TYPE1; default = 0
							    //               bit1-bit31 for wav dolbyE FrameNum
							    //dwReserved[5]: 0 is not dbe, otherwise is dbe: 1--stream0 is dbe, 2--stream1 is dbe, 4--stream2 is dbe, 8--stream3 is dbe...
							    //dwReserved[6]: bit0 for DF or NDF. dwReserved[6] bit0 is 1 for DF, 0 for NDF.
							    //dwReserved[6]: bit1 for progressive/interlaced. dwReserved[6] bit1 is 1 for progressive, 0 for interlaced.
							    //dwReserved[6]: bit2 for video 10bit/8bit compresion. dwReserved[6] bit2 is 1 for 10bit, 0 for 8bit.
							    //dwReserved[6]: bit3 for mxf closed caption. 1 for CC, 0 for No CC.
							    //dwReserved[6]: bit5 for top/bottom field first. 0 = tff; 1 = bff.
							    //dwReserved[6]: bit6-7 for aspect ratio: 0, unknown; 1, 1:1; 2, 4:3; 3, 16:9. 
							    //dwReserved[6]: bit8 indicate the Fixed Frame Rate or Variable Frame Rate
							    //				 bit8 is 1 for Variable Frame Rate
							    //				 bit8 is 0 for Fixed	 Frame Rate
							    //				 bit9 is 1 for mix dolbyE&Pcm
							    //				 bit10 is 1 for dolbyE only
							    //				 bit11 for aspect ratio, bit11+bit7+bit6:0, unknown; 1, 1:1; 2, 4:3; 3, 16:9, 4,2.21:1, 5,5:4, 6,3:2
	                            //               bit12-13 indicate that how the decoder works: 1 for CloseGopAsync, 2 for OpenGopAsync, 3 for Sync 
							    //dwReserved[7~7]::bit31(set): create dvbs when create index;
							    //				 bit0-bit7:afd
        intptr_t reserved[4];
    };

    struct TTMediaVideoInfo
    {
        enum VERSION
        {
            version_1 = 0,
        };

        unsigned int iSize;
        unsigned int iVersion;

        unsigned int fccNovaVideoId;            /**< ��Ƶ����nova.id */
        unsigned int iSbtVideoId;               /**< ��Ƶ����sdk.id */

        double dbFrameRate;                     /**< ֡�� */
        unsigned int iWidth;                    /**< ���� */
        unsigned int iHeight;                   /**< �߶� */
        unsigned int iBitrate;                  /**< ���� */
        unsigned int iBits;                     /**< ����λ�� */
        unsigned int iAFD;                      /**< AFD��Ϣ(��sdkȡ������ֵ��û������λ����) */
        TTPixelFormat ttPixelFormat;            /**< ���ظ�ʽ */
        stuTTVideoStandard ttVStandard;         /**< ��ʽ */
        __int64 llDuration;                     /**< ʱ�䳤�ȣ���λ100ns */
        bool bIsVBR;                            /**< �Ƿ���vbr */

        struct
        {
            unsigned int nGopCount;	
            unsigned int nGOP_I_FrameCount;
            unsigned int nGOP_B_FrameCount;
            unsigned int nGOP_P_FrameCount;
        }GopInfo;                               /**< gop ��Ϣ*/
        unsigned int iVideoFourcc;              /**< �ļ�������fcc, only valid for AVI file */
        int iECStartPos;
        unsigned int lStill;                    /**< �Ƿ���ͼƬ */
        unsigned int iCompression;              /**< iCompression */

        __int64 reserved[8];                      /**< 0: TTMediaRawData* */
    };
    struct TTMediaAudioInfo
    {
        enum VERSION
        {
            version_1 = 0,
        };

        unsigned int iSize;
        unsigned int iVersion;
        unsigned int fccNovaAudioId;        /**< ��Ƶ����nova.id */
        unsigned int iSbtAudioId;           /**< ��Ƶ����sdk.id */

        unsigned int iChannels;             /**< ������ */
        unsigned int iSampleBits;           /**< ����λ�� */
        unsigned int iSampleRate;           /**< ������ */

        bool bIsVBR;                        /**< �Ƿ���VBR */

        __int64 llDuration;                 /**< ɨ�跽ʽ�����С����� */

/*

����ο��Ǳ��TPFileInfo.vecAudioChs(struct TTFileAudioChannel)

reserved[0] == dwMediaClass;          ͨ������(TP_MEDIA_CLASS_TYPE)
reserved[1] == dwSubMediaClass;       ��ͨ������(TP_MEDIA_CLASS_TYPE),�ɿ���ȥ��
reserved[2] == AudioChannel;          ��Ƶ��������



reserved[2] : 
    0                   ��ʾ�Ƕ��������
    TT_AudioChannel_2_0 ��ʾ��һ����������
    TT_AudioChannel_5_1 ��ʾ��һ����5.1
    ...

*/
        __int64 reserved[8];
    };

    union TTMediaExtraInfo
    {
        enum VERSION
        {
            version_1 = 0,
        };
        intptr_t reserved[15];              /**< 0, TTMediaInfo_SBTReserved* */
											/**< 1, Yuv2RGBType, 0 : none;   1 : eMatrixCoefficients_BT_709;    2:eMatrixCoefficients_Unspecified;  9:eMatrixCoefficients_BT_2020_NCL; 10:eMatrixCoefficients_BT_2020_CL */
    };

    struct TTMediaInfo
    {
        enum VERSION
        {
            version_1 = 0,
        };

        unsigned int iSize;
        unsigned int iVersion;
        wchar_t wszFilePath[MAX_PATH];  /**< �ļ�·�� */
       
        GUID guidNovaFileId;            /**< ��Ƶ����nova.id */
        unsigned int iSbtFileId;        /**< �Ƿ������Ƶ */
        unsigned int iFileState;        /**< �ļ�״̬ */
        unsigned int iMediaInfo;        /**< ý���ļ���Ϣ */

        BYTE bVideo;                    /**< �Ƿ������Ƶ */
        BYTE bAudio;                    /**< �Ƿ������Ƶ */
        __int64 llFileSize;             /**< �ļ���С */
        __int64	llDuration;             /**< ʱ�䳤�ȣ���λ100ns */
        __int64	llLength;               /**< ֡���� */
        __int64 llSampleCount;          /**< sample���� */

		ULONGLONG dwMediaType;       /**< novaУ�����ý������, Include\\base\\NXBaseVADataDef.h, TP_MEDIA_CLASS_V, TP_MEDIA_CLASS_A */      
		ULONGLONG dwMediaSubType;    /**< novaУ�����ý��������, Include\\base\\NXBaseVADataDef.h, TP_MEDIA_CLASS_V_V, TP_MEDIA_CLASS_V_P */

        TTMediaVideoInfo ttVideo;       /**< ��Ƶ��Ϣ */
        TTMediaAudioInfo ttAudio;       /**< ��Ƶ��Ϣ */
        TTMediaExtraInfo ttExtra;       /**< ���� */

        int Reset()
        {
            memset(&this->iSize, 0, sizeof(*this));
            iSize = sizeof(*this);
            iVersion = TTMediaInfo::VERSION::version_1;
            return 0;
        }
    };



#define  TT_STREAM_TYPE_UNKNOW		0
#define  TT_STREAM_TYPE_VIDEO		1	//��Ƶ��
#define  TT_STREAM_TYPE_AUDIO		2	//��Ƶ��
#define  TT_STREAM_TYPE_CG			3	//��Ļ��

#define  TT_STEAM_FLAG_UNKNOW		0x00000000
#define  TT_STEAM_FLAG_DEFAULT		0x00000001	//Ĭ��ʹ����

#define  TT_CLIP_STREAM_UNKNOW		0x0000000000000000
#define  TT_CLIP_STREAM_S1			0x0000000000000001
#define  TT_CLIP_STREAM_S2			0x0000000000000002
#define  TT_CLIP_STREAM_S3			0x0000000000000004
#define  TT_CLIP_STREAM_S4			0x0000000000000008
#define  TT_CLIP_STREAM_S5			0x0000000000000010
#define  TT_CLIP_STREAM_S6			0x0000000000000020
#define  TT_CLIP_STREAM_S7			0x0000000000000040
#define  TT_CLIP_STREAM_S8			0x0000000000000080
#define  TT_CLIP_STREAM_S9			0x0000000000000100
#define  TT_CLIP_STREAM_S10			0x0000000000000200
#define  TT_CLIP_STREAM_S11			0x0000000000000400
#define  TT_CLIP_STREAM_S12			0x0000000000000800
#define  TT_CLIP_STREAM_S13			0x0000000000001000
#define  TT_CLIP_STREAM_S14			0x0000000000002000
#define  TT_CLIP_STREAM_S15			0x0000000000004000
#define  TT_CLIP_STREAM_S16			0x0000000000008000
//���Լ�������������
#define  TT_FOREACH_STREAM_S(n)	   (TT_CLIP_STREAM_S1<<n)

    struct TTMediaStream
    {
	    int			iType;				    //���� TT_STREAM_TYPE_UNKNOW TT_STREAM_TYPE_VIDEO TT_STREAM_TYPE_AUDIO TT_STREAM_TYPE_CG
	    LONGLONG	llStreamClass;		    //��id TT_CLIP_STREAM_UNKNOW TT_CLIP_STREAM_S1
	    DWORD		dwStreamFlag;			//����־ TT_CLIP_STREAM_UNKNOW TT_CLIP_STREAM_S1 TT_CLIP_STREAM_S2 ...
	    TCHAR       sStreamName[256];		//������
        void *      pMediaInfo;             /* 

                                            TTMediaVideoInfo *
                                            TTMediaAudioInfo *

                                            */
        __int64     reserved[8];
    };
    struct TTMediaInfo2
    {
        TTMediaInfo info;
        DWORD dwStreamNum;
        TTMediaStream * pStreamData;
    };


    // ************************************************************************************************
    /** ý����ӿ�*/

    struct ITTMediaDetect
    {
        enum ACCESS_MODE
        {
            ACCESS_MODE_Directory,
            ACCESS_MODE_FTP,
        };
        enum FETCH_MODE
        {
            FETCH_MODE_Normal,
            FETCH_MODE_ReadIndex,
            FETCH_MODE_QuickDetect,
        };

		struct DetectParam
		{
			ACCESS_MODE	nAccessMode;	//=ACCESS_MODE_Directory, 
			FETCH_MODE	nInfoFetchMode;	//=FETCH_MODE_Normal)
			DWORD		dwFileType;		//�ļ�����1Ϊ8k�ķ��ز�
			TCHAR		chReserver[32]; //�����ֶ�

			DetectParam()
			{
				nAccessMode		= ACCESS_MODE_Directory;
				nInfoFetchMode	= FETCH_MODE_Normal;
				dwFileType		= 0;
				memset(chReserver ,0 ,sizeof(TCHAR) *32);
			}
		};

        /** ���������ļ���
        @param iProgress ��ǰ�Ľ���
        @param iFrom ��ʼλ��
        @param iTo ֹͣλ�� 
        @return >= 0 ������������
        < 0 ֹͣ��������
        */
        typedef int (*FUNC_PROGRESS)(int iProgress, int iFrom, int iTo, void* pUser);

        /** ���������ļ���������ʹ��SBT�����; VFR��֡�ʵ������Ҫת��, �ο�TTMediaInfo.iMediaInfo&TT_MEDIA_INFO_VFR
        @param lpszFilename
        @param nAccessMode
        @param nInfoFetchMode
        @return
        == 0 �ɹ�
        == 1 ��Ҫ��������
        < 0 ʧ��
        */    
        virtual int SetFilePath(const wchar_t* lpszFilename, DetectParam& param) = 0;

        /** ���������ļ���������TTMediaReader��Ϊ���ã�����Ƿ����ת��; VFR��֡�ʵ������Ҫת��, �ο�TTMediaInfo.iMediaInfo&TT_MEDIA_INFO_VFR
        @param lpszFilename
        @param nAccessMode
        @param nInfoFetchMode
        @return
        == 0 �ɹ�
        == 1 ��Ҫ��������
        < 0 ʧ��
        */    
        virtual int SetFilePathWithTTMR(const wchar_t* lpszFilename, ACCESS_MODE nAccessMode=ACCESS_MODE_Directory, FETCH_MODE nInfoFetchMode=FETCH_MODE_Normal) = 0;

        /** ���������ļ���
        @param funcProgress ����֪ͨ�ص�
        @param pProgressUser ����֪ͨ�ص����û�����
        @return
        > 0 �ɹ�
        == 0 ��Ҫ��������
        < 0 ʧ��
        */    
        virtual int CreateIndex(FUNC_PROGRESS funcProgress, void* pProgressUser) = 0;

        /** ��ȡ�ļ���ʽ��Ϣ
        @param tpFileFormat nova�ĸ�ʽ���ļ���Ϣ
        @param bFastDetect �Ƿ���ټ��
        @return
        >= 0 �ɹ�
        < 0 ʧ��
        */    
        virtual int GetMediaInfo(TTMediaInfo& tpFileFormat, bool bFastDetect = true) = 0;

        /** ��ȡָ��֡��ͼ��
        @param iFrameId ͼ���֡��
        @param pData ���ͼ��
        @param iWidth ���ͼ��Ŀ���
        @param iHeight ���ͼ��ĸ߶�
        @param pitch ���ͼ���һ�е��ֽ���, Ŀǰֻ֧��TT_PIX_FMT_RGBA32������pitch >= iWidth*4
        @param pixel �������ɫ�ռ䣬Ŀǰֻ֧��TT_PIX_FMT_RGBA32
        @return
        >= 0 �ɹ�
        < 0 ʧ��
        */
        virtual int GetImage(unsigned int iFrameId, unsigned char* pData, unsigned int iWidth, unsigned int iHeight, unsigned int iPitch, TTPixelFormat ePixelFmt = TT_PIX_FMT_RGBA32) = 0;

        /** ����ý������
        @return Ŀǰδʹ��
        */    
        virtual int Reset() = 0;

        /** ���ٶ��� */
        virtual int Destroy() = 0;
    };

    struct ITTMediaDetect2 : public ITTMediaDetect
    {
        virtual int GetMediaInfo(TTMediaInfo2& tpFileFormat) = 0;
    };

    // ************************************************************************************************
    /** CC�ļ�ת�����ļ���ǶCCת��Ϊ������CC�ļ��ӿڣ�����TT.TTMediaInfo.iMediaInfo�Ƿ��б�־λTT_MEDIA_INFO_ClosedCaption���ж��ļ��Ƿ���CC����.
    */
    struct ITTConvertCCFile
    {
        /** ���������ļ���
        @param iProgress ��ǰ�Ľ���
        @param iFrom ��ʼλ��
        @param iTo ֹͣλ�� 
        @return >= 0 ������������
        < 0 ֹͣ��������
        */
        typedef int (*FUNC_PROGRESS)(int iProgress, int iFrom, int iTo, void* pUser);

        /** ת��CC�ļ�
        @param lpszCCFilename ����Ķ���cc�ļ�
        @param lpszSrcFilename cc����Դ�ļ���("c:/xxx.mxf")
        @param funcProc ���ɽ��Ȼص�
        @param pUser ���ɽ��Ȼص�
        @param fps Ĭ��֡�ʣ������ܴ��ļ���ȡ��֡��ʱ��Ч
        @return
        == 0 �ɹ�
        < 0 ʧ��
        @remark lpszSrcFilenameĿǰ����֧��xmf
        */    
        virtual int ConvertCC(const wchar_t* lpszCCFilename, const wchar_t* lpszSrcFilename, FUNC_PROGRESS funcProc, void* pUser) = 0;
        /** reserved
        @return
        == 0 �ɹ�
        < 0 ʧ��
        */    
        virtual int Cmd(int iCmd, intptr_t param0, intptr_t param1) = 0;

        /** ���ٶ��� */
        virtual int Destroy() = 0;
    };

    // ************************************************************************************************
    /** ��Ϣ��ѯ�ӿ�, IID_ITTQueryInfo */
    struct ITTQueryInfo
    {
        /** ����tpFileFormat�����ݣ���ȡ�ļ�������
        @param ttFileFormat �ļ���Ϣ
        @return �ļ�������
        */    
        virtual const wchar_t* GetFileTypeName(const TTMediaInfo& ttFileFormat) = 0;

        /** ��ȡ�ļ�������
        @param guidFileType �ļ�����
        @param uiFcc ����fcc
        @return �ļ�������
        */    
        virtual const wchar_t* GetFileTypeName(const GUID& guidFileType, unsigned int fccVideo, unsigned int fccAudio) = 0;

        /** ����tpFileFormat����Ƶ��Ϣ����ȡ��Ƶ������
        @param tpFileFormat �ļ���Ϣ��������Ƶ��Ϣ
        @return ����������
        */    
        virtual const wchar_t* GetCodecName(const TTMediaInfo& tpFileFormat) = 0;

        /** ����guid��FCC, ��ȡ��Ӧ�ı�����(��Ƶ������Ƶ)
        @param guidFileType �ļ���Ϣ
        @param uiFcc ����fcc
        @return ����������
        */    
        virtual const wchar_t* GetCodecName(const GUID& guidFileType, unsigned int uiFcc) = 0;

        /** tpFileFormat����Ƶ��Ϣ����ȡ��Ƶ������
        @param tpFileFormat �ļ���Ϣ��������Ƶ��Ϣ
        @return ��Ƶ����������
        */    
        virtual const wchar_t* GetAudioCodecName(const TTMediaInfo& tpFileFormat) = 0;

        /** ���ٶ��� */
        virtual int Destroy() = 0;
    };

    /** ��Ƶ��ʽ��Ϣ�ӿ�, IID_ITTVideoStandardInfo  */
    struct ITTVideoStandardInfo
    {
        /** ���ٶ��� */
        virtual int Destroy() = 0;

        ///** ȡ��Ƶ��ʽ�����ߣ�֡�ʣ����߱ȣ��Ӵ�����������λ��
        //@param [in] ttvs��Ƶ��ʽ
        //@param [out] ttAspec ��Ƶ����
        //@param [out] ttFrameRate ֡��
        //@param [out] eAspect ��Ƶ��ʾʱ�Ŀ��߱�
        //@param [out] ttView �Ӵ�����
        //@param [out] ttBitCount ����λ��
        //@return
        //>= 0 �ɹ�
        //< 0 ʧ��
        //*/    
        //virtual int GetStandardInfo(const TTMediaVideoStandard& ttvs, TTVS::TPASPECT& ttAspec, TTVS::TPFRAMERATE& ttFrameRate, TTVS::eTP_ASPECTRATIO& eAspect, TTVS::ETPVIEW& ttView, TTVS::ETPBITCOUNT& ttBitCount) = 0;

        ///** �������õĿ��ߣ�֡�ʣ����߱ȣ��Ӵ�����������λ����ɨ�跽ʽȡ�ö�Ӧ����ʽ
        //@param [out] iWidth ��Ƶ����
        //@param [out] iHeight ��Ƶ�߶�
        //@param [out] dFrameRate ֡��
        //@param [out] eAspect ��Ƶ������߱�
        //@param [out] eScanMode ɨ�跽ʽ
        //@param [out] iViewCount �Ӵ�����
        //@param [out] iBitCount ����λ��
        //@return ��Ӧ����ʽ
        //*/    
        //virtual TTMediaVideoStandard MakeVideoStandard(int iWidth, int iHeight, double dFrameRate, TTVS::eTP_ASPECTRATIO eAspect, TTVS::eTPSCANMODE eScanMode, int iViewCount, int iBitCount) = 0;

        /** ������ʽȡ�ö�Ӧ��������Ϣ
        @param wszVSName ��ʽ������Ϣ�Ļ���
        @param iVSNameMaxCount ��ʽ������Ϣ�Ļ��������ַ����� (wszVSName���ֽ���/sizeof(wchar_t))
        @param ttvs ��Ƶ��ʽ
        @return ������
        */    
        virtual int GetStandardDesc(wchar_t* wszVSName, int iVSNameMaxCount, const stuTTVideoStandard& ttvs) = 0;
    };

    /** ��Ϣ��ѯ�ӿ�, IID_ITTQueryMediaId */
    struct ITTQueryMediaId
    {
        /** ���ٶ��� */
        virtual int Destroy() = 0;

        /** ����guid+fcc��Ӧ��sdk file id
        @param guid 
        @param dwFcc
        @return sbt file id
        */    
        virtual int GetFileId(const GUID& guid, DWORD dwFcc) = 0;

        /** ����guid+fcc��Ӧ��sdk media id
        @param guid 
        @param dwFcc
        @return sbt media id
        */    
        virtual int GetMediaId(const GUID& guid, DWORD dwFcc) = 0;

        /** ����sdk file id��Ӧ�� guid+fcc����Ҫ����fileId, mediaId, iAudioMediaId����������ֻ������
        @param fileTypeId       nova�ļ�����guid 
        @param dwVideoFcc       nova��Ƶ����fcc
        @param dwAudioFcc       nova��Ƶ����fcc
        @param fileId           sbt�ļ�id
        @param mediaId          sbt��Ƶid
        @param iAudioMediaId    sbt��Ƶid
        @param pVideo           ��Ƶ������Ϣ
        @param pAudio           ��Ƶ��Ϣ
        @param iPixelFormat     ��Ƶ�����ظ�ʽ
        @param iDataRate        ��Ƶ����
        @return ������
        */    
        virtual int GetNovaId(GUID& fileTypeId, DWORD& dwVideoFcc, DWORD& dwAudioFcc
            , int fileId, int mediaId, int iAudioMediaId
            , tagBITMAPINFOHEADER* pVideo = nullptr, tWAVEFORMATEX* pAudio = nullptr, int iPixelFormat = TT_PIX_FMT_UNKNOWN, int iDataRate = 0
            , intptr_t reserved0 = 0 , intptr_t reserved1 = 0) = 0;
    };

}

#endif
