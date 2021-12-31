#pragma once

#include "TTMediaPlayerExport.h"

typedef struct stu_TTMediaPlayerAudioOutputVTR
{
	WORD	iChannels;				//通道数
	DWORD	iSamplesRate;			//采样率
	WORD	iBitsPerSample;			//量化位数
	DWORD	iSampleCount;			//这一个帧Sample数目
	BYTE*	iAudioData[8];

	void Reset()
	{
		iChannels		= 0;
		iSamplesRate	= 48000;
		iBitsPerSample	= 16;
		iSampleCount	= 0;
		for(int i = 0; i < 8;i ++)
		{
			iAudioData[i] = NULL;
		}
	}
	stu_TTMediaPlayerAudioOutputVTR()
	{
		Reset();
	}
}TTMediaPlayerAudioOutputVTR,*lpTTMediaPlayerAudioOutputVTR;

typedef struct stu_TTMediaPlayerOutputCallbackVTR
{
	//!iFieldType == 0 ODD,==1 EVEN
	int	(* TT_Output_GetVideoBuffer)(void * hEngineData,LONG eIOType,__int64 lPos, int iFieldType, void **ppBufID, BYTE **ppData, int *piPitch, int *piWidth, int *piHeight, TTPixelFormat *piPixelFormat);
	int	(* TT_Output_FreeVideoBuffer)(void * hEngineData,LONG eIOType, void *pBufID);
	int (* TT_Output_GetAudioBuffer)(void * hEngineData, LONG eIOType,__int64 iStartSamplePos, long lSampleNum, TTMediaPlayerAudioOutputVTR & stuAudioData);

	// !被输出引擎，或者音频预监调用，用来同步显示视频帧，
	int	(* TT_Output_CurPos)(HTTMPHANDLE hData,__int64 lPos);

	stu_TTMediaPlayerOutputCallbackVTR()
	{
		memset(this,0,sizeof(stu_TTMediaPlayerOutputCallbackVTR));
	}
}TTMediaPlayerOutputCallbackVTR,*lpTTMediaPlayerOutputCallbackVTR;


#define TTVtrState DWORD

#define	TTVtrState_CTRLON_LOCAL		0x0000		// VTR 处于 LOCAL 控制状态
#define	TTVtrState_HARO_ERROR		0x0002		// VTR 故障
#define	TTVtrState_TAPE_TROUBLE		0x0003		// VTR 磁带故障
#define	TTVtrState_REF_MIS			0x0004		// VTR 锁相失败
#define	TTVtrState_TAPE_OUT			0x0005		// VTR 无磁带

#define	TTVtrState_ON_PLAY			0x0100		// VTR ON PLAY
#define	TTVtrState_ON_REC			0x0101		// VTR ON REC
#define	TTVtrState_ON_FF			0x0102		// VTR ON FF
#define	TTVtrState_ON_REW			0x0103		// VTR ON REW
#define	TTVtrState_ON_EJECT			0x0104		// VTR ON EJECT
#define	TTVtrState_ON_STOP			0x0105		// VTR ON STOP
#define	TTVtrState_TENSION_RELRASE	0x0106		// VTR TENSION RELRASE
#define	TTVtrState_ON_STANDBY		0x0107		// VTR ON STANDBY

#define	TTVtrState_ON_CUEUP			0x0200		// VTR ON CUEUP
#define	TTVtrState_ON_STILL			0x0201		// VTR ON STILL
#define	TTVtrState_TAPEDIRCTION		0x0202		// VTR TAPE DIRECTION 0=FWD
#define	TTVtrState_ON_VAR			0x0203		// VTR ON VAR
#define	TTVtrState_ON_JOG			0x0204		// VTR ON JOG
#define	TTVtrState_ON_SHTL			0x0205		// VTR ON SHTL
#define	TTVtrState_TSO_HOLD			0x0206		// VTR TSO HOLD
#define	TTVtrState_SERYO_LOCK		0x0207		// VTR SERYO LOCK

