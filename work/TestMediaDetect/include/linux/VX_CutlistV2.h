#if !defined(_VX_CUTLISTV2_H_INCLUDED_)
#define _VX_CUTLISTV2_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "VXSDKPlatform.h"
#include "VX_CutListV2DataStruct.h"

class VXCutlistV2Impl;
class VX_SDK_API VX_CutlistV2
{
public:
	VX_CutlistV2();
	virtual ~VX_CutlistV2();

/***初始化***/

	//初始化Cutlsit
	//参数为类型   SBT_CUTLIST_ITEM_VIDEO    SBT_CUTLIST_ITEM_AUDIO
	int Initialize(uint32_t dwItemType);


/***缓冲设置***/

	//设置缓冲方式 
	//1为自动缓冲 0为手动缓冲
	//自动缓冲：不需要调用PrepareBuffer函数，Cutlist根据设置自动进行缓冲
	//手动缓冲：如果需要进行后台缓冲，需要自己调用PrepareBuffer函数
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetBufferingMode(int bAutoBuffering);
	
	//设置缓冲大小 
	//参数1为基带数据缓冲池大小 参数2为文件级缓冲池大小
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetBufferPoolSize(int nDecodedBufferPoolSize, int nFileFrameBufferPoolSize);
	
	//设置开始时缓冲的准备大小 
	//参数1为基带数据缓冲 参数2为文件级缓冲 
	//若不进行设置，默认为缓冲池大小的二分之一
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetPrepareNum(int nDecodedBufferNum, int nFileFrameBufferNum);
	


/***时间线设置***/

	//设置帧率
	//0x00 ：FPS为25   
	//0x01 ：FPS为29.97
	//0x02 : FPS为30
	//0x03 : FPS为23.976
	//0x04 : FPS为24
	//0x05 : FPS为50
	//0x06 : FPS为60
	//0x07 : FPS为59.94
	int SetFPS(uint32_t dwFPS);

	//设置输出格式
	//参数1为类型   SBT_CUTLIST_ITEM_VIDEO    SBT_CUTLIST_ITEM_AUDIO
	//参数2为具体的格式
	//只有在NONE SEEK SCRUB模式下才会设置有效
	int SetOutputFormat(uint32_t dwItemType, VX_MEDIA_TYPE *pmt);
	
	//设置时间线上的素材
	//参数1为ITEM数组 参数2为数组长度
	int SetItemList(VX_CUTLIST_ITEM *pItema, int nListLen);

	//设置状态
	//SBT_CUTLIST_STATUS_NONE				0x00    //None
	//SBT_CUTLIST_STATUS_SEEK				0x01	//Seek
	//SBT_CUTLIST_STATUS_PLAY				0x02    //Play
	//SBT_CUTLIST_STATUS_REVERSEPLAY		0x03	//reverse play
	//SBT_CUTLIST_STATUS_SCRUB				0x04	//Scrub
	//注意：PLAY和REVERSEPLAY不能直接互换，需要用SEEK或SCRUB过渡
	int SetStatus(uint32_t dwStatus);



/***取帧***/
	
	//后台准备数据
	//用于手动缓冲下准备缓冲帧数据
	int PrepareBuffer(int64_t llPos, int bDecode);

	//取帧数据
	//按照设置的格式输出基带数据
	int GetOutputBuffer(VX_CUTLISTV2_DECODE_IN *pstDecCtrl, VX_CUTLISTV2_DECODE_OUT &stDecResult);

	

/***取信息***/

	//取CUTLIST在当前状态下的信息
	int GetCutlistProInfo(VX_CUTLIST_PROCESS_INFO& stCutlistInfo);
	
	//取上一次的错误信息
	int GerLastErrorCodeInfo(VX_CUTLIST_ERROR_INFO& stErrorInfo);
	
/***配置参数***/

	//配置可变参数和函数
	int ConfigureObj(int nFuncType,void* pParam, int32_t nParamLen);

public:

	VXCutlistV2Impl* m_pImpObj;
	
};

#endif // !defined(AFX_SBT_CUTLISTV2_H__8A2F21DC_A962_4A22_8CE1_5BD7C5AF2E35__INCLUDED_)
