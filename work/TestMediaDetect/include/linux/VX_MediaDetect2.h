// VX_MediaDetect2.h: interface for the VX_MediaDetect2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(VX_MEDIADETECT2_H_INCLUDED_)
#define VX_MEDIADETECT2_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VXSDKPlatform.h"
#include "VX_CutListV2DataStruct.h"


//////////////////////////////////////////////////////////////////////////

struct VX_GOP_INFO2
{
	int nGopLen;
	int nIFrameCount;
	int nBFrameCount;
	int nPFrameCount;

	VX_GOP_INFO2()
	{
		nGopLen = 0;
		nIFrameCount = 0;
		nBFrameCount = 0;
		nPFrameCount = 0;
	}
};

struct VX_VIDEO_INFO2
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

	VX_BITMAPINFOHEADER stBmpInfo; 

	VX_GOP_INFO2 stGopInfo;

	uint32_t dwFourCC;

	int     bVBR;
	int64_t nBitRate;

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

	int bProgressive;
	int bTopFieldFirst;

	uint32_t dwReserved[8]; //extend use
			             //dwReserved[0]: bit0 for DF or NDF. dwReserved[0] bit0 is 1 for DF, 0 for NDF.
			             //               bit1 for 8bit compresion or 10bit compresion, bit1 is 1 for 10bit,0 for 8bit.
			             //               bit2 for mxf closed caption. 1 for CC, 0 for No CC.
						 //               bit3 is last_frame_incomplete_flag. 0: last frame is complete, 1: last frame is incomplete.
			             //dwReserved[2]: for EC StartPos,in edit unit
			             //dwReserved[1]: for undefined framerate. when nFrameRateCode = 0, fps = dwReserved[1] / 1000000.0	
			             //dwReserved[3]: bit0 indicate the Fixed Frame Rate or Variable Frame Rate
			             //               bit0 is 1 for Variable Frame Rate
			             //               bit0 is 0 for Fixed	 Frame Rate
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
			             //               bit18-19 for Rotation:  0x0 = 0°, 0x1 = 90°, 0x2 = 180°, 0x3 = 270°
			             //dwReserved[7]: mxf StartTimecode(TimecodeComponent)

	VX_VIDEO_INFO2()
	{
		nMediaID = XH_TRANS_MEDIA_NONE;
		nFrameNum = 0;
		nFrameRateCode = 0;
		memset(&stBmpInfo, 0, sizeof(VX_BITMAPINFOHEADER));
		dwFourCC = 0;
		bVBR = 0;
		nBitRate = 0;
		nChroma = 0;
		nAspectRatio = 0;
		bProgressive = 0;
		bTopFieldFirst = 0;
		memset(dwReserved, 0, 8 * sizeof(uint32_t));
	}
};

//音频位置信息描述定义
enum eVXSingleChannelPosition
{
	eVXSingleChannelPosition_Unknown        = 0x0,
	eVXSingleChannelPosition_FRONT_LEFT     = 0x1,      //L
	eVXSingleChannelPosition_FRONT_RIGHT    = 0x2,      //R
	eVXSingleChannelPosition_FRONT_CENTER   = 0x3,      //C
	eVXSingleChannelPosition_LOW_FREQUENCY  = 0x4,      //LFE
	eVXSingleChannelPosition_LEFT_SURROUND  = 0x5,      //Ls
	eVXSingleChannelPosition_RIGHT_SURROUND = 0x6,      //Rs
	eVXSingleChannelPosition_LEFT_CENTER    = 0x7,      //Lc
	eVXSingleChannelPosition_RIGHT_CENTER   = 0x8,      //Rc
};

//常用音频流声道信息描述定义
enum eVXAudioChannelPositionTag
{
	eVXAudioChannelPositionTag_Mono     = 0x00000003,	   //单声道   C
	eVXAudioChannelPositionTag_Stereo   = 0x00000021,      //立体声   L R
	eVXAudioChannelPositionTag_WAVE_5_1 = 0x00654321,      //WAVE 5.1  L R C LFE Ls Rs
	eVXAudioChannelPositionTag_WAVE_7_1 = 0x87654321,      //WAVE 7.1  L R C LFE Ls Rs Lc Rc
};

