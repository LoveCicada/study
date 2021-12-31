#ifndef __def_TTMediaPlayerExport__header__
#define __def_TTMediaPlayerExport__header__

//#include "Afxtempl.h"
#include "TTNewStandardDef.h"

//!�����ӿڵİ汾
#define  TTMediaPlayerExport_Version  3

#define HTTMPHANDLE					 void *
#define HTLITEM						 void *
#define TT_MEDIAPLAYER_AUDIO_NUM	16
//!��Ƶ����
#define TT_MEDIAPLAYER_AM_NUM		16	// �޸�Ϊ8����

#define TT_ERROR_CreateIndexFailed  1001

////���°汾ʹ�� TTVS::TP_VIDEO_STANDARD
//enum	TT_MEDIAPLAYER_VIDEO_STANDARD	// ������Ƶ��ʽ��׼ö�ٶ���
//{
//	TT_MP_VIDEOSTANDARD_UNKNOW				= 0x00000000,		//Invalid
//
//	TT_MP_VIDEOSTANDARD_PAL					= 0x00000001,		//PAL size:720*576 f/s : 25
//	TT_MP_VIDEOSTANDARD_NTSC_2997			= 0x00000002,		//NTSC size:720*486  f/s : 29.97
//	TT_MP_VIDEOSTANDARD_NTSC_30				= 0x00000004,		//NTSC size:720*486 f/s : 30 
//	TT_MP_VIDEOSTANDARD_SECAM				= 0x00000008,		//SECAM
//
//	TT_MP_VIDEOSTANDARD_1920_1080_50i		= 0x00000010,		//HDTV size:1920*1080 f/s : 25  interlaced
//	TT_MP_VIDEOSTANDARD_1920_1080_5994i		= 0x00000020,		//HDTV size:1920*1080 f/s : 29.97 interlaced
//	TT_MP_VIDEOSTANDARD_1920_1080_60i		= 0x00000040,		//HDTV size:1920*1080 f/s : 30 interlaced
//	TT_MP_VIDEOSTANDARD_1920_1080_2398p		= 0x00000080,		//HDTV size:1920*1080 f/s : 23.98 progressive
//	TT_MP_VIDEOSTANDARD_1920_1080_24p		= 0x00000100,		//HDTV size:1920*1080 f/s : 24 progressive
//	TT_MP_VIDEOSTANDARD_1920_1080_25p		= 0x00000200,		//HDTV size:1920*1080 f/s : 25 progressive
//	TT_MP_VIDEOSTANDARD_1920_1080_2997p		= 0x00000400,		//HDTV size:1920*1080 f/s : 29.97 progressive
//	TT_MP_VIDEOSTANDARD_1920_1080_30p		= 0x00000800,		//HDTV size:1920*1080 f/s : 30 progressive
////	TT_MP_VIDEOSTANDARD_1920_1080_50p		= 0x00001000,		//HD size:1920*1080 f/s : 50 progressive
////	TT_MP_VIDEOSTANDARD_1920_1080_5994p		= 0x00002000,		//HD size:1920*1080 f/s : 59.94 progressive
//
//	TT_MP_VIDEOSTANDARD_1280_720_2398p		= 0x00001000,	    //HDTV size:1280*720 f/s : 23.98 progressive
//	TT_MP_VIDEOSTANDARD_1280_720_24p		= 0x00002000,		//HDTV size:1280*720 f/s : 24 progressive
//	TT_MP_VIDEOSTANDARD_1280_720_50p		= 0x00004000,		//HDTV size:1280*720 f/s : 50 progressive
//	TT_MP_VIDEOSTANDARD_1280_720_5994p		= 0x00008000,		//HDTV size:1280*720 f/s : 59.94 progressive
//	TT_MP_VIDEOSTANDARD_1280_720_2997p		= 0x02000000,		//HDTV size:1280*720 f/s : 29.97 progressive
//	TT_MP_VIDEOSTANDARD_1280_720_25p		= 0x01000000,		//HDTV size:1280*720 f/s : 25 progressive
//
//	TT_MP_VIDEOSTANDARD_1440_1080_50i		= 0x00010000,	    //HD  size:1440*1080 f/s : 25 interlaced
//	TT_MP_VIDEOSTANDARD_1440_1080_5994i		= 0x00020000,	    //HD  size:1440*1080 f/s : 29.97 interlaced
//	TT_MP_VIDEOSTANDARD_1440_1080_60i		= 0x00040000,	    //HD  size:1440*1080 f/s : 30 interlaced
//
//    TP_MP_VIDEOSTANDARD_PAL_16_9			= 0x00080000,		//PAL size:720*576 f/s : 25  
//
//    TP_MP_VIDEOSTANDARD_NTSC_2997_16_9		= 0x00100000,		//NTSC size:720*486  f/s : 29.97
//    TP_MP_VIDEOSTANDARD_NTSC_30_16_9		= 0x00200000,		//NTSC size:720*486 f/s : 30 
//    TP_MP_VIDEOSTANDARD_NTSC_2997_480		= 0x00400000,		//NTSC size:720*480  f/s : 29.97  //�����ţ���ֹ�Ժ���������ٸĳ�480
//    TP_MP_VIDEOSTANDARD_NTSC_30_480		    = 0x00800000,		//NTSC size:720*480 f/s : 30 //�����ţ���ֹ�Ժ���������ٸĳ�480
//
////	TT_MP_VIDEOSTANDARD_1440_1080_2997p		= 0x00800000,		//HD  size:1440*1080 f/s : 29.97 progressive
////	TT_MP_VIDEOSTANDARD_1440_1080_25p		= 0x01000000,		//HD  size:1440*1080 f/s : 25 progressive
////	TT_MP_VIDEOSTANDARD_1440_1080_2398p		= 0x02000000,		//HD  size:1440*1080 f/s : 23.98 progressive
////	TT_MP_VIDEOSTANDARD_1440_1080_24p		= 0x04000000,		//HD  size:1440*1080 f/s : 24 progressive
//
////	TT_MP_VIDEOSTANDARD_960_720_50p			= 0x08000000,		//HDTV size:1280*720 f/s : 50 progressive
////	TT_MP_VIDEOSTANDARD_960_720_5994p		= 0x10000000,		//HDTV size:1280*720 f/s : 59.94 progressive
//};

