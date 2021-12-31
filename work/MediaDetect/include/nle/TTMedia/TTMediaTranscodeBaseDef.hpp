
#ifndef __media_transcode_base_def_header__
#define __media_transcode_base_def_header__

#include "./TTMediaReaderBaseDef.hpp"
#include "./ITTMediaSampeAVS.hpp"

enum TT_HDSD_COMPILE_MODE
{
    TT_HDSD_COMPILE_NoChange,     /**< ���仯 */
    TT_HDSD_COMPILE_Stretch,      /**< ��� */
    TT_HDSD_COMPILE_CutHorz,      /**< ˮƽ���� */
    TT_HDSD_COMPILE_EstopVert,    /**< ��ֱ���� */
    TT_HDSD_COMPILE_Custom,       /**< �Զ������� */
};

enum TT_DEINTERLACE_MODE
{
    TT_DEINTERLACE_None,            /**< �������� */
    TT_DEINTERLACE_BottomField,     /**< ����ż�������� */
    TT_DEINTERLACE_TopField,        /**< �����泡������ */
    TT_DEINTERLACE_MELA,            /**< ����MELA���������� */
};

enum TT_AUDIO_RESAMPLE_TYPE
{
    TT_RESAMPLE_A_Default,              /**< Ĭ����Ƶ�ز������� */
    TT_RESAMPLE_A_Nearest,              /**< �ٽ����ز�����Ŀǰδʵ�� */
    TT_RESAMPLE_A_Linear,               /**< �����ز�����Ŀǰδʵ�� */
    TT_RESAMPLE_A_Sinc_Fast,            /**< ��������ٶ�Sinc�����ز�����Ŀǰδʵ�� */
    TT_RESAMPLE_A_Sinc_MediumQuality,   /**< �����е�����Sinc�����ز�����Ŀǰδʵ�� */
    TT_RESAMPLE_A_Sinc_BestQuality,     /**< �����������Sinc�����ز������ٶ�����Ŀǰδʵ�� */
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
    __int64 llStartTime;                        /**< ��ʼʱ��, ��λ100ns, 1s == 1000*1000*1000ns */
    __int64 llStopTime;                         /**< ����ʱ��, ��λ100ns, 1s == 1000*1000*1000ns */
    wchar_t wszFilenameV[MAX_PATH];             /**< Ŀ���ļ��� */
    wchar_t wszFilenameA[MAX_AUDIO_FILE_COUNT][MAX_PATH];          /**< Ŀ���ļ��� */
    TTMPlayerCompileFormat ttCompileFormatV;    /**< Ŀ���ļ���ʽ */
    TTMPlayerCompileFormat ttCompileFormatA;    /**< Ŀ���ļ���ʽ */
    int nAudioFileCount;                        /**< Ŀ���ļ����� */

    enum TT_HDSD_COMPILE_MODE   eAdapMode;              /**< �������� */
    enum TT_DEINTERLACE_MODE    eDeinterlaceType;       /**< �������� */
    enum TT_AUDIO_RESAMPLE_TYPE eAudioResampleMode;     /**< ��Ƶ�ز������� */
};

#endif