struct VX_AUDIO_INFO2
{
	int nMediaID;

	int64_t llDuration;

	VX_WAVEFORMATEX stWavFormat;

	int bVBR;

	int nContainerBitWidth;

	uint32_t dwReserved[8]; //dwReserved[0]:dolbyE nFrameRateCode, 0:Unknown  1: 24000/1001 (23.976)  2: 24
			             //                                     3:25       4: 30000/1001 (29.97)   5: 30
	                     //                                     6:50       7: 60000/1001 (59.94)   8: 60
			             //dwReserved[1]: bit0-bit31 for wav dolbyE FrameNum
			             //dwReserved[2]: bit0-bit31 for wav dolbyE nChanMapConf(program configuration)
	                     //dwReserved[3]: 音频流声道信息描述(最多支持8声道)
	                     //               bit00-bit03:   声道1 音频位置信息 (详细定义：eSingleChannelPosition)
	                     //               bit04-bit07:   声道2 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit08-bit11:   声道3 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit12-bit15:   声道4 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit16-bit19:   声道5 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit20-bit23:   声道6 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit24-bit27:   声道7 音频位置信息 (详细定义：eSingleChannelPosition)
		                 //               bit28-bit31:   声道8 音频位置信息 (详细定义：eSingleChannelPosition)

	                     //dwReserved[5]: 音频语言信息描述：采用ISO:639-2标准(使用3个字母来描述语音)
						 //             : bit00-bit07:   字母1
	                     //             : bit08-bit15:   字母2
	                     //             : bit16-bit23:   字母3
	                     //             : bit24-bit31:   00
				 

	VX_AUDIO_INFO2()
	{
		nMediaID = XH_TRANS_MEDIA_NONE;
		llDuration = 0;
		memset(&stWavFormat, 0, sizeof(VX_WAVEFORMATEX));
		bVBR = 0;
		nContainerBitWidth = 0;
		memset(dwReserved, 0, 8 * sizeof(uint32_t));
	}

};

//////////////////////////////////////////////////////////////////////////
//对应SBT_MEDIA_INFO2->GetExtraInfo()扩展定义 

//文件扩展信息
enum
{
	eVXExtInfoTypeFileUnknown = 0x100,
};

//视频扩展信息
enum
{
	eVXExtInfoTypeVideoUnknown = 0x200,
	eVXExtInfoTypeVideoColourDescription,
	eVXExtInfoTypeVideoCameraMetadata,
	eVXExtInfoTypeMXF,
	eVXExtInfoTypeVideoColourDescription2,
};

//nExtInfoTypeVideoColourDescription定义
//nExtInfoLen   = sizeof(stExtInfoVideoColourDescription)
//pExtInfo      = &stExtInfoVideoColourDescription


//ColorSpace定义
enum
{
	//Rec. ITU-R BT.709
	eVXColourPrimaries_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application
	eVXColourPrimaries_Unspecified = 2,
	//ITU-R Rec. BT.601
	eVXColourPrimaries_BT_601_625 = 5,
	//ITU-R Rec. BT.601
	eVXColourPrimaries_BT_601_525 = 6,
	//Rec. ITU-R BT.2020
	eVXColourPrimaries_BT_2020 = 9,
	//Sony S-Gamut Color Space
	eVXColourPrimaries_SGamut = 100,
	//Sony S-Gamut3 Color Space
	eVXColourPrimaries_SGamut3 = 101,
	//Sony S-Gamut3.Cine Color Space
	eVXColourPrimaries_SGamut3Cine = 102,
	//Canon Cinema Gamut
	eVXColourPrimaries_Canon_Cinema_Gamut = 110,
	//RED Wide Gamut RGB
	eVXColourPrimaries_RED_Wide_Gamut = 120,
	//DJI D-Gamut
	eVXColourPrimaries_DJI_DGamut = 130,
	//Panasonic V-Gamut
	eVXColourPrimaries_VGamut = 200,
	//Arri Wide Gamut RGB
	eVXColourPrimaries_Arri_Wide_Gamut = 210,
};

