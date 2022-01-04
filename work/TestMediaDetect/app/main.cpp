
#include "../MediaDetect/src/VXMediaDetect.h"

void test()
{
    IVXMediaDectect* pMediaDetect = CreateMediaDetect();
    pMediaDetect->Init();
    std::string fileName = "/mnt/d/code/private/loveCicada_test/srs/video/test.flv";
    int mode = 0;
    pMediaDetect->GetMediaInfo(fileName, mode);

}

int main()
{
    std::cout << "media test case" << std::endl;

    test();

    std::cout << "media test finish" << std::endl;

    return 0;
}