#define	TTVtrState_LAMP_IN			0x0300		// VTR LAMP IN
#define	TTVtrState_LAMP_OUT			0x0301		// VTR LAMP	OUT
#define	TTVtrState_LAMP_AUDIO_IN	0x0302		// VTR LAMP	AUDIO IN
#define	TTVtrState_LAMP_AUDIO_OUT	0x0303		// VTR LAMP AUDIO OUT
#define	TTVtrState_LAMP_AUTOMODE	0x0307		// VTR LAMP AUTO MODE

#define	TTVtrState_ON_PREROLL		0x0400		// VTR ON PREROLL
#define	TTVtrState_ON_PREVIEW		0x0401		// VTR ON PREVIEW
#define	TTVtrState_ON_AUTOEDIT		0x0402		// VTR ON AUTOEDIT
#define	TTVtrState_ON_REVIEW		0x0403		// VTR ON REVIEW
#define	TTVtrState_ON_EDIT			0x0404		// VTR ON EDIT
#define	TTVtrState_FULL_EE_ON		0x0406		// VTR FULL EE ON
#define	TTVtrState_SELECT_EE_ON		0x0407		// VTR SELECT EE ON

#define	TTVtrState_LAMP_AUDIO_1		0x0500		// VTR LAMP AUDIO 1
#define	TTVtrState_LAMP_AUDIO_2		0x0501		// VTR LAMP AUDIO 2
#define	TTVtrState_LAMP_TC			0x0502		// VTR LAMP TC
#define	TTVtrState_LAMP_SYNC		0x0503		// VTR LAMP SYNC
#define	TTVtrState_LAMP_VIDEO		0x0504		// VTR LAMP VIDEO
#define	TTVtrState_LAMP_ASMBL		0x0505		// VTR LAMP ASSEMBLE
#define	TTVtrState_LAMP_INS			0x0506		// VTR LAMP	INS

#define	TTVtrState_1				0x0600		// VTR TTVtrState 1
#define	TTVtrState_2				0x0601		// VTR TTVtrState 2
#define	TTVtrState_SEARCH_LED		0x0602		// VTR SEARCH LED
#define	TTVtrState_8				0x0603		// VTR TTVtrState 8
#define	TTVtrState_LAMP_REW			0x0604		// VTR LAMP REW
#define	TTVtrState_LAMP_FWD			0x0605		// VTR LAMP FWD
#define	TTVtrState_LAMP_STILL		0x0606		// VTR LAMP STILL

#define	TTVtrState_IN_OUT			0x0700		// VTR IN/OUT TTVtrState
#define	TTVtrState_SPOT_ERASE		0x0702		// VTR SPOT ERASE
#define	TTVtrState_DISP_HOLD		0x0703		// VTR DISP HOLD
#define	TTVtrState_AUDIO_SPLIT		0x0705		// VTR AUDIO SPLIT
#define	TTVtrState_VARMEM_ACTIVE	0x0706		// VTR VAR MEM ACTIVE
#define	TTVtrState_VARMEM_MODE		0x0707		// VTR VAR MEM MODE

#define	TTVtrState_REC_INHIBT		0x0800		// VTR REC INHIBT
#define	TTVtrState_SYSTEM_ALARM		0x0801		// VTR SYSTEM ALARM
#define	TTVtrState_SERVO_ALARM		0x0802		// VTR SERVO ALARM
#define	TTVtrState_COLOR_FRANE_LOCK	0x0803		// VTR COLOR FRANE LOCK
#define	TTVtrState_ROT				0x0804		// VTR ROT
#define	TTVtrState_NEAR_ROT			0x0805		// VTR NEAR ROT
#define	TTVtrState_LOST_LOCK		0x0806		// VTR LOST LOCK
#define	TTVtrState_BVZZER_ALARM		0x0807		// VTR BVZZER ALARM

