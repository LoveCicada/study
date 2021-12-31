
#ifndef __media_transcode_base_def_header__
#define __media_transcode_base_def_header__

#include "./TTMediaReaderBaseDef.hpp"
#include "./ITTMediaSampeAVS.hpp"

enum TT_HDSD_COMPILE_MODE
{
    TT_HDSD_COMPILE_NoChange,     /**< 不变化 */
    TT_HDSD_COMPILE_Stretch,      /**< 填充 */
    TT_HDSD_COMPILE_CutHorz,      /**< 水平适配 */
    TT_HDSD_COMPILE_EstopVert,    /**< 垂直适配 */
    TT_HDSD_COMPILE_Custom,       /**< 自定义适配 */
};

enum TT_DEINTERLACE_MODE
{
    TT_DEINTERLACE_None,            /**< 不反交错 */
    TT_DEINTERLACE_BottomField,     /**< 采用偶场反交错 */
    TT_DEINTERLACE_TopField,        /**< 采用奇场反交错 */
    TT_DEINTERLACE_MELA,            /**< 采用MELA方法反交错 */
};

enum TT_AUDIO_RESAMPLE_TYPE
{
    TT_RESAMPLE_A_Default,              /**< 默认音频重采样方法 */
    TT_RESAMPLE_A_Nearest,              /**< 临近点重采样，目前未实现 */
    TT_RESAMPLE_A_Linear,               /**< 线性重采样，目前未实现 */
    TT_RESAMPLE_A_Sinc_Fast,            /**< 采用最快速度Sinc方法重采样，目前未实现 */
    TT_RESAMPLE_A_Sinc_MediumQuality,   /**< 采用中等质量Sinc方法重采样，目前未实现 */
    TT_RESAMPLE_A_Sinc_BestQuality,     /**< 采用最佳质量Sinc方法重采样，速度慢，目前未实现 */
};

inline __int64 fremaId_to_100ns(__int64 iiFrameId, double fps)
{
    return 1000*1000*10*iiFrameId/fps;
}

inline __int64 fremaId_to_time(__int64 iiFrameId, double fps)
{
    return fremaId_to_100ns(iiFrameId, fps);
}


// src ---> target
// VA  ---> VA
//          V
//          A
//
//  A  ---> VA
//          A
//
//  V  ---> VA
//          V
//
struct TTTargetFileInfo
{
    enum
    {
        MAX_AUDIO_FILE_COUNT = 16,
    };
    __int64 llStartTime;                        /**< 起始时间, 单位100ns, 1s == 1000*1000*1000ns */
    __int64 llStopTime;                         /**< 结束时间, 单位100ns, 1s == 1000*1000*1000ns */
    wchar_t wszFilenameV[MAX_PATH];             /**< 目标文件名 */
    wchar_t wszFilenameA[MAX_AUDIO_FILE_COUNT][MAX_PATH];          /**< 目标文件名 */
    TTMPlayerCompileFormat ttCompileFormatV;    /**< 目标文件格式 */
    TTMPlayerCompileFormat ttCompileFormatA;    /**< 目标文件格式 */
    int nAudioFileCount;                        /**< 目标文件个数 */

    enum TT_HDSD_COMPILE_MODE   eAdapMode;              /**< 适配类型 */
    enum TT_DEINTERLACE_MODE    eDeinterlaceType;       /**< 反交错方法 */
    enum TT_AUDIO_RESAMPLE_TYPE eAudioResampleMode;     /**< 音频重采样方法 */
};

#endif