enum TTPixelFormat 
{
	TT_PIX_FMT_UNKNOWN		= 0x00000000,

	TT_PIX_FMT_ARGB32		= 0x00000001,///< Packed pixel, 4 bytes per pixel, ARGBARGB...
	TT_PIX_FMT_RGBA32		= 0x00000002,///< Packed pixel, 4 bytes per pixel, BGRABGRA...
	TT_PIX_FMT_RGB24		= 0x00000004,///< Packed pixel, 3 bytes per pixel, RGBRGB...
	TT_PIX_FMT_BGR24		= 0x00000008,///< Packed pixel, 3 bytes per pixel, BGRBGR...
	TT_PIX_FMT_GRAY8		= 0x00000010,  
	TT_PIX_FMT_RGB565		= 0x00000020,///< always stored in cpu endianness   16 bpp
	TT_PIX_FMT_RGB555		= 0x00000040,///< always stored in cpu endianness, most significant bit to 1  16 bpp

	TT_PIX_FMT_YUYV			= 0x00000100,
	TT_PIX_FMT_YUAYVA		= 0x00000200,	
	TT_PIX_FMT_UYVY			= 0x00000400,
	TT_PIX_FMT_UYAVYA		= 0x00000800,
	TT_PIX_FMT_YUV422P		= 0x00001000,///< Planar YUV 4:2:2 (1 Cr & Cb sample per 2x1 Y samples)
	TT_PIX_FMT_YUV444P		= 0x00002000,///< Planar YUV 4:4:4 (1 Cr & Cb sample per 1x1 Y samples)
	TT_PIX_FMT_YUV410P		= 0x00004000,///< Planar YUV 4:1:0 (1 Cr & Cb sample per 4x4 Y samples)
	TT_PIX_FMT_YUV411P		= 0x00008000,///< Planar YUV 4:1:1 (1 Cr & Cb sample per 4x1 Y samples)
	TT_PIX_FMT_YUV420P		= 0x00010000,///< Planar YUV 4:2:0 (1 Cr & Cb sample per 2x2 Y samples)
	TT_PIX_FMT_YUVA			= 0x00020000,


	TT_PIX_FMT_SPLIT_ALPHA	= 0x00040000, ///�Ƿ���ж�����alpha buffer
	TT_PIX_FMT_RGBA32X		= 0x00080000 ///< Packed pixel, 4 bytes per pixel, RGBARGBA...
};

//!�ļ�����
typedef DWORD  TT_MEDIAPLAYER_CLASS_TYPE;

#define  TT_MEDIAPLAYER_CLASS_UNKNOWN 0x00000000
#define  TT_MEDIAPLAYER_CLASS_V       0x00000001

#define  TT_MEDIAPLAYER_CLASS_A1      0x00000002
#define  TT_MEDIAPLAYER_CLASS_A2      0x00000004
#define  TT_MEDIAPLAYER_CLASS_A3      0x00000008
#define  TT_MEDIAPLAYER_CLASS_A4      0x00000010
#define  TT_MEDIAPLAYER_CLASS_A5      0x00000020
#define  TT_MEDIAPLAYER_CLASS_A6      0x00000040
#define  TT_MEDIAPLAYER_CLASS_A7      0x00000080
#define  TT_MEDIAPLAYER_CLASS_A8      0x00000100

#define  TT_MEDIAPLAYER_CLASS_A9      0x00000200 // support the 16 channel audio
#define  TT_MEDIAPLAYER_CLASS_A10     0x00000400
#define  TT_MEDIAPLAYER_CLASS_A11     0x00000800
#define  TT_MEDIAPLAYER_CLASS_A12     0x00001000
#define  TT_MEDIAPLAYER_CLASS_A13     0x00002000
#define  TT_MEDIAPLAYER_CLASS_A14     0x00004000
#define  TT_MEDIAPLAYER_CLASS_A15     0x00008000
#define  TT_MEDIAPLAYER_CLASS_A16     0x00010000

#define  TT_MEDIAPLAYER_CLASS_A(chId) (TT_MEDIAPLAYER_CLASS_A1 << (chId-1))

