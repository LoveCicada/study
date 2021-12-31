
#ifndef __def__transcode_source_interface__header__
#define __def__transcode_source_interface__header__

#include "./TTMediaTranscodeBaseDef.hpp"
#include <InitGuid.h>
// -------------------------------------------------------------------------

struct ITTTranscodeSource
{
    virtual int GetFileFormat(TTMPlayerFileFormat& fileInfo) = 0;
    virtual int Start(__int64 llTimeIn, __int64 llTimeOut, bool bOutputVideo, bool bOutputAudio) = 0;
    virtual int ReadSamples(ITTMPVideoSamplePtr& pVideoSample, __int64 llTimePos) = 0;
    virtual int ReadSamples(ITTMPAudioSamplePtr& pAudioSample, __int64 llTimePos) = 0;
    virtual int Stop() = 0;
};

// {1EF00138-3053-4547-8710-3CA881E02613}
DEFINE_GUID(IID_ISetTranscodeSource, 0x1ef00138, 0x3053, 0x4547, 0x87, 0x10, 0x3c, 0xa8, 0x81, 0xe0, 0x26, 0x13);
struct ISetTranscodeSource
{
    virtual int SetSource(ITTTranscodeSource* pSource) = 0;
    virtual int ClearSource() = 0;
};

// -------------------------------------------------------------------------

#endif
