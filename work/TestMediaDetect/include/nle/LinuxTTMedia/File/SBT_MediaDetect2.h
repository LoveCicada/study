// SBT_MediaDetect2.h: interface for the SBT_MediaDetect2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SBT_MEDIADETECT2_H__C31C2733_B29A_4F43_80CC_257600627C4D__INCLUDED_)
#define AFX_SBT_MEDIADETECT2_H__C31C2733_B29A_4F43_80CC_257600627C4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../../LinuxTTMedia/ITTAdaptWinDefine.h"
#include "SBT_TransBaseDefine.h"
#include <cstring>

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

struct SBT_GOP_INFO2
{
	int nGopLen;
	int nIFrameCount;
	int nBFrameCount;
	int nPFrameCount;

	SBT_GOP_INFO2()
	{
		nGopLen = 0;
		nIFrameCount = 0;
		nBFrameCount = 0;
		nPFrameCount = 0;
	}
};

struct SBT_VIDEO_INFO2
{
	int nMediaID;

	int nFrameNum;

	//0:	Unknown
	//1:	24000/1001 (23.976)
	//2:	24
	//3:	25
	//4:	30000/1001 (29.97)
	//5:	30
	//6:	50
	//7:	60000/1001 (59.94)
	//8:	60
	//-1:	Variable Frame Rate

	int nFrameRateCode;

	BITMAPINFOHEADER stBmpInfo; 

	SBT_GOP_INFO2 stGopInfo;

	DWORD dwFourCC;

	BOOL bVBR;
	int nBitRate;

	//0:	Unknown
	//1:	420
	//2:	422
	//3:	411
	//4:    444
	int nChroma;

	//0:	Unknown
	//1:	1:1
	//2:	4:3
	//3:	16:9
	//4:	2.21:1
	//5:    5:4
	//6:    3:2
	int nAspectRatio;

	BOOL bProgressive;
	BOOL bTopFieldFirst;

	DWORD dwReserved[8]; //extend use
			             //dwReserved[0]: bit0 for DF or NDF. dwReserved[0] bit0 is 1 for DF, 0 for NDF.
			             //               bit1 for 8bit compresion or 10bit compresion, bit1 is 1 for 10bit,0 for 8bit.
			             //               bit2 for mxf closed caption. 1 for CC, 0 for No CC.
						 //               bit3 is last_frame_incomplete_flag. 0: last frame is complete, 1: last frame is incomplete.
						 //               bit8-15 Extension of nBitrate to form a unsigned 48bit value. 
			             //dwReserved[2]: for EC StartPos,in edit unit
			             //dwReserved[1]: for undefined framerate. when nFrameRateCode = 0, fps = dwReserved[1] / 1000000.0	
			             //dwReserved[3]: bit0 indicate the Fixed Frame Rate or Variable Frame Rate
			             //               bit0 is 1 for Variable Frame Rate
			             //               bit0 is 0 for Fixed	 Frame Rate
                         //               bit1-bit4: HDR Clip Type: 0x0 = Unknown, 0x1 = HDR Vivid, 0x2 = SR-Live
			             //dwReserved[4]: = 0, not have video total duration info
			             //              >= 0, the value is video total duration (ms)	
			             //dwReserved[5]: AFD
			             //dwReserved[6]: bit0-1 indicate that how the decoder works: 1 for CloseGopAsync, 2 for OpenGopAsync, 3 for Sync 
			             //               bit2-9 profile_and_level_indication for MPEG2
			             //
			             //               0x14 =     HP@HL     0x16 =     HP@H-14			  
			             //               0x44 =     MP@HL     0x46 =     MP@H-14     0x48 =  MP@ML
			             //               0x82 =   422P@HL     0x85 =   422P@ML			
			             //   
			             //               bit2-9   profile_idc for H264/H265(UnSupported)
			             //               bit10-17 level_idc   for H264/H265(UnSupported)
			             //
			             //               bit18-19 for Rotation:  0x0 = 0��, 0x1 = 90��, 0x2 = 180��, 0x3 = 270��
			             //dwReserved[7]: mxf StartTimecode(TimecodeComponent)