#define  TT_MEDIAPLAYER_CLASS_G	      0x00040000 // 0x00001000
#define  TT_MEDIAPLAYER_CLASS_KEY	  0x00080000


//!�߱���ת��ģʽ
enum TT_MEDIAPLAYER_HDSD_MODE
{
	TT_MEDIAPLAYER_HDSD_NoChange = 1,
	TT_MEDIAPLAYER_HDSD_Stretch,
	TT_MEDIAPLAYER_HDSD_CutHorz,//!ˮƽ����
	TT_MEDIAPLAYER_HDSD_EstopVert,//!��ֱ����
};
//!��ż����ʾ
enum TT_MEDIAPLAYER_DISPLAY_MODE
{
	TT_MEDIAPLAYER_DSP_NO	= 0, //!����ʾ
	TT_MEDIAPLAYER_DSP_FRAME,
	TT_MEDIAPLAYER_DSP_ODD,
	TT_MEDIAPLAYER_DSP_EVEN,
};
//!״̬
enum TT_MEDIAPLAYER_STATUS
{
	TT_MEDIAPLAYER_STATUS_NULL  = -1,
	TT_MEDIAPLAYER_STATUS_STOP	= 0,
	TT_MEDIAPLAYER_STATUS_PAUSE = 1,
	TT_MEDIAPLAYER_STATUS_PLAY	= 2,
	TT_MEDIAPLAYER_STATUS_PLAY_J= 3,
	TT_MEDIAPLAYER_STATUS_PLAY_K= 4,
	TT_MEDIAPLAYER_STATUS_PLAY_L= 5
};

//!��������
enum TT_MEDIAPLAYER_AUDIO_MODE
{
	TT_MEDIAPLAYER_AUDIO_MONO = 0,
	TT_MEDIAPLAYER_AUDIO_STEREO,
	TT_MEDIAPLAYER_AUDIO_5POINT1,
	TT_MEDIAPLAYER_AUDIO_7POINT1,
};

// maybe we do not need play para
#define USE 0
#if USE

typedef struct stu_TTMediaPlayerSetupPara
{
	BOOL						bEnableOutput;	//!�Ƿ������������
	BOOL						bEnableOutputAudio;//!�Ƿ��Io�������Ƶ,ǰ����bEnableOutput��Ч
	TT_MEDIAPLAYER_DISPLAY_MODE	eIOOutputMode;//!IO���������ʽ����seek��ʱ����Ч��
	GUID						guidVideoOutEngine;//!I0���������
	TCHAR						szOutEngineName[64];

	BOOL						bEnableAudioCard;//!�Ƿ�����������Ƶ
	int							iAudiSeekFramesNext;//!��Ƶseek��֡
	TT_MEDIAPLAYER_DISPLAY_MODE	eDisplayMode;//!Ԥ��ķ�ʽ
	BOOL						bMultipleZoom;//!Ԥ�ര�ڸ�����Ƶ���汶��������ʾ
	TT_MEDIAPLAYER_HDSD_MODE	eHDSDMode;

	BOOL						b169SafeBox; //!��ȫ��
	BOOL						b43SafeBox;
	int							iSafeRectH;
	int							iSafeRectV;
	BOOL						bDropFrame;	//����Ƶ��ʵʱ���Ƿ�֡��ʾ
	stu_TTMediaPlayerSetupPara()
	{
		bEnableOutput		= 0;
		bEnableOutputAudio	= 0;
		eIOOutputMode		= TT_MEDIAPLAYER_DSP_ODD;
		guidVideoOutEngine	= GUID_NULL;
		bEnableAudioCard	= TRUE;
		iAudiSeekFramesNext = 0;
		eDisplayMode		= TT_MEDIAPLAYER_DSP_FRAME;
		bMultipleZoom		= FALSE;
		eHDSDMode			= TT_MEDIAPLAYER_HDSD_NoChange;
		b169SafeBox			= FALSE;
		b43SafeBox			= FALSE;
		iSafeRectH			= 100;
		iSafeRectV			= 100;
		bDropFrame			= FALSE;
	}
	stu_TTMediaPlayerSetupPara & operator = (const stu_TTMediaPlayerSetupPara & stuDst)
	{
		bEnableOutput		= stuDst.bEnableOutput;
		bEnableOutputAudio	= stuDst.bEnableOutputAudio;
		eIOOutputMode		= stuDst.eIOOutputMode;
		guidVideoOutEngine	= stuDst.guidVideoOutEngine;
		bEnableAudioCard	= stuDst.bEnableAudioCard;
		iAudiSeekFramesNext	= stuDst.iAudiSeekFramesNext;
		eDisplayMode		= stuDst.eDisplayMode;
		bMultipleZoom		= stuDst.bMultipleZoom;
		eHDSDMode			= stuDst.eHDSDMode;
		b169SafeBox			= stuDst.b169SafeBox;
		b43SafeBox			= stuDst.b43SafeBox;
		iSafeRectH			= stuDst.iSafeRectH;
		iSafeRectV			= stuDst.iSafeRectV;
		bDropFrame			= stuDst.bDropFrame;
		memset(szOutEngineName,0,sizeof(TCHAR)*64);	
		memcpy(szOutEngineName,stuDst.szOutEngineName,sizeof(TCHAR)*64);
		return * this;
	}

}TTMediaPlayerSetupPara,*lpTTMediaPlayerSetupPara;
//!IO����Ϣ
typedef struct stu_TTMediaPlayerIOCard
{
	GUID							guidVideoOutEngine;
	TCHAR							szOutEngineName[64];
	stuTTVideoStandard				tpVideoStandard;//!֧�ֵ���ʽ���
	stu_TTMediaPlayerIOCard()
	{
		guidVideoOutEngine  = GUID_NULL;
		tpVideoStandard.Reset();
	}
	stu_TTMediaPlayerIOCard & operator = (const stu_TTMediaPlayerIOCard & stuDst)
	{
		guidVideoOutEngine	= stuDst.guidVideoOutEngine;
		tpVideoStandard.Copy(stuDst.tpVideoStandard);
		memset(szOutEngineName,0,sizeof(TCHAR)*64);	
		memcpy(szOutEngineName,stuDst.szOutEngineName,sizeof(TCHAR)*64);
		return * this;
	}
}TTMediaPlayerIOCard,*lpTTMediaPlayerIOCard;

