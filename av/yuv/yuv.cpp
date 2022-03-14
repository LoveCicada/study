/**
 * @file yuv.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

enum ColorSpace
{
    YUVUNKNOW = 0,
    YUV420P = 1,
    YUV422P = 2,
    YUYV = 3,

};

/**
 * @brief Get the Color Space Size object
 * 
 * @param ColorSpace 
 * @param nW 
 * @param nH 
 * @param yLineSize 
 * @param uLineSize 
 * @param vLineSize 
 * @return true 
 * @return false 
 */
bool GetColorSpaceSize(ColorSpace ColorSpace, int nW, int nH,
    int& yLineSize, int& uLineSize, int& vLineSize)
{
    bool bRet = false;

    if(nW <=0 || nH <= 0){
        return bRet;
    }

    switch (ColorSpace)
    {
    case ColorSpace::YUVUNKNOW:
        yLineSize = 0;  uLineSize = 0; vLineSize = 0; bRet = false;
        break;
    case ColorSpace::YUV420P:
        yLineSize = nW;  uLineSize = nW >> 1; vLineSize = nW >> 1; bRet = true;
        break;
    case ColorSpace::YUV422P:
        yLineSize = nW;  uLineSize = nW >> 1; vLineSize = nW >> 1; bRet = true;
        break;    
    case ColorSpace::YUYV:      //! YUYV等价于YUV422交错
        yLineSize = nW;  uLineSize = nW >> 1; vLineSize = nW >> 1; bRet = true;
        break;
    default:
        break;
    }

    return bRet;
}

bool GetColorSpaceSize(ColorSpace ColorSpace, int nW, int nH,
    int& yLineSize, int& uLineSize, int& vLineSize,
    int& yTotalSize, int& uTotalSize, int& vTotalSize)
{
    bool bRet = false;

    if(nW <=0 || nH <= 0){
        return bRet;
    }

    switch (ColorSpace)
    {
    case ColorSpace::YUVUNKNOW:
        yLineSize = 0;  uLineSize = 0; vLineSize = 0; bRet = false;
        break;
    case ColorSpace::YUV420P:
        yLineSize = nW;  uLineSize = vLineSize = nW >> 1; 
        yTotalSize = nW * nH; uTotalSize = vTotalSize = (nW >> 1) * (nH >> 1);
        bRet = true;
        break;
    case ColorSpace::YUV422P:
        yLineSize = nW;  uLineSize = vLineSize = nW >> 1; 
        yTotalSize = nW * nH; uTotalSize = vTotalSize = (nW * nH) >> 1;
        bRet = true;
        break;    
    case ColorSpace::YUYV:
        yLineSize = nW;  uLineSize = vLineSize = nW >> 1;
        yTotalSize = nW * nH; uTotalSize = vTotalSize = (nW * nH) >> 1;
        bRet = true;
        break;
    default:
        break;
    }

    return bRet;
}

class YUVData
{
public:
    YUVData(int _w, int _h)
    {
        m_w = _w;
        m_h = _h;
        m_yLineSize = _w;
        m_uLineSize = _w/2;
        m_vLineSize = _w/2;

        m_ySize = m_w * m_h;
        m_uSize = m_w * m_h / 2;
        m_vSize = m_w * m_h / 2;

        m_pY = new unsigned char[m_w * m_h];
        memset(m_pY, 0, m_w * m_h);
        m_pU = new unsigned char[m_w * m_h / 2];
        memset(m_pU, 0, m_w * m_h / 2);
        m_pV = new unsigned char[m_w * m_h / 2];
        memset(m_pV, 0, m_w * m_h / 2);
    }

    YUVData(ColorSpace colorSpace, int _w, int _h)
    {
        SetColorSpace(colorSpace);
        SetWH(_w, _h);
        GetColorSpaceSize(m_colorSpace, m_w, m_h, 
            m_yLineSize, m_uLineSize, m_vLineSize,
            m_ySize, m_uSize, m_vSize);
        CalTotalByteCount();
        Init();
        Alloc();
    }

    ColorSpace GetColorSpace()
    {
        return m_colorSpace;
    }

    bool SetColorSpace(ColorSpace colorSpace)
    {
        bool bRet = false;
        if(ColorSpace::YUVUNKNOW == colorSpace){
            return bRet;
        }
        m_colorSpace = colorSpace;
        bRet = true;
        return bRet;
    }

    bool SetWH(int _w, int _h)
    {
        bool bRet = false;

        if( _w<=0 || _h<=0){
            return bRet;
        }
        m_w = _w;
        m_h = _h;
        bRet = true;
        return bRet;
    }

    bool Init()
    {
        m_pData = nullptr;
        m_pY    = nullptr;
        m_pU    = nullptr;
        m_pV    = nullptr;
        return true;
    }

    bool Alloc()
    {
        bool bRet = false;
        Free();
        m_pData = new unsigned char [m_totalByte];
        memset(m_pData, 0, m_totalByte);
        m_pY = m_pData;
        m_pU = m_pY + m_ySize;
        m_pV = m_pU + m_uSize;

        return bRet;
    }

    bool Free()
    {
        bool bRet = false;
        if (m_pData) {
            delete m_pData;
        }

        bRet = true;
        return bRet;
    }

    ~YUVData()
    {
        Free();
    }

    void CalTotalByteCount()
    {
        m_totalByte = m_ySize + m_uSize + m_vSize;
    }

    int GetTotalByteCount()
    {
        return m_totalByte;
    }

    unsigned char* GetY()
    {
        return m_pY;
    }

    unsigned char* GetU()
    {
        return m_pU;
    }

    unsigned char* GetV()
    {
        return m_pV;
    }

    int GetYSzie()
    {
        return m_ySize;
    }
    
    int GetUSzie()
    {
        return m_uSize;
    }

    int GetVSzie()
    {
        return m_vSize;
    }

    int GetYLineSzie()
    {
        return m_yLineSize;
    }
    
    int GetULineSzie()
    {
        return m_uLineSize;
    }

    int GetVLineSzie()
    {
        return m_vLineSize;
    }

    int GetWidth()
    {
        return m_w;
    }

    int GetHeight()
    {
        return m_h;
    }

private:
    unsigned char* m_pData;
    unsigned char* m_pY;
    unsigned char* m_pU;
    unsigned char* m_pV;

    int m_w;
    int m_h;
    int m_ySize;
    int m_uSize;
    int m_vSize;
    int m_totalByte;

    int m_yLineSize;
    int m_uLineSize;
    int m_vLineSize;

    ColorSpace m_colorSpace;
};

class Rect
{
public:
    Rect(int xStart, int yStart, int _w, int _h)
    {
        m_xStart = xStart;
        m_yStart = yStart;
        m_width = _w;
        m_height = _h;
        m_xEnd = m_xStart + m_width;
        m_yEnd = m_yStart + m_height;
    }

    int GetWidth()
    {
        return m_width;
    }

    int GetHeight()
    {
        return m_height;
    }

    int GetStartX()
    {
        return m_xStart;
    }

    int GetStartY()
    {
        return m_yStart;
    }

    int GetEndX()
    {
        return m_xEnd;
    }

    int GetEndY()
    {
        return m_yEnd;
    }

private:
    int m_xStart;
    int m_yStart;
    int m_xEnd;
    int m_yEnd;
    int m_width;
    int m_height;
};

class YUVCrop
{
public:

    bool Crop(YUVData& srcYuv, YUVData& dstYuv, Rect& rt)
    {
        bool bRet = false;
        if (srcYuv.GetColorSpace() == dstYuv.GetColorSpace())
        {
            //! YUV422P
            if (dstYuv.GetColorSpace() == ColorSpace::YUV422P)
            {
                for (int nStartH = rt.GetStartY(); nStartH < rt.GetEndY(); nStartH++) {

                    unsigned char* pYSrc = srcYuv.GetY() + (srcYuv.GetYLineSzie() * nStartH) + rt.GetStartX();
                    unsigned char* pYDst = dstYuv.GetY() + (dstYuv.GetYLineSzie() * (nStartH - rt.GetStartY()));
                    memcpy(pYDst, pYSrc, dstYuv.GetYLineSzie());

                    unsigned char* pUSrc = srcYuv.GetU() + (srcYuv.GetULineSzie() * nStartH) + rt.GetStartX();
                    unsigned char* pUDst = dstYuv.GetU() + (dstYuv.GetULineSzie() * (nStartH - rt.GetStartY()));
                    memcpy(pUDst, pUSrc, dstYuv.GetULineSzie());

                    unsigned char* pVSrc = srcYuv.GetV() + (srcYuv.GetVLineSzie() * nStartH) + rt.GetStartX();
                    unsigned char* pVDst = dstYuv.GetV() + (dstYuv.GetVLineSzie() * (nStartH - rt.GetStartY()));
                    memcpy(pVDst, pVSrc, dstYuv.GetVLineSzie());
                }
            }
            else if (dstYuv.GetColorSpace() == ColorSpace::YUYV)
            {
                 //! YUYV交错存储, 可以把YUV看成一个整体, 类似RGB
                 //! 处理buffer时，可以单个像素点(YUV)来处理
                 //! Y U V三者的高度是相同的
                 //! 每一行的字节数 = w * 2字节
                for (int nStartH = rt.GetStartY(); nStartH < rt.GetEndY(); nStartH++) {
                    
                    //! 8bit YUYV 字节数是2
                    unsigned char* pYSrc = srcYuv.GetY() + srcYuv.GetWidth() * 2 * nStartH + rt.GetStartX() * 2;
                    unsigned char* pYDst = dstYuv.GetY() + dstYuv.GetWidth() * 2 * (nStartH - rt.GetStartX());
                    memcpy(pYDst, pYSrc, dstYuv.GetWidth() * 2);
                }
            }

            //!
        }

        bRet = true;
        return bRet;
    }

};


