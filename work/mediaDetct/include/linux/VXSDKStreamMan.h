/*********************************************************
* 文件名　：VXSDKStreamMan.h
* 功能  　：VXSDK流收录类定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_CROSS_SDK_StreamMan_INCLUDE_
#define _VX_CROSS_SDK_StreamMan_INCLUDE_

#ifdef _MSC_VER
#pragma once
#endif

#include <string>
#include "VXSDKPlatform.h"
#include "VXSDKBaseDefine.h"

#define VXFUNC_TYPE_GET_MEDIA_STATUS 0x100

class VXStreamManImpl;
class VX_SDK_API VXSDKStreamMan
{
public:
	enum VXStreamCallBackType
	{
		VXCallBackEvent,
		VXCallBackTimeGet,
		VXCallBackAudioFlush,
	};
	enum VXStreamEventType
	{
		VXEventEndReached,
		VXEventEncounteredError,
		VXEventMediaParsedChanged,
	};

	struct VXEvent
	{
		int type;
		void* pData;
		int nDataLen;
		int reversed[13];
	};

	struct VXMediaStats
	{
		/* Input */
		int         readBytes;
		float       inputBitrate;
		/* Demux */
		int         demuxReadBytes;
		float       demuxBitrate;
		int         demuxCorrupted;
		int         demuxDiscontinuity;
		/* Decoders */
		int         decodedVideo;
		int         decodedAudio;
		/* Video Output */
		int         displayedPictures;
		int         lostPictures;
		/* Audio output */
		int         playedAbuffers;
		int         lostAbuffers;
	};

	//音视频基带数据回调函数
	typedef int(*VXStreamFrameCallback)(stVXSDKFrame& frame, void* pUserData);
	//事件处理函数
	typedef int(*VXStreamEventCallBack)(VXEvent& event, void* pUserData);
	//音频同步回调函数
	typedef int(*VXStreamAudioTimeGetCallBack)(void *data, int64_t* pts);
	//音频flash回调函数
	typedef void(*VXStreamAudioFlushCallBack)(void *data, int64_t pts);
	
public:
	VXSDKStreamMan();
	virtual ~VXSDKStreamMan();

	//设置流地址
	int SetDataSource(std::string url);
	//设置音视频回调函数
	int SetAVDataCallBack(VXStreamFrameCallback audioCB, VXStreamFrameCallback videoCB, void* pUserData);
	//设置事件回调函数
	int SetEventCallBack(VXStreamCallBackType type, void* callback, void* pUserData);
	//添加流收录参数
	int AddOption(std::string& option);
	//开始收录
	int Start();
	//停止收录
	int Stop();
	//扩展函数
	int ConfigureObj(int nObjectType, void* pObj, int nFuncType, void* pParam, int nParamLen);

private:
	VXStreamManImpl *m_pImpObj;
};

#endif