//OETF转换特性定义
enum
{
	//Rec. ITU-R BT.709
	eVXTransferCharacteristic_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application.
	eVXTransferCharacteristic_Unspecified = 2,
	//display gamma 2.2
	eVXTransferCharacteristic_GAMMA22 = 4,
	//display gamma 2.8
	eVXTransferCharacteristic_GAMMA28 = 5,
	//ITU-R Rec. BT.601
	eVXTransferCharacteristic_BT_601 = 6,
	//Linear transfer characteristics
	eVXTransferCharacteristic_LINEAR = 8,
	//Logarithmic transfer characteristic(100:1 range)
	eVXTransferCharacteristic_LOG = 9,
	//Logarithmic transfer characteristic(100 * Sqrt(10) : 1 range)
	eVXTransferCharacteristic_LOG_SQRT = 10,
	//display gamma 2.4
	eVXTransferCharacteristic_GAMMA24 = 13,
	//Rec. ITU-R BT.2020-2 for 10-bit system
	eVXTransferCharacteristic_BT_2020_10BIT = 14,
	//Rec. ITU-R BT.2020-2 for 12-bit system
	eVXTransferCharacteristic_BT_2020_12BIT = 15,
	//Rec. ITU-R BT.2100-0 perceptual quantization (PQ) system
	eVXTransferCharacteristic_BT_2100_PQ = 16,
	//Rec. ITU-R BT.2100-0 hybrid loggamma (HLG) system
	eVXTransferCharacteristic_BT_2100_HLG = 18,
	//Sony S-Log2(/S-Gamut)
	eVXTransferCharacteristic_SLog2 = 100,
	//Sony S-Log3(/S-Gamut3 Or S-Gamut3.Cine)
	eVXTransferCharacteristic_SLog3 = 101,
	//Sony S-Log3(Live)
	eVXVXTransferCharacteristic_SLog3_Live = 102,
	//Canon Log
	eVXVXTransferCharacteristic_CLog = 110,
	//Canon Log 2
	eVXTransferCharacteristic_Clog_2 = 111,
	//Canon Log 3
	eVXTransferCharacteristic_Clog_3 = 112,
	//RED LOG3G10
	eVXTransferCharacteristic_RED_LOG3G10 = 120,
	//DJI D-Log
	eVXTransferCharacteristic_DJI_DLog = 130,
	//Panasonic V-Log
	eVXTransferCharacteristic_VLog = 200,
	//Panasonic V-709
	eVXTransferCharacteristic_V709 = 201,
	//Arri ALEXA 3.x Log C Curve
	eVXTransferCharacteristic_Alexa_LogC_3 = 210,
	//Arri ALEXA 2.x Log C Curve
	eVXTransferCharacteristic_Alexa_LogC_2 = 211,
	//BT.2100 HLG(OETF Only)
	eVXTransferCharacteristic_BT_2100_HLG_SCENE = 228,
	//display gamma 2.6
	eVXTransferCharacteristic_GAMMA26 = 230,
};

//矩阵转换系数定义
enum
{
	//ITU-R Rec. BT.709
	eVXMatrixCoefficients_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application
	eVXMatrixCoefficients_Unspecified = 2,
	//ITU-R Rec. BT.601
	eVXMatrixCoefficients_BT_601_625 = 5,
	//ITU-R Rec. BT.601
	eVXMatrixCoefficients_BT_601_525 = 6,
	//Rec. ITU-R BT.2020-2 non-constant luminance system
	eVXMatrixCoefficients_BT_2020_NCL = 9,
	//Rec. ITU-R BT.2020-2 constant luminance system
	eVXMatrixCoefficients_BT_2020_CL = 10,
};

//操作模式定义
enum
{
	eVXMxfOperationPatternUnknown = 0,
	eVXMxfOperationPatternOp1a = 101,
	eVXMxfOperationPatternOp1b = 102,
	eVXMxfOperationPatternOp1c = 103,
	eVXMxfOperationPatternOp2a = 201,
	eVXMxfOperationPatternOp2b = 202,
	eVXMxfOperationPatternOp2c = 203,
	eVXMxfOperationPatternOp3a = 301,
	eVXMxfOperationPatternOp3b = 302,
	eVXMxfOperationPatternOp3c = 303,
	eVXMxfOpweationPatternOpAtom = 400,
};

struct stVXExtInfoVideoColourDescription
{
	int nVideoStreamIndex;

	int nColourPrimaries;

	int nTransferCharacteristics;

	int nMatrixCoeffs;
};

struct stVXExtInfoVideoColourDescription2
{
	int nVideoStreamIndex;
	//视频颜色空间信息
	int nColourPrimaries;
	//视频转换函数信息
	int nTransferCharacteristics;
	//视频矩阵转换信息
	int nMatrixCoeffs;
	//视频信号范围(0:Unknown 1:Full 2:Limited)
	int nVideoRange;
	
	//ST2086静态元数据信息标志位(0:无效 1:有效)
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
	
	//扩展信息，暂时未使用
	int nReserved[16];
};



//nVXExtInfoTypeVideoCameraMetadata定义
//nExtInfoLen   = sizeof(stVXExtInfoVideoCamaraMetadata)
//pExtInfo      = &stVXExtInfoVideoCamaraMetadata



struct stVXExtInfoVideoCamaraMetadata
{
	int nVideoStreamIndex;
	//信息标志位
	int nMetadataValid;
	//ISO值
	int nExposureIndex;
	//白平衡色温
	int nWhiteBalanceKelvin;
	//白平衡色调(实际值: 当前值 / 100.0)
	int nWhiteBalanceTint;


	//曝光值(实际值: 当前值 / 100.0) 
	int nEV;
	//红色增益值(实际值: 当前值 / 100.0) 
	int	nGainRed;
	//绿色增益值(实际值: 当前值 / 100.0) 
	int	nGainGreen;
	//蓝色增益值(实际值: 当前值 / 100.0) 
	int	nGainBlue;
	//饱和度(实际值: 当前值 / 100.0) 
	int	nSaturation;
	//对比度(实际值: 当前值 / 100.0) 
	int	nContrast;
	//亮度(实际值: 当前值 / 100.0) 
	int	nBrightness;
	//高光控制(实际值: 当前值 / 100.0) 
	int	nDRX;
	//阴影控制(实际值: 当前值 / 100.0) 
	int nShadow;
	//ISO微调控制(实际值: 当前值 / 100.0) 
	int	nFLUT;

	int nReserved[1];
};

struct stVXExtInfoMXF
{
	int nVideoStreamIndex;
	//操作模式
	int nOperationalPattern;

	int nReserved[14];
};


//音频扩展信息
enum
{
	nVXExtInfoTypeAudioUnknown = 0x300,
};

//////////////////////////////////////////////////////////////////////////


class VXMediaInfo2Impl;
class VX_SDK_API VX_MEDIA_INFO2
{
public:
	VX_MEDIA_INFO2();
	virtual ~VX_MEDIA_INFO2();

public:
	std::wstring FileName();

	int64_t FileSize();

	int32_t FileFormatID();

	int VideoStreamNum();

	int AudioStreamNum();

	VX_VIDEO_INFO2 VideoInfo(int nVideoStreamIndex);

	VX_AUDIO_INFO2 AudioInfo(int nAudioStreamIndex);
	
	int32_t MinVideoFrameNum();

	int64_t MinAudioDuration();

	//额外的信息，保留函数
	int GetExtraInfo(int nExtraInfoType, void** ppExtraInfo, int& nExtraInfoLen);

public:
	//不能直接拷贝，需要用Clone函数
	void Clone(VX_MEDIA_INFO2* pMediaInfo2);

public:
	VXMediaInfo2Impl* m_pImpObj;
};

//////////////////////////////////////////////////////////////////////////

class VXMediaDetect2Impl;
class VX_SDK_API VX_MediaDetect2
{
public:
	VX_MediaDetect2();
	virtual ~VX_MediaDetect2();

	//nDetectMode = 0:普通模式
	//nDetectMode = 1:快速模式，用于边采边编，返回3表示文件已封口，此次快速检测无效。
	int SetInputFile(std::wstring strFileName, int nDetectMode = 0);

	int GetMediaInfo2(VX_MEDIA_INFO2* pMediaInfo2);
	
private:
	VXMediaDetect2Impl *m_pImpObj;
};

#endif // !defined(VX_MEDIADETECT2_H_INCLUDED_)
