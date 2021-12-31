
#pragma once

//#ifndef __TP__AVFileMapMediaTypeFrom__Sbt__Header__
//#define __TP__AVFileMapMediaTypeFrom__Sbt__Header__

#include "../include/nle/LinuxTTMedia/File/SBT_TransBaseDefine.h"
#include "../include/nle/LinuxTTMedia/ITTAdaptWinDefine.h"

#include "../include/nle/LinuxTTMedia/File/TPBaseFccDef.h"

DWORD TPAVFileGetFCC(int iID, int iFileId, BITMAPINFOHEADER* bmpInfo, WAVEFORMATEX* wfxInfo)
{
    DWORD dwFOURCC=0;
    switch(iID)
    {
    case XH_TRANS_VIDEO_PNG:
        dwFOURCC=mmioFOURCC('P','N','G','V');
        break;
    case XH_TRANS_VIDEO_RLE:
        dwFOURCC=fccRLE_Video;
        break;
    case XH_TRANS_VIDEO_DV:
        dwFOURCC=mmioFOURCC ('D', 'V', ' ', ' ');//FOURCC('DV  ');
        break;
    case XH_TRANS_VIDEO_DVSD:
        dwFOURCC=mmioFOURCC ('D', 'V', 'S', 'D');// FOURCC('DVSD');
        break;
    case XH_TRANS_VIDEO_DV25:
        dwFOURCC=mmioFOURCC('D','V','2','5');//FOURCC('DV25');
        break;
    case XH_TRANS_VIDEO_DV50:
        dwFOURCC=mmioFOURCC('D','V','5','0');//FOURCC('DV50');
        break;
    case XH_TRANS_VIDEO_DVH5:
        dwFOURCC = mmioFOURCC('D','V','H','5');
        break;
    case XH_TRANS_VIDEO_DVH6:
        dwFOURCC = mmioFOURCC('D','V','H','6');
        break;
    case XH_TRANS_VIDEO_DVHP:
        dwFOURCC = mmioFOURCC('D','V','H','P');
        break;
    case XH_TRANS_VIDEO_CDVC:
        dwFOURCC = mmioFOURCC('C','D','V','C');
        break;
    case XH_TRANS_VIDEO_MPEG4:
        dwFOURCC=mmioFOURCC('M','P','G','4');//FOURCC('MPG4');
        break;
    case XH_TRANS_VIDEO_MPEG4_MSV2:
        dwFOURCC=mmioFOURCC('M','S','V','2');//FOURCC('MSV2');
        break;
    case XH_TRANS_VIDEO_MPEG4_MSV3:
        dwFOURCC=mmioFOURCC('M','S','V','3');//FOURCC('MSV3');
        break;
    case XH_TRANS_VIDEO_MPEG4_DIVXV5:
        dwFOURCC=mmioFOURCC('D','I','V','X');//FOURCC('DIVX');//
        break;
    case XH_TRANS_VIDEO_MPEG4_SONY_PROXY:
        dwFOURCC=mmioFOURCC('P','R','O','X');//FOURCC('PROX');
        break;
        // laizp, 2013.01.14, sdk˵��ͬһ�ָ�ʽ������XVID
    case XH_TRANS_VIDEO_MPEG4_ISO_ASP:
        if (XH_TRANS_FILE_AVI == iFileId
            || XH_TRANS_FILE_RIFF_AVI == iFileId
            || XH_TRANS_FILE_OPDML_AVI == iFileId
            || XH_TRANS_FILE_AVMIXED_AVI2 == iFileId
            || XH_TRANS_FILE_MATROX_AVI == iFileId
            )
            dwFOURCC=mmioFOURCC('X','V','I','D');
        else
            dwFOURCC=mmioFOURCC('I','S','O','A');
        break;
    case XH_TRANS_VIDEO_MPEG4_XVID:
        dwFOURCC=mmioFOURCC('X','V','I','D');//FOURCC('DIVX');//
        break;
    case XH_TRANS_VIDEO_MPEG4_REALMAGIC:
        dwFOURCC= mmioFOURCC('R','M','A','G');//FOURCC('RMAG');
        break;
    case XH_TRANS_VIDEO_MPEG4_ISO:
        dwFOURCC=mmioFOURCC('I','S','O',' ');//FOURCC('ISO ');
        break;
    case XH_TRANS_VIDEO_MPEG4_ISO_SP:
        dwFOURCC=mmioFOURCC('I','S','O','S');//FOURCC('ISOS');
        break;
    case XH_TRANS_VIDEO_MPEG1:
        dwFOURCC=mmioFOURCC('M','P','G','1');//FOURCC('MPG1');
        break;
    case XH_TRANS_VIDEO_MPEG1_VCD:
        dwFOURCC=mmioFOURCC('V','C','D',' ');//FOURCC('VCD ');
        break;
    case XH_TRANS_VIDEO_MPEG2:
        dwFOURCC=mmioFOURCC('M','P','G','2');//FOURCC('MPG2');
        break;
    case XH_TRANS_VIDEO_MPEG2_MPML:
        dwFOURCC=mmioFOURCC('M','P','M','L');//FOURCC('MPML');
        break;
    case XH_TRANS_VIDEO_MPEG2_422PML:
        dwFOURCC=mmioFOURCC('P','M','L',' ');//FOURCC('PML ');
        break;
    case XH_TRANS_VIDEO_MPEG2_MPHL:
        dwFOURCC=mmioFOURCC('M','P','H','L');//FOURCC('MPHL');
        break;
    case XH_TRANS_VIDEO_MPEG2_MPH1440L:
        dwFOURCC=mmioFOURCC('M','1','4','4');//FOURCC('M144');
        break;
    case XH_TRANS_VIDEO_MPEG2_HPHL:
        dwFOURCC=mmioFOURCC('H','P','H','L');//('HPHL');
        break;
    case XH_TRANS_VIDEO_MPEG2_HPH1440L:
        dwFOURCC=mmioFOURCC('H','1','4','4');//FOURCC('H144');
        break;
    case XH_TRANS_VIDEO_MPEG2_DVD:
        dwFOURCC=mmioFOURCC('D','V','D',' ');//FOURCC('DVD ');
        break;
    case XH_TRANS_VIDEO_MPEG2_SVCD:
        dwFOURCC=mmioFOURCC('S','V','C','D');//FOURCC('SVCD');
        break;
    case XH_TRANS_VIDEO_MPEG2_SONY_IMX:
        dwFOURCC=mmioFOURCC('I','M','X',' ');//FOURCC('SIMX');
        break;
    case XH_TRANS_VIDEO_MPEG2_MATROX_I:
        dwFOURCC=mmioFOURCC('I',' ',' ',' ');//FOURCC('I  ');//
        break;
    case XH_TRANS_VIDEO_MPEG2_MATROX_IBP:
        dwFOURCC=mmioFOURCC('I','B','P',' ');//FOURCC('IBP ');
        break;
    case XH_TRANS_VIDEO_WMV:
        dwFOURCC=mmioFOURCC('W','M','V',' ');
        break;
    case XH_TRANS_VIDEO_WMV8:
        dwFOURCC=mmioFOURCC('W','M','V','8');//FOURCC('WMV8');
        break;
    case XH_TRANS_VIDEO_WMV9:
        dwFOURCC=mmioFOURCC('W','M','V','9');//FOURCC('WMV9');
        break;
    case XH_TRANS_VIDEO_REAL:
        dwFOURCC=mmioFOURCC('V','R','E','L');//FOURCC('VREL');
        break;
    case XH_TRANS_VIDEO_REAL9:
        dwFOURCC=mmioFOURCC('R','E','L','9');//FOURCC('REL9');
        break;
    case XH_TRANS_VIDEO_QT:
        dwFOURCC=mmioFOURCC('Q','T',' ',' ');//FOURCC('QT  ');
        break;
    case XH_TRANS_VIDEO_MJPEG:
        dwFOURCC= mmioFOURCC('M','J','P','G');//FOURCC('MJPG');
        break;
    case XH_TRANS_VIDEO_QT_MJPEGA:
        dwFOURCC= fccMJPEG_A;//FOURCC('MJPG');
        break;
    case XH_TRANS_VIDEO_QT_MJPEGB:
        dwFOURCC= fccMJPEG_B;//FOURCC('MJPG');
        break;
    case XH_TRANS_VIDEO_ODML_MJPEG:
        dwFOURCC= fccOdmlMJPEG;
        break;
    case XH_TRANS_VIDEO_BASEBAND:
		{
			if (iFileId == 0x46fcd0db)//r3d
				dwFOURCC = fccR3DV;
			else if (iFileId == XH_TRANS_PLUGIN_FILE_BRAW)
				dwFOURCC = fccBRAW;
			else
				dwFOURCC=mmioFOURCC('S','A','V','I');
		}
        break;
    case XH_TRANS_AUDIO_LPCM:
        dwFOURCC=mmioFOURCC('L','P','C','M');//FOURCC('LPCM');//
        break;
    case XH_TRANS_AUDIO_MP1:
        dwFOURCC=mmioFOURCC('M','P','1',' ');//FOURCC('MP1 ');
        break;
    case XH_TRANS_AUDIO_MP2:
        dwFOURCC= mmioFOURCC('M','P','2',' ');//FOURCC('MP2 ');
        break;
    case XH_TRANS_AUDIO_MP3:
        dwFOURCC=mmioFOURCC('M','P','3',' ');//FOURCC('MP3 ');
        break;
    case XH_TRANS_AUDIO_WMA:
        dwFOURCC=mmioFOURCC('W','M','A',' ');//FOURCC('WMA ');
        break;
    case XH_TRANS_AUDIO_REAL:
        dwFOURCC= mmioFOURCC('A','R','E','L');//FOURCC('AREL');
        break;
    case XH_TRANS_AUDIO_ALAW:
        dwFOURCC=mmioFOURCC('A','L','A','W');//FOURCC('ALAW');
        break;
    case XH_TRANS_AUDIO_AAC: dwFOURCC = fccAAC;break;
    case XH_TRANS_AUDIO_AMR: dwFOURCC=fccAMR;break;
    case XH_TRANS_VIDEO_DNXHD:
    case XH_TRANS_VIDEO_DNX_220X_1080p:
    case XH_TRANS_VIDEO_DNX_145_1080p:
    case XH_TRANS_VIDEO_DNX_220_1080p:
    case XH_TRANS_VIDEO_DNX_220X_720p:
    case XH_TRANS_VIDEO_DNX_220_720p:
    case XH_TRANS_VIDEO_DNX_145_720p:
    case XH_TRANS_VIDEO_DNX_220X_1080i:
    case XH_TRANS_VIDEO_DNX_145_1080i:
    case XH_TRANS_VIDEO_DNX_220_1080i:
    case XH_TRANS_VIDEO_DNX_145_1440_1080i:
    case XH_TRANS_VIDEO_DNX_36_1080p:
    case XH_TRANS_VIDEO_DNX_50_1080i:
        dwFOURCC=mmioFOURCC('A','V','d','n');
        break;
    case XH_TRANS_VIDEO_MPEG4_AVCIntra:
        dwFOURCC = mmioFOURCC('A','V','C','I');
        break;
    case XH_TRANS_VIDEO_MJPEG2000:
        dwFOURCC = mmioFOURCC('m','j','2','k');
        break;
    case XH_TRANS_VIDEO_H263:
        dwFOURCC = mmioFOURCC(' ','2','6','3');
        break;
    case XH_TRANS_VIDEO_SORENSON_H263:
        dwFOURCC = mmioFOURCC('H','2','6','3');
        break;
    case XH_TRANS_VIDEO_MPEG4_H264:
        dwFOURCC = mmioFOURCC('H','2','6','4');
        break;
    case XH_TRANS_AUDIO_AC3:
        dwFOURCC=mmioFOURCC('A','C','3',' ');//FOURCC('AC3 ');
        break;
    case XH_TRANS_AUDIO_DRA:
        dwFOURCC=mmioFOURCC('D','R','A',' ');//FOURCC('DRA ');
        break;
    case XH_TRANS_AUDIO_DTS:
        dwFOURCC=mmioFOURCC('D','T','S',' ');//FOURCC('DRA ');
        break;

    case XH_TRANS_VIDEO_PRORES_PROXY: 
        dwFOURCC=fccPRORES422_PROXY;
        break;
    case XH_TRANS_VIDEO_PRORES_LT: 
        dwFOURCC=fccPRORES422_LT;
        break;
    case XH_TRANS_VIDEO_PRORES_STANDARD: 
        dwFOURCC=fccPRORES422_STANDARD;
        break;
    case XH_TRANS_VIDEO_PRORES_HQ: 
        dwFOURCC=fccPRORES422_HQ;
        break;
    case XH_TRANS_VIDEO_PRORES_4444:
        dwFOURCC=fccPRORES4444;
        break;

	case XH_TRANS_VIDEO_DNXHR:
		dwFOURCC = mmioFOURCC('A','V','x','h');
		break;
	case XH_TRANS_VIDEO_DNXHR_444:
		dwFOURCC = mmioFOURCC('A','V','x','4');
		break;
	case XH_TRANS_VIDEO_DNXHR_HIGH:
		dwFOURCC = mmioFOURCC('A','V','x','H');
		break;
	case XH_TRANS_VIDEO_DNXHR_LOW:
		dwFOURCC = mmioFOURCC('A','V','x','l');
		break;
	case XH_TRANS_VIDEO_DNXHR_HIGH_EXT:
		dwFOURCC = mmioFOURCC('A','V','x','e');
		break ;
	case XH_TRANS_VIDEO_DNXHR_MEDIUM:	
		dwFOURCC = mmioFOURCC('A','V','x','m');
		break;

    case XH_TRANS_VIDEO_PRORES422:
        dwFOURCC=mmioFOURCC('P','R','O','R');//FOURCC('PROR');
        break;
    case XH_TRANS_VIDEO_PRORES422_1080i:
        dwFOURCC=mmioFOURCC('P','R','O','R');//FOURCC('PROR');
        break;
    case XH_TRANS_VIDEO_PRORES422_720p:
        dwFOURCC=mmioFOURCC('P','R','O','R');//FOURCC('PROR');
        break;
    case XH_TRANS_VIDEO_PRORES422_1080p:
        dwFOURCC=mmioFOURCC('P','R','O','R');//FOURCC('PROR');
        break;
    case XH_TRANS_VIDEO_PRORES422_1440_1080p:
        dwFOURCC=mmioFOURCC('P','R','O','R');//FOURCC('PROR');
        break;
    case XH_TRANS_VIDEO_PRORES422_HQ:
        dwFOURCC=mmioFOURCC('P','R','O','H');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_PRORES422_HQ_1080i:
        dwFOURCC=mmioFOURCC('P','R','O','H');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_PRORES422_HQ_720p:
        dwFOURCC=mmioFOURCC('P','R','O','H');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_PRORES422_HQ_1080p:
        dwFOURCC=mmioFOURCC('P','R','O','H');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_PRORES422_HQ_1440_1080p:
        dwFOURCC=mmioFOURCC('P','R','O','H');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_MPEG4_HDCAM_SR:
        dwFOURCC=mmioFOURCC('h','d','r','s');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_MPEG4_MSVC:
        dwFOURCC=mmioFOURCC('V','C','-','1');//FOURCC('PROH');
        break;
    case XH_TRANS_VIDEO_VP8:
        dwFOURCC=fccVP8;
        break;
	case XH_TRANS_PLUGIN_VIDEO_VP9:
		dwFOURCC=fccVP9;
		break;
    case XH_TRANS_AUDIO_IN32:
        dwFOURCC=mmioFOURCC('A','I','3','2');
        break;
    case XH_TRANS_AUDIO_IN24:
        dwFOURCC=mmioFOURCC('A','I','2','4');
        break;
    case XH_TRANS_AUDIO_FL32:
        dwFOURCC=mmioFOURCC('A','F','3','2');
        break;
    case XH_TRANS_AUDIO_FL64:
        dwFOURCC=mmioFOURCC('A','F','6','4');
        break;
	case XH_TRANS_PLUGIN_VIDEO_AVCU_LT: dwFOURCC = mmioFOURCC('A','V','C','L'); break ;
    case XH_TRANS_PLUGIN_VIDEO_AVCU : dwFOURCC = mmioFOURCC('A','V','C','U'); break;
    case XH_TRANS_PLUGIN_VIDEO_XAVC : dwFOURCC = mmioFOURCC('X','A','V','C'); break;
    case XH_TRANS_VIDEO_CanopusHQ_CUVC : dwFOURCC = mmioFOURCC('C','U','V','C'); break;
    case XH_TRANS_VIDEO_MVC : dwFOURCC = mmioFOURCC('M','V','C',' '); break; 
    case XH_TRANS_AUDIO_DDE : dwFOURCC = fccDDE; break;
	case XH_TRANS_PLUGIN_VIDEO_TGA: dwFOURCC = mmioFOURCC('t','g','a',' '); break ;

#ifdef XH_TRANS_PLUGIN_VIDEO_SONY_RAW                     
    case XH_TRANS_PLUGIN_VIDEO_SONY_RAW:
        {
            dwFOURCC=fccSonyRAW; 
            if (bmpInfo)
            {
                if (bmpInfo->biCompression == FCC('XOCN'))
                    dwFOURCC = fccXOCN;
                else if (bmpInfo->biCompression == FCC('OCNS'))
                    dwFOURCC = fccXOCN_ST;
                else if (bmpInfo->biCompression == FCC('OCNL'))
                    dwFOURCC = fccXOCN_LT;
            }
        }
        break;
#endif
#ifdef XH_TRANS_PLUGIN_VIDEO_AVCU_LONGGOP                     
    case XH_TRANS_PLUGIN_VIDEO_AVCU_LONGGOP: dwFOURCC=fccAVCULongGop; break;
#endif
#ifdef XH_TRANS_PLUGIN_VIDEO_XAVC_LONGGOP                     
    case XH_TRANS_PLUGIN_VIDEO_XAVC_LONGGOP: dwFOURCC=fccXAVCLongGop; break;
#endif
#ifdef XH_TRANS_PLUGIN_VIDEO_H265                     
    case XH_TRANS_PLUGIN_VIDEO_H265: dwFOURCC=fccH265; break;
#endif
#ifdef XH_TRANS_AUDIO_DOLBY_WAV                     
    case XH_TRANS_AUDIO_DOLBY_WAV: dwFOURCC=fccDDEWAV; break;
#endif
    case XH_TRANS_AUDIO_IMAADPCM: dwFOURCC=fccIMAD; break;
    case XH_TRANS_AUDIO_EC3: dwFOURCC = fccEC3; break;
    case XH_TRANS_AUDIO_FLAC: dwFOURCC = fccFLAC; break;
    case XH_TRANS_AUDIO_APE: dwFOURCC = fccAPE; break;
    case XH_TRANS_AUDIO_VORBIS: dwFOURCC = fccOGG; break;
    case XH_TRANS_AUDIO_IMA4: dwFOURCC = fccIMA4; break;
    case XH_TRANS_VIDEO_SVQ3: dwFOURCC = fccSVQ3; break;
    case XH_TRANS_AUDIO_DOLBY: dwFOURCC = fccDolby; break;
    case XH_TRANS_PLUGIN_VIDEO_SOBEY_CODEC: dwFOURCC = fccSobeyCodec; break;

    case XH_TRANS_AUDIO_MAC3: dwFOURCC = fccMACE_3_1; break;
    case XH_TRANS_AUDIO_MAC6: dwFOURCC = fccMACE_6_1; break;
	case XH_TRANS_AUDIO_ACE2: dwFOURCC = fccACE_2_1; break;
	case XH_TRANS_AUDIO_ACE8: dwFOURCC = fccACE_8_3; break;
	case XH_TRANS_AUDIO_ADPCM: dwFOURCC = fccADPCM; break;

    case XH_TRANS_VIDEO_V210: dwFOURCC = fccV210; break;
	case XH_TRANS_PLUGIN_AUDIO_TRUEHD: dwFOURCC = mmioFOURCC('D','B','T','H'); break;
	case XH_TRANS_PLUGIN_VIDEO_CLLC: dwFOURCC = mmioFOURCC('C','L','L','C'); break;
	case XH_TRANS_PLUGIN_FILE_DNG:	dwFOURCC = fccDNG; break;
	case XH_TRANS_VIDEO_CanopusHQX :dwFOURCC = mmioFOURCC('C' ,'H','Q' ,'X') ;break;
	case XH_TRANS_PLUGIN_VIDEO_CANON_RAW: dwFOURCC = fccCRM;break;
	case XH_TRANS_PLUGIN_VIDEO_CINEFORM: dwFOURCC = fccCFHD;break;
	case XH_TRANS_PLUGIN_VIDEO_ARRI_RAW: dwFOURCC = fccARRI;break;
	case XH_TRANS_PLUGIN_VIDEO_JpegXS:	dwFOURCC = fccJPXS;break;
	case XH_TRANS_PLUGIN_VIDEO_SPEED_HQ:dwFOURCC = fccSHQ ;break;
	case XH_TRANS_PLUGIN_VIDEO_SSVC:dwFOURCC = fccSSVC ;break;
    case XH_TRANS_PLUGIN_VIDEO_SEVC:dwFOURCC = fccSEVC; break;
    default:
        break;
    }
    return dwFOURCC;
}


DWORD TPAVFileGetFCC(int iID, int iFileId)
{
    return TPAVFileGetFCC(iID, iFileId, NULL, NULL);
}

//#define __TP__AVFileMapMediaTypeFrom__Sbt__Header__