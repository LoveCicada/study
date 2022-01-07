 /*********************************************************
 * Filename: VX_CutlistV2DataStruct.h
 * Contents: DataStruct of the Class/Interface of CUTLISTV2 SDK 
 * Authors: Jinsha Zhang, Pu Lin, Yingqi Wang  
 * Date: Oct, 10, 2008
 * All Rights Reserved
 * Sobey Inc, P.R.China
 **********************************************************/


#ifndef _VX_CUTLISTV2_INTERFACE_DECLARATION_H_
#define _VX_CUTLISTV2_INTERFACE_DECLARATION_H_


////////////////////////// Item type defination //////////////////////////
#define SBT_SUTLIST_ITEM_NONE				0x00    //invalid cutlist
#define SBT_CUTLIST_ITEM_VIDEO				0x01	//video
#define SBT_CUTLIST_ITEM_AUDIO				0x02	//audio
//#define SBT_CUTLIST_ITEM_GRAPHICS			0x03    //CG
#define SBT_CUTLIST_ITEM_VIDEO_10BIT		0x11	//10 bit video


///////////////////////// status type defination /////////////////////////
#define SBT_CUTLIST_STATUS_NONE				0x00    //None:To Seek Mode and clear buffer
#define SBT_CUTLIST_STATUS_SEEK				0x01	//Seek, step in, step back
#define SBT_CUTLIST_STATUS_PLAY				0x02    //Play
#define SBT_CUTLIST_STATUS_REVERSEPLAY		0x03	//reverse play
#define SBT_CUTLIST_STATUS_SCRUB			0x04    //scrub
#define SBT_CUTLIST_STATUS_LOWMEMSEEK		0x05    //low memory seek

#define SBT_CUTLIST_STATUS_JKL_0X			0x1000  //JKL Mode: k
#define SBT_CUTLIST_STATUS_JKL_1X			0x1001	//JKL Mode: 1X Play
#define SBT_CUTLIST_STATUS_JKL_2X			0x1002	//JKL Mode: 2X Play
#define SBT_CUTLIST_STATUS_JKL_4X			0x1004	//JKL Mode: 4X Play
#define SBT_CUTLIST_STATUS_JKL_8X			0x1008	//JKL Mode: 8X Play
#define SBT_CUTLIST_STATUS_JKL_16X			0x1010	//JKL Mode: 16X Play
#define SBT_CUTLIST_STATUS_JKL_R1X			0x1101	//JKL Mode: 1X ReversePlay
#define SBT_CUTLIST_STATUS_JKL_R2X			0x1102	//JKL Mode: 2X ReversePlay
#define SBT_CUTLIST_STATUS_JKL_R4X			0x1104	//JKL Mode: 4X ReversePlay
#define SBT_CUTLIST_STATUS_JKL_R8X			0x1108	//JKL Mode: 8X ReversePlay
#define SBT_CUTLIST_STATUS_JKL_R16X			0x1110	//JKL Mode: 16X Reverselay

//#define SBT_CUTLIST_STATUS_EDITPLAY         0x12
//#define SBT_CUTLIST_STATUS_EDITREVERSEPLAY  0x13
////////////////// cutlist operation mode defination /////////////////////
//#define SBT_CUTLIST_OPMODE_BYFRAME          0x00    //operated in FRAME mode
//#define SBT_CUTLIST_OPMODE_BYTIME           0x01    //operation in time mode, the unit is 100ns
#define SBT_CUTLIST_OPMODE_FULLSIZE         0x1000  //decode full size of the video,especially for JPEG2000
#define SBT_CUTLIST_OPMODE_HALFSIZE         0x1001  //decode half size of the video,especially for JPEG2000


/////////////// cutlist methods return value defination  //////////////////////
#define SBT_CUTLIST_RET_SUCCESS             0x01    //success 
#define SBT_CUTLIST_RET_FAILURE             0x00    //failure 

/////////////// cutlist configureobj nFuncType value defination  //////////////
#define SBT_CUTLIST_MOVEFRAME				0x00 //param = int64_t  ,paramlen = sizeof(int64_t)

//0: Two Channel Mode(Old) , 1: Real Mode(New)
#define SBT_CUTLIST_AUDIO_OUTMODE			0x01 //param = int , paramlen = sizeof(int)
#define SBT_CUTLIST_AUDIO_CFGMODE			0x02 //param = ST_AUDIO_CFG , paramlen = sizeof(ST_AUDIO_CFG)
#define SBT_CUTLIST_AUDIO_NOFILTER			0x10 //param = int , paramlen = sizeof(int)

