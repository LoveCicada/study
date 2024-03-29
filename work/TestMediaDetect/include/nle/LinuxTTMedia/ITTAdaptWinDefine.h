
#pragma once

#include <iostream>

/**
 * @brief adapt Windows to Linux
 * 
 */

#define TRUE 1
#define FALSE 0

#define MAX_PATH 260

typedef unsigned long DWORD;
typedef DWORD FOURCC;   /* a four character code */
typedef long LONG;
typedef unsigned short WORD;
typedef wchar_t WCHAR;
typedef WCHAR TCHAR, *PTCHAR;
typedef int64_t __int64;
typedef __int64 LONGLONG;
typedef uint64_t ULONGLONG;

typedef uint64_t ULONG_PTR, *PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
typedef bool BOOL;
typedef unsigned int UINT;
typedef int INT;

typedef struct _GUID{
    unsigned long   Data1;
    unsigned short  Data2;
    unsigned short  Data3;
    unsigned char   Data4[8];
}GUID;

//maybe need new define
#define GUID_NULL GUID()

#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
        const GUID  name \
                = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }


#if 0 // microcsoft windows define
/* FOURCC */
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))


/* MMIO macros */
#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)

#endif

typedef unsigned char BYTE;


#if 1   // ## look at follow comment ##

/**
 * @brief adapt windows BITMAPINFOHEADER
 * this struct define at VX_CutList2DataStruct.h,
 * so we we could not define at here,
 * but direct to use VX_CutList2DataStruct.h
 */

typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;


/*
 *  extended waveform format structure used for all non-PCM formats. this
 *  structure is common to all non-PCM formats.
 */
typedef struct tWAVEFORMATEX
{
    WORD        wFormatTag;         /* format type */
    WORD        nChannels;          /* number of channels (i.e. mono, stereo...) */
    DWORD       nSamplesPerSec;     /* sample rate */
    DWORD       nAvgBytesPerSec;    /* for buffer estimation */
    WORD        nBlockAlign;        /* block size of data */
    WORD        wBitsPerSample;     /* number of bits per sample of mono data */
    WORD        cbSize;             /* the count in bytes of the size of */
                                    /* extra information (after cbSize) */
} WAVEFORMATEX, *PWAVEFORMATEX, *NPWAVEFORMATEX, *LPWAVEFORMATEX;

#if 0

//we need modify
int _tcscpy_s(TCHAR* src, TCHAR* dst)
{

    return 0;
}

//we need modify
int lstrcmp(TCHAR* src, TCHAR* dst)
{

    return 0;
}
#endif

#endif

#define AFX_EXT_API