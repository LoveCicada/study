#pragma once

#include "TTMediaPlayerExport.h"

typedef LPVOID HCGRENDERHANDLE;
typedef DWORD  TTRESULT;

typedef struct stu_TTMediaPlayerCGRenderInterface
{
	TTRESULT			(*TT_MPI_GetFileInfo)(LPCTSTR lpStrFile,TTMediaPlayerFileFormat &FileFormat);
	HCGRENDERHANDLE		(*TT_MPI_CreateCGRender)();
	TTRESULT			(*TT_MPI_SetOutPutFormat)(HCGRENDERHANDLE hCGRender, stuTTVideoStandard tpVideoStandard,DWORD eBufferType,TTPixelFormat ePixelFormat);
	TTRESULT			(*TT_MPI_AddFile)(HCGRENDERHANDLE hCGRender,const TTMediaPlayerFileItemArray& arrItemList);
	TTRESULT			(*TT_MPI_ClearFile)(HCGRENDERHANDLE hCGRender);
	TTRESULT			(*TT_MPI_Start)(HCGRENDERHANDLE hCGRender,TT_MEDIAPLAYER_STATUS ePlayerStatus,lpTTMediaPlayerPlayPara pPlayPara);
	TTRESULT			(*TT_MPI_Stop)(HCGRENDERHANDLE hCGRender);
	TTRESULT			(*TT_MPI_CloseCGRender)(HCGRENDERHANDLE hCGRender);
	TTRESULT			(*TT_MPI_GetBuffer)(HCGRENDERHANDLE hCGRender,__int64 nPos,BOOL bodd,BYTE** pY,int *nYpith,BYTE** pU,int *nUpith,BYTE** pV,int *nVpith,BYTE** pA,int *nApith,int *nWdith,int *nHeight,TTPixelFormat *ePixelFormat);
}TTMediaPlayerCGRenderInterface,*LPTTMediaPlayerCGRenderInterface;

int AFX_EXT_API TT_GetCGRenderInterface( LPTTMediaPlayerCGRenderInterface lpCGRenderInfterface );

#define TT_INLCUDE