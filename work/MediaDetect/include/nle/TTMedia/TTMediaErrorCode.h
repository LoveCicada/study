
#ifndef __def__ttmediautility_error_code__header__
#define __def__ttmediautility_error_code__header__

enum
{
    TT_SUCCEED_FileClosed_InvalidDetect = 2,
    TT_SUCCEED_NEED_INDEX = 1,
    TT_SUCCEED = 0,
    TT_ERR_AllocFailed = -100001,
    TT_ERR_FreeFailed = -100002,
    TT_ERR_PluginRegisted = -100003,
    TT_ERR_InvalidFile = -100004,
    TT_ERR_InvalidAudio = -100005,
    TT_ERR_InvalidVideo = -100006,
    TT_ERR_InvalidFilename = -100007,
    TT_ERR_InvalidOpenMode = -100008,
    TT_ERR_InvalidParam = -100009,
    TT_ERR_InvalidPixelFormat = -100010,
    TT_ERR_InvalidStartTime = -100011,
    TT_ERR_InvalidAudioFileCount = -100012,
    TT_ERR_InvalidStartTimeOrStopTime = -100013,
    TT_ERR_NoSample = -100014,
    TT_ERR_NoImplement= -100015,
    TT_ERR_NoContext = -100016,
    TT_ERR_NoPugin = -100017,
    TT_ERR_NoModule = -100018,
    TT_ERR_NoDecoder = -100019,
    TT_ERR_LoadDllFailed = -100020,
    TT_ERR_InitDllFailed = -100021,
    TT_ERR_CreateWriterFailed = -100022,
    TT_ERR_StartWriteFailed = -100023,
    TT_ERR_StopWriteFailed = -100024,
    TT_ERR_CloseWriteFailed = -100025,
    TT_ERR_ExsitReader = -100026,
    TT_ERR_CreateReaderFailed = -100027,
    TT_ERR_StartReaderFailed = -100028,
    TT_ERR_StopReaderFailed = -100029,
    TT_ERR_CloseReaderFailed = -100030,
    TT_ERR_GetTPFileFormatFailed = -100031,
    TT_ERR_GetConfigFailed = -100032,
    TT_ERR_CreateCutlistFailed = -100033,
    TT_ERR_CreateThreadFailed = -100034,
    TT_ERR_CreateImageConvertFailed = -100035,
    TT_ERR_CreateAudioResamplerFailed = -100036,
    TT_ERR_CreateDecoderFailed = -100037,
    TT_ERR_GetBufferFailed = -100038,
    TT_ERR_SetPluginFailed = -100039,
    TT_ERR_NoInterface = -100040,
    TT_ERR_SetInputFileFailed = -101040,
    TT_ERR_CannelCreateIndex = -101041,
    TT_ERR_CannotCreateIndex = -101042,
    TT_ERR_InvalidSource = -101043,
    TT_ERR_CannotCrateDetector = -101044,
    TT_ERR_NeedIndex = -101045,

    ERR_CreateEncoder = -107000,
    ERR_StartEncode = -107001,
    ERR_EncodeVideo = -107002,
    ERR_EncodeAudio = -107003,
    ERR_StopEncode = -107004,

    ERR_CreateDecoder = -109000,
    ERR_StartDecode = -109001,
    ERR_DecodeVideo = -109002,
    ERR_DecodeAudio = -109003,
    ERR_StopDecode = -109004,

    ERR_WriteVideo = -110005,
    ERR_WriteAudio = -110006,
    ERR_StopWrite = -110007,
};

enum
{
    ERR_IsPlaying = TT_SUCCEED,
    ERR_Success = TT_SUCCEED,
    ERR_AllocFailed = TT_ERR_AllocFailed,
    ERR_FreeFailed = TT_ERR_FreeFailed,
    ERR_PluginRegisted = TT_ERR_PluginRegisted,
    ERR_InvalidFile = TT_ERR_PluginRegisted,
    ERR_InvalidAudio = TT_ERR_InvalidAudio,
    ERR_InvalidVideo = TT_ERR_InvalidVideo,
    ERR_InvalidFilename = TT_ERR_InvalidFilename,
    ERR_InvalidOpenMode = TT_ERR_InvalidOpenMode,
    ERR_InvalidParam = TT_ERR_InvalidParam,
    ERR_InvalidPixelFormat = TT_ERR_InvalidPixelFormat,
    ERR_InvalidStartTime = TT_ERR_InvalidStartTime,
    ERR_InvalidAudioFileCount = TT_ERR_InvalidAudioFileCount,
    ERR_InvalidStartTimeOrStopTime = TT_ERR_InvalidStartTimeOrStopTime,
    ERR_NoSample = TT_ERR_NoSample,
    ERR_NoImplement=  TT_ERR_NoImplement,
    ERR_NoContext = TT_ERR_NoContext,
    ERR_NoPugin = TT_ERR_NoPugin,
    ERR_NoModule = TT_ERR_NoModule,
    ERR_NoDecoder = TT_ERR_NoDecoder,
    ERR_LoadDllFailed = TT_ERR_LoadDllFailed,
    ERR_InitDllFailed = TT_ERR_InitDllFailed,
    ERR_CreateWriterFailed = TT_ERR_CreateWriterFailed,
    ERR_StartWriteFailed = TT_ERR_StartWriteFailed,
    ERR_StopWriteFailed = TT_ERR_StopWriteFailed,
    ERR_CloseWriteFailed = TT_ERR_CloseWriteFailed,
    ERR_ExsitReader = TT_ERR_ExsitReader,
    ERR_CreateReaderFailed = TT_ERR_CreateReaderFailed,
    ERR_StartReaderFailed = TT_ERR_StartReaderFailed,
    ERR_StopReaderFailed = TT_ERR_StopReaderFailed,
    ERR_CloseReaderFailed = TT_ERR_CloseReaderFailed,
    ERR_GetTPFileFormatFailed = TT_ERR_GetTPFileFormatFailed,
    ERR_GetConfigFailed = TT_ERR_GetConfigFailed,
    ERR_CreateCutlistFailed = TT_ERR_CreateCutlistFailed,
    ERR_CreateThreadFailed = TT_ERR_CreateThreadFailed,
    ERR_CreateImageConvertFailed = TT_ERR_CreateImageConvertFailed,
    ERR_CreateAudioResamplerFailed = TT_ERR_CreateAudioResamplerFailed,
    ERR_CreateDecoderFailed = TT_ERR_CreateDecoderFailed,
    ERR_GetBufferFailed = TT_ERR_GetBufferFailed,
    ERR_SetPluginFailed = TT_ERR_SetPluginFailed,
    ERR_NoInterface = TT_ERR_NoInterface,
};

inline bool IsOk(int iErrCode)
{
    return iErrCode >=0;
}

inline bool IsFailed(int iErrCode)
{
    return iErrCode < 0;
}

#endif