#define SBT_CUTLIST_DV_TOP_FIELD_FIRST		0x2010
#define SBT_CUTLIST_DV_BOTTOM_FIELD_FIRST	0x2020

#define SBT_CUTLIST_MAX_READERS_COUNT		0x2101
//set max readers count, param = int, paramlen = sizeof(int)

#define SBT_CUTLIST_OPEN_FILE				0x2102

#define SBT_CUTLIST_APPEND_ITEM			    0x2103
//open specific file, param = CComBSTR, paramlen = sizeof(CComBSTR)

#define SBT_CUTLIST_JUMP_FRAME				0x2104
//for video cutlist, before get disorder frame when status is play or reverseplay, call this first
//param = _int64, paramlen = sizeof(_int64)

#define SBT_CUTLIST_IPE_MODE				0x2105

#define SBT_CUTLIST_APPEND_ITEMLIST			0x2106

#define SBT_CUTLIST_FILEFRAMEPOOL_REDUNDANCY		0x2107

#define SBT_CUTLIST_MINI_ISCRUB				0x2108

#define SBT_CUTLIST_MINI_STATUS				0x2109
//for decmini ConfigureObj
//pParam = int, paramlen = sizeof(int)
//pParam: 0, seek; 1, play; -1. reverseplay

#define SBT_CUTLIST_MINI_NO_MEDIADET		0x2110
//for decmini ConfigureObj
//pParam = NULL, paramlen = 0

#define SBT_CUTLIST_MINI_PARAM				0x2111
//for decmini ConfigureObj
//pParam =  ST_CUTLIST_ITEM, paramlen = sizeof(ST_CUTLIST_ITEM)


#define SBT_CUTLIST_CLEAR_DECODERS			0x2112


#define SBT_CUTLIST_MINI_OUTPUT_FORMAT      0x2113
//for decmini ConfigureObj
//pParam = &int, paramlen = sizeof(int)
//pParam: 0:  ignore,   1: output the decoder format

#define SBT_CUTLIST_CLEAR_CX_DECODER		0x2114

//10bit格式解码后不做任何处理
#define SBT_CUTLIST_10BIT_NO_PROCESS		0x2115

//XAVC Intra开启两个解码器并行解码
#define SBT_CUTLIST_ENABLE_XAVC_2_DECODERS	0x2116

//手动清除预卷队列
//pParam = BOOL(bDecode, 0:读文件预卷队列, 1:解码预卷队列)
#define SBT_CUTLIST_CLEAR_PREROLL_QUEUE		0x2117

//清除Item时是否保留Reader
//pParam = &int, nParamLen = sizeof(int)
//*(int *)pParam: 0- SetItemList(NULL)时关闭相应的Reader(默认) 1- SetItemList(NULL)时保留相应的Reader
#define SBT_CUTLIST_CLEAR_ITEM_KEEP_READER	0x2118

//设置硬件GPU设备
//nParamLen 设备类型
#define SBT_CUTLIST_SET_GPU_DEVICE			0x2119

//设置硬件GPU临界区信息
#define SBT_CUTLIST_SET_GPU_CRITICAL_SECTION_INFO  0x2120


#define SBT_CUTLIST_SET_FPS					0x2200

#define SBT_CUTLIST_SET_FRAME_FORMAT           0x4000
/*
  
The param   set struct of " ST_FRAME_FORMAT_INFO "   by " ConfigureObj" function 
  
*/


////////////////////////////// include ///////////////////////////////////
#include "VX_TransBaseDefine.h"
#include <stdint.h>
#include <string.h>
#include <string>

struct VX_BITMAPINFOHEADER
{
	uint32_t   biSize;
	int32_t    biWidth;
	int32_t    biHeight;
	uint16_t   biPlanes;
	uint16_t   biBitCount;
	uint32_t   biCompression;
	uint32_t   biSizeImage;
	int32_t    biXPelsPerMeter;
	int32_t    biYPelsPerMeter;
	uint32_t   biClrUsed;
	uint32_t   biClrImportant;
};

