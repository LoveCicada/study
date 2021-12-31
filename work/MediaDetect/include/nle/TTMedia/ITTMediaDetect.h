
#ifndef __TT_DEF_MEDIADETECT__HEADER__
#define __TT_DEF_MEDIADETECT__HEADER__

#include "./TTMediaUtilityBase.h"

struct stu_ETMediaFormatDef;
struct tagBITMAPINFOHEADER;
struct tWAVEFORMATEX;

namespace TT
{
#define _BIT_(idx) (1<<idx)

#define TT_MEDIA_INFO_VFR               _BIT_(0)    /**< VFR标志位，~TT_MEDIA_INFO_VFR为 CFR */
//#define TT_MEDIA_INFO_VBR             _BIT_(1)    /**< VBR标准位，~TT_MEDIA_INFO_VBR为 CBR */
#define TT_MEDIA_INFO_DF                _BIT_(2)    /**< DF标准位，~TT_MEDIA_INFO_DF为 NDF */
#define TT_MEDIA_INFO_ClosedCaption     _BIT_(3)    /**< mxf closed caption */
#define TT_MEDIA_INFO_WithCC            _BIT_(3)    /**< 媒体文件内含有CC字幕 */
#define TT_MEDIA_INFO_DV_AVITYPE1       _BIT_(4)    /**< DV AVI TYPE1; */
#define TT_MEDIA_INFO_Raw               _BIT_(31)   /**< RAW格式; */

#define TT_FILE_STATE_ReadAble          _BIT_(0)
#define TT_FILE_STATE_WriteAble         _BIT_(1)
#define TT_FILE_STATE_NeedIndex         _BIT_(2)	/**< 文件需要创建索引 */
#define TT_FILE_STATE_WithIndex         _BIT_(3)	/**< 文件带有索引 */
#define TT_FILE_STATE_WithXmlCC         _BIT_(4)    /**< 文件带有XML CC字幕 */
#define TT_FILE_STATE_NOVA              _BIT_(29)   /**< SBT支持该文件 */
#define TT_FILE_STATE_SBT               _BIT_(30)   /**< SBT支持该文件 */
#define TT_FILE_STATE_NeedTranscode     _BIT_(31)   /**< nova 不能直接处理该类型的文件，需要转码 */


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
#define TT_AudioChannel_2_1				0x00000800	//only for AC3,E-AC3: 2.1:L,R,Lfe(低音)
#define TT_AudioChannel_2_0				0x00001000	// stereo audio
#define TT_AudioChannel_7_1				0x00002000	// 7.1
#define TT_AudioChannel_6		        0x00004000
#define TT_AudioChannel_5_1				0x00008000	//only for DTS:5.1channal; for AC3,EAC3: 5.1.

    struct TTMediaRawData
    {
        enum{RAW_DATA_NAME_SIZE=128,};
        enum eRAW_TYPE                                                          /**< Raw 信息类型 */
        {
            RAW_TYPE_Red,                                                       /**< Red Raw 信息类型 */
            RAW_TYPE_Sony,                                                      /**< Sony 信息类型 */
        };
        eRAW_TYPE						    eRawType;							/**< Raw数据格式类型 */
        float								fKelvin;                            /**< 色温 */
        float								fTint;                              /**< 色泽 */
        float								fExposure;                          /**< 曝光 */
        float								fGainR;                             /**< Red 增益 */
        float								fGainG;                             /**< Green 增益 */
        float								fGainB;                             /**< Blue 增益 */
        float								fSaturation;                        /**< 饱和度 */
        float								fContrast;                          /**< 对比度 */
        float								fBrightness;                        /**< 亮度 */
        float								fDRX;
        float								fShadow;
        float								fFLUT;
        __int64								iISO;
        TCHAR								ptszGammaCurve[RAW_DATA_NAME_SIZE]; /**< Gamma曲线名称 */
        TCHAR								ptszColorSpace[RAW_DATA_NAME_SIZE]; /**< 颜色空间名称 */
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
        enum{__VERSION__ = 0};

        unsigned int iSize;
        unsigned int iVersion;

