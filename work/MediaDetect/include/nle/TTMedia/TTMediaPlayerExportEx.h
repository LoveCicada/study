#pragma once

#include "TTMediaPlayerExport.h"
#include <vector>

typedef struct tag_ItemPosInfo
{
	bool bChange;
	__int64 lTrackIn;
	__int64 lTrackOut;
	int  iTrackIndex;
	tag_ItemPosInfo()
	{
		bChange = false;
		lTrackIn = -1;
		lTrackOut = -1;
		iTrackIndex = 0;
	}
}ItemPosInfo;
typedef std::vector<ItemPosInfo> ItemPosInfoArray;

typedef void (* TT_Callback_SetCurrentPosAndVU)(void * pUserData,__int64 iPos,TTMediaPlayerVUData * pVUData, TT_MEDIAPLAYER_STATUS eSysStatus, HANDLE hSyncAVSemaphore);

typedef struct stu_TTMediaPlayerSequenceEx
{
	TTMediaPlayerTrack			stuGraphicsTrack;   //!ͼ�ι��
	TTMediaPlayerTrackArray		arrVideoTrack;      //!��Ƶ���
	TTMediaPlayerTrackArray		arrAudioTrack;      //!��Ƶ���
	TTMediaPlayerMarkPointArray	arrMarkPoint;       //!��ǵ�
}TTMediaPlayerSequenceEx, * lpTTMediaPlayerSequenceEx;

struct TTMediaPlayerInterfaceEx : public stu_TTMediaPlayerInterface
{
	int (* TT_MPI_SetDataEx)(HTTMPHANDLE hSequence,lpTTMediaPlayerSequenceEx pData);
	int (* TT_MPI_UpdateTrack)(HTTMPHANDLE hSequence,TTMediaPlayerTrack * pTrack,int iTrackIndex);
	int (* TT_MPI_AddTrack)(HTTMPHANDLE hSequence,TTMediaPlayerTrack * pTrack,int iTrackIndex);
	int (* TT_MPI_DelTrack)(HTTMPHANDLE hSequence,int iTrackIndex);
	int (* TT_MPI_GetVideoTrackNum)(HTTMPHANDLE hSequence);
	int (* TT_MPI_GetAudioTrackNum)(HTTMPHANDLE hSequence);

	int (* TT_MPI_SetTotalWndNum)(HTTMPHANDLE hSequence, UINT nWndNum);
	int (* TT_MPI_SetTrackPosInfo)(HTTMPHANDLE hSequence, const int * pActiveID, ItemPosInfoArray * pTrackInfoVector, CRITICAL_SECTION * pLock);
	int (* TT_MPI_SetMulitWnds)(HTTMPHANDLE hSequence, HWND * pWndList,DWORD dwWndNum);
	int (* TT_MPI_SetActiveWnd)(HTTMPHANDLE hSequence, int nVideoTrackIndex);
	int (* TT_MPI_ShowID)(HTTMPHANDLE hSequence, int nVideoTrackIndex, int iTrackIndex, LPCWSTR pStrID);

	int (* TT_MPI_SetCurrentPosAndVU)(HTTMPHANDLE hSequence, TT_Callback_SetCurrentPosAndVU func, void * pUserData);
};

typedef TTMediaPlayerInterfaceEx* lpTTMediaPlayerInterfaceEx;

int AFX_EXT_API TT_GetInterfaceEx(TTMediaPlayerInterfaceEx lpInterface);


