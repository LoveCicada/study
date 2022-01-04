
#include "../MediaDetect/src/VXMediaDetect.h"

void test()
{
    IVXMediaDectect* pMediaDetect = CreateMediaDetect();
    pMediaDetect->Init();
    std::string fileName = "/mnt/WebShare/Dyf/SRC/clip/test2.mp4";
    int mode = 0;
    pMediaDetect->GetMediaInfo(fileName, mode);

    TT::TTMediaInfo mediaInfo;
    pMediaDetect->ConvertToNovaInfo(mediaInfo);


}

int main()
{
    std::cout << "media test case" << std::endl;

    test();

    std::cout << "media test finish" << std::endl;

    return 0;
}