typedef CArray<TTMediaPlayerIOCard,TTMediaPlayerIOCard &> TTMediaPlayerIOCardArray;

//!���Ų���
typedef struct stu_TTMediaPlayerPlayPara
{
	HTTMPHANDLE hSequence;
	__int64		lInPoint;
	__int64		lOutPoint;
	__int64     lStartPoint;
	BOOL		bLoop;
	BOOL		bReverse;
	BOOL		bReturnPos;
	BOOL		bReturnVU;
	BOOL		bPreStop;
	BOOL		bPlayAudio;
	BOOL		bPlayVideo;
	BOOL		bPlayWaitGlobalEvent;
	stu_TTMediaPlayerPlayPara()
	{
		hSequence	= NULL;
		lInPoint	= 0;
		lOutPoint	= 0;
		bLoop		= FALSE;
		bReverse	= FALSE;
		bReturnPos	= TRUE;
		bReturnVU	= TRUE;
		bPreStop    = FALSE;
		bPlayAudio  = TRUE;
		bPlayVideo  = TRUE;
		bPlayWaitGlobalEvent = FALSE;
	}

	stu_TTMediaPlayerPlayPara & operator = (const stu_TTMediaPlayerPlayPara & srcPara)
	{
		hSequence	= srcPara.hSequence;
		lInPoint	= srcPara.lInPoint;
		lOutPoint	= srcPara.lOutPoint;
		lStartPoint	= srcPara.lStartPoint;
		bLoop		= srcPara.bLoop;
		bReverse	= srcPara.bReverse;
		bReturnPos	= srcPara.bReturnPos;
		bReturnVU	= srcPara.bReturnVU;
		bPreStop	= srcPara.bPreStop;
		bPlayAudio  = srcPara.bPlayAudio;
		bPlayVideo  = srcPara.bPlayVideo;
		bPlayWaitGlobalEvent = srcPara.bPlayWaitGlobalEvent;
		return *this;
	}

}TTMediaPlayerPlayPara,*lpTTMediaPlayerPlayPara;
//!Seek ����
typedef struct stu_TTMediaPlayerSeekPara
{
	HTTMPHANDLE hSequence;
	__int64		lPos;
	BOOL		bSeekVideo;
	BOOL		bSeekAudio;	
	BOOL		bReturnPos;
	BOOL		bReturnVU;
	BOOL		bAsync;			//�Ƿ��첽Seek
	stu_TTMediaPlayerSeekPara()
	{
		hSequence	= NULL;
		lPos		= 0;
		bSeekVideo	= TRUE;
		bSeekAudio	= TRUE;
		bReturnPos	= TRUE;
		bReturnVU	= TRUE;
		bAsync		= TRUE;
	}
	stu_TTMediaPlayerSeekPara & operator = (const stu_TTMediaPlayerSeekPara & srcPara)
	{
		hSequence	= srcPara.hSequence;
		lPos		= srcPara.lPos;
		bSeekVideo	= srcPara.bSeekVideo;
		bSeekAudio	= srcPara.bSeekAudio;
		bReturnPos	= srcPara.bReturnPos;
		bReturnVU	= srcPara.bReturnVU;
		bAsync		= srcPara.bAsync;
		return *this;
	}

}TTMediaPlayerSeekPara,*lpTTMediaPlayerSeekPara;

typedef struct stu_TTMediaPlayerVUData
{
	BOOL  bPeekValue;						 // TRUE ��ֵ FALSE VU ֵ
	WORD  wBitsPerSample; 	
	int   iAudioTrackValue[TT_MEDIAPLAYER_AUDIO_NUM];          // �������
	int   iAudioOutValue[TT_MEDIAPLAYER_AUDIO_NUM];			// ���ͨ������
	stu_TTMediaPlayerVUData()
	{
		bPeekValue		= FALSE;
		wBitsPerSample	= 16;
		for(int i = 0; i < TT_MEDIAPLAYER_AUDIO_NUM;i ++)
		{
			iAudioTrackValue[i] = 0;
			iAudioOutValue[i]	= 0;
		}
	}
}TTMediaPlayerVUData,*lpTTMediaPlayerVUData;

