/*********************************************************
* 文件名　：VXCutlistV2Plus.h
* 功能  　：VXSDK Cutlist模块定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_CUTLISTV2_PLUS_INCLUDE_
#define _VX_SDK_CUTLISTV2_PLUS_INCLUDE_

#ifdef _MSC_VER
#pragma once
#endif

#include <string>
#include <string.h>
#include <stdint.h>
#include "VXSDKPlatform.h"


#define VX_CUTLIST_ITEM_NONE				0x00    //invalid cutlist
#define VX_CUTLIST_ITEM_VIDEO				0x01	//video
#define VX_CUTLIST_ITEM_AUDIO				0x02	//audio


///////////////////////// status type defination /////////////////////////
#define VX_CUTLIST_STATUS_NONE				0x00    //None:To Seek Mode and clear buffer
#define VX_CUTLIST_STATUS_SEEK				0x01	//Seek, step in, step back
#define VX_CUTLIST_STATUS_PLAY				0x02    //Play
#define VX_CUTLIST_STATUS_REVERSEPLAY		0x03	//reverse play
#define VX_CUTLIST_STATUS_SCRUB				0x04    //scrub
#define VX_CUTLIST_STATUS_LOWMEMSEEK		0x05    //low memory seek

#define VX_CUTLIST_STATUS_JKL_0X			0x1000  //JKL Mode: k
#define VX_CUTLIST_STATUS_JKL_1X			0x1001	//JKL Mode: 1X Play
#define VX_CUTLIST_STATUS_JKL_2X			0x1002	//JKL Mode: 2X Play
#define VX_CUTLIST_STATUS_JKL_4X			0x1004	//JKL Mode: 4X Play
#define VX_CUTLIST_STATUS_JKL_8X			0x1008	//JKL Mode: 8X Play
#define VX_CUTLIST_STATUS_JKL_16X			0x1010	//JKL Mode: 16X Play
#define VX_CUTLIST_STATUS_JKL_R1X			0x1101	//JKL Mode: 1X ReversePlay
#define VX_CUTLIST_STATUS_JKL_R2X			0x1102	//JKL Mode: 2X ReversePlay
#define VX_CUTLIST_STATUS_JKL_R4X			0x1104	//JKL Mode: 4X ReversePlay
#define VX_CUTLIST_STATUS_JKL_R8X			0x1108	//JKL Mode: 8X ReversePlay
#define VX_CUTLIST_STATUS_JKL_R16X			0x1110	//JKL Mode: 16X Reverselay


//时间线Item设置
struct stVXCutlistSDKItem
{
	//Item类型
	int nItemType;

	//文件名
	std::string strFileName;

	//文件格式ID
	int nFileFormatID;
	//音视频媒体ID
	int nMediaID;

	//音视频流号
	int nStreamNo;

	//文件入点
	int64_t llMediaIn;
	//文件出点
	int64_t llMediaOut;
	//时间线入点
	int64_t llTimelineIn;
	//时间线出点
	int64_t llTimelineOut;

	//解码模式
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
	int nResolutionDecodeMode;

	//图像缩放模式
	int nFrameResizeMode;
	//图像匹配模式
	int nFrameMatchedMode;

	//解码nMediaID子类型(可以用于选择不同的解码器, 详细定义查看VXSDKBaseDefine.h)
	int nSubMediaType;

	int nReserved[29];

	stVXCutlistSDKItem()
	{
		nItemType = VX_CUTLIST_ITEM_NONE;
		nFileFormatID = 0;
		nMediaID = 0;
		nStreamNo = 0;
		llMediaIn = 0;
		llMediaOut = 0;
		llTimelineIn = 0;
		llTimelineOut = 0;
		nResolutionDecodeMode = 0;
		nFrameResizeMode = 0;
		nFrameMatchedMode = 0;
		nSubMediaType = 0;
		memset(nReserved, 0, sizeof(nReserved));
	}
};

//Cutlist输出设置
struct stVXCutlistOutputFormat
{
	//时间线帧率
	//0x01 ：25p     fps   
	//0x02 ：29.97p  fps 
	//0x03 : 30p     fps 
	//0x04 : 23.976p fps 
	//0x05 : 24p     fps 
	//0x06 : 50i     fps 
	//0x07 : 60i     fps 
	//0x08 : 59.94i  fps 
	//0x09 : 50p     fps
	//0x10 : 60p     fps
	//0x11 : 59.94p  fps
	int nTimelineFrameRate;


	//视频输出参数设置(对应视频Cutlist解码)

	//视频的高度
	int nVideoWidth;
	//视频的宽度
	int nVideoHeight;
	//视频对应的参数:eVXCutlistSDKVideoColorSpaceFormat
	int nVideoFormat;

	//音频输出参数设置(对应音频Cutlist解码)

	//音频采样率
	int nAudioSampleRate;
	//声道数
	int nAudioChannels;
	//位深
	int nBitsPerSample;
	//音频对应的参数:eVXSDKAudioSampleType
	int nAudioSampleType;


	//指定输出模式
	//0x00 : 指定按连续方式输出[默认]
	//	   : [视频] 按单一连续Buffer输出
	//	   : [音频] 按交错输出	
	//0x01 : 指定按分片方式
	//	   : [视频] 按分片方式输出(如YUV420 YUV422等)
	//	   : [音频] 按声道分片输出
	int nOutputMode;


	//优先的数据解码方式 定义参看:eVXSDKBufferType
	int nDecoderBufferType;

	//指定按外面传入的信息进行数据Buffer分配
	void* pDeviceID;
	void* pContext;

	//帧间插值模式(如不同帧率的视频素材混编)
	//0: 最近相邻帧
	//1: 帧间融合
	int nFrameInterpolationMode;

	//图像缩放模式
	int nFrameResizeMode;

	//图像匹配模式
	int nFrameMatchedMode;

	//设置多解码器解码，部分全I帧格式可以支持
	int nParallelDecoderNum;

	int nReserved[23];

	stVXCutlistOutputFormat()
	{
		memset(this, 0, sizeof(stVXCutlistOutputFormat));
	}
};


struct stVXCutlistDecodeIn
{
	//解码的时间线帧位置
	int64_t llTimelinePos;

	//是否按原样输出
	//0: 按stVXCutlistOutputFormat指定的格式进行输出
	//1: 按解码器实际解码出的数据输出(效率最高)
	int nOriginalOutput; 

	//强制下一次不进行预卷操作(PLAY SEEK JKL状态下有效)
	//针对应用层特定情况下存在同一帧取多次的逻辑
	int nIgnoreNextPrepare;

	int nReserved[31];

	stVXCutlistDecodeIn()
	{
		memset(this, 0, sizeof(stVXCutlistDecodeIn));
	}
};

struct stVXCutlistDecodeOut
{
	//数据的存放地址
	uint8_t** ppData;

	//ppData数据的总大小
	int *pDataSize;

	//如果是音频数据与pDataSize一致
	//如果是视频分片数据,对应的是每行数据所占的大小
	int	*pDataLineSize;

	//Data的有效个数
	int nDataNumber;

	//对应Scrub模式下返回的实际帧位置
	int64_t llActualPosition;

	//视频相关参数

	//视频的高度
	int nWidth;
	//视频的宽度
	int nHeight;


	//音频相关参数

	//音频采样率
	int nSampleRate;
	//音频解码返回的Sample数
	int nNumberSamples;
	//声道数
	int nChannels;
	//音频存放方式
	int nAudioPackMode;

	//Buffer格式
	//视频对应的参数为:eVXSDKVideoColorSpaceFormat
	//音频对应的参数为:eVXSDKAudioSampleType
	int nFormat;

	//数据类型定义eVXSDKBufferType
	int nBufferType;

	//数据Buffer的相应附属信息
	void* pDeviceID;
	void* pContext;

	//外部管理内存模式下的参数
	//
	//对应SetExternalOutputBufferCallbacks()设置的指针
	void *pOpaque;
	//对应VXCutlistBufferLockCB()的返回值, 为了通知应用层可以解锁Buffer
	void *pLockUserData;

	int nReserved[23];

	stVXCutlistDecodeOut()
	{
		memset(this, 0, sizeof(stVXCutlistDecodeOut));
	}
};


//回调函数锁定Buffer
//
//参数说明：
//pOpaque      对应SetExternalOutputBufferCallbacks()设置的指针
//ppBuffer     对应分配的内存地址
//nBufferSize  分配的内存大小
//nBufferType  分配的Buffer类型,正常情况下为调用SetOutputFormat()时传入的值
//pDeviceID    分配Buffer时所需要的额外参数,正常情况下为调用SetOutputFormat()时传入的值
//pContext     分配Buffer时所需要的额外参数,正常情况下为调用SetOutputFormat()时传入的值
//返回值       指针地址，对应stVXCutlistDecodeOut或VXCutlistBufferUnLockCB中的pLockUserData
//
//备注:
//如果分配对应的是CPUBuffer 地址需按64字节对齐
typedef void *(*VXCutlistBufferLockCB)(void *pOpaque, void **ppBuffer, int nBufferSize, int nBufferType, void *pDeviceID, void *pContext);


//回调函数解除锁定Buffer
//
//参数说明：
//pOpaque       对应SetExternalOutputBufferCallbacks()设置的指针
//pLockUserData 对应VXCutlistBufferLockCB()的返回值
//
//备注：
//正常逻辑下GetOutputBuffer()并不会触发回调
typedef void (*VXCutlistBufferUnLockCB)(void *pOpaque, void *pLockUserData);



//ConfigureObj扩展功能参数定义
//
enum eVXCutlistV2PlusConfig
{
    //获取CutlistV2Plus内部准备好的基带缓冲个数
    //
    //参数说明：
    // pParam       应int *指针地址, 填入获取到的数据
    // nParamLen    等于sizeof(int)
    //
    eVXConfigGetDecodedCacheSize = 0x01,

	//获取CutlistV2Plus内部准备好的文件缓冲个数
	//
    //参数说明：
    // pParam       对应int *指针地址, 填入获取到的数据
    // nParamLen    等于sizeof(int)
    //
    eVXConfigGetFileCacheSize = 0x02,
};


class VXCutlistV2PlusImpl;
class VX_SDK_API VXSDKCutlistV2Plus
{
public:
	VXSDKCutlistV2Plus();
	virtual ~VXSDKCutlistV2Plus();

/***初始化***/

	//初始化Cutlsit
	//参数为类型   VX_CUTLIST_ITEM_VIDEO    VX_CUTLIST_ITEM_AUDIO
	int Initialize(int nItemType);

