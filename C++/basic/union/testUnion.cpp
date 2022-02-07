
#include <iostream>
using namespace std;

typedef unsigned int QRgb;

int qRed(QRgb rgb)
{
    return ( (rgb>>16) & 0xff );
}

int qGreen(QRgb rgb)
{
    return ( (rgb>>8) & 0xff );
}

int qBlue(QRgb rgb)
{
    return ( (rgb) & 0xff );
}

typedef union _tag_RGBA
{   
    struct{
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    }sColor;
    unsigned long int uColor;
}RGBA;

void test()
{
    RGBA rgba;
    rgba.sColor.r = 251;
    rgba.sColor.g = 53;
    rgba.sColor.b = 11;
    rgba.sColor.a = 255;

    std::cout << "rgba.uColor: " << rgba.uColor << std::endl;
    std::cout << "qRed(rgba.uColor): " << qRed(rgba.uColor) << std::endl;
    std::cout << "qGreen(rgba.uColor): " <<qGreen(rgba.uColor) << std::endl;
    std::cout << "qBlue(rgba.uColor): " <<qBlue(rgba.uColor) << std::endl;

}

int main()
{
    test();

    return 0;
}