        unsigned int fccNovaVideoId;            /**< 视频编码nova.id */
        unsigned int iSbtVideoId;               /**< 视频编码sdk.id */

        double dbFrameRate;                     /**< 帧率 */
        unsigned int iWidth;                    /**< 宽度 */
        unsigned int iHeight;                   /**< 高度 */
        unsigned int iBitrate;                  /**< 码率 */
        unsigned int iBits;                     /**< 采样位数 */
        unsigned int iAFD;                      /**< AFD信息(从sdk取出来的值，没有做移位操作) */
        TTPixelFormat ttPixelFormat;            /**< 像素格式 */
        stuTTVideoStandard ttVStandard;         /**< 制式 */
        __int64 llDuration;                     /**< 时间长度，单位100ns */
        bool bIsVBR;                            /**< 是否是vbr */

        struct
        {
            unsigned int nGopCount;	
            unsigned int nGOP_I_FrameCount;
            unsigned int nGOP_B_FrameCount;
            unsigned int nGOP_P_FrameCount;
        }GopInfo;                               /**< gop 信息*/
        unsigned int iVideoFourcc;              /**< 文件本身的fcc, only valid for AVI file */
        int iECStartPos;
        unsigned int lStill;                    /**< 是否是图片 */
        unsigned int iCompression;              /**< iCompression */

        __int64 reserved[8];                      /**< 0: TTMediaRawData* */
    };
    struct TTMediaAudioInfo
    {
        enum{__VERSION__ = 0};

        unsigned int iSize;
        unsigned int iVersion;
        unsigned int fccNovaAudioId;        /**< 音频编码nova.id */
        unsigned int iSbtAudioId;           /**< 音频编码sdk.id */

        unsigned int iChannels;             /**< 声道数 */
        unsigned int iSampleBits;           /**< 采样位数 */
        unsigned int iSampleRate;           /**< 采样率 */

        bool bIsVBR;                        /**< 是否是VBR */

        __int64 llDuration;                 /**< 扫描方式，隔行、逐行 */

/*

具体参考非编的TPFileInfo.vecAudioChs(struct TTFileAudioChannel)

reserved[0] == dwMediaClass;          通道类型(TP_MEDIA_CLASS_TYPE)
reserved[1] == dwSubMediaClass;       子通道类型(TP_MEDIA_CLASS_TYPE),可考虑去掉
reserved[2] == AudioChannel;          音频声道类型



reserved[2] : 
    0                   表示是多个单声道
    TT_AudioChannel_2_0 表示第一流是立体声
    TT_AudioChannel_5_1 表示第一流是5.1
    ...

*/
        __int64 reserved[8];
    };

    union TTMediaExtraInfo
    {
        enum{__VERSION__ = 0};
        intptr_t reserved[15];              /**< 0, TTMediaInfo_SBTReserved* */
											/**< 1, Yuv2RGBType, 0 : none;   1 : eMatrixCoefficients_BT_709;    2:eMatrixCoefficients_Unspecified;  9:eMatrixCoefficients_BT_2020_NCL; 10:eMatrixCoefficients_BT_2020_CL */
    };

    struct TTMediaInfo
    {
        enum { __VERSION__ = 0};

        unsigned int iSize;
        unsigned int iVersion;
        wchar_t wszFilePath[MAX_PATH];  /**< 文件路径 */
       
        GUID guidNovaFileId;            /**< 音频编码nova.id */
        unsigned int iSbtFileId;        /**< 是否存在视频 */
        unsigned int iFileState;        /**< 文件状态 */
        unsigned int iMediaInfo;        /**< 媒体文件信息 */

        BYTE bVideo;                    /**< 是否存在视频 */
        BYTE bAudio;                    /**< 是否存在音频 */
        __int64 llFileSize;             /**< 文件大小 */
        __int64	llDuration;             /**< 时间长度，单位100ns */
        __int64	llLength;               /**< 帧长度 */
        __int64 llSampleCount;          /**< sample数量 */

		ULONGLONG dwMediaType;       /**< nova校验出的媒体类型, Include\\base\\NXBaseVADataDef.h, TP_MEDIA_CLASS_V, TP_MEDIA_CLASS_A */      
		ULONGLONG dwMediaSubType;    /**< nova校验出的媒体子类型, Include\\base\\NXBaseVADataDef.h, TP_MEDIA_CLASS_V_V, TP_MEDIA_CLASS_V_P */

