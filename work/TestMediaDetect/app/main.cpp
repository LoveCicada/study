
#include "../MediaDetect/src/VXMediaDetect.h"

void test(char* path = nullptr)
{
    IVXMediaDectect* pMediaDetect = CreateMediaDetect();
    pMediaDetect->Init();
    std::string fileName = "/mnt/WebShare/Dyf/SRC/clip/test2.mp4";
    int mode = 0;
    pMediaDetect->GetMediaInfo(fileName, mode);

    TT::TTMediaInfo mediaInfo;
    pMediaDetect->ConvertToNovaInfo(mediaInfo);


}

int main(int argc, char* argv[])
{
    std::cout << "media test case" << std::endl;

    if(argc>1)
    {
        test(argv[1]);
    }else{
        test();
    }


    std::cout << "media test finish" << std::endl;

    return 0;
}