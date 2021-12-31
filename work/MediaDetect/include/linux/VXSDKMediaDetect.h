/*********************************************************
* 文件名　：VXMediaDetect.h
* 功能  　：VXSDK媒体检测模块定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_MEDIA_DETECT_INCLUDE_
#define _VX_SDK_MEDIA_DETECT_INCLUDE_

#ifdef _MSC_VER
#pragma once
#endif

#include <string.h>
#include <stdint.h>
#include "VXSDKPlatform.h"
#include "VXSDKBaseDefine.h"


class VXMediaInfoImpl;
class VX_SDK_API VXSDKMediaInfo
{
public:
	VXSDKMediaInfo();

	virtual ~VXSDKMediaInfo();

public:

	stVXSDKFileMediaInfo FileMediaInfo();

	int VideoStreamNum();

	int AudioStreamNum();

	int SystemStreamNum();

	int DataStreamNum();

	stVXSDKVideoStreamInfo VideoMediaInfo(int nVideoStreamIndex);

	stVXSDKAudioStreamInfo AudioMediaInfo(int nAudioStreamIndex);

	stVXSDKSystemStreamInfo SystemMediaInfo(int nSystemStreamIndex);

	stVXSDKDataStreamInfo DataMediaInfo(int nDataStreamIndex);

public:

	//不能直接拷贝，需要用Clone函数
	void Clone(VXSDKMediaInfo* pMediaInfo);

	//获取视音频流的额外扩展数据
	int GetExtraDataInfo(int nDataStreamType, int nStreamIndex, uint8_t **ppExtraData, int& nExtraDataSize);

protected:

	VXMediaInfoImpl* m_pImpObj;
};

//////////////////////////////////////////////////////////////////////////

class VXMediaDetectImpl;
class VX_SDK_API VXSDKMediaDetect
{
public:
	VXSDKMediaDetect();
	virtual ~VXSDKMediaDetect();

	//nDetectMode = 0:普通模式
	//nDetectMode = 1:快速模式，用于边采边编，返回3表示文件已封口，此次快速检测无效。
	int SetInputFile(const char *cFileName, int nDetectMode = 0);

	int GetMediaInfo(VXSDKMediaInfo* pMediaInfo);
	
private:

	VXMediaDetectImpl *m_pImpObj;
};

#endif