	SBT_VIDEO_INFO2()
	{
		nMediaID = XH_TRANS_MEDIA_NONE;
		nFrameNum = 0;
		nFrameRateCode = 0;
		memset(&stBmpInfo, 0, sizeof(BITMAPINFOHEADER));
		dwFourCC = 0;
		bVBR = FALSE;
		nBitRate = 0;
		nChroma = 0;
		nAspectRatio = 0;
		bProgressive = FALSE;
		bTopFieldFirst = 0;
		memset(dwReserved, 0, 8 * sizeof(DWORD));
	}
};

//��Ƶλ����Ϣ��������
enum eSingleChannelPosition
{
	eSingleChannelPosition_Unknown        = 0x0,
	eSingleChannelPosition_FRONT_LEFT     = 0x1,      //L
	eSingleChannelPosition_FRONT_RIGHT    = 0x2,      //R
	eSingleChannelPosition_FRONT_CENTER   = 0x3,      //C
	eSingleChannelPosition_LOW_FREQUENCY  = 0x4,      //LFE
	eSingleChannelPosition_LEFT_SURROUND  = 0x5,      //Ls
	eSingleChannelPosition_RIGHT_SURROUND = 0x6,      //Rs
	eSingleChannelPosition_LEFT_CENTER    = 0x7,      //Lc
	eSingleChannelPosition_RIGHT_CENTER   = 0x8,      //Rc
};

//������Ƶ��������Ϣ��������
enum eAudioChannelPositionTag
{
	eAudioChannelPositionTag_Mono            = 0x00000003,		//������   C
	eAudioChannelPositionTag_Stereo          = 0x00000021,      //������   L R
	eAudioChannelPositionTag_WAVE_5_1        = 0x00654321,      //WAVE 5.1  L R C LFE Ls Rs
	eAudioChannelPositionTag_WAVE_7_1        = 0x87654321,      //WAVE 7.1  L R C LFE Ls Rs Lc Rc
};

struct SBT_AUDIO_INFO2
{
	int nMediaID;

	LONGLONG llDuration;

	WAVEFORMATEX stWavFormat;

	BOOL bVBR;

	int nContainerBitWidth;

	DWORD dwReserved[8]; //dwReserved[0]:dolbyE nFrameRateCode, 0:Unknown  1: 24000/1001 (23.976)  2: 24
			             //                                     3:25       4: 30000/1001 (29.97)   5: 30
	                     //                                     6:50       7: 60000/1001 (59.94)   8: 60
			             //dwReserved[1]: bit0-bit31 for wav dolbyE FrameNum
			             //dwReserved[2]: bit0-bit31 for wav dolbyE nChanMapConf(program configuration)
	                     //dwReserved[3]: ��Ƶ��������Ϣ����(���֧��8����)
	                     //               bit00-bit03:   ����1 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
	                     //               bit04-bit07:   ����2 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit08-bit11:   ����3 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit12-bit15:   ����4 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit16-bit19:   ����5 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit20-bit23:   ����6 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit24-bit27:   ����7 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)
		                 //               bit28-bit31:   ����8 ��Ƶλ����Ϣ (��ϸ���壺eSingleChannelPosition)

	                     //dwReserved[5]: ��Ƶ������Ϣ����������ISO:639-2��׼(ʹ��3����ĸ����������)
						 //             : bit00-bit07:   ��ĸ1
	                     //             : bit08-bit15:   ��ĸ2
	                     //             : bit16-bit23:   ��ĸ3
	                     //             : bit24-bit31:   00
				 

	SBT_AUDIO_INFO2()
	{
		nMediaID = XH_TRANS_MEDIA_NONE;
		llDuration = 0;
		memset(&stWavFormat, 0, sizeof(WAVEFORMATEX));
		bVBR = FALSE;
		nContainerBitWidth = 0;
		memset(dwReserved, 0, 8 * sizeof(DWORD));
	}

};

//////////////////////////////////////////////////////////////////////////
//��ӦSBT_MEDIA_INFO2->GetExtraInfo()��չ���� 

//�ļ���չ��Ϣ
enum
{
	nExtInfoTypeFileUnknown             = 0x100,
};

//��Ƶ��չ��Ϣ
enum
{
	nExtInfoTypeVideoUnknown            = 0x200,
	nExtInfoTypeVideoColourDescription,
	nExtInfoTypeVideoCameraMetadata,
	nExtInfoTypeMXF,
	nExtInfoTypeVideoColourDescription2,
};

//nExtInfoTypeVideoColourDescription����
//nExtInfoLen   = sizeof(stExtInfoVideoColourDescription)
//pExtInfo      = &stExtInfoVideoColourDescription


