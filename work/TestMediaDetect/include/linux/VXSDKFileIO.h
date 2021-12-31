/*********************************************************
* 文件名　：VXSDKFileIO.h
* 功能  　：VXSDK文件读取类定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_FILE_IO_INCLUDE_
#define _VX_SDK_FILE_IO_INCLUDE_

#ifdef _MSC_VER
#pragma once
#endif

#include <string.h>
#include <stdint.h>
#include "VXSDKPlatform.h"

typedef void*  VXFILEHANDLE;

enum
{
	eVXMoveMethodFileBegin   = 0,
	eVXMoveMethodFileCurrent = 1,
	eVXMoveMethodFileEnd     = 2,
};

enum
{
	eVXDesiredAccessRead = 1,
	eVXDesiredAccessWrite = 2,
	eVXDesiredAccessReadWrite = eVXDesiredAccessRead | eVXDesiredAccessWrite,
};

enum
{
	eVXShareModeNone = 0,
	eVXShareModeRead = 1,
	eVXShareModeWrite = 2,
	eVXShareModeDelete = 4,
};

enum
{
	eVXCreationDispositionCreateNew = 1,
	eVXCreationDispositionCreateAlways = 2,
	eVXCreationDispositionOpenExisting = 3,
	eVXCreationDispositionCheckFileExist = 10,
};

enum
{
	eVXFileACLNotSet = 0,
	eVXFileACLPublicRead = 2,
};

struct stVXCreateFileParam
{
	int nDesiredAccess;
	int nShareMode;
	int nCreationDisposition;
	int nAttributes;
	//读取或写入块大小
	int nFileBlockSize;

	//S3相关
	//
	//唯一ID
	const char *cFileID;
	//文件权限
	int nFileACL;

	stVXCreateFileParam()
	{
		nDesiredAccess = eVXDesiredAccessRead;
		nShareMode = 0;
		nCreationDisposition = eVXCreationDispositionOpenExisting;
		nAttributes = 0;
		nFileBlockSize = 0;
		cFileID = nullptr;
		nFileACL = eVXFileACLNotSet;
	}
};

struct stVXReadWriteExtParam
{
	int nPartNum;

	int64_t llOffset;

	int nReserved[9];

	stVXReadWriteExtParam()
	{
		memset(this, 0, sizeof(stVXReadWriteExtParam));
	}
};


VX_SDK_BEGIN_C_DECL

//文件操作IO
VX_SDK_API VXFILEHANDLE VXCreateFile(const char *lpFileName, stVXCreateFileParam *pParam);

VX_SDK_API int64_t VXGetFileSize(VXFILEHANDLE hFile, int nRefresh VX_SDK_DEFAULT(0));

VX_SDK_API int VXGetFileProperty(VXFILEHANDLE hFile, void *pProperty);

VX_SDK_API int VXSetFileControl(VXFILEHANDLE hFile, void *pControl);

VX_SDK_API int64_t VXSetFilePointer(VXFILEHANDLE hFile, int64_t llDistanceToMove, int nMoveMethod);

VX_SDK_API int VXReadFile(VXFILEHANDLE hFile, unsigned char *lpBuffer, int nNumberOfBytesToRead, void *pExtParam);

VX_SDK_API int VXWriteFile(VXFILEHANDLE hFile, unsigned char *lpBuffer, int nNumberOfBytesToWrite, void *pExtParam);

VX_SDK_API int VXFlushFile(VXFILEHANDLE hFile);

VX_SDK_API int VXCloseFile(VXFILEHANDLE hFile);


//文件是否存在
VX_SDK_API int VXFileIsExist(const char *lpFileName);

//删除文件
VX_SDK_API int VXDeleteFile(const char *lpFileName);


VX_SDK_END_C_DECL

#endif
