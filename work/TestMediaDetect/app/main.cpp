
#include "../MediaDetect/src/VXMediaDetect.h"

void test()
{
    IVXMediaDectect* pMediaDetect = CreateMediaDetect();
    pMediaDetect->Init();
    std::string fileName;
    int mode = 0;
    pMediaDetect->GetMediaInfo(fileName, mode);
}

int main()
{
    std::cout << "media test case" << std::endl;
    test();

    return 0;
}