/***缓冲设置***/

	//设置缓冲大小 
	//参数1为基带数据缓冲池大小 参数2为文件级缓冲池大小
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetBufferPoolSize(int nDecodedBufferPoolSize, int nFileFrameBufferPoolSize);
	
	//设置开始时缓冲的准备大小 
	//参数1为基带数据缓冲 参数2为文件级缓冲 
	//若不进行设置，默认为缓冲池大小的二分之一
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetPrepareNum(int nDecodedPrepareBufferNum, int nFileFramePrepareBufferNum);

/***外部内存管理模式***/

	//设置输出Buffer的回调接口，支持由外面分配管理内存，目前只针对视频解码有效
	int SetExternalOutputBufferCallbacks(VXCutlistBufferLockCB pLockCB, VXCutlistBufferUnLockCB pUnLockCB, void *pOpaque);

/***时间线设置***/

	//设置输出格式
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetOutputFormat(stVXCutlistOutputFormat *pOutputFormat);
	
	//设置时间线上的素材
	//参数1为ITEM数组 参数2为数组长度
	int SetItemList(stVXCutlistSDKItem *pItemList, int nItemListLen);

	//设置状态
	int SetStatus(int nStatus, int64_t llTimelinePos VX_SDK_DEFAULT(-1));

/***取帧***/

	//取帧数据
	//按照设置的格式输出基带数据
	int GetOutputBuffer(stVXCutlistDecodeIn *pDecCtrl, stVXCutlistDecodeOut &stDecResult);


/***配置参数***/

	//配置可变参数和函数
	int ConfigureObj(int nFuncType,void* pParam,int nParamLen);

private:

	VXCutlistV2PlusImpl* m_pImpObj;
};

#endif