        TTMediaVideoInfo ttVideo;       /**< 视频信息 */
        TTMediaAudioInfo ttAudio;       /**< 音频信息 */
        TTMediaExtraInfo ttExtra;       /**< 保留 */

        int Reset()
        {
            memset(&this->iSize, 0, sizeof(*this));
            iSize = sizeof(*this);
            iVersion = TTMediaInfo::__VERSION__;
            return 0;
        }
    };



#define  TT_STREAM_TYPE_UNKNOW		0
#define  TT_STREAM_TYPE_VIDEO		1	//视频流
#define  TT_STREAM_TYPE_AUDIO		2	//音频流
#define  TT_STREAM_TYPE_CG			3	//字幕流

#define  TT_STEAM_FLAG_UNKNOW		0x00000000
#define  TT_STEAM_FLAG_DEFAULT		0x00000001	//默认使用流

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
//可以继续定义其他流
#define  TT_FOREACH_STREAM_S(n)	   (TT_CLIP_STREAM_S1<<n)

    struct TTMediaStream
    {
	    int			iType;				    //类型 TT_STREAM_TYPE_UNKNOW TT_STREAM_TYPE_VIDEO TT_STREAM_TYPE_AUDIO TT_STREAM_TYPE_CG
	    LONGLONG	llStreamClass;		    //流id TT_CLIP_STREAM_UNKNOW TT_CLIP_STREAM_S1
	    DWORD		dwStreamFlag;			//流标志 TT_CLIP_STREAM_UNKNOW TT_CLIP_STREAM_S1 TT_CLIP_STREAM_S2 ...
	    TCHAR       sStreamName[256];		//流名称
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
    /** 媒体检测接口*/

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
			DWORD		dwFileType;		//文件类型1为8k四分素材
			TCHAR		chReserver[32]; //保留字段

			DetectParam()
			{
				nAccessMode		= ACCESS_MODE_Directory;
				nInfoFetchMode	= FETCH_MODE_Normal;
				dwFileType		= 0;
				memset(chReserver ,0 ,sizeof(TCHAR) *32);
			}
		};

        /** 设置输入文件名
        @param iProgress 当前的进度
        @param iFrom 起始位置
        @param iTo 停止位置 
        @return >= 0 继续创建索引
        < 0 停止创建索引
        */
        typedef int (*FUNC_PROGRESS)(int iProgress, int iFrom, int iTo, void* pUser);

        /** 设置输入文件名，仅仅使用SBT做检测; VFR变帧率的情况需要转码, 参考TTMediaInfo.iMediaInfo&TT_MEDIA_INFO_VFR
        @param lpszFilename
        @param nAccessMode
        @param nInfoFetchMode
        @return
        == 0 成功
        == 1 需要创建索引
        < 0 失败
        */    
        virtual int SetFilePath(const wchar_t* lpszFilename, DetectParam& param) = 0;

        /** 设置输入文件名，启用TTMediaReader作为备用，检测是否可以转码; VFR变帧率的情况需要转码, 参考TTMediaInfo.iMediaInfo&TT_MEDIA_INFO_VFR
        @param lpszFilename
        @param nAccessMode
        @param nInfoFetchMode
        @return
        == 0 成功
        == 1 需要创建索引
        < 0 失败
        */    
        virtual int SetFilePathWithTTMR(const wchar_t* lpszFilename, ACCESS_MODE nAccessMode=ACCESS_MODE_Directory, FETCH_MODE nInfoFetchMode=FETCH_MODE_Normal) = 0;

        /** 设置输入文件名
        @param funcProgress 进度通知回调
        @param pProgressUser 进程通知回调的用户环境
        @return
        > 0 成功
        == 0 需要创建索引
        < 0 失败
        */    
        virtual int CreateIndex(FUNC_PROGRESS funcProgress, void* pProgressUser) = 0;