typedef struct stu_TTMediaPlayerMarkPoint
{
	__int64		iPos;
	TCHAR		szNote[64];
	BYTE		bMarkType;
	DWORD_PTR	dwParam;
	void Reset()
	{
		iPos		= -1;
		memset(szNote,0,sizeof(TCHAR)*64);	
		bMarkType	= 0;
		dwParam		= 0;
	}
	stu_TTMediaPlayerMarkPoint()
	{
		Reset();
	}
	stu_TTMediaPlayerMarkPoint & operator = (const stu_TTMediaPlayerMarkPoint & stuDst)
	{
		iPos		= stuDst.iPos;
		bMarkType	= stuDst.bMarkType;
		dwParam		= stuDst.dwParam;
		memset(szNote,0,sizeof(TCHAR)*64);	
		memcpy(szNote,stuDst.szNote,sizeof(TCHAR)*64);
		return * this;
	}
}TTMediaPlayerMarkPoint,lpTTMediaPlayerMarkPoint;

typedef CArray<TTMediaPlayerMarkPoint,TTMediaPlayerMarkPoint &> TTMediaPlayerMarkPointArray;

//!Editmax7,Nova ,Enet5 , EM2 �ȵ�ϵͳ�������ݿ��¼��ý���ļ���ʽ��Ϣ
typedef struct stu_TTMediaPlayerMediaFormatForE7
{
	BYTE					bFormatType;				//1����Ƶ��ʽ��2����Ƶ��ʽ��3������ʽ��4��ͼƬ��ʽ
	GUID					guidFileType;			//�ļ���ʽ��GUID
	long					lDataRate;			//����
	long					lFOURCC;				//ý������
	long					lMediaType;			//ý���ļ�����
	long					lSubMediaType;		//ý���ļ�������
	long					lAudioChannels;		//��Ƶͨ����
	long					lAudioSamplesRate;	//��Ƶ������
	long					lAudioBitsperSample;	//����λ��
	long					lVideoImgWidth;		//�زĻ����
	long					lVideoImgHeight;		//�زĻ����
	stuTTVideoStandard		tpVideoStandard;		//��ʽ
	long					lVPixFmt;				//���ظ�ʽ
	long					lVBitsPerPixel;		//ÿ����λ��
	double					dblVFrameRate;		//֡��
	long					lVCompression;		//����ѹ����ʽ
	long					lVScanMode;			//ɨ��ģʽ
	long					lVGOPSize;			//GOP����
	long					lVBFrameCount;		//B֡����
	long					lVPFrameCount;		//P֡����
	//���캯��
	stu_TTMediaPlayerMediaFormatForE7()
	{
		Reset();
	}
	//��λ����
	void Reset()
	{
		bFormatType			= 0;
		guidFileType		= GUID_NULL;
		lDataRate			= 0;
		lFOURCC			= 0;
		lMediaType		= 0;
		lSubMediaType		= 0;
		lAudioChannels	= 0;
		lAudioSamplesRate	= 0;
		lAudioBitsperSample= 0;
		lVideoImgWidth	= 0;
		lVideoImgHeight	= 0;
		tpVideoStandard.Reset();
		lVPixFmt			= 0;
		lVBitsPerPixel	= 0;
		dblVFrameRate		= 0;
		lVCompression		= 0;
		lVScanMode		= 0;
		lVGOPSize			= 0;
		lVBFrameCount		= 0;
		lVPFrameCount		= 0;		
	}	
}TTMediaPlayerMediaFormatForE7,*lpTTMediaPlayerMediaFormatForE7;

//!��Ƶ�ļ��ļ���ʽ�ͱ����ʽ����
typedef struct stu_TTMediaPlayerVideoFormat
{
	//!Ӧ����sobey��������SDK����
	DWORD dwFileFormatID;
	DWORD dwMediaTypeID;
	//!V
	DWORD  dwWidth;
	DWORD  dwHeight;
	DWORD  dwBitsPerPixel;
	DWORD  dwPixFmt;

	stuTTVideoStandard  tpVideoStandard;

	BYTE   bCreateIndex; //!�Ƿ���Ҫ��������
	DWORD_PTR dwParam;
	
	void Reset()
	{
		dwFileFormatID	= 0;
		dwMediaTypeID	= 0;
		dwWidth			= 0;
		dwHeight		= 0;
		dwBitsPerPixel	= 0;
		dwPixFmt		= 0;
		bCreateIndex	= 1;
		dwParam			= 0;
		tpVideoStandard.Reset();
	}
	stu_TTMediaPlayerVideoFormat()
	{
		Reset();
	}
}TTMediaPlayerVideoFormat,*lpTTMediaPlayerVideoFormat;
//!��Ƶ�ļ��ļ���ʽ�ͱ����ʽ����
typedef struct stu_TTMediaPlayerAudioFormat
{
	//!Ӧ����sobey��������SDK����
	DWORD	dwFileFormatID;
	DWORD	dwMediaTypeID;

	WORD	iChannels;				//ͨ����
	DWORD	iSamplesRate;			//������
	WORD	iBitsPerSample;			//����λ��
	
	BYTE	bCreateIndex; //!�Ƿ���Ҫ��������
	DWORD_PTR dwParam;
	void Reset()
	{
		dwFileFormatID	= 0;
		dwMediaTypeID	= 0;
		iChannels		= 0;
		iSamplesRate	= 0;
		iBitsPerSample	= 0;
		bCreateIndex	= 0;
		dwParam			= 0;
	}
	stu_TTMediaPlayerAudioFormat()
	{
		Reset();
	}
}TTMediaPlayerAudioFormat,*lpTTMediaPlayerAudioFormat;
//!����Ƶ�ļ�

