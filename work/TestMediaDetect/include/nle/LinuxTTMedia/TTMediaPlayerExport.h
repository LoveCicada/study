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



#endif