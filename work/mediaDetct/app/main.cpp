
#include "VXMediaDetect.h"

void test()
{
    IVXMediaDectect* pMediaDectect = CreateMediaDectect();
    pMediaDectect->Init();
    pMediaDectect->GetMediaInfo();
}

int main()
{
    std::cout << "media test case" << std::endl;
    test();

    return 0;
}