#define TT_GET_TC_FROM_MEDIA_FILE 0x1000

typedef struct stu_TTMediaPlayerFileFormat
{
	TTMediaPlayerVideoFormat stuVideoFormat;
	TTMediaPlayerAudioFormat stuAudioFormat;

	BYTE					 bAVInterleave;      //����Ƶͬһ�ļ� 
	BYTE					 bVideo;
	BYTE					 bAudio;
	DWORD_PTR				 dwParam;
	__int64					 iLength;
	__int64					 iSampleCount;

	void Reset()
	{
		stuVideoFormat.Reset();
		stuAudioFormat.Reset();
		bAVInterleave	= 0;
		bVideo			= 0;
		bAudio			= 0;
		dwParam			= 0;
		iLength			= 0;
		iSampleCount	= 0;
	}
	stu_TTMediaPlayerFileFormat()
	{
		Reset();
	}
}TTMediaPlayerFileFormat,*lpTTMediaPlayerFileFormat;

//�ļ���
typedef struct stu_TTMediaPlayerFileItem
{
	TCHAR						szMediaFile[MAX_PATH];	
	TT_MEDIAPLAYER_CLASS_TYPE	dwChannel;//!ȷ���Ƿ���Ƶ������Ƶ���������Ƶ��ô��������ѡ��
	__int64						iFileIn;
	__int64						iFileOut;
	__int64						iTrackIn;
	__int64						iTrackOut;
	DWORD						dwFileStatus;
	TT_MEDIAPLAYER_HDSD_MODE	emHDSDMode;
	lpTTMediaPlayerFileFormat	lpFileFormat; //!���Ϊ�գ�TTMediaPlayer�Զ�У��
	GUID						guidFilePlugin;// ѡ���ļ�Cutlist guid,���û������Ҫ��һ��ΪGUID_NULL;
	GUID						guidFile; //!����Ωһ�ı�ʶ��
	HTTMPHANDLE				    hFileData; //���ݾ����ΪCGԤ��
	DWORD_PTR					dwParam;
	void Reset(BOOL bDelFmt = TRUE)
	{
		memset(szMediaFile,0,sizeof(TCHAR)*MAX_PATH);		
		dwChannel		= TT_MEDIAPLAYER_CLASS_UNKNOWN;
		iFileIn			= 0;
		iFileOut		= 0;
		iTrackIn		= 0;
		iTrackOut		= 0;
		dwFileStatus	= 0;
		dwParam			= 0;
		guidFilePlugin	= GUID_NULL;
		guidFile		= GUID_NULL;
		hFileData		= NULL;
		emHDSDMode		= TT_MEDIAPLAYER_HDSD_NoChange;
		if(NULL != lpFileFormat)
		{
			if(bDelFmt)
			{
				delete lpFileFormat;
				lpFileFormat = NULL;
			}
			else
			{
				lpFileFormat->Reset();
			}
		}
	}
	stu_TTMediaPlayerFileItem()
	{
		lpFileFormat = NULL;
		Reset(TRUE);
	}
	stu_TTMediaPlayerFileItem & operator = (const stu_TTMediaPlayerFileItem & stuDst)
	{
		Reset(FALSE);
		memcpy(szMediaFile,stuDst.szMediaFile,sizeof(TCHAR)*MAX_PATH);
		dwChannel		= stuDst.dwChannel;
		iFileIn			= stuDst.iFileIn;
		iFileOut		= stuDst.iFileOut;
		iTrackIn		= stuDst.iTrackIn;
		iTrackOut		= stuDst.iTrackOut;
		dwFileStatus	= stuDst.dwFileStatus;
		emHDSDMode		= stuDst.emHDSDMode;
		guidFilePlugin	= stuDst.guidFilePlugin;
		hFileData		= stuDst.hFileData;
		guidFile		= stuDst.guidFile;
		dwParam			= stuDst.dwParam;
		if(NULL != stuDst.lpFileFormat)
		{
			if(NULL == lpFileFormat)lpFileFormat = new TTMediaPlayerFileFormat;

			*lpFileFormat = *stuDst.lpFileFormat;
		}
		else
		{
			if(NULL != lpFileFormat)
			{
				delete lpFileFormat;
				lpFileFormat = NULL;
			}
		}
		return * this;
	}
	~stu_TTMediaPlayerFileItem(void)
	{
		if(NULL != lpFileFormat)
		{
			delete lpFileFormat;
			lpFileFormat = NULL;
		}
	}
}TTMediaPlayerFileItem,*lpTTMediaPlayerFileItem;

typedef CArray<lpTTMediaPlayerFileItem,lpTTMediaPlayerFileItem> TTMediaPlayerFileItemArray;

