
/**
 * @file getResolution.cpp
 * @author dyf (you@domain.com)
 * @brief 获取Windows机器分辨率
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <windows.h>
using namespace std;

void GetResolution(int16_t w, int16_t h)
{
    HDC hdcScreen;
    hdcScreen = CreateDC(L"DISPLAY", NULL, NULL, NULL);
    if (!hdcScreen) {
        DWORD err = GetLastError();
        cout << __FUNCTION__ << " err: " << err << endl;
        return;
    }

    //! pixel, width
    int16_t iX = GetDeviceCaps(hdcScreen, HORZRES);
    //! pixel, height
    int16_t iY = GetDeviceCaps(hdcScreen, VERTRES);
    //! mm, width
    int16_t iPhsX = GetDeviceCaps(hdcScreen, HORZSIZE);
    //! mm, height
    int16_t iPhsY = GetDeviceCaps(hdcScreen, VERTSIZE);

    w = iX;
    h = iY;

    cout << "ix: " << iX
         << " iy: " << iY
         << " iPhsX: " << iPhsX
         << " iPhsY: " << iPhsY
         << endl;

    if (nullptr != hdcScreen)
    {
        DeleteDC(hdcScreen);
    }
}

int main(int argc, char *argv[])
{
    int16_t w = 0;
    int16_t h = 0;
    GetResolution(w, h);

    return 0;
}