//ColorSpace����
enum
{
	//Rec. ITU-R BT.709
	eColourPrimaries_BT_709              =   1,
	//Image characteristics are unknown or are determined by the application
	eColourPrimaries_Unspecified         =   2,
	//ITU-R Rec. BT.601
	eColourPrimaries_BT_601_625			 =   5,
	//ITU-R Rec. BT.601
	eColourPrimaries_BT_601_525			 =   6,
	//Rec. ITU-R BT.2020
	eColourPrimaries_BT_2020             =   9,
	//Sony S-Gamut Color Space
	eColourPrimaries_SGamut              = 100,
	//Sony S-Gamut3 Color Space
	eColourPrimaries_SGamut3             = 101,
	//Sony S-Gamut3.Cine Color Space
	eColourPrimaries_SGamut3Cine         = 102,
	//Canon Cinema Gamut
	eColourPrimaries_Canon_Cinema_Gamut  = 110,
	//RED Wide Gamut RGB
	eColourPrimaries_RED_Wide_Gamut      = 120,
	//DJI D-Gamut
	eColourPrimaries_DJI_DGamut			 = 130,
	//Panasonic V-Gamut
	eColourPrimaries_VGamut				 = 200,
	//Arri Wide Gamut RGB
	eColourPrimaries_Arri_Wide_Gamut	 = 210,
};

//OETFת�����Զ���
enum
{
	//Rec. ITU-R BT.709
	eTransferCharacteristic_BT_709        =   1,
	//Image characteristics are unknown or are determined by the application.
	eTransferCharacteristic_Unspecified   =   2,
	//display gamma 2.2
	eTransferCharacteristic_GAMMA22       =   4,
	//display gamma 2.8
	eTransferCharacteristic_GAMMA28       =   5,
	//ITU-R Rec. BT.601
	eTransferCharacteristic_BT_601        =   6,
	//Linear transfer characteristics
	eTransferCharacteristic_LINEAR        =   8,
	//Logarithmic transfer characteristic(100:1 range)
	eTransferCharacteristic_LOG           =   9,
	//Logarithmic transfer characteristic(100 * Sqrt(10) : 1 range)
	eTransferCharacteristic_LOG_SQRT      =  10,
	//display gamma 2.4
	eTransferCharacteristic_GAMMA24       =  13,
	//Rec. ITU-R BT.2020-2 for 10-bit system
	eTransferCharacteristic_BT_2020_10BIT =  14,
	//Rec. ITU-R BT.2020-2 for 12-bit system
	eTransferCharacteristic_BT_2020_12BIT =  15,
	//Rec. ITU-R BT.2100-0 perceptual quantization (PQ) system
	eTransferCharacteristic_BT_2100_PQ    =  16,
	//Rec. ITU-R BT.2100-0 hybrid loggamma (HLG) system
	eTransferCharacteristic_BT_2100_HLG   =  18,
	//Sony S-Log2(/S-Gamut)
	eTransferCharacteristic_SLog2         = 100,
	//Sony S-Log3(/S-Gamut3 Or S-Gamut3.Cine)
	eTransferCharacteristic_SLog3         = 101,
	//Sony S-Log3(Live)
	eTransferCharacteristic_SLog3_Live    = 102,
	//Canon Log
	eTransferCharacteristic_CLog          = 110,
	//Canon Log 2
	eTransferCharacteristic_Clog_2		  = 111,
	//Canon Log 3
	eTransferCharacteristic_Clog_3        = 112,
	//RED LOG3G10
	eTransferCharacteristic_RED_LOG3G10	  = 120,
	//DJI D-Log
	eTransferCharacteristic_DJI_DLog	  = 130,
	//Panasonic V-Log
	eTransferCharacteristic_VLog	 	  = 200,
	//Panasonic V-709
	eTransferCharacteristic_V709	 	  = 201,
	//Arri ALEXA 3.x Log C Curve
	eTransferCharacteristic_Alexa_LogC_3  = 210,
	//Arri ALEXA 2.x Log C Curve
	eTransferCharacteristic_Alexa_LogC_2  = 211,
	//BT.2100 HLG(OETF Only)
	eTransferCharacteristic_BT_2100_HLG_SCENE = 228,
	//display gamma 2.6
	eTransferCharacteristic_GAMMA26		  = 230,
};