//!һ���
typedef struct stu_TTMediaPlayerTrack
{
	TTMediaPlayerFileItemArray  ArrayFileItem;
	BOOL						bAutoDel;
	BOOL						bValid;//!�ù���Ƿ���Ч��
	DWORD_PTR					dwParam;

	int	GetCount(){return (int)ArrayFileItem.GetSize();}
	void DelAllFileItem()
	{
		lpTTMediaPlayerFileItem pItem = NULL;
		for(INT_PTR i = 0; i < ArrayFileItem.GetSize();i ++)
		{
			pItem = ArrayFileItem[i];
			if(NULL != pItem)
			{
				delete pItem;
				pItem = NULL;
			}
		}
		ArrayFileItem.RemoveAll();
	}
	stu_TTMediaPlayerTrack()
	{
		bAutoDel  = TRUE;
		bValid	  = TRUE;
		dwParam	  = 0;
	}
	~stu_TTMediaPlayerTrack()
	{
		if(bAutoDel)
		{
			DelAllFileItem();
		}
	}
}TTMediaPlayerTrack,*lpTTMediaPlayerTrack;

typedef CArray<lpTTMediaPlayerTrack,lpTTMediaPlayerTrack> TTMediaPlayerTrackArray;

//!Sequence
typedef struct stu_TTMediaPlayerSequence
{
	TTMediaPlayerTrack			stuGraphicsTrack;   //!ͼ�ι��
	TTMediaPlayerTrack			stuVideoTrack;	    //!��Ƶ���
	TTMediaPlayerTrack			stuAudioTrack[TT_MEDIAPLAYER_AUDIO_NUM]; //!��Ƶ���
	TTMediaPlayerMarkPointArray	ArrayMarkPoint;
}TTMediaPlayerSequence, * lpTTMediaPlayerSequence;

typedef struct stu_TTMediaPlayerTCItem
{
	DWORD dwTCType;
    long frame;
    long tc;
}TTMediaPlayerTCItem, * lpTTMediaPlayerTCItem;

typedef struct stu_TTMediaPlayerTC
{
    CArray<TTMediaPlayerTCItem> tcArray;

}TTMediaPlayerTC, * lpTTMediaPlayerTC;