struct VX_WAVEFORMATEX
{
	uint16_t   wFormatTag;         /* format type */
	uint16_t   nChannels;          /* number of channels (i.e. mono, stereo...) */
	uint32_t   nSamplesPerSec;     /* sample rate */
	uint32_t   nAvgBytesPerSec;    /* for buffer estimation */
	uint16_t   nBlockAlign;        /* block size of data */
	uint16_t   wBitsPerSample;     /* number of bits per sample of mono data */
	uint16_t   cbSize;             /* the count in bytes of the size of */
								   /* extra information (after cbSize) */
};


struct VX_MEDIA_TYPE
{
	uint32_t cbFormat;
	uint8_t *pbFormat;
};


////////////////////// cutlist item defination ///////////////////////////

struct VX_CUTLIST_ITEM
{
	//item type
	uint32_t      dwItemType;			 //type of item, video/audio/CG
										//the type of the first item defines the type of the whole cutlist item
	//file and media stream information
	std::wstring  bstrFileName;         //file full name, including the file full path
	uint32_t      dwFileFormatID;	     //file format ID,see defination in "SBT_TransBaseDefine.h"
	uint32_t      dwMediaTypeID;		 //media format ID of the specified stream, see defination in "SBT_TransBaseDefine.h"			
	uint32_t      dwStreamNo;           //specified media stream No., default is 0       (dwSubStreamType)


	//media and timeline trim in/out
	//[llMediaIn, llMediaOut)
	int64_t   llMediaIn;            //Media trim in
	int64_t   llMediaOut;           //Media trim out, default: llMediaOut >= llMediaIn
	                                 //for item reverse play, let:   llMediaIn >= llMediaOut
	                                 //Example: for item [0,100), the reverse item is [99,-1)
	                                 //         for item [50,200), the reverse item is [199,49)
	//[llTimelineIn, llTimelineOut)
	int64_t   llTimelineIn;         //timeline trim in
	int64_t   llTimelineOut;        //timeline trim out, 
	                                 //note: llTimelineOut must greater or equal than llTimelineIn
									 //no DMC
	//single frame
	int64_t   llSingleFrame;        //single frame FLAG and position,
	                                 // = -1: means the item is not a single frame, default value
	                                 // >=0: means single frame is enabled and the frame position is specified 

	//userdata
	uint32_t     dwUserData;            //User Data

	//reserved
	uint32_t     dwReserved1;           //reserved  
	//The  low 8bit of  "dwReserved1" is frame rate following value is defined
	//0x01 ：25p fps   
	//0x02 ：29.97p fps 
	//0x03 : 30p fps 
	//0x04 : 23.976p fps 
	//0x05 : 24p fps 
	//0x06 : 50i fps 
	//0x07 : 60i fps 
	//0x08 : 59.94i fps 
	//0x09 : 50p fps
	//0x10 : 60p fps
	//0x11 : 59.94p fps
	
	//The bit8-15 of "dwReserved1" is video resolution decode mode(only RAW decode use)
	//0x00 : Full resolution highest quality
	//0x01 : Full resolution good    quality
	//0x02 : 1/2  resolution highest quality
	//0x03 : 1/2  resolution good    quality
	//0x04 : 1/4  resolution highest quality
	//0x05 : 1/4  resolution good    quality
	//0x06 : 1/8  resolution highest quality
	//0x07 : 1/8  resolution good    quality
	//0x08 : 1/16 resolution highest quality
	//0x09 : 1/16 resolution good    quality

	uint32_t     dwReserved2;           //reserved
	//userdata_ptr
	void*  pdwUserData;          // User Data ptr  
	//////////////////////////////////construction
	VX_CUTLIST_ITEM()
	{
		dwItemType = SBT_SUTLIST_ITEM_NONE;
		dwFileFormatID = XH_TRANS_FILE_UNKNOWN;
		dwMediaTypeID = XH_TRANS_MEDIA_UNKNOWN;
		dwStreamNo = 0;
		llMediaIn = 0;
		llMediaOut = -1;
		llTimelineIn = 0;
		llTimelineOut = 0;
		llSingleFrame = -1;

		dwUserData = 0;
		dwReserved1 = 0;
		dwReserved2 = 0;
		pdwUserData = 0;
	}
};


