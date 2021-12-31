
#ifndef __define__media_sample_utility__header__
#define __define__media_sample_utility__header__

#include "../ITTMediaSampeAVS.hpp"

inline int memcpy_lines(BYTE* dst, int dst_linesize, BYTE* src, int src_linesize, int lines)
{
    int copy_size = min(dst_linesize, src_linesize);
    if (dst_linesize == src_linesize)
    {
        memcpy(dst, src, copy_size*lines);
    }
    else
    {
        for (int i = 0; i < lines; ++i, dst += dst_linesize, src += src_linesize)
        {
            memcpy(dst, src, copy_size);
        }
    }
    return ERR_Success;
}


static void TTSample_GetBufferSize(int linesize[4], int height[4], int iWidth, int iHeight, enum TTPixelFormat pixel_format)
{
    memset(linesize, 0, sizeof(linesize));
    memset(height, 0, sizeof(height));

    switch(pixel_format)
    {
    case TT_PIX_FMT_YUVA:
    case TT_PIX_FMT_ARGB32:
    case TT_PIX_FMT_RGBA32: linesize[0] = iWidth*4, height[0] = iHeight; break;

    case TT_PIX_FMT_RGB24:
    case TT_PIX_FMT_BGR24:  linesize[0] = iWidth*3, height[0] = iHeight; break;

    case TT_PIX_FMT_YUYV:
    case TT_PIX_FMT_UYVY:
    case TT_PIX_FMT_RGB565:
    case TT_PIX_FMT_RGB555:  linesize[0] = iWidth*2, height[0] = iHeight; break;

    case TT_PIX_FMT_GRAY8:  linesize[0] = iWidth*1, height[0] = iHeight; break;

    case TT_PIX_FMT_YUV422P:
        linesize[0] = iWidth, height[0] = iHeight;
        linesize[1] = iWidth/2, height[1] = iHeight;
        linesize[2] = iWidth/2, height[2] = iHeight;
        break;

    case TT_PIX_FMT_YUV444P:
        linesize[0] = iWidth, height[0] = iHeight;
        linesize[1] = iWidth, height[1] = iHeight;
        linesize[2] = iWidth, height[2] = iHeight;
        break;

    case TT_PIX_FMT_YUV420P:
        linesize[0] = iWidth, height[0] = iHeight;
        linesize[1] = iWidth/2, height[1] = iHeight/2;
        linesize[2] = iWidth/2, height[2] = iHeight/2;
        break;
    }
};

typedef int (*FUNC_GetBufferHeight)(int arrHeight[4], enum ePixelFormat ePixelFmt, int iHeight);

static int TT_GetBufferHeight(int arrHeight[4], enum ePixelFormat ePixelFmt, int iHeight)
{
    memset(arrHeight, 0, sizeof(arrHeight[0])*4);

    int retval = 0;
    switch(ePixelFmt)
    {
    case TT_PIX_FMT_ARGB32: 
    case TT_PIX_FMT_RGBA32: 
    case TT_PIX_FMT_RGBA32X: 
    case TT_PIX_FMT_YUVA:

    case TT_PIX_FMT_RGB24: 
    case TT_PIX_FMT_BGR24:

    case TT_PIX_FMT_GRAY8: 

    case TT_PIX_FMT_RGB565: 
    case TT_PIX_FMT_RGB555: 
    case TT_PIX_FMT_YUYV: 
    case TT_PIX_FMT_UYVY:

        arrHeight[0] = iHeight;
        break;

    case TT_PIX_FMT_YUV444P: 
    case TT_PIX_FMT_YUV422P: 
    case TT_PIX_FMT_YUV411P: 
        arrHeight[0] = iHeight; 
        arrHeight[1] = iHeight;
        arrHeight[2] = iHeight;
        break;

    case TT_PIX_FMT_YUV420P: 
        arrHeight[0] = iHeight; 
        arrHeight[1] = iHeight/2;
        arrHeight[2] = iHeight/2;
        break;
    }
    return retval;
}


static BOOL TTSample_FillBuffer(BYTE* data[4], BYTE* buffer, int iWidth, int iHeight, enum TTPixelFormat pixel_format)
{
    memset(data, 0, sizeof(data));

    if (NULL == buffer)
        return FALSE;

    int arrLineSize[4];
    int arrHeight[4];
    TTSample_GetBufferSize(arrLineSize, arrHeight, iWidth, iHeight, pixel_format);

    if (0 == arrLineSize[0])
        return FALSE;

    int iSizeAccount = 0;
    for (int i = 0; i < _countof(arrLineSize) && arrLineSize[i]; ++i)
    {
        data[i] = buffer + iSizeAccount;
        iSizeAccount += arrLineSize[i]*arrHeight[i];
    }

    return TRUE;
};


static BOOL TTSample_Copy(BYTE* pBuffer, ITTMPVideoSample* pSrcSample)
{
    if (NULL == pBuffer || NULL == pSrcSample)
        return FALSE;

    int arrLineSize[4];
    int arrHeight[4];
    TTSample_GetBufferSize(arrLineSize, arrHeight, pSrcSample->ImageInfo().biWidth, pSrcSample->ImageInfo().biHeight, pSrcSample->PixelFormat());

    if (0 == arrLineSize[0])
        return FALSE;

    int arrSize[4] = {0};
    BYTE* arrIter[4] = {0};

    int iCopySize = 0;
    for (int i = 0; i < _countof(arrLineSize) && arrLineSize[i]; ++i)
    {
        BYTE* iter = pBuffer+iCopySize;
        BYTE* src_iter = pSrcSample->Data((TTMP_BUF_IDX)(TTMP_BUF+i));
        memcpy_lines(iter, arrLineSize[i], src_iter, pSrcSample->LineSize((TTMP_BUF_IDX)(TTMP_BUF+i)), arrHeight[i]);
        iCopySize += arrLineSize[i]*arrHeight[i];
    }

    return TRUE;
}

static BOOL TTSample_Copy(ITTMPVideoSample* pDstSample, ITTMPVideoSample* pSrcSample, FUNC_GetBufferHeight funcGetBufferHeight)
{
    if (   pDstSample->PixelFormat() == pSrcSample->PixelFormat()
        && pDstSample->ImageInfo().biWidth == pSrcSample->ImageInfo().biWidth
        && pDstSample->ImageInfo().biHeight == pSrcSample->ImageInfo().biHeight
        )
    {
        int arrHeight[4] = {0};
        funcGetBufferHeight(arrHeight, (ePixelFormat)pSrcSample->PixelFormat(), pSrcSample->ImageInfo().biHeight);        
        for (int i = 0; i < 3 && arrHeight[i]; ++i)
        {
            TTMP_BUF_IDX bufidx = (TTMP_BUF_IDX)i;
            if (pDstSample->Data(bufidx) && pSrcSample->Data(bufidx))
            {
                memcpy_lines(pDstSample->Data(bufidx), pDstSample->LineSize(bufidx)
                    , pSrcSample->Data(bufidx), pSrcSample->LineSize(bufidx)
                    , arrHeight[i]);
            }
        }
        return TRUE;
    }
    return FALSE;
}

static void TTMP_SetScanMode(BITMAPINFOHEADER& dst, eTTMP_SCANMODE_TYPE eScanModeType)
{
    dst.biClrUsed |= ((int)(eScanModeType))<<24;
}

static eTTMP_SCANMODE_TYPE TTMP_GetScanMode(const BITMAPINFOHEADER& dst)
{
    return (eTTMP_SCANMODE_TYPE)((dst.biClrUsed >> 24)&0xff);
}

static bool TTMP_IsProgressive(eTTMP_SCANMODE_TYPE eScanModeType)
{
    return eScanModeType == TTMP_FRAME_TYPE_Progressive;
}

#endif