#define	TTVtrState_LOW_RF			0x0900		// VTR LOW RF
#define	TTVtrState_FUNCTION_ABOUT	0x0907		// VTR FUNCTION ABOUT

#define	TTVtrState_NOREADY			0x1000		// VTR Is not ready

#define	TTVtrState_Download			0x2000		// VTR Is downloading


#define TTVtrDownload_ED_AUDIO_ALL              0x10000000L //  or any of the following OR'd together
#define TTVtrDownload_ED_AUDIO_1                0x00000001L
#define TTVtrDownload_ED_AUDIO_2                0x00000002L
#define TTVtrDownload_ED_AUDIO_3                0x00000004L
#define TTVtrDownload_ED_AUDIO_4                0x00000008L
#define TTVtrDownload_ED_AUDIO_5                0x00000010L
#define TTVtrDownload_ED_AUDIO_6                0x00000020L
#define TTVtrDownload_ED_AUDIO_7                0x00000040L
#define TTVtrDownload_ED_AUDIO_8                0x00000080L
#define TTVtrDownload_ED_VIDEO                  0x02000000L  // for Edit props below
#define TTVtrDownload_INSERT					0x00000000L
#define TTVtrDownload_ASSEMBLE					0x10000000L


#define TTVtrDownload_End						0x00000000
#define TTVtrDownload_DropFrame					0x00000001
#define TTVtrDownload_Cancle					0x00000002
#define TTVtrDownload_LostVtr					0x00000004
#define TTVtrDownload_VtrStop					0x00000008
#define TTVtrDownload_VtrError					0x00000010



#define TTVTRUpload_END							0x00000001
#define TTVTRUpload_LOSTVIDEO					0x00000002
#define TTVTRUpload_DROPFRAM					0x00000004
#define TTVTRUpload_VTRLOST						0x00000008
#define TTVTRUpload_VTRSTOP						0x00000010
#define TTVTRUpload_NOROOM						0x00000020
#define	TTVTRUpload_CARDERROR					0x00000040
#define TTVTRUpload_VTRERROR					0x00000080
#define TTVTRUpload_VTRPOINT					0x00000100 // 找点
#define TTVTRUpload_VTRSTART					0x00000200
#define TTVTRUpload_FAILPREROLL					0x00000400 // 回滚失败
#define	TTVTRUpload_PLUGIN						0x10000001
#define	TTVTRUpload_PLUGOUT						0x10000002
#define TTVTRUpload_DBECHANGE					0x10000008

typedef struct tag_TTVTRUploadFeature
{
	GUID	devGuid;
	WCHAR	strName[128];
	BOOL	bCanBasic;			//basic function(play,stop,pause, etc)
	BOOL	bExportDialog;		//有自己的调整对话框
	BOOL	bCanInsertEdit;		//是否可插入编辑
	BOOL	bHasJogMode;		//是否有Jog模式
	BOOL	bHasVarMode;		//是否有Jog模式
	BOOL	bCanEject;			//能否can Eject media
	BOOL	bCanEdit;			//能否可以编辑
	BOOL	bCanPosInfo;		//能否可以获取位置信息
	BOOL	bCanRecord;			//能否可以录制
	BOOL	bCanSeek;			//能否Seek
	BOOL	bCan1_5;			//能否播放 at 1/5 speed
	BOOL	bCan1_10;			//能否播放 at 1/10 speed
	BOOL	bCanHasOptions;		//能否plug-in puts up an options dialog
	BOOL	bCanHasReversePlay;	//能否可以倒放
	BOOL	bCanEditInOut;		//能否输入入出点
	BOOL	bCanRew;			//能否快退	
	BOOL	bCanFF;				//能否快进
	BOOL	bCanStep;			//能否步进
	BOOL	bMarkInPlaying;		//能否播放在Mark点

}TTVTRUploadFeature, *lpTTVTRUploadFeature;

