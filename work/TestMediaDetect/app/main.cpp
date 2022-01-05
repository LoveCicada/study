
#include "../MediaDetect/src/VXMediaDetect.h"

void printInfo(const TT::TTMediaInfo& mediaInfo)
{
    std::cout << std::endl;
    std::cout << "<NleInfo>" << std::endl;

    // video - begin
    std::cout << "  <Video>" << std::endl;
    std::cout << "      <GuidFileType>" << std::endl;
    std::cout << "      <VideoFormat>" << std::endl;
    std::cout << "      <DataRate>" << std::endl;
    std::cout << "      <FOURCC>" << std::endl;
    std::cout << "      <MediaType>" << std::endl;
    std::cout << "      <SubMediaType>" << std::endl;
    std::cout << "      <VideoImgWidth>" << std::endl;
    std::cout << "      <VideoImgHeight>" << std::endl;
    std::cout << "      <VPixFmt>" << std::endl;
    std::cout << "      <VBitsPerPixel>" << std::endl;
    std::cout << "      <VFrameRate>" << std::endl;
    std::cout << "      <VCompression>" << std::endl;
    std::cout << "      <ScanMode>" << std::endl;
    std::cout << "      <GOPSize>" << std::endl;
    std::cout << "      <CompressType>" << std::endl;
    std::cout << "      <BFrameCount>" << std::endl;
    std::cout << "      <PFrameCount>" << std::endl;

    // VideoStandDetail - begin
    std::cout << "      <VideoStandDetail>" << std::endl;
    std::cout << "          <Version>" << std::endl;
    std::cout << "          <EditWidth>" << std::endl;
    std::cout << "          <EditHeight>" << std::endl;
    std::cout << "          <FrameRateFrequency>" << std::endl;
    std::cout << "          <FrameRateScale>" << std::endl;
    std::cout << "          <WidthAspectRatio>" << std::endl;
    std::cout << "          <HeightAspectRatio>" << std::endl;
    std::cout << "          <WidthPixRatio>" << std::endl;
    std::cout << "          <HeightPixRatio>" << std::endl;
    std::cout << "          <BitCount>" << std::endl;
    std::cout << "          <ScanMode>" << std::endl;
    std::cout << "          <DeinterlaceType>" << std::endl;
    std::cout << "          <ViewNum>" << std::endl;
    std::cout << "          <ColorsSpace>" << std::endl;
    // VideoStandDetail - end
    std::cout << "      </VideoStandDetail>" << std::endl;

    // video - end
    std::cout << "  <Video>" << std::endl;

    //audio - begin
    std::cout << "  <Audio>" << std::endl;
    std::cout << "      <MediaType>" << std::endl;
    std::cout << "      <SubMediaType>" << std::endl;
    std::cout << "      <AudioFormat>" << std::endl;
    std::cout << "      <FOURCC>" << std::endl;
    std::cout << "      <AudioChannels>" << std::endl;
    std::cout << "      <AudioSamplesRate>" << std::endl;
    std::cout << "      <AudioBitsperSample>" << std::endl;
    //audio - end
    std::cout << "  </Audio>" << std::endl;

    std::cout << "</NleInfo>" << std::endl;
    std::cout << std::endl;
}

void test(string file = "")
{
    std::string fileName = "/mnt/WebShare/Dyf/SRC/clip/test2.mp4";
    if(file.empty())
    {
        file = fileName;
    }
    printf("file = %s\n", file.c_str());

    IVXMediaDectect* pMediaDetect = CreateMediaDetect();
    pMediaDetect->Init();
    
    int mode = 0;
    pMediaDetect->GetMediaInfo(file, mode);

    TT::TTMediaInfo mediaInfo;
    pMediaDetect->ConvertToNovaInfo(mediaInfo);

    printInfo(mediaInfo);

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