//!TTMediaPlayer I/F
typedef struct stu_TTMediaPlayerInterface
{	
	HTTMPHANDLE (* TT_MPI_NewSequence)(const GUID & guidSequence,stuTTVideoStandard tpVideoStandard,DWORD dwWidth, DWORD dwHeight);
	int			(* TT_MPI_CloseSequence)(HTTMPHANDLE & hSequence);
	int			(* TT_MPI_CloseAllSequence)();
	HTTMPHANDLE (* TT_MPI_GetSequence)(const GUID & guidSequence);
	
	int			(* TT_MPI_SetViewWnd)(HTTMPHANDLE hSequence,HWND hWnd);
	int			(* TT_MPI_Invalidate)(HTTMPHANDLE hSequence,HWND hWnd,BOOL bUpdateRect);
	int         (* TT_MPI_SetExtraWnd)(HTTMPHANDLE hSequence,int nVideoTrackIndex, HWND hWnd);
	//!��pData == NULL �����������
	int			(* TT_MPI_SetData)(HTTMPHANDLE hSequence,lpTTMediaPlayerSequence pData);
	int			(* TT_MPI_PushData)(HTTMPHANDLE hSequence,lpTTMediaPlayerSequence pNewData);
	int			(* TT_MPI_UpdateData)(HTTMPHANDLE hSequence,lpTTMediaPlayerSequence pData,BOOL bAuto);
	//!���ù���Ƿ���Ч
	int			(* TT_MPI_SetTrackValid)(HTTMPHANDLE hSequence,TT_MEDIAPLAYER_CLASS_TYPE dwTrackIndex,BOOL bValid);
	//!������Ƶ����
	int			(* TT_MPI_SetVUMixData)(HTTMPHANDLE hSequence,DWORD dwMixData[TT_MEDIAPLAYER_AUDIO_NUM][TT_MEDIAPLAYER_AUDIO_NUM]);
	int         (* TT_MPI_SetAnyMatrix)(HTTMPHANDLE hSequence,const DWORD * pMatrix, DWORD dwWidth, DWORD dwHeight);
	//!���ü���ͨ��
	int			(* TT_MPI_SetAudioMonitor)(HTTMPHANDLE hSequence,DWORD dwMonitorData[TT_MEDIAPLAYER_AM_NUM][TT_MEDIAPLAYER_AUDIO_NUM], TT_MEDIAPLAYER_AUDIO_MODE emAudioMode);

	//Mark Point
	//!��������㣬���Ϊ-1 ȡ���� ����
	int			(* TT_MPI_SetInOut)(HTTMPHANDLE hSequence,__int64 lInPoint, __int64 lOutPoint); 
	int			(* TT_MPI_GetInOut)(HTTMPHANDLE hSequence,__int64 & lInPoint, __int64 & lOutPoint);
	//!��ȡSequence����Ч����㣬Sequence�ĳ���ΪlOutPoint;Sequence����Ч����Ϊ(lOutPoint - lInPoint)
	int			(* TT_MPI_GetRealInOut)(HTTMPHANDLE hSequence,__int64 & lInPoint, __int64 & lOutPoint);

	int			(* TT_MPI_UpdateMarkPoint)(HTTMPHANDLE hSequence,const TTMediaPlayerMarkPointArray & ArrayMarkPoint);
	int			(* TT_MPI_InsertMarkPoint)(HTTMPHANDLE hSequence,const TTMediaPlayerMarkPoint & stuMarkPoint);
	int			(* TT_MPI_ModifyMarkPoint)(HTTMPHANDLE hSequence,const TTMediaPlayerMarkPoint & stuMarkPoint);
	int			(* TT_MPI_DelMarkPoint)(HTTMPHANDLE hSequence,const TTMediaPlayerMarkPoint & stuMarkPoint);
	int			(* TT_MPI_DelAllMarkPoint)(HTTMPHANDLE hSequence);

	int			(* TT_MPI_Play)(const TTMediaPlayerPlayPara & stuPlayPara);
	int			(* TT_MPI_Stop)(HTTMPHANDLE hSequence);
	int			(* TT_MPI_StopAll)();
	int			(* TT_MPI_Seek)(const TTMediaPlayerSeekPara & stuSeekPara);
	int			(* TT_MPI_Play_J)(const TTMediaPlayerPlayPara & stuPlayPara);
	int			(* TT_MPI_Play_K)(HTTMPHANDLE hSequence);
	int			(* TT_MPI_Play_L)(const TTMediaPlayerPlayPara & stuPlayPara);

	int			(* TT_MPI_GetCurrentPosAndVU)(HTTMPHANDLE hSequence,__int64 & iPos,TTMediaPlayerVUData ** pVUDat);//!�ⲿ����del��ָ��
	int			(* TT_MPI_GetStatus)(HTTMPHANDLE hSequence,TT_MEDIAPLAYER_STATUS & eSysStatus);
	int			(* TT_MPI_Snapshot)(HTTMPHANDLE hSequence, LPCTSTR pstrFileName, DWORD dwWidth, DWORD dwHeight);

/*
    Get TC 
        input  : stuFileFormat.dwParam = TT_GET_TC_FROM_MEDIA_FILE
        output : stuFileFormat.stuVideoFormat.dwParam

*/
	int			(* TT_MPI_VerifyFile)(LPCTSTR pstrFileName,TTMediaPlayerFileFormat & stuFileFormat);
	int			(* TT_MPI_E7Format2MediaPlayerFormt)(TTMediaPlayerFileFormat & stuFileFormat,const TTMediaPlayerMediaFormatForE7 & stuE7Format);

	int			(* TT_MPI_SetSysSetupPara)(HTTMPHANDLE hSequence,const TTMediaPlayerSetupPara & stuSetupPara);
	int			(* TT_MPI_GetSysSetupPara)(HTTMPHANDLE hSequence,TTMediaPlayerSetupPara & stuSetupPara);
	int			(* TT_MPI_GetIOCardArray)(TTMediaPlayerIOCardArray & ArrayIOCard);
	int			(* TT_MPI_VUValueToPos)(int iValue,WORD wBitsPerSample);

	//�¼ӽӿ�	by wqm


	//֧��һ��sequence�ര����ʾ
	int			(* TT_MPI_AddViewWnd)(HTTMPHANDLE hSequence, HWND hWnd);		
	int			(* TT_MPI_DeleteViewWnd)(HTTMPHANDLE hSequence, HWND hWnd);
	
	//��Ƶ���ؽӿ�
	int			(* TT_MPI_SetAudioActive)(HTTMPHANDLE hSequence, BOOL bActive);
	int			(* TT_MPI_SetWindowActive)(HTTMPHANDLE hSequence, BOOL bActive);
	
	//��sequenceͬ���ӿ�
	int			(* TT_MPI_SetSynchronous)(HTTMPHANDLE hSequence, BOOL bSynchronous);

	//PreStop����
	int			(* TT_MPI_SetPreStopEnable)(HTTMPHANDLE hSequence, BOOL bEnable);

	//�������� ������Χ(0-2,Ĭ��Ϊ1)
	int			(* TT_MPI_SetVolume)(HTTMPHANDLE hSequence, float fVolume);


	//�ྵͷ ����Sequence����
	int         (* TT_MPI_SetSequenceDescription)(HTTMPHANDLE hSequence, LPCTSTR szDes, UINT uiFontSize, COLORREF clrText);

	//!Ԥ���ӿ�
	int			(* TT_MPI_ThisIsALegend)(DWORD_PTR dwLegendID,DWORD_PTR dwParam);

    //!����TC��ʾ
    int         (* TT_MPI_SetTC)(HTTMPHANDLE hSequence, int nVideoTrackIndex, lpTTMediaPlayerTC pTC);

	stu_TTMediaPlayerInterface()
	{
		memset(this,0,sizeof(stu_TTMediaPlayerInterface));
	}
}TTMediaPlayerInterface,*lpTTMediaPlayerInterface;


int AFX_EXT_API TT_Initialize(DWORD & dwVersion);

int AFX_EXT_API TT_GetInterface(lpTTMediaPlayerInterface lpInterface);

int AFX_EXT_API TT_UnInitialize();

#endif

#endif