typedef struct stu_TTVTRUploadData
{
	void * hEngineData;
	int iCaptureType;
	int iCaptureDeviceInOutRange;
	int iDeviceIn;
	int iDeviceOut;
}TTVTRUploadData, *lpTTVTRUploadData;

typedef struct tag_TTVTRUploadInfo
{
	GUID					devGuid;
	WCHAR					strName[128];

	BOOL					bCanCapVideo;		//if can record video
	BOOL					bCanCapAudio;		//if can record audio
	BOOL					bCanCapStill;		//if can record still frame file
	BOOL					bCanCapMultiQuality;//if can record multiply quality file
	BOOL					bCanSperateVA;      //if can record sperate video and audio file    
	BOOL					bCanPreview;		//if can preview when recording
	BOOL					bCanCountCapFrames; //if can calculate how many frames have been recorded
	BOOL					bCanAbortDropped;	//if abort by itself when frame dropped
	BOOL					bCanGetTimecode;	//if can get time code(pos)
	BOOL					bCanSetAudioPara;	//if can set audio para
	BOOL					bCanSetVideoPara;	//if can set video para
	BOOL					bCanSetTimeBase;	//if can set timebase
	BOOL					bCanEject;			//if can eject by zhh
	BOOL					bCanCoverLable;     //能否帖台标
	BOOL					bCanPause;			//能否暂停
	BOOL					bCanSceneTest;		//能否场景切换

	int 					iMinImageWidth;		//Minimum width (set min = max to allow only one size)
	int 					iMinImageHeight;	//Mininum height
	int 					iMaxImageWidth;		//Maximum width
	int 					iMaxImageHeight;	//Maximum height
	int    					iMaxVideoChannel;	//how many video can recorded at the same time
	int    					iMaxAudioChannel;	//how manu audio can recorded at the same time
	long					lPrefTimescale;		//preferred timebase to capture to (if acceptsTimebase was true)
	long					lPrefSamplesize;	//preferred dividend of timebase (if acceptsTimebase was true)
	long    				lAudioLiveIn;       //AudioTrackNumber;
	BOOL    				bCloseOutput;
	BOOL					bCanPrerollEdit;	//if can preroll edit

	DWORD   				eVideoStandard;	
	int						iCurVideoWidth;
	int						iCurVideoHeight;
	int						iCurAudioChannel;
	int						iCurAudioBitCount;
	int						iCurAudioSampleRate;

}TTVTRUploadInfo, *lpTTVTRUploadInfo;

typedef struct tag_TTVtrDownloadInfo
{
	GUID					devGuid;
	WCHAR					strName[128];
}TTVtrDownloadInfo, *lpTTVtrDownloadInfo;

typedef struct tag_TTVtrDownload
{
	int						iDeviceInPos;		//录机入点
	int						iDeviceOutPos;		//录机出点
	int						iSrcInPos;			//时间线或素材入点
	int						iSrcOutPos;			//时间线或素材出点
	DWORD					nDataType;			//TTVtrDownload_...

//	int						iDeviceLength;		//录机入出点间长度
//	int						iSrcLength;			//时间线或素材入出点之间长度
//	DWORD					dwDeviceInATNPos;   //录机入点
//	DWORD					dwDeviceOutATNPos;  //录机出点
//	DWORD					dwDeviceATNLength;  //录机入出点间长度
//	BOOL					bUserVtr;
//	DWORD					tpPrintVAType;		//时间线或素材的播放方式
//	int						iFrstEditTcLen;		//预先铺时码的长度
}TTVtrDownload, *lpTTVtrDownload;

typedef struct stu_TTVTRUploadCallback
{
	int	(* TT_Output_VideoBuffer)(void * hEngineData, BYTE *pData, int *piPitch, int *piWidth, int *piHeight, DWORD *piPixelFormat);
	int (* TT_Output_AudioBuffer)(void * hEngineData, BYTE *pData, int iSampleNum, int iChannelNum, int iBitCount);

}TTVTRUploadCallback,*lpTTVTRUploadCallback;