//struct of the cutlist decoder input
struct VX_CUTLISTV2_DECODE_IN
{
	//decode control
	int64_t      llTimelinePos;      //position in cutlist timeline
	uint32_t     dwCropResizeMode;   //only valid for video
	                                 //default is 0x00:
	uint32_t     dwMask;			 //for video: 0x01: odd field
	                                 //           0x02: even field
	                                 //           0x03: keep frame as is
									 //           0x04: odd and even field block 
                                     //for strero audio: 
	                                 //           0x01: left channel
	                                 //           0x02: right channel
	                                 //           0x03: keep stream as is
									 //for mono audio: "dwSubStreamMask" is ignored
									 //default: dwMask = 0xFFFF: keep frame as is
	//target user buffer 
	uint8_t       *pUserBuffer;      //user allocated buffer (main buffer)
	uint8_t       *pUserBuffer2;     //user allocated buffer 2, only valid in case of dwMask = 0x04 
									 //if pUserBuffer = NULL, cutlist will use the internal buffer as the result buffer
	int32_t       nUserBufSize;      //user buffer size, you must allocate enough buffer to hold the data
	                                 //only valid in case of pUserBuffer != NULL
	int32_t       nUserBufStride;    //width stride of the user buffer,
	                                 //only valid in case of pUserBuffer != NULL

	//parameter
	uint32_t	  dwParameter;	     //bit0:  0:  ignore,   1: output the decoder format
	//reserved 
	uint32_t	  dwReserved;

	///////////////////////////////////construct
	VX_CUTLISTV2_DECODE_IN()
	{
		llTimelinePos = 0;
		dwCropResizeMode = 0x00;
		dwMask = 0xFFFF;
		pUserBuffer = NULL;
		pUserBuffer2 = NULL;
		nUserBufSize = 0;
		nUserBufStride = 0;
		dwParameter = 0;
		dwReserved = 0;
	}
};

///struct of the cutlist decoder output
struct VX_CUTLISTV2_DECODE_OUT
{
	//dest buffer data
	uint8_t *pDestBuffer;                //point to the result buffer (main returned buffer)
	uint8_t *pDestBuffer2;               //point to the result buffer 2 (only valid in case of dwMask = 0x04)
	int32_t nActualDataSize;             //actual data size in the buffer
	int32_t nTopField;					 //0: odd field first   1: even field first
	int64_t llActualTimelinePos;         //actual pos on the time line  (only valid in scrub)

	//dest buffer info
	VX_BITMAPINFOHEADER stDestBmpInfo;  //only for video
	VX_WAVEFORMATEX     stDestWavInfo;  //only for audio

	uint32_t dwReserved;

	/////////////////////////////////construct
	VX_CUTLISTV2_DECODE_OUT()
	{
		pDestBuffer = NULL;
		pDestBuffer2 = NULL;
		nTopField = 0;
		nActualDataSize = 0;
		dwReserved = 0;

		memset(&stDestBmpInfo, 0, sizeof(VX_BITMAPINFOHEADER));
		memset(&stDestWavInfo, 0, sizeof(VX_WAVEFORMATEX));
	}
};

//struct of cutlist process infomation
struct VX_CUTLIST_PROCESS_INFO
{
	int32_t nFileReadBufferNum;   //the file reader bufferlist left number
	int32_t nDecodedBufferNum;    //the decoded bufferlist left number
	int64_t llHeldBufferSize; //buffersize of all bufferlist hold
	int32_t dwStatus;           //cutlist status

	VX_CUTLIST_PROCESS_INFO()
	{
		nFileReadBufferNum = 0;
		nDecodedBufferNum = 0;
		llHeldBufferSize = 0;
		dwStatus = 0;
	}
};

struct VX_FRAME_FORMAT_INFO
{
	double				 dFrameRate;	    // 
	int32_t				 nFramelayer;		// 0, ttf, interlacing; 1, btf, interlacing; 2, progressive
	
	int32_t				 nAdaptionAspect;	// 0, no adaption; 1, height; 2, width adaption; 3, center 
	VX_BITMAPINFOHEADER biOutFormat;		// only be used when nAdaptionAspect > 0
};

struct VX_CUTLIST_ERROR_INFO
{
	int          m_nthreadID;
	uint32_t     m_nErrorCode;
	std::wstring  m_strDiscrypt;
	uint8_t      byteResversl[8];
	
	VX_CUTLIST_ERROR_INFO()
	{
		m_nthreadID = 0;
		m_nErrorCode = 0;
		memset(byteResversl, 0, 8 * sizeof(uint8_t));
	}
};


#endif