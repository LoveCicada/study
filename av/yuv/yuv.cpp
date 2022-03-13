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

    ~YUVData()
    {
        delete m_pY;
        delete m_pU;
        delete m_pV;
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

private:
    unsigned char* m_pY;
    unsigned char* m_pU;
    unsigned char* m_pV;

    int m_w;
    int m_h;
    int m_ySize;
    int m_uSize;
    int m_vSize;

    int m_yLineSize;
    int m_uLineSize;
    int m_vLineSize;

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
    
    YUVData yuv422p(nW, nH);

    ifstream ifs;
    ifs.open(input, ios_base::binary);
    ifs.read((char*)(yuv422p.GetY()), yuv422p.GetYSzie());
    ifs.read((char*)(yuv422p.GetU()), yuv422p.GetUSzie());
    ifs.read((char*)(yuv422p.GetV()), yuv422p.GetVSzie());
    ifs.close();

    Rect rect(nW/2, nH/2, nW/2, nH/2);
    YUVData yuv422p_out(nW/2, nH/2);

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

    ofstream ofs;
    ofs.open(outpath, ios_base::binary | ios::trunc|ios::out|ios::in);
    ofs.write((char*)(yuv422p_out.GetY()), yuv422p_out.GetYSzie());
    ofs.write((char*)(yuv422p_out.GetU()), yuv422p_out.GetUSzie());
    ofs.write((char*)(yuv422p_out.GetV()), yuv422p_out.GetVSzie());
    ofs.close();

    return 0;
}