int main(int argc, char* argv[])
{
    std::cout << " Usage: ./yuvDemo src_yuv420p.yuv dst_yuv420p.yuv\n" 
              << "Default use: yuv422p.yuv, yuv422p_output.yuv\n"; 

    string input = "yuv422p.yuv";
    string outpath = "yuv422p_output.yuv";
    if(argc > 1){
        input = argv[1];
    }
    if(argc > 2){
        outpath = argv[2];
    }

    int nW = 1920;
    int nH = 1080;
    
#if 0
    YUVData yuv422p(nW, nH);
#else
    YUVData yuv422p(ColorSpace::YUYV, nW, nH);
#endif

    ifstream ifs;
    ifs.open(input, ios_base::binary);
    ifs.read((char*)(yuv422p.GetY()), yuv422p.GetYSzie());
    ifs.read((char*)(yuv422p.GetU()), yuv422p.GetUSzie());
    ifs.read((char*)(yuv422p.GetV()), yuv422p.GetVSzie());
    ifs.close();

    Rect rect(nW / 2, nH / 2, nW / 2, nH / 2);
    YUVData yuv422p_out(ColorSpace::YUYV, nW/2, nH/2);

#if 0
    //crop
    for(int nStartH = rect.GetStartY(); nStartH < rect.GetEndY(); nStartH++){

        unsigned char* pYSrc = yuv422p.GetY() + (yuv422p.GetYLineSzie() * nStartH) + rect.GetStartX();
        unsigned char* pYDst = yuv422p_out.GetY() + (yuv422p_out.GetYLineSzie() * (nStartH - rect.GetStartY()));
        memcpy(pYDst, pYSrc, yuv422p_out.GetYLineSzie());

        unsigned char* pUSrc = yuv422p.GetU() + (yuv422p.GetULineSzie() * nStartH) + rect.GetStartX();
        unsigned char* pUDst = yuv422p_out.GetU() + (yuv422p_out.GetULineSzie() * (nStartH - rect.GetStartY()));
        memcpy(pUDst, pUSrc, yuv422p_out.GetULineSzie());

        unsigned char* pVSrc = yuv422p.GetV() + (yuv422p.GetVLineSzie() * nStartH) + rect.GetStartX();
        unsigned char* pVDst = yuv422p_out.GetV() + (yuv422p_out.GetVLineSzie() * (nStartH - rect.GetStartY()));
        memcpy(pVDst, pVSrc, yuv422p_out.GetVLineSzie());
    }
#else

    Rect rtLeftTop(0, 0, nW / 2, nH / 2);
    YUVCrop yuvCrop;
    yuvCrop.Crop(yuv422p, yuv422p_out, rtLeftTop);
#endif

    ofstream ofs;
    ofs.open(outpath, ios_base::binary | ios::trunc|ios::out|ios::in);
    ofs.write((char*)(yuv422p_out.GetY()), yuv422p_out.GetYSzie());
    ofs.write((char*)(yuv422p_out.GetU()), yuv422p_out.GetUSzie());
    ofs.write((char*)(yuv422p_out.GetV()), yuv422p_out.GetVSzie());
    ofs.close();

    return 0;
}