typedef struct tag_TTVTRUploadInterface
{
	int  (*TT_VTR_Init)(DWORD dwVideoStandard);											//初始化
	int  (*TT_VTR_Release)();															//释放
	int  (*TT_VTR_SetRecordDisplayWnd)(HWND hWnd);										//设置回放窗口和位置
	int  (*TT_VTR_GetDeviceInfo)(TTVTRUploadInfo * pRecDeciceInfo);						                    //获得采集设备信息
	int  (*TT_VTR_StartRecord)(void * hEngineData, TTVTRUploadData* pData, TTVTRUploadCallback* pRec);		//开始录制
	int  (*TT_VTR_StopRecord)();														//停止
	int  (*TT_VTR_GetAudioVU)(TTMediaPlayerVUData* pPara);								//获取音频
	int  (*TT_VTR_AdjAudioVU)(TTMediaPlayerVUData* pPara);								//调节音频
	int  (*TT_VTR_GetCaptureFrameNumber)();												//获取采集帧数
	int  (*TT_VTR_GetState)(DWORD* pState);												//获取状态
	int  (*TT_VTR_GetDropFrame)(int *iBegin,int *iCount);								//获取丢帧数目
	int  (*TT_VTR_CustomSetup)();														//自定义设置
	int  (*TT_VTR_Pause)(BOOL bPause);													//暂停
	int  (*TT_VTR_PauseRecord)();														//暂停录制
	int  (*TT_VTR_ContinueRecord)();													//继续录制

}TTVTRUploadInterface, *lpTTVTRUploadInterface;

typedef struct stu_TTVtrDownloadCallback
{
	int	 (*TT_VTR_GetVideoBuffer )(void * hEngineData, __int64 lPos, int iFieldType, void **ppBufID, BYTE **ppData, int *piPitch, int *piWidth, int *piHeight, DWORD *piPixelFormat);
	int	 (*TT_VTR_FreeVideoBuffer)(void * hEngineData,  void *pBufID);
	int  (*TT_VTR_GetAudioBuffer )(void * hEngineData, __int64 iStartSamplePos, long lSampleNum, TTMediaPlayerAudioOutputVTR & stuAudioData);

}TTVtrDownloadCallback,*lpTTVtrDownloadCallback;

typedef struct tag_TTVtrDownloadInterface
{
	int  (*TT_VTR_Init)(stuTTVideoStandard tpVideoStandard);											//初始化
	int  (*TT_VTR_Open)(TTMediaPlayerOutputCallbackVTR * pCreatePara, void * hEngineData);	    //打开，切换至输出状态
	int  (*TT_VTR_StartPrint)(TTVtrDownload * param);									//开始
	int  (*TT_VTR_StopPrint )();														//停止
	int  (*TT_VTR_GetCurPlayPos)(int& iCurPos);											//获得当前播放位置
	int  (*TT_VTR_GetCurDevicePos)(int& iCurPos);										//获得当前设备位置
	int  (*TT_VTR_GetAudioVU)(TTMediaPlayerVUData* pPara);								//获得AUDIO VU表
	int  (*TT_VTR_GetCurState)(DWORD& iState);	       					                //获得下载状态
	int  (*TT_VTR_GetLastError)(LPTSTR &sError);										//返回错误
	int  (*TT_VTR_ExecCommand)(UINT uCmd,LPARAM lParam);								//执行扩展命令
	int  (*TT_VTR_Release)();															//释放

}TTVtrDownloadInterface, *lpTTVtrDownloadInterface;