        /** 获取文件格式信息
        @param tpFileFormat nova的格式的文件信息
        @param bFastDetect 是否快速检测
        @return
        >= 0 成功
        < 0 失败
        */    
        virtual int GetMediaInfo(TTMediaInfo& tpFileFormat, bool bFastDetect = true) = 0;

        /** 获取指定帧的图像
        @param iFrameId 图像的帧号
        @param pData 输出图像
        @param iWidth 输出图像的宽度
        @param iHeight 输出图像的高度
        @param pitch 输出图像的一行的字节数, 目前只支持TT_PIX_FMT_RGBA32，所以pitch >= iWidth*4
        @param pixel 输出的颜色空间，目前只支持TT_PIX_FMT_RGBA32
        @return
        >= 0 成功
        < 0 失败
        */
        virtual int GetImage(unsigned int iFrameId, unsigned char* pData, unsigned int iWidth, unsigned int iHeight, unsigned int iPitch, TTPixelFormat ePixelFmt = TT_PIX_FMT_RGBA32) = 0;

        /** 重置媒体监测器
        @return 目前未使用
        */    
        virtual int Reset() = 0;

        /** 销毁对象 */
        virtual int Destroy() = 0;
    };

    struct ITTMediaDetect2 : public ITTMediaDetect
    {
        virtual int GetMediaInfo(TTMediaInfo2& tpFileFormat) = 0;
    };

    // ************************************************************************************************
    /** CC文件转换，文件内嵌CC转换为独立的CC文件接口，根据TT.TTMediaInfo.iMediaInfo是否含有标志位TT_MEDIA_INFO_ClosedCaption来判断文件是否含有CC数据.
    */
    struct ITTConvertCCFile
    {
        /** 设置输入文件名
        @param iProgress 当前的进度
        @param iFrom 起始位置
        @param iTo 停止位置 
        @return >= 0 继续创建索引
        < 0 停止创建索引
        */
        typedef int (*FUNC_PROGRESS)(int iProgress, int iFrom, int iTo, void* pUser);

        /** 转换CC文件
        @param lpszCCFilename 输出的独立cc文件
        @param lpszSrcFilename cc数据源文件名("c:/xxx.mxf")
        @param funcProc 生成进度回调
        @param pUser 生成进度回调
        @param fps 默认帧率，当不能从文件中取出帧率时有效
        @return
        == 0 成功
        < 0 失败
        @remark lpszSrcFilename目前仅仅支持xmf
        */    
        virtual int ConvertCC(const wchar_t* lpszCCFilename, const wchar_t* lpszSrcFilename, FUNC_PROGRESS funcProc, void* pUser) = 0;
        /** reserved
        @return
        == 0 成功
        < 0 失败
        */    
        virtual int Cmd(int iCmd, intptr_t param0, intptr_t param1) = 0;

        /** 销毁对象 */
        virtual int Destroy() = 0;
    };

    // ************************************************************************************************
    /** 信息查询接口, IID_ITTQueryInfo */
    struct ITTQueryInfo
    {
        /** 根据tpFileFormat的内容，获取文件类型名
        @param ttFileFormat 文件信息
        @return 文件类型名
        */    
        virtual const wchar_t* GetFileTypeName(const TTMediaInfo& ttFileFormat) = 0;

        /** 获取文件类型名
        @param guidFileType 文件类型
        @param uiFcc 编码fcc
        @return 文件类型名
        */    
        virtual const wchar_t* GetFileTypeName(const GUID& guidFileType, unsigned int fccVideo, unsigned int fccAudio) = 0;

        /** 根据tpFileFormat的视频信息，获取视频编码名
        @param tpFileFormat 文件信息，用了视频信息
        @return 编码类型名
        */    
        virtual const wchar_t* GetCodecName(const TTMediaInfo& tpFileFormat) = 0;

        /** 根据guid和FCC, 获取对应的编码名(音频或者视频)
        @param guidFileType 文件信息
        @param uiFcc 编码fcc
        @return 编码类型名
        */    
        virtual const wchar_t* GetCodecName(const GUID& guidFileType, unsigned int uiFcc) = 0;

        /** tpFileFormat的音频信息，获取音频编码名
        @param tpFileFormat 文件信息，用了音频信息
        @return 音频编码类型名
        */    
        virtual const wchar_t* GetAudioCodecName(const TTMediaInfo& tpFileFormat) = 0;

        /** 销毁对象 */
        virtual int Destroy() = 0;
    };

    /** 视频制式信息接口, IID_ITTVideoStandardInfo  */
    struct ITTVideoStandardInfo
    {
        /** 销毁对象 */
        virtual int Destroy() = 0;

        ///** 取视频制式，宽高，帧率，宽高比，视窗个数，采样位数
        //@param [in] ttvs视频制式
        //@param [out] ttAspec 视频宽高
        //@param [out] ttFrameRate 帧率
        //@param [out] eAspect 视频显示时的宽高比
        //@param [out] ttView 视窗个数
        //@param [out] ttBitCount 采样位数
        //@return
        //>= 0 成功
        //< 0 失败
        //*/    
        //virtual int GetStandardInfo(const TTMediaVideoStandard& ttvs, TTVS::TPASPECT& ttAspec, TTVS::TPFRAMERATE& ttFrameRate, TTVS::eTP_ASPECTRATIO& eAspect, TTVS::ETPVIEW& ttView, TTVS::ETPBITCOUNT& ttBitCount) = 0;

        ///** 根据设置的宽高，帧率，宽高比，视窗个数，采样位数，扫描方式取得对应的制式
        //@param [out] iWidth 视频宽度
        //@param [out] iHeight 视频高度
        //@param [out] dFrameRate 帧率
        //@param [out] eAspect 视频幅面宽高比
        //@param [out] eScanMode 扫描方式
        //@param [out] iViewCount 视窗个数
        //@param [out] iBitCount 采样位数
        //@return 对应的制式
        //*/    
        //virtual TTMediaVideoStandard MakeVideoStandard(int iWidth, int iHeight, double dFrameRate, TTVS::eTP_ASPECTRATIO eAspect, TTVS::eTPSCANMODE eScanMode, int iViewCount, int iBitCount) = 0;

        /** 根据制式取得对应的描述信息
        @param wszVSName 制式描述信息的缓存
        @param iVSNameMaxCount 制式描述信息的缓存的最大字符数量 (wszVSName的字节数/sizeof(wchar_t))
        @param ttvs 视频制式
        @return 错误码
        */    
        virtual int GetStandardDesc(wchar_t* wszVSName, int iVSNameMaxCount, const stuTTVideoStandard& ttvs) = 0;
    };

    /** 信息查询接口, IID_ITTQueryMediaId */
    struct ITTQueryMediaId
    {
        /** 销毁对象 */
        virtual int Destroy() = 0;

        /** 返回guid+fcc对应的sdk file id
        @param guid 
        @param dwFcc
        @return sbt file id
        */    
        virtual int GetFileId(const GUID& guid, DWORD dwFcc) = 0;

        /** 返回guid+fcc对应的sdk media id
        @param guid 
        @param dwFcc
        @return sbt media id
        */    
        virtual int GetMediaId(const GUID& guid, DWORD dwFcc) = 0;

        /** 返回sdk file id对应的 guid+fcc，主要依据fileId, mediaId, iAudioMediaId，其他参数只做辅助
        @param fileTypeId       nova文件类型guid 
        @param dwVideoFcc       nova视频编码fcc
        @param dwAudioFcc       nova音频编码fcc
        @param fileId           sbt文件id
        @param mediaId          sbt视频id
        @param iAudioMediaId    sbt音频id
        @param pVideo           视频幅面信息
        @param pAudio           音频信息
        @param iPixelFormat     视频的像素格式
        @param iDataRate        视频码率
        @return 错误码
        */    
        virtual int GetNovaId(GUID& fileTypeId, DWORD& dwVideoFcc, DWORD& dwAudioFcc
            , int fileId, int mediaId, int iAudioMediaId
            , tagBITMAPINFOHEADER* pVideo = NULL, tWAVEFORMATEX* pAudio = NULL, int iPixelFormat = TT_PIX_FMT_UNKNOWN, int iDataRate = 0
            , intptr_t reserved0 = NULL, intptr_t reserved1 = NULL) = 0;
    };

}

#endif
