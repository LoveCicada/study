
//#pragma once

#ifndef __TPAVFileMapFileTypeFromSbt__Header__
#define __TPAVFileMapFileTypeFromSbt__Header__

#include "../../include/nle/LinuxTTMedia/File/SBT_TransBaseDefine.h"
#include "../../include/nle/LinuxTTMedia/File/TPAVFileTypeDefs.h"

#include "./TPAVFileMapFileTypeFromSbt.h"

GUID TPAVFileGetGUID(int iID)
{
    //GUID guidFile=GUID_NULL;
    GUID guidFile;
    switch(iID)
    {
    case XH_TRANS_FILE_NONE:
        break;
    case XH_TRANS_FILE_UNKNOWN:
        break;
    case XH_TRANS_FILE_UNCARE:
        break;
    case XH_TRANS_FILE_AVI:
        guidFile=GUID_FILE_GENERAL_AVI;
        break;
    case XH_TRANS_FILE_RIFF_AVI:
        guidFile=GUID_FILE_RIFF_AVI;
        break;
    case XH_TRANS_FILE_OPDML_AVI:
        guidFile=GUID_FILE_OPDML_AVI;
        break;//
    case XH_TRANS_FILE_AVMIXED_AVI2:
        guidFile =GUID_FILE_AVMIXED_AVI2;
        break;
    case XH_TRANS_FILE_DV_DIFF:
        guidFile = GUID_FILE_DV_DIFF;
        break;
    case XH_TRANS_FILE_MPEG:
        guidFile = GUID_FILE_MPEG;
        break;
    case XH_TRANS_FILE_MPEG_M2T:
        guidFile = GUID_FILE_MPEG_M2T;
        break;
    case XH_TRANS_FILE_MPEG_ES:
        guidFile = GUID_FILE_MPEG_ES;
        break;
    case XH_TRANS_FILE_MPEG_PS:
        guidFile = GUID_FILE_MPEG_PS;
        break;
    case XH_TRANS_FILE_MPEG_TS:
        guidFile = GUID_FILE_MPEG_TS;
        break;
    case XH_TRANS_FILE_MPEG_DVD:
        guidFile = GUID_FILE_MPEG_DVD;
        break;
    case XH_TRANS_FILE_MPEG_VCD:
        guidFile = GUID_FILE_MPEG_VCD;
        break;
    case XH_TRANS_FILE_MPEG_SVCD:
        guidFile = GUID_FILE_MPEG_SVCD;
        break;
    case XH_TRANS_FILE_MPEG_MP4:
        guidFile = GUID_FILE_MPEG_MP4;
        break;
    case XH_TRANS_FILE_MS_WMV:
        guidFile = GUID_FILE_MS_WMV;
        break;
    case XH_TRANS_FILE_MS_ASF:
        guidFile = GUID_FILE_MS_ASF;
        break;
    case XH_TRANS_FILE_REAL_RM:
        guidFile = GUID_FILE_REAL_RM;
        break;
    case XH_TRANS_FILE_QT_MOV:
        guidFile = GUID_FILE_QT_MOV;
        break;
    case XH_TRANS_FILE_PROMPEG_MXF:
        guidFile = GUID_FILE_PROMPEG_MXF;
        break;
    case XH_TRANS_FILE_IMX_MXF:
        guidFile = GUID_FILE_IMX_MXF;
        break;
    case XH_TRANS_FILE_MATROX_AVI:
        guidFile = GUID_FILE_MATROX_AVI;
        break;
    case XH_TRANS_FILE_SONY_IMX:
        guidFile = GUID_FILE_SONY_IMX;
        break;
    case XH_TRANS_FILE_SONY_MAV70:
        guidFile = GUID_FILE_SONY_MAV70;
        break;
    case XH_TRANS_FILE_SEACHANGE:
        guidFile = GUID_FILE_SEACHANGE;
        break;
    case XH_TRANS_FILE_GVG_GXF:
        guidFile = GUID_FILE_GVG_GXF;
        break;
    case XH_TRANS_FILE_WAV:
        guidFile=GUID_FILE_WAV;//
        break;
    case XH_TRANS_FILE_MP1:
        guidFile = GUID_FILE_MP1;
        break;
    case XH_TRANS_FILE_MP2:
        guidFile = GUID_FILE_MP2;
        break;
    case XH_TRANS_FILE_MP3:
        guidFile=GUID_FILE_MP3;//
        break;
    case XH_TRANS_FILE_AAC:
        guidFile = GUID_FILE_AAC;
        break;
    case XH_TRANS_FILE_WMA:
        guidFile = GUID_FILE_WMA;
        break;
    case XH_TRANS_FILE_RMA:
        guidFile = GUID_FILE_RMA;
        break;
        //== [2/29/2008 wangqing] 
        //case XH_TRANS_VIDEO_MPEG4_AVCIntra:
        //	guidFile = GUID_FILE_AVCINTRA;
        //	break;
    case XH_TRANS_VIDEO_MJPEG2000:
        guidFile = GUID_FILE_JPEG2000;
        break;
    case XH_TRANS_FILE_3GP:
        guidFile = GUID_FILE_3GP;
        break;
    case XH_TRANS_FILE_FLASH_FLV:
        guidFile = GUID_FILE_FLV;
        break;
    case XH_TRANS_FILE_DV_AVI:
        guidFile = GUID_FILE_DV_AVI;
        break;
    case XH_TRANS_FILE_F4V:
        guidFile = GUID_FILE_F4V;
        break;
    case XH_TRANS_FILE_MKV:
        guidFile = GUID_FILE_MKV;
        break;
    case XH_TRANS_FILE_ISMV:     
        guidFile = GUID_FILE_ISMV;
        break;
    case XH_TRANS_FILE_DDE:
        guidFile = GUID_FILE_AUDIO_DDE;
        break;
    case XH_TRANS_FILE_S48: guidFile = GUID_FILE_S48; break;
    case XH_TRANS_FILE_VORBIS: guidFile = GUID_FILE_OGG; break;
    case XH_TRANS_FILE_APE: guidFile = GUID_FILE_APE; break;
    case XH_TRANS_FILE_FLAC: guidFile = GUID_FILE_FLAC; break;
    case XH_TRANS_FILE_WEBM: guidFile = GUID_FILE_WEBM; break;
    case XH_TRANS_FILE_M4A: guidFile = GUID_FILE_M4A; break;
    case XH_TRANS_FILE_AIFF: guidFile = GUID_FILE_AIFF; break;
	case XH_TRANS_PLUGIN_FILE_DASH: guidFile = GUID_FILE_DASH_MPD; break;
    case XH_TRANS_PLUGIN_FILE_AMR: guidFile = GUID_FILE_AMR; break;
	case XH_TRANS_PLUGIN_FILE_DNG: guidFile = GUID_FILE_DNG; break;
	case XH_TRANS_PLUGIN_FILE_CRM:guidFile = GUID_FILE_CONNON_RAW;break;
	case XH_TRANS_PLUGIN_FILE_R3D : guidFile = GUID_FILE_R3D;break;
	case XH_TRANS_PLUGIN_FILE_BRAW:guidFile = GUID_FILE_BLACKMAGIC_RAW;break;
    case XH_TRANS_PLUGIN_FILE_SEFS: guidFile = GUID_FILE_SEFS; break;
        /*
        case XH_TRANS_FILE_FLASH_EXE:
        break;
        case XH_TRANS_FILE_FLASH_SWF:
        break;
        */
    default:
        break;
    }
    return guidFile;
}

#endif __TPAVFileMapFileTypeFromSbt__Header__