//����ת��ϵ������
enum
{
	//ITU-R Rec. BT.709
	eMatrixCoefficients_BT_709                 =  1,
	//Image characteristics are unknown or are determined by the application
	eMatrixCoefficients_Unspecified            =  2,
	//ITU-R Rec. BT.601
	eMatrixCoefficients_BT_601_625			   =  5,
	//ITU-R Rec. BT.601
	eMatrixCoefficients_BT_601_525			   =  6,
	//Rec. ITU-R BT.2020-2 non-constant luminance system
	eMatrixCoefficients_BT_2020_NCL            =  9,
	//Rec. ITU-R BT.2020-2 constant luminance system
	eMatrixCoefficients_BT_2020_CL             = 10,
};

//����ģʽ����
enum
{
	eMxfOperationPatternUnknown = 0,
	eMxfOperationPatternOp1a    = 101,
	eMxfOperationPatternOp1b    = 102,
	eMxfOperationPatternOp1c    = 103,
	eMxfOperationPatternOp2a    = 201,
	eMxfOperationPatternOp2b    = 202,
	eMxfOperationPatternOp2c    = 203,
	eMxfOperationPatternOp3a    = 301,
	eMxfOperationPatternOp3b    = 302,
	eMxfOperationPatternOp3c    = 303,
	eMxfOpweationPatternOpAtom  = 400,
};

struct stExtInfoVideoColourDescription
{
	int nVideoStreamIndex;

	int nColourPrimaries;

	int nTransferCharacteristics;

	int nMatrixCoeffs;
};

struct stExtInfoVideoColourDescription2
{
	int nVideoStreamIndex;
	//��Ƶ��ɫ�ռ���Ϣ
	int nColourPrimaries;
	//��Ƶת��������Ϣ
	int nTransferCharacteristics;
	//��Ƶ����ת����Ϣ
	int nMatrixCoeffs;
	//��Ƶ�źŷ�Χ(0:Unknown 1:Full 2:Limited)
	int nVideoRange;
	
	//ST2086��̬Ԫ������Ϣ��־λ(0:��Ч 1:��Ч)
	int nMasteringDisplayColourFlags;

	int nRedPrimaries_x;
	int nRedPrimaries_y;
	int nGreenPrimaries_x;
	int nGreenPrimaries_y;
	int nBluePrimaries_x;
	int nBluePrimaries_y;
	int nWhitePoint_x;
	int nWhitePoint_y;
	int nMaxDisplayLuminance;
	int nMinDisplayLuminance;
	
	//��չ��Ϣ����ʱδʹ��
	int nReserved[16];
};



//nExtInfoTypeVideoCameraMetadata����
//nExtInfoLen   = sizeof(stExtInfoVideoCamaraMetadata)
//pExtInfo      = &stExtInfoVideoCamaraMetadata



struct stExtInfoVideoCamaraMetadata
{
	int nVideoStreamIndex;
	//��Ϣ��־λ
	int nMetadataValid;
	//ISOֵ
	int nExposureIndex;
	//��ƽ��ɫ��
	int nWhiteBalanceKelvin; 	
	//��ƽ��ɫ��(ʵ��ֵ: ��ǰֵ / 100.0)
	int nWhiteBalanceTint;


	//�ع�ֵ(ʵ��ֵ: ��ǰֵ / 100.0) 
	int nEV;
	//��ɫ����ֵ(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nGainRed;	
	//��ɫ����ֵ(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nGainGreen;		
	//��ɫ����ֵ(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nGainBlue;
	//���Ͷ�(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nSaturation;
	//�Աȶ�(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nContrast;	
	//����(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nBrightness;
	//�߹����(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nDRX;
	//��Ӱ����(ʵ��ֵ: ��ǰֵ / 100.0) 
	int nShadow;	
	//ISO΢������(ʵ��ֵ: ��ǰֵ / 100.0) 
	int	nFLUT;

	int nReserved[1];
};

struct stExtInfoMXF
{
	int nVideoStreamIndex;
	//����ģʽ
	int nOperationalPattern;

	int nReserved[14];
};


//��Ƶ��չ��Ϣ
enum
{
	nExtInfoTypeAudioUnknown = 0x300,
};

//////////////////////////////////////////////////////////////////////////




#endif // !defined(AFX_SBT_MEDIADETECT2_H__C31C2733_B29A_4F43_80CC_257600627C4D__INCLUDED_)