typedef struct tag_TTVtrCtrlInterface
{
	int  (*TT_VTR_Init)(stuTTVideoStandard tpVideoStandard);						//初始化
	int  (*TT_VTR_Release)();										//释放
	int  (*TT_VTR_Open)();											//设备打开，进入设备控制状态
	int  (*TT_VTR_Close)();											//设备关闭，离开设备控制状态
	int  (*TT_VTR_GetCurState)(TTVtrState& iState);					//获得设备当前状态  
	int  (*TT_VTR_Seek)(int iPos);									//SEEK
	int  (*TT_VTR_GetCurPos)(long& lPos);							//获取当前帧
	int  (*TT_VTR_GetCurPosEx)(long& lPos, BOOL& bDropFrame);		//获取当前帧 + 是否是丢帧时码
	int  (*TT_VTR_Play)();											//播放
	int  (*TT_VTR_Record)();     									//录制
	int  (*TT_VTR_Pause)();      									//暂停
	int  (*TT_VTR_Stop)();       									//停止
	int  (*TT_VTR_FastForward)();       							//快进
	int  (*TT_VTR_Rewind)();										//快退
	int  (*TT_VTR_StepForward)();									//单步前进	
	int  (*TT_VTR_StepBackward)();									//单步后退
	int  (*TT_VTR_GetJogRange)(long& iMin, long& iMax);				//获得Jog范围 
	int  (*TT_VTR_GetShuttleRange)(long& iMin, long& iMax);			//获得Shuttle范围
	int  (*TT_VTR_ShuttleTo)(long iPos);							//执行Shuttle命令
	int  (*TT_VTR_JogTo)(long iPos);								//Jog到某一位置
	int  (*TT_VTR_Var)(long iPos);									//Jog到某一位置
	int  (*TT_VTR_Eject)();											//介质弹出
	int  (*TT_VTR_AskIsRemoteContrl)(BOOL& bRemoteContrl);			//是否遥控
//	BOOL (*TT_VTR_CanRecord)();										//能够录制
//	int  (*TT_VTR_GetEngineInfo)(void*& pEngineInfo);				//设备信息	
//	BOOL (*TT_VTR_CheckDevice)();									//

}TTVtrCtrlInterface, *lpTTVtrCtrlInterface;



typedef struct stu_TTVtrCard
{
    GUID							guidEngine;
    TCHAR							szEngineName[64];
    stuTTVideoStandard				tpVideoStandard;
    void *                          pInterface;
    stu_TTVtrCard()
    {
        guidEngine      = GUID_NULL;
		tpVideoStandard.Reset();
        pInterface      = NULL;
    }
    stu_TTVtrCard & operator= (const stu_TTVtrCard & stuDst)
    {
        guidEngine      = stuDst.guidEngine;
        pInterface      = stuDst.pInterface;
        memset(szEngineName,0,sizeof(TCHAR)*64);	
        memcpy(szEngineName,stuDst.szEngineName,sizeof(TCHAR)*64);
		tpVideoStandard.Copy(stuDst.tpVideoStandard);
        return * this;
    }
}TTVtrCard,*lpTTVtrCard;



typedef int                         (*pTTVtr_Initialize)();
typedef int                         (*pTTVtr_GetCtrlDevice)(TTVtrCard * pDeviceList);
typedef int                         (*pTTVtr_GetUploadDevice)(TTVtrCard * pDeviceList);
typedef int                         (*pTTVtr_GetDownloadDevice)(TTVtrCard * pDeviceList);

typedef lpTTVtrCtrlInterface        (*pTTVtr_GetCtrlDeviceInterface)(const GUID & guid);
typedef lpTTVTRUploadInterface      (*pTTVtr_GetUploadDeviceInterface)(const GUID & guid);
typedef lpTTVtrDownloadInterface    (*pTTVtr_GetDownloadDeviceInterface)(const GUID & guid);
typedef int                         (*pTTVtr_UnInitialize)();


/*

#ifdef _DEBUG
    #ifdef _UNICODE
        #pragma comment(lib, "TTVtrManagerUD.lib")
    #else
        #pragma comment(lib, "TTVtrManagerD.lib")
    #endif
#else
    #ifdef _UNICODE
        #pragma comment(lib, "TTVtrManagerU.lib")
    #else
        #pragma comment(lib, "TTVtrManager.lib")
    #endif
#endif

*/