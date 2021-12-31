/*********************************************************
* 文件名　：VXTransBaseDefine.h
* 功能  　：跨平台SDK基本变量和结构体定义
* 创建日期：
* 修改日期：
* 版本号  ：v1.0.0.1

* 索贝数码科技股份有限公司
* All Rights Reserved
**********************************************************/
#ifndef _VX_SDK_BASE_DEFINE_INCLUDED_
#define _VX_SDK_BASE_DEFINE_INCLUDED_

#include <stdint.h>
#include <string.h>

////////////////////////////		媒体ID定义				///////////////////////
///////general
#define VX_TYPE_MEDIA_NONE                 0x0000          //do not produce file
#define VX_TYPE_MEDIA_UNKNOWN              0x0001          //unknown file format
#define VX_TYPE_MEDIA_UNCARE               0x0002          //do not care about the file format

///////Base-band
#define VX_TYPE_VIDEO_BASEBAND             0x0004          //indicate video is RGB/YUV

///////video DV
#define VX_TYPE_VIDEO_DV					0x0010          //DV general
#define VX_TYPE_VIDEO_DVSD					0x0011          //DVCAM or DVSD
#define VX_TYPE_VIDEO_DV25					0x0012          //DVCPRO or DV25
#define VX_TYPE_VIDEO_DV50					0x0013          //DVCPRO50 or DV50
#define VX_TYPE_VIDEO_DVH5                 0x0014          //DVCPROHD 1080/50i
#define VX_TYPE_VIDEO_DVH6                 0x0015          //DVCPROHD 1080/60i
#define VX_TYPE_VIDEO_DVHP                 0x0016          //DVCPROHD 720/50p or 720/60p
#define VX_TYPE_VIDEO_CDVC                 0x0017          //CDVC

///////video MPEG-4
#define VX_TYPE_VIDEO_MPEG4				0x0020          //MPEG4 general
#define VX_TYPE_VIDEO_MPEG4_MSV2			0x0021          //Microsoft MPEG-4 V2
#define VX_TYPE_VIDEO_MPEG4_MSV3			0x0022          //Microsoft MPEG-4 V3
#define VX_TYPE_VIDEO_MPEG4_DIVXV5			0x0023          //DivX MPEG-4 V5
#define VX_TYPE_VIDEO_MPEG4_REALMAGIC		0x0024          //RealMagic ISO MPEG-4
#define VX_TYPE_VIDEO_MPEG4_H264			0x0025          //mpeg4 H264
#define VX_TYPE_VIDEO_MPEG4_MSVC			0x0026          //mpeg4 msvc1
#define VX_TYPE_VIDEO_MPEG4_AVCIntra       0x0027          //mpeg4 AVCIntra
#define VX_TYPE_VIDEO_H263                 0x0028          //h263


#define VX_TYPE_VIDEO_SORENSON_H263		0x002A			//Sorenson H.263

#define VX_TYPE_VIDEO_MVC					0x002B
#define VX_TYPE_VIDEO_MVC_INDEPENDENT		0x002C
#define VX_TYPE_VIDEO_MVC_DEPENDENT		0x002D

///////video MPEG4 ISO
#define VX_TYPE_VIDEO_MPEG4_ISO            0x0030          //ISO MPEG4 general 
#define VX_TYPE_VIDEO_MPEG4_ISO_SP         0x0031          //ISO MPEG4 SP 
#define VX_TYPE_VIDEO_MPEG4_ISO_ASP        0x0032          //ISO MPEG4 ASP 
#define VX_TYPE_VIDEO_MPEG4_SONY_PROXY     0x0033          //SONY Proxy MPEG4
#define VX_TYPE_VIDEO_MPEG4_XVID			0x0034			//XVID

//////video mpeg4 SR
#define VX_TYPE_VIDEO_MPEG4_HDCAM_SR       0x0035          //hcacm_sr

///////video MPEG-1
#define VX_TYPE_VIDEO_MPEG1				0x0040          // MPEG1 - standard
#define VX_TYPE_VIDEO_MPEG1_VCD			0x0041          // MPEG1 - VCD

///////video MPEG-2
#define VX_TYPE_VIDEO_MPEG2				0x0050          // MPEG2 - standard
#define	VX_TYPE_VIDEO_MPEG2_MPML			0x0051          // MPEG2 - MP@ML, 4:2:0
#define	VX_TYPE_VIDEO_MPEG2_422PML			0x0052          // MPEG2 - 422P@ML, 4:2:2 
#define	VX_TYPE_VIDEO_MPEG2_MPHL			0x0053          // MPEG2 - MP@HL, 4:2:0
#define	VX_TYPE_VIDEO_MPEG2_MPH1440L		0x0054          // MPEG2 - MP@H1440L, 4:2:0
#define	VX_TYPE_VIDEO_MPEG2_HPHL			0x0055          // MPEG2 - HP@HL, 4:2:2
#define	VX_TYPE_VIDEO_MPEG2_HPH1440L		0x0056          // MPEG2 - HP@H1440L, 4:2:2
#define	VX_TYPE_VIDEO_MPEG2_DVD			0x0057          // MPEG2 - DVD
#define	VX_TYPE_VIDEO_MPEG2_SVCD			0x0058          // MPEG2 - SVCD

#define	VX_TYPE_VIDEO_MPEG2_SONY_IMX		0x005a          // MPEG2 - SONY IMX format
#define	VX_TYPE_VIDEO_MPEG2_MATROX_I		0x005b          // MPEG2 - Matrox I
#define	VX_TYPE_VIDEO_MPEG2_MATROX_IBP		0x005c          // MPEG2 - Matrox IBP


///////video WMV
#define VX_TYPE_VIDEO_WMV					0x0060          //WMV general
#define VX_TYPE_VIDEO_WMV8					0x0061          //WMV8
#define VX_TYPE_VIDEO_WMV9					0x0062          //WMV9

///////video RealVideo
#define VX_TYPE_VIDEO_REAL				    0x0070          //Real general
#define VX_TYPE_VIDEO_REAL9				0x0071          //Real video 9

///////video QuickTime
#define VX_TYPE_VIDEO_QT                   0x0080          //QuickTime general
#define VX_TYPE_VIDEO_SVQ3					0x0081			//QT SVQ3

///////video png
#define VX_TYPE_VIDEO_PNG                  0x0085          //PNG
#define VX_TYPE_VIDEO_RLE					0x0086			//RLE

///////video M-JPEG
#define VX_TYPE_VIDEO_MJPEG                0x0090          //Motion JPEG
#define VX_TYPE_VIDEO_MJPEG2000            0x0091          //Motion JPEG2000
#define VX_TYPE_VIDEO_QT_MJPEGA			0x0092			//QuickTime Motion-JPEG(format A)
#define VX_TYPE_VIDEO_QT_MJPEGB			0x0093			//QuickTime Motion-JPEG(format B)
#define VX_TYPE_VIDEO_ODML_MJPEG			0x0094			//OpenDML Motion JPEG


//avid dnx
#define VX_TYPE_VIDEO_DNXHD                0x0082         //Avid DNxHD

#define VX_TYPE_VIDEO_DNX_220X_1080p		0x00b1 ///<  1080p, 10 bit, 220 mbps
#define VX_TYPE_VIDEO_DNX_145_1080p		0x00b2 ///<  1080p,  8 bit, 145 mbps
#define VX_TYPE_VIDEO_DNX_220_1080p		0x00b3///<  1080p,  8 bit, 220 mbps
#define VX_TYPE_VIDEO_DNX_220X_720p		0x00b4 ///<  720p,  10 bit, 220 mbps 
#define VX_TYPE_VIDEO_DNX_220_720p			0x00b5///<  720p,  8 bit,  220 mbps
#define VX_TYPE_VIDEO_DNX_145_720p			0x00b6 ///<  720p,  8 bit,  145 mbps
#define VX_TYPE_VIDEO_DNX_220X_1080i		0x00b7 ///<  1080i, 10 bit, 220 mbps
#define VX_TYPE_VIDEO_DNX_145_1080i		0x00b8///<  1080i,  8 bit, 145 mbps
#define VX_TYPE_VIDEO_DNX_220_1080i		0x00b9 ///<  1080i,  8 bit, 220 mbps
#define VX_TYPE_VIDEO_DNX_145_1440_1080i	0x00ba ///<  1080i,  8 bit, 145 mbps, thin raster
#define VX_TYPE_VIDEO_DNX_36_1080p			0x00bb ///<  1080p,  8 bit,  36 mbps
#define VX_TYPE_VIDEO_DNX_50_1080i			0x00bc ///<  1080i,  8 bit,  50 mbps



#define VX_TYPE_VIDEO_DNXHR				0x01b0
#define VX_TYPE_VIDEO_DNXHR_444			0x01b1
#define VX_TYPE_VIDEO_DNXHR_HIGH_EXT		0x01b2
#define VX_TYPE_VIDEO_DNXHR_HIGH			0x01b3
#define VX_TYPE_VIDEO_DNXHR_MEDIUM			0x01b4
#define VX_TYPE_VIDEO_DNXHR_LOW			0x01b5


//Prores Type Defination
#define VX_TYPE_VIDEO_PRORES_PROXY			0x00dc
#define VX_TYPE_VIDEO_PRORES_LT				0x00dd
#define VX_TYPE_VIDEO_PRORES_STANDARD		0x00de
#define VX_TYPE_VIDEO_PRORES_HQ				0x00df
#define VX_TYPE_VIDEO_PRORES_4444			0x00e0
#define VX_TYPE_VIDEO_PRORES_4444XQ			0x00e1

//video v210
#define VX_TYPE_VIDEO_V210                 0x00f0

//Video VP8
#define VX_TYPE_VIDEO_VP8					0x0100

//Video Canopus HQ
#define VX_TYPE_VIDEO_CanopusHQ_CUVC		0x0110
//Video Canopus HQX
#define VX_TYPE_VIDEO_CanopusHQX			0x0111

///////audio 
#define VX_TYPE_AUDIO_LPCM                 0x0410
#define VX_TYPE_AUDIO_MP1                  0x0411
#define VX_TYPE_AUDIO_MP2                  0x0412
#define VX_TYPE_AUDIO_MP3                  0x0413
#define VX_TYPE_AUDIO_WMA                  0x0414
#define VX_TYPE_AUDIO_REAL                 0x0415
#define VX_TYPE_AUDIO_ALAW                 0x0416
#define VX_TYPE_AUDIO_AAC                  0x0417
#define VX_TYPE_AUDIO_AC3                  0x0418
#define VX_TYPE_AUDIO_EC3                  0x041A

// by or 2008.9.10 for quicktime audio info.
#define VX_TYPE_AUDIO_ULAW                 0x0419 // Ulaw 2:1
#define VX_TYPE_AUDIO_MAC3                 0x0420 // MACE 3:1.
#define VX_TYPE_AUDIO_MAC6                 0x0421 // MACE 6:1.
#define VX_TYPE_AUDIO_RAW					0x0424 // raw Samples are stored uncompressed
#define VX_TYPE_AUDIO_MP4					0x0425 // MPEG-4 audio
#define VX_TYPE_AUDIO_DVCA	                0x0426 // DV Audio
#define VX_TYPE_AUDIO_IMA4					0x0427 // IMA 4:1.
					
#define VX_TYPE_AUDIO_NOCOMP				0x0428 // uncompressed	
#define VX_TYPE_AUDIO_FL32					0x0429 // 32-bit floating point	
#define VX_TYPE_AUDIO_FL64					0x0430 // 64-bit floating point	
#define VX_TYPE_AUDIO_IN24                 0x0431 // 24-bit integer
#define VX_TYPE_AUDIO_IN32					0x0432 // 32-bit integer	
#define VX_TYPE_AUDIO_QDM2					0x0433 // QDesign music version 2
#define VX_TYPE_AUDIO_QDMC					0x0434 // QDesign music		
#define VX_TYPE_AUDIO_QCLP					0x0435 // QUALCOMM PureVoice	
#define VX_TYPE_AUDIO_MP3V1				0x0436 // MPEG-1 layer 3, CBR only (pre-QT4.1)
#define VX_TYPE_AUDIO_ADPCM				0x0437 // Microsoft ADPCM-ACM code 2
#define VX_TYPE_AUDIO_IMAADPCM				0x0438 // DVI/Intel IMAADPCM-ACM code 17
#define VX_TYPE_AUDIO_AMR                  0x0439 // amr
#define VX_TYPE_AUDIO_DRA					0x043A // DRA 
#define VX_TYPE_AUDIO_DTS					0x043B // DTS	
#define VX_TYPE_AUDIO_M4A					0x0440 // M4A          
#define VX_TYPE_AUDIO_DDE					0x0441 // DDE--DolbyE .dde文件         
#define VX_TYPE_AUDIO_VORBIS				0x0442 // VORBIS
#define VX_TYPE_AUDIO_FLAC					0x0443 // FLAC
#define VX_TYPE_AUDIO_APE					0x0444 // APE
#define VX_TYPE_AUDIO_ACE2					0x0445 // ACE 2:1
#define VX_TYPE_AUDIO_ACE8					0x0446 // ACE 8:3
#define VX_TYPE_AUDIO_OPUS					0x0447 


#define VX_TYPE_AUDIO_DOLBY                0x0600  // mxf dolby-E audio    
#define VX_TYPE_AUDIO_DOLBY_WAV            0x0601  // wav dolby-E audio,符合smpte 337标准的non-pcm wav文件    

#define VX_TYPE_SUB_DVB					0x701 
#define VX_TYPE_SUB_DVD					0x702          

#define VX_TYPE_DATA_CC					0x710 //Closed caption
#define VX_TYPE_DATA_SRLIVE             0x711 //Sony SRLive Meta

////////////////////////// media file format ID defination  ///////////////////////
/////general
#define VX_TYPE_FILE_NONE                  0x0800     //do not produce file
#define VX_TYPE_FILE_UNKNOWN               0x0801     //unknown file format
#define VX_TYPE_FILE_UNCARE                0x0802     //do not care about the file format

/////AVI file format
#define VX_TYPE_FILE_AVI                   0x0810     // avi file general 
#define VX_TYPE_FILE_RIFF_AVI              0x0811     //.avi
#define VX_TYPE_FILE_OPDML_AVI             0x0812     //.avi
#define VX_TYPE_FILE_AVMIXED_AVI2          0x0813     //.avi, AV mixed           
#define VX_TYPE_FILE_DV_AVI                0x0814

/////video DV diff file format
#define VX_TYPE_FILE_DV_DIFF               0x0820     //.dv

/////video MPEG file format
#define VX_TYPE_FILE_MPEG                  0x0830     // mpg file general
#define VX_TYPE_FILE_MPEG_ES               0x0831     //.m2v, .m2a
#define VX_TYPE_FILE_MPEG_PS               0x0832     //.mpg, .ps
#define VX_TYPE_FILE_MPEG_TS               0x0833     //.mpg, .ts
#define VX_TYPE_FILE_MPEG_DVD              0x0834     //.vob
#define VX_TYPE_FILE_MPEG_VCD              0x0835     //.dat
#define VX_TYPE_FILE_MPEG_SVCD             0x0836     //
#define VX_TYPE_FILE_MPEG_MP4              0x0837     //
#define VX_TYPE_FILE_MPEG_M2P				0x0838     //.m2p
#define VX_TYPE_FILE_MPEG_M2T				0x0839	   //.m2t	

#define VX_TYPE_FILE_MPEG_M4V				0x084A	   //.m4v

/////video WMV file format
#define VX_TYPE_FILE_MS_WMV                0x0840     //.wmv
#define VX_TYPE_FILE_MS_ASF                0x0841     //.asf

/////video RM file format
#define VX_TYPE_FILE_REAL_RM               0x0850     //.rm

/////video QuickTime file format
#define VX_TYPE_FILE_QT_MOV                0x0860     //.mov

/////video MXG
#define VX_TYPE_FILE_PROMPEG_MXF           0x0870     //.mxf
#define VX_TYPE_FILE_IMX_MXF               0x0871     //.mxf

/////broadcast file format, manufacturer oriented
#define VX_TYPE_FILE_MATROX_AVI            0x0880     //.avi
#define VX_TYPE_FILE_SONY_IMX              0x0881     //.mxf
#define VX_TYPE_FILE_SONY_MAV70            0x0882     //.
#define VX_TYPE_FILE_SEACHANGE             0x0883     //.gxf
#define VX_TYPE_FILE_GVG_GXF               0x0884     //.gxf

//file format of 3gp
#define VX_TYPE_FILE_3GP                   0x0890     //.3gp

//file format of ismv
#define VX_TYPE_FILE_ISMV                  0x0895    //.ismv

#define VX_TYPE_FILE_FLV				    0x08B2		//flv
#define VX_TYPE_FILE_F4V				    0x08B3		//f4v

//file picture
#define VX_TYPE_FILE_PIC_BMP				0X8D0		//bmp
#define VX_TYPE_FILE_PIC_JPG				0X8D1		//jpg
#define VX_TYPE_FILE_PIC_TGA				0X8D2		//tga
#define VX_TYPE_FILE_PIC_DPX				0X8D3		//dpx


/////audio file format
#define VX_TYPE_FILE_WAV                   0x0910     //.wav
#define VX_TYPE_FILE_MP1                   0x0911     //.mp1
#define VX_TYPE_FILE_MP2                   0x0912     //.mp2
#define VX_TYPE_FILE_MP3                   0x0913     //.mp3
#define VX_TYPE_FILE_AAC                   0x0915     //.aac
#define VX_TYPE_FILE_WMA                   0x0916     //.wma
#define VX_TYPE_FILE_RMA                   0x0917     //.rm, real audio file
#define VX_TYPE_FILE_DDE                   0x0918     //.dde
#define VX_TYPE_FILE_S48                   0x0922	   //.s48
#define VX_TYPE_FILE_OGG				   0x0923	   //.ogg
#define VX_TYPE_FILE_FLAC                  0x0924	   //.flac
#define VX_TYPE_FILE_APE					0x0925	   //.ape
#define VX_TYPE_FILE_AIFF					0x0926	   //.aif .aiff
#define VX_TYPE_FILE_AC3					0x0927	   //.ac3

#define VX_TYPE_FILE_DVBS					0x0A10

#define VX_TYPE_FILE_MKV					0x0B10		//.mkv
#define VX_TYPE_FILE_WEBM					0x0B11		//.webm
	
#define VX_TYPE_FILE_M4A                   0x0C10	   //.m4a

#define VX_TYPE_FILE_CC                    0x0C12	   //.cc

#define VX_TYPE_FILE_SMTT             0x0C13      //.smtt

#define VX_TYPE_FILE_HLS             0x0C14     //.m3u8



/////////////////////// Plugin File Format ID Defination //////////////////////////////////////////
#define VX_TYPE_PLUGIN_FILE_ID_FLAG		0x46000000

//Plugin H265 Stream File
#define VX_TYPE_PLUGIN_FILE_H265        0x46146091

#define VX_TYPE_PLUGIN_FILE_LXF         0x46FCF855

#define VX_TYPE_PLUGIN_FILE_R3D         0x46FCD0DB

#define VX_TYPE_PLUGIN_FILE_TS          0x46FFF71D

#define VX_TYPE_PLUGIN_FILE_AMR         0x46FDB58A

#define VX_TYPE_PLUGIN_FILE_W64         0x46FC41A0

#define	VX_TYPE_PLUGIN_FILE_TIFF		0x463CF49D

#define VX_TYPE_PLUGIN_FILE_DPX         0x46FE164D

#define VX_TYPE_PLUGIN_FILE_DSD         0x46FCD70D

#define VX_TYPE_PLUGIN_FILE_RF64		0x461063DB

#define VX_TYPE_PLUGIN_FILE_PSD			0x46FCD719

#define VX_TYPE_PLUGIN_FILE_PNG			0x4641767F

#define VX_TYPE_PLUGIN_FILE_GIF			0x46FCF490

#define VX_TYPE_PLUGIN_FILE_DASH		0x4645C28D

#define VX_TYPE_PLUGIN_FILE_KEY			0x46FE2394

#define VX_TYPE_PLUGIN_FILE_EXR			0x46FDB84E

#define VX_TYPE_PLUGIN_FILE_CRM			0x46FD66CC

#define VX_TYPE_PLUGIN_FILE_BRAW	    0x4680A6CB

#define VX_TYPE_PLUGIN_FILE_ARI			0x46FD26CA

#define VX_TYPE_PLUGIN_FILE_VRW			0x46FE06DF

#define VX_TYPE_PLUGIN_FILE_DNG			0x46FD05CD

#define VX_TYPE_PLUGIN_FILE_AMFS		0x4670F58A

#define VX_TYPE_PLUGIN_FILE_SSEQ		0x4668E71C

#define VX_TYPE_PLUGIN_FILE_SSFS		0x4670F71C

/////////////////////// Plugin Video Format ID Defination /////////////////////////////////////////
#define VX_TYPE_PLUGIN_VIDEO_ID_FLAG	0x56000000

//Plugin XAVC-Intra
#define VX_TYPE_PLUGIN_VIDEO_XAVC		0x5631F2A1
//Plugin AVCUltra-Intra
#define VX_TYPE_PLUGIN_VIDEO_AVCU		0x5678C7CA
#define VX_TYPE_PLUGIN_VIDEO_AVCU_LT	0x5655E30A
//Plugin H.265/HEVC
#define VX_TYPE_PLUGIN_VIDEO_H265		0x56146091

//Plugin Sony RAW
#define VX_TYPE_PLUGIN_VIDEO_SONY_RAW   0x56EA46DC
//Sony RAW子类型根据FCC区分
//FCC == mmioFOURCC('S', 'R', 'A', 'W'), General Sony RAW
//FCC == mmioFOURCC('X', 'O', 'C', 'N'), General X-OCN
//FCC == mmioFOURCC('O', 'C', 'N', 'S'), X-OCN ST
//FCC == mmioFOURCC('O', 'C', 'N', 'L'), X-OCN LT

//Plugin XAVC-LongGOP
#define VX_TYPE_PLUGIN_VIDEO_XAVC_LONGGOP  0x5654C7E1
//Plugin AVCUltra-LongGOP
#define VX_TYPE_PLUGIN_VIDEO_AVCU_LONGGOP  0x5655E31F

#define VX_TYPE_PLUGIN_VIDEO_RED_RAW	   0x5680A6DB
//Plugin SobeyCodec
#define VX_TYPE_PLUGIN_VIDEO_SOBEY_CODEC   0x56F25C9C
//Plugin TGA
#define VX_TYPE_PLUGIN_VIDEO_TGA		   0x56FCA41D
//Plugin SpeedHQ
#define VX_TYPE_PLUGIN_VIDEO_SPEED_HQ	   0x56FDA45C	
//Plugin Canopus Lossless
#define VX_TYPE_PLUGIN_VIDEO_CLLC		   0x5631554C
//Plugin Canon RAW
#define VX_TYPE_PLUGIN_VIDEO_CANON_RAW	   0x5680A6CC
//Plugin Arri RAW
#define VX_TYPE_PLUGIN_VIDEO_ARRI_RAW      0x5680A6CA
//Plugin Panasonic RAW
#define VX_TYPE_PLUGIN_VIDEO_PANASONIC_RAW 0x5680A6DF
//Plugin VP9
#define VX_TYPE_PLUGIN_VIDEO_VP9           0x56FC965F
//Plugin VP6
#define VX_TYPE_PLUGIN_VIDEO_VP6	       0x56FC665F
//Plugin VP6F
#define VX_TYPE_PLUGIN_VIDEO_VP6F	       0x563C665F

//Sobey UHDCodec
#define VX_TYPE_PLUGIN_VIDEO_UHDC		   0x5630D45E

// JPEGXS
#define VX_TYPE_PLUGIN_VIDEO_JPXS		   0x56721653

#define VX_TYPE_PLUGIN_VIDEO_SSVC			0x5631F71C	

#define VX_TYPE_PLUGIN_VIDEO_SUVC			0x568391CF

#define VX_TYPE_PLUGIN_VIDEO_AV1           0x56FC17CA

/////////////////////// Plugin Audio Format ID Defination /////////////////////////////////////////
#define VX_TYPE_PLUGIN_AUDIO_ID_FLAG       0x41000000

#define VX_TYPE_PLUGIN_AUDIO_DSD           0x41FCD70D
//Dolby TrueHD
#define VX_TYPE_PLUGIN_AUDIO_TRUEHD	       0x41351D5D


//SMTT SubFileType定义
enum eVXSDKSubFileTypeSMTT
{
	eVXSubFileTypeSMTTMxf = 0,
	eVXSubFileTypeSMTTMp4 = 1,
};

//编码子类型
enum eVXSDKVideoSubMediaType
{
	//H264
	eVXVideoSubMediaTypeH264Native  = 0,
	eVXVideoSubMediaTypeH264NVCodec = 1,
	eVXVideoSubMediaTypeH264Vega550 = 2,
	//H265
	eVXVideoSubMediaTypeH265Native  = 0,
	eVXVideoSubMediaTypeH265NVCodec = 1,
	eVXVideoSubMediaTypeH265Vega550 = 2,
    eVXVideoSubMediaTypeH265Parallel = 3,

	//XAVC
	eVXVideoSubMediaTypeXAVCNative  = 0,
	eVXVideoSubMediaTypeXAVCSony    = 1,
	eVXVideoSubMediaTypeXAVCMatrox  = 2,
	eVXVideoSubMediaTypeXAVCVega550	= 3,

	// AVCU-Intra
	eVXVideoSubMediaTypeAVCUNative		= 0,
	eVXVideoSubMediaTypeAVCUPanasonic	= 1,
	eVXVideoSubMediaTypeAVCUMatrox		= 2,

	//ProRes
	eVXVideoSubMediaTypeProResNative = 0,
	eVXVideoSubMediaTypeProResApple = 1,

	// UHDC保留测试新格式
	eVXVideoSubMediaTypeUHDCNative = 0,
	eVXVideoSubMediaTypeUHDCCuda = 1,

	// JPEGXS
	eVXVideoSubMediaTypeJPXSNative = 0,
	eVXVideoSubMediaTypeJPXSCuda = 1,
	//eVXVideoSubMediaTypeJPXSThirdPartyHF = 2,

	// SSVC
	eVXVideoSubMediaTypeSSVCNative = 0,
	eVXVideoSubMediaTypeSSVCCuda = 1,
	// SUVC
	eVXVideoSubMediaTypeSUVCNative = 0,
	eVXVideoSubMediaTypeSUVCCuda = 1,
	//Baseband
	eVXVideoSubMediaTypeGIF = 0x474946,
};


//视频Profile定义
enum eVXSDKVideoProfile
{
	//H264Profile
	eVXVideoProfileH264BaseLine = 66,
	eVXVideoProfileH264Main = 77,
	eVXVideoProfileH264Extended = 88,
	eVXVideoProfileH264High = 100,
	eVXVideoProfileH264High10 = 110,
	eVXVideoProfileH264High422 = 122,
	eVXVideoProfileH264High444 = 144,
	//H265Profile
	eVXVideoProfileH265Main = 1,
	eVXVideoProfileH265Main10 = 2,

	//XAVCIntraProfile
	eVXVideoProfileXAVCIntraCBG100 = 1,  //10Bit 422 幅面支持 2048x1080 1920x1080 1280x720 
	eVXVideoProfileXAVCIntraCBG300 = 2,  //10Bit 422 幅面支持 4096x2160 3840x2160
	eVXVideoProfileXAVCIntraVBR300 = 4,  //10Bit 422 幅面支持 4096x2160 3840x2160
	eVXVideoProfileXAVCIntraCBG480 = 5,  //10Bit 422 幅面支持 4096x2160 3840x2160
	eVXVideoProfileXAVCIntraVBR480 = 6,  //10Bit 422 幅面支持 4096x2160 3840x2160
	//XAVCLongGOPProfile
	eVXVideoProfileXAVCLongGOP25M = 11, //10Bit 422 幅面支持 1920x1080
	eVXVideoProfileXAVCLongGOP35M = 12, //10Bit 422 幅面支持 1920x1080
	eVXVideoProfileXAVCLongGOP50M = 13, //10Bit 422 幅面支持 1920x1080
	eVXVideoProfileXAVCLongGOP100M = 15, //10Bit 422 幅面支持 3840x2160
	eVXVideoProfileXAVCLongGOP140M = 16, //10Bit 422 幅面支持 3840x2160
	eVXVideoProfileXAVCLongGOP200M = 17, //10Bit 422 幅面支持 3840x2160 

	//AVCUIntraProfile
	eVXVideoProfileAVCUIntraCBG50 = 1,
	eVXVideoProfileAVCUIntraCBG100 = 2,
	eVXVideoProfileAVCUIntraCBG200 = 3,

	//AVCULongGOPProfile
	eVXVideoProfileAVCULongGOP6M = 1,
	eVXVideoProfileAVCULongGOP12M = 2,
	eVXVideoProfileAVCULongGOP25M = 3,
	eVXVideoProfileAVCULongGOP50M = 4,

	//MPEG2Profile
	eVXVideoProfileMPEG2High = 1,
	eVXVideoProfileMPEG2Main = 2,
	eVXVideoProfileMPEG2Simple = 3,
	eVXVideoProfileMPEG2422 = 4,
	eVXVideoProfileMPEG2XDCAM = 100,
	eVXVideoProfileMPEG2IMX = 101,

	//UHDC保留测试新格式
	eVXVideoProfileUHDCMain = 1,	// 5-1
	eVXVideoProfileUHDCLight = 2,	// 5-0
	eVXVideoProfileUHDCHigh = 3,	// 5-2

	//JpegXs
	eVXVideoProfileJpXsCBR300 = 1, // 4K画面对应500M码率, 8K幅面对应2000M码率
	eVXVideoProfileJpXsCBR480 = 2, // 4K画面对应800M码率, 8K幅面对应3200M码率

	// SSVC
	eVXVideoProfileSsvcCBR300 = 1,
	eVXVideoProfileSsvcCBR480 = 2,

	//AVCIntraProfile
    eVXVideoProfileClass50  = 1,
    eVXVideoProfileClass100 = 2,
    eVXVideoProfileClass200 = 3,
};

//视频Level定义
enum eVXSDKVideoLevel
{
	//H264Level
	eVXVideoLevelH264_1 = 10,
	eVXVideoLevelH264_11 = 11,
	eVXVideoLevelH264_12 = 12,
	eVXVideoLevelH264_13 = 13,
	eVXVideoLevelH264_2 = 20,
	eVXVideoLevelH264_21 = 21,
	eVXVideoLevelH264_22 = 22,
	eVXVideoLevelH264_23 = 23,
	eVXVideoLevelH264_3 = 30,
	eVXVideoLevelH264_31 = 31,
	eVXVideoLevelH264_32 = 32,
	eVXVideoLevelH264_33 = 33,
	eVXVideoLevelH264_4 = 40,
	eVXVideoLevelH264_41 = 41,
	eVXVideoLevelH264_42 = 42,
	eVXVideoLevelH264_5 = 50,
	eVXVideoLevelH264_51 = 51,
	eVXVideoLevelH264_Auto = -1,
	//H265Level
	eVXVideoLevelH265_1 = 10,
	eVXVideoLevelH265_2 = 20,
	eVXVideoLevelH265_21 = 21,
	eVXVideoLevelH265_3 = 30,
	eVXVideoLevelH265_31 = 31,
	eVXVideoLevelH265_4 = 40,
	eVXVideoLevelH265_41 = 41,
	eVXVideoLevelH265_5 = 50,
	eVXVideoLevelH265_51 = 51,
	eVXVideoLevelH265_52 = 52,
	eVXVideoLevelH265_6 = 60,
	eVXVideoLevelH265_61 = 61,
	eVXVideoLevelH265_62 = 62,
	eVXVideoLevelH265_85 = 85,
	eVXVideoLevelH265_Auto = -1,

	//MPEG2Level
	eVXVideoLevelMPEG2_Low     = 10,
	eVXVideoLevelMPEG2_Main    = 8,
	eVXVideoLevelMPEG2_High144 = 6,
	eVXVideoLevelMPEG2_High    = 4,
	eVXVideoLevelMPEG2_Auto    = -1,

	//JpegXs Level
	eVXVideoLevelJpXs_Auto = 0, // 默认为eVXVideoLevelJpXs_52
	eVXVideoLevelJpXs_50   = 1,
	eVXVideoLevelJpXs_51   = 2,
	eVXVideoLevelJpXs_52   = 3, // 推荐使用, 支持多种画面输出，GPU解码速度快
	eVXVideoLevelJpXs_11   = 4, // 仅针对SSVC有效
};

//视频编码速度定义
enum eVXSDKVideoEncSpeed
{
	eVXVideoEncSpeedAuto = 0,
	eVXVideoEncSpeedUltrafast = 1,
	eVXVideoEncSpeedSuperfast = 2,
	eVXVideoEncSpeedVeryfast = 3,
	eVXVideoEncSpeedFaster = 4,
	eVXVideoEncSpeedFast = 5,
	eVXVideoEncSpeedNormal = 6,
	eVXVideoEncSpeedSlow = 7,
	eVXVideoEncSpeedSlower = 8,
	eVXVideoEncSpeedVerySlow = 9,
};

//音频编码子类型
enum eVXSDKAudioSubMediaType
{

};


//音频编码Profile定义
enum eVXSDKAudioProfile
{
	//AAC Profile
	eVXAudioProfileAAC_MPEG4_LC = 2,
	eVXAudioProfileAAC_MPEG4_HE_AAC = 5,
	eVXAudioProfileAAC_MPEG4_HE_AAC_V2 = 29,
	eVXAudioProfileAAC_MPEG2_LC = 129,
	eVXAudioProfileAAC_MPEG2_HE_AAC = 132,
	eVXAudioProfileAAC_MPEG2_HE_AAC_V2 = 156,

};


//文件Stream流类型定义
enum eVXSDKDataStreamType
{
	eVXSDKStreamTypeUnknown = 0,
	eVXSDKStreamTypeVideo,
	eVXSDKStreamTypeAudio,
	eVXSDKStreamTypeSystem,
	eVXSDKStreamTypeData,
};

//基带Buffer数据类型定义
enum eVXSDKBufferType
{
	eVXBufferTypeCPUBuffer    = 0,
	eVXBufferTypeOpenCLBuffer,
	eVXBufferTypeCUDABuffer,
	eVXBufferTypeOpenGLBuffer,
};

// 基带buffer数据子类型定义
enum eVXSDKBufferSubType
{
	// CUDA存储类型
	eVXBufferSubTypeCUDAPinnedBuffer = 0,
	eVXBufferSubTypeCUDADevicePtr	 = 1,
	eVXBufferSubTypeCUDAArray2D		 = 2,
	eVXBufferSubTypeCUDAArray3D		 = 3,
	eVXBufferSubTypeCUDATextureObj	 = 4,
	eVXBufferSubTypeCUDATSurfaceObj  = 5,

	// OPENGL存储类型
	eVXBufferSubTypeOpenGLBufferObj  = 0,
	eVXBufferSubTypeOpenGLTextureObj = 1,
};

//视频的色彩空间定义
enum eVXSDKVideoColorSpaceFormat
{
	eVXVideoCsFmtUnknown = 0,
	eVXVideoCsFmtYUV420P,
	eVXVideoCsFmtYUYV,
	eVXVideoCsFmtUYVY,
	eVXVideoCsFmtYUV422,
	eVXVideoCsFmtYUV422P,
	eVXVideoCsFmtYUV422P10LE,
	eVXVideoCsFmtYUV444P,
	eVXVideoCsFmtRGB,
	eVXVideoCsFmtRGBA,
	eVXVideoCsFmtARGB,
	eVXVideoCsFmtBGR,
	eVXVideoCsFmtBGRA,
	eVXVideoCsFmtABGR,
	eVXVideoCsFmtNV12,
	eVXVideoCsFmtYUV420P10LE,
	eVXVideoCsFmtNV16,
	eVXVideoCsFmtYUYV10LE,
	eVXVideoCsFmtYUV444P10LE,
	eVXVideoCsFmtP010BE,
	eVXVideoCsFmtUYVY10LE,
	eVXVideoCsFmtYUYV10BE,
	eVXVideoCsFmtYUV420P16,
	eVXVideoCsFmtYUVA4444,
	eVXVideoCsFmtYUVA4444P10LE,
	eVXVideoCsFmtYUVA4444P10BE,
	eVXVideoCsFmtYUVA4444P16,
	eVXVideoCsFmtYUV411P,
	eVXVideoCsFmtYV12,
	eVXVideoCsFmtV210LE,
	eVXVideoCsFmtYUVA,
	eVXVideoCsFmtYUVA10LE,
	eVXVideoCsFmtYUVA10BE,
	eVXVideoCsFmtUYVY10BE,
	eVXVideoCsFmtRGB10BE,
	eVXVideoCsFmtBGR10BE,
	eVXVideoCsFmtRGB10LE,
	eVXVideoCsFmtBGR10LE,
	eVXVideoCsFmtRGBA10BE,
	eVXVideoCsFmtBGRA10BE,
	eVXVideoCsFmtRGBA10LE,
	eVXVideoCsFmtBGRA10LE,
	eVXVideoCsFmtRGB8,
	eVXVideoCsFmtYUV422P16,
	eVXVideoCsFmtYUV422P10BE,
	eVXVideoCsFmtGRAY,
    eVXVideoCsFmtGRAY10LE,
	eVXVideoCsFmtGRAY12LE,
    eVXVideoCsFmtYUV420P12LE,
    eVXVideoCsFmtYUV422P12LE,
    eVXVideoCsFmtYUV444P12LE,
};

//视频YUV采样定义
enum eVXSDKVideoChroma
{
	eVXVideoChromaUnknown = 0,
	eVXVideoChroma420,
	eVXVideoChroma422,
	eVXVideoChroma411,
	eVXVideoChroma444,
    eVXVideoChroma400,
};

//视频宽高比定义
enum eVXSDKVideoAspectRatio
{
	eVXVideoAspectRatioUnknown = 0,
	eVXVideoAspectRatio1_1,
	eVXVideoAspectRatio4_3,
	eVXVideoAspectRatio16_9,
	eVXVideoAspectRatio2_21_1,
	eVXVideoAspectRatio5_4,
	eVXVideoAspectRatio3_2,
	eVXVideoAspectRatio256_135,
};

//视频扫描类型定义
enum eVXSDKVideoScanType
{
	eVXVideoScanTypeUnknown = 0,
	eVXVideoScanTypeProgressive,
	eVXVideoScanTypeInterlaced,
};

//视频隔行扫描顺序定义
enum eVXSDKVideoScanOrder
{
	eVXVideoScanOrderUnknown = 0,
	eVXVideoScanOrderTopFieldFirst,
	eVXVideoScanOrderBottomFieldFirst,
};

//视频旋转信息定义
enum eVXSDKVideoRotation
{
	eVXVideoRotation00 = 0,
	eVXVideoRotation90,
	eVXVideoRotation180,
	eVXVideoRotation270,
};


//视频HDR信息Range定义
enum eVXSDKVideoRangeFlags
{
	//Unknown
	eVXVideoRangeFlagsUnknown = 0,
	//Full Range
	eVXVideoRangeFlagsFull = 1,
	//Narrow Range
	eVXVideoRangeFlagsNarrow = 2,
};

//视频HDR信息颜色空间定义
enum eVXSDKVideoColourPrimaries
{
	//Unknown
	eVXVideoColourPrimaries_Unknown = 0,
	//Rec. ITU-R BT.709
	eVXVideoColourPrimaries_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application
	eVXVideoColourPrimaries_Unspecified = 2,
	//ITU-R Rec. BT.601
	eVXVideoColourPrimaries_BT_601_625 = 5,
	//ITU-R Rec. BT.601
	eVXVideoColourPrimaries_BT_601_525 = 6,
	//Rec. ITU-R BT.2020
	eVXVideoColourPrimaries_BT_2020 = 9,
	//Sony S-Gamut Color Space
	eVXVideoColourPrimaries_SGamut = 100,
	//Sony S-Gamut3 Color Space
	eVXVideoColourPrimaries_SGamut3 = 101,
	//Sony S-Gamut3.Cine Color Space
	eVXVideoColourPrimaries_SGamut3Cine = 102,
	//Canon Cinema Gamut
	eVXVideoColourPrimaries_Canon_Cinema_Gamut = 110,
	//RED Wide Gamut RGB
	eVXVideoColourPrimaries_RED_Wide_Gamut = 120,
	//DJI D-Gamut
	eVXVideoColourPrimaries_DJI_DGamut = 130,
	//Panasonic V-Gamut
	eVXVideoColourPrimaries_VGamut = 200,
	//Arri Wide Gamut RGB
	eVXVideoColourPrimaries_Arri_Wide_Gamut = 210,
};


//视频HDR信息OETF转换特性定义
enum eVXSDKVideoTransferCharacteristic
{
	//Unknown
	eVXVideoTransferCharacteristic_Unknown = 0,
	//Rec. ITU-R BT.709
	eVXVideoTransferCharacteristic_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application.
	eVXVideoTransferCharacteristic_Unspecified = 2,
	//display gamma 2.2
	eVXVideoTransferCharacteristic_GAMMA22 = 4,
	//display gamma 2.8
	eVXVideoTransferCharacteristic_GAMMA28 = 5,
	//ITU-R Rec. BT.601
	eVXVideoTransferCharacteristic_BT_601 = 6,
	//Linear transfer characteristics
	eVXVideoTransferCharacteristic_LINEAR = 8,
	//Logarithmic transfer characteristic(100:1 range)
	eVXVideoTransferCharacteristic_LOG = 9,
	//Logarithmic transfer characteristic(100 * Sqrt(10) : 1 range)
	eVXVideoTransferCharacteristic_LOG_SQRT = 10,
	//display gamma 2.4
	eVXVideoTransferCharacteristic_GAMMA24 = 13,
	//Rec. ITU-R BT.2020-2 for 10-bit system
	eVXVideoTransferCharacteristic_BT_2020_10BIT = 14,
	//Rec. ITU-R BT.2020-2 for 12-bit system
	eVXVideoTransferCharacteristic_BT_2020_12BIT = 15,
	//Rec. ITU-R BT.2100-0 perceptual quantization (PQ) system
	eVXVideoTransferCharacteristic_BT_2100_PQ = 16,
	//Rec. ITU-R BT.2100-0 hybrid loggamma (HLG) system
	eVXVideoTransferCharacteristic_BT_2100_HLG = 18,
	//Sony S-Log2(/S-Gamut)
	eVXVideoTransferCharacteristic_SLog2 = 100,
	//Sony S-Log3(/S-Gamut3 Or S-Gamut3.Cine)
	eVXVideoTransferCharacteristic_SLog3 = 101,
	//Sony S-Log3(Live)
	eVXVideoTransferCharacteristic_SLog3_Live = 102,
	//Canon Log
	eVXVideoTransferCharacteristic_CLog = 110,
	//Canon Log 2
	eVXVideoTransferCharacteristic_Clog_2 = 111,
	//Canon Log 3
	eVXVideoTransferCharacteristic_Clog_3 = 112,
	//RED LOG3G10
	eVXVideoTransferCharacteristic_RED_LOG3G10 = 120,
	//DJI D-Log
	eVXVideoTransferCharacteristic_DJI_DLOG	   = 130,
	//Panasonic V-Log
	eVXVideoTransferCharacteristic_VLog = 200,
	//Arri ALEXA Log C Curve
	eVXVideoTransferCharacteristic_Alexa_LogC = 210,
	//BT.2100 HLG(OETF Only)
	eVXVideoTransferCharacteristic_BT_2100_HLG_SCENE = 228,
	//display gamma 2.6
	eVXVideoTransferCharacteristic_GAMMA26 = 230,
};

//视频HDR信息矩阵转换系数定义
enum eVXSDKVideoMatrixCoefficients
{
	//Unknown
	eVXVideoMatrixCoefficients_Unknown = 0,
	//ITU-R Rec. BT.709
	eVXVideoMatrixCoefficients_BT_709 = 1,
	//Image characteristics are unknown or are determined by the application
	eVXVideoMatrixCoefficients_Unspecified = 2,
	//ITU-R Rec. BT.601
	eVXVideoMatrixCoefficients_BT_601_625 = 5,
	//ITU-R Rec. BT.601
	eVXVideoMatrixCoefficients_BT_601_525 = 6,
	//Rec. ITU-R BT.2020-2 non-constant luminance system
	eVXVideoMatrixCoefficients_BT_2020_NCL = 9,
	//Rec. ITU-R BT.2020-2 constant luminance system
	eVXVideoMatrixCoefficients_BT_2020_CL = 10,
};



//视频解码器工作模式定义
enum eVXSDKVideoDecoderWorkMode
{
	eVXVideoDecoderWorkModeUnknown = 0,
	eVXVideoDecoderWorkModeCloseGopAsync,
	eVXVideoDecoderWorkModeOpenGopAsync,
	eVXVideoDecoderWorkModeSync,
};

//视频帧类型定义
enum eVXSDKVideoFrameType
{
	eVXVideoFrameTypeUnknown  = 0x00,
	eVXVideoFrameTypeIFrame   = 0x01,
	eVXVideoFrameTypePFrame   = 0x02,
	eVXVideoFrameTypeBFrame   = 0x03,
	eVXVideoFrameTypeIDRFrame = 0x05,
};


//音频位置信息描述定义
enum eVXSDKAudioChannelPosition
{
	eVXAudioChannelPositionUnknown = 0x0,
	eVXAudioChannelPositionFrontLeft,       //L
	eVXAudioChannelPositionFrontRight,      //R
	eVXAudioChannelPositionFrontCenter,     //C
	eVXAudioChannelPositionLowFrequency,    //LFE
	eVXAudioChannelPositionLeftSurround,    //Ls
	eVXAudioChannelPositionRightSurround,   //Rs
	eVXAudioChannelPositionLeftCenter,      //Lc
	eVXAudioChannelPositionRightCenter,     //Rc
};

//常用音频流声道信息描述定义
enum eVXSDKAudioChannelLayout
{
	eVXAudioChannelLayoutMono     = 0x00000003,  //单声道    C
	eVXAudioChannelLayoutStereo   = 0x00000021,  //立体声    L R
	eVXAudioChannelLayoutWAVE_5_1 = 0x00654321,  //WAVE 5.1  L R C LFE Ls Rs
	eVXAudioChannelLayoutWAVE_7_1 = 0x87654321,  //WAVE 7.1  L R C LFE Ls Rs Lc Rc
};

//音频打包方式定义
enum eVXSDKAudioPackMode
{
	eVXAudioPackModeUnknown = 0,
	//音频输出是交错模式
	eVXAudioPackModeInterleaved,
	//音频输出是分片模式
	eVXAudioPackModePlanar,
};

//音频解码的类型
enum eVXSDKAudioSampleType
{
	eVXAudioSampleTypeUnknown = 0,
	eVXAudioSampleType_8BitInt,
	eVXAudioSampleType_16BitInt,
	eVXAudioSampleType_24BitInt,
	eVXAudioSampleType_32BitInt,
	eVXAudioSampleType_32BitFloat,
	eVXAudioSampleType_64BitFloat,
	eVXAudioSampleType_16BitIntBigEndian,
	eVXAudioSampleType_24BitIntBigEndian,
	eVXAudioSampleType_32BitIntBigEndian,
	eVXAudioSampleType_32BitFloatBigEndian,
};

//编码OutputFormat定义
enum eVXSDKAudioOutputFormat
{
	//AAC OutputFormat
	eVXAudioOutputFormatAAC_RAW = 0,
	eVXAudioOutputFormatAAC_ADTS = 1,
};



//音视频基带数据信息定义
struct stVXSDKFrame
{
#define VX_MAX_DATA_NUM		4	

	//视频音频分片数据地址
	//备注：
	//限制条件(目前音频不支持分片)
	unsigned char *pData[VX_MAX_DATA_NUM];

	//视音频分片数据每行的大小
	//如果是视频数据对应YUV分量的跨度
	//如果是音频数据对应的是音频数据的总大小
	int nDataLineSize[VX_MAX_DATA_NUM];

	//数据类型定义eVXSDKBufferType
	int nBufferType;

	//数据Buffer的相应附属信息
	void* pDeviceID;
	void* pContext;

	//数据相应参数定义值参考eVXSDKDataStreamType
	int nDataStreamType;

	//数据流ID
	int nStreamIdx;

	//视频相关参数

	//视频的高度
	int nWidth;
	//视频的宽度
	int nHeight;

	//视频扫描类型 定义值参看:eVXVideoScanType
	int nScanType;
	//视频扫描顺序 定义值参看:eVXVideoScanOrder
	int nScanOrder;

	//帧率分子
	int nFrameRateNum;
	//帧率分母
	int nFrameRateDen;

	//HDR相应参数
	int nHDRColorInfoValid;
	int nColorRange;
	int nColorPrimaries;
	int nColorTransferCharacteristic;
	int nColorMatrixCoefficients;

	int nReserved1[59];


	//音频相关参数

	//音频采样率
	int nSampleRate;
	//音频的Sample数
	int nNumberSamples;
	//声道数
	int nChannels;
	//声道映射关系
	int64_t llChannelLayout;

	//音频存放方式(目前只支持eVXAudioPackModeInterleaved)
	int nAudioPackMode;

	int nReserved2[32];

	//Frame格式类型
	//视频对应的参数为:eVXSDKVideoColorSpaceFormat
	//音频对应的参数为:eVXSDKAudioSampleType
	int nFormat;

	//时间戳相应参数
	int64_t llTimeScale;
	int64_t llTimeDuration;
	int64_t llPts;
	int64_t llDts;


	//编码器生效
	//置1时将一帧强制编码为关键帧，0由编码器自动判断
	int nKeyFrame;

	//用户的私有数据
	void *pOpaqueData;
	//帧数据使用完毕后的通知回调
	void(*VXFrameCompletionCB)(void *pOpaqueData);
	//备注: 以上两个参数设置后内部会默认当前内存地址一直有效, 内部使用完毕后通过回调通知

	int nLtc;
	int nVitc;
	int nAfd;

	int nReserved3[25];

	stVXSDKFrame()
	{
		memset(this, 0, sizeof(stVXSDKFrame));
	}
};

struct stVXSDKStreamSideData
{
    unsigned char *pSideData;
    int nSideDataSize;
    int nSideDataType;
};

//视音频编码帧数据
struct stVXSDKBitStream
{
	unsigned char *pData;

	int nDataLen;

	//帧数据类型
	int nDataStreamType;
	int nStreamIdx;

	//数据帧类型
	//视频帧类型定义参看: eVXSDKVideoFrameType
	int nDataFrameType;

	//时间戳相应参数
	int64_t llTimeScale;
	int64_t llTimeDuration;
	int64_t llPts;
	int64_t llDts;

	//用户的私有数据
	void *pOpaqueData;
	//帧数据使用完毕后的通知回调
	void(*VXBitStreamCompletionCB)(void *pOpaqueData);
	//备注: 以上两个参数设置后内部会默认当前内存地址一直有效, 内部使用完毕后通过回调通知

	void *pFrame;

	int nLtc;
	int nVitc;
	int nAfd;

    stVXSDKStreamSideData *pSideData;
    int nSideDataCount;

	int nReserved[4];

	stVXSDKBitStream()
	{
		memset(this, 0, sizeof(stVXSDKBitStream));
	}
};



struct stVXSDKFileMediaInfo
{
	//文件名(按UTF8存储)
	const char *cFileName;
	//文件大小
	int64_t llFileSize;
	//文件长度单位
	int nFileTimeScale;
	//文件总长度(以长度单位为基准)
	int64_t llFileTimeDuration;

	//边采边编标志
	int nFileGrowing;

	//文件格式ID
	int nFileFormatID;
	//文件子类型
	int nSubFileType;
	//文件FourCC
	int nFileFourCC;
	//文件总码率
	int nFileBitrate;

	const char *cCompanyName;

	const char *cProductName;

	const char *cProductVersion;

	int nDropTimeCodeFlags;

	int64_t llStartTimecode;

	//分段长度（以帧为单位）
	int nSegmentDuration;

	//文件public权限
	int nPublic;

	int nReserved[30];

	stVXSDKFileMediaInfo()
	{
		memset(this, 0, sizeof(stVXSDKFileMediaInfo));
	}
};



//CameraMeta信息定义
struct stVXSDKVideoCameraMetaInfo
{
	//ISO值
	float	fISO;
	//白平衡色温
	float	fWhiteBalanceKelvin;
	//白平衡色调
	float	fWhiteBalanceTint;
	//曝光值
	float	fEV;
	//红色增益值
	float	fGainRed;
	//绿色增益值
	float	fGainGreen;
	//蓝色增益值
	float	fGainBlue;
	//饱和度
	float	fSaturation;
	//对比度
	float	fContrast;
	//亮度
	float	fBrightness;
	//高光控制
	float	fDRX;
	//阴影控制
	float	fShadow;
	//ISO微调控制
	float	fFLUT;

	stVXSDKVideoCameraMetaInfo()
	{
		memset(this, 0, sizeof(stVXSDKVideoCameraMetaInfo));
	}
};

//视频流信息定义
struct stVXSDKVideoStreamInfo
{
	int nMediaID;
	int nSubMediaType;
	int nFourCC;
	int nProfile;
	int nLevel;

	int nFrameNum;

	int nTimeScale;
	int64_t llTimeDuration;

	//变帧率标志
	int nVariableFrameRate;

	//GOP信息
	int nGopLen;
	int nIFrameCount;
	int nPFrameCount;
	int nBFrameCount;

	int nReserved1[28];

	//可变GOP的最大长度(编码有效)
	int nMaxGopSize;
	//可变GOP的最小长度(编码有效)
	int nMinGopSize;
	//B帧数目(编码有效)
	int nBframes;

	//码率模式
	//0 CBR
	//1 VBR 
	int nBitrateMode;
	//平均码率(单位为Kbps)
	int nBitrate;
	//最大码率(单位为Kbps)
	int	nMaxBitrate;

	//视频宽度
	int nWidth;
	//视频高度
	int nHeight;
	//视频位深
	int nBitDepth;

	//定义值参看:eVXSDKVideoColorSpaceFormat
	int nVideoFormat;

	//常见帧率组合
	//23.976:	24000 / 1001
	//24:		24	  /    1
	//25:		25    /    1
	//29.97:	30000 / 1001
	//30:		30    /    1
	//50:	    50    /    1
	//59.94:	60000 / 1001
	//60:	    60    /    1
	int nFrameRateNum;
	int nFrameRateDen;

	//定义值参看:eVXSDKVideoChroma
	int nChroma;
	//定义值参看:eVXSDKVideoAspectRatio
	int nAspectRatio;
	//定义值参看:eVXSDKVideoScanType
	int nScanType;
	//定义值参看:eVXSDKVideoScanOrder
	int nScanOrder;

	int nAFD;

	//定义值参看:eVXSDKVideoRotation
	int nRotation;

	//HDR相应参数
	int nHDRColorInfoValid;
	int nColorRange;
	int nColorPrimaries;
	int nColorTransferCharacteristic;
	int nColorMatrixCoefficients;

	//ST2086静态元数据信息标志位(0:无效 1:有效)
	int nMasteringDisplayColourFlags;

	int nRedPrimaries_x;
	int nRedPrimaries_y;
	int nGreenPrimaries_x;
	int nGreenPrimaries_y;
	int nBluePrimaries_x;
	int nBluePrimaries_y;
	int nWhitePoint_x;
	int nWhitePoint_y;
	int nMaxDisplayLuminance;
	int nMinDisplayLuminance;

	//CamaraMetadata信息
	int nCamaraMetadataVaild;
	stVXSDKVideoCameraMetaInfo stCameraMetadata;

	//视频解码工作方式(eVXSDKVideoDecoderWorkMode)
	int nDecoderWordMode;

	int nReserved2[25];

	//视频编解码时数据Buffer优先使用方式 eVXSDKBufferType
	int nBufferType;

	//数据Buffer的相应附属信息
	void* pDeviceID;
	void* pContext;

	//并行编解码模式(针对Intra格式)(0:关闭 1:打开)
	int nParallelCodecMode;

	//并行编解码个数
	int nParallelCodecInstanceNum;

	//速度(编码有效)
	int nSpeed;
	//编解码设置线程数(编码有效)
	int nThreadNum;


	//编码高级参数

	//参考帧数目
	int nRefFrameNum;
	//VBV的大小
	int nVBVBufferSize;
	//一帧中的Slice数目
	int	nMaxSliceNum;
	//显示比例
	int	nSarWidth;
	int	nSarHeight;
	//是否进行转场检测
	int nSceneDetect;
	//按ANNEXB方式输出码流
	int nAnnexb;
	//在码流中增加AUD
	int	nAUD;
	//是否使用deblocking方式
	int nDeblocking;
	//编码器进行内容检测的帧数
	int nDelayFrames;
	int nPyramid;
	int nCabac;
	int nHrd;
	int nPicStructPresent;
	int	nSpsID;
	int nPpsID;

	int nReserved3[64];

	stVXSDKVideoStreamInfo()
	{
		memset((void*)this, 0, sizeof(stVXSDKVideoStreamInfo));
	}
};

//通用音频流信息定义
struct stVXSDKAudioStreamInfo
{
	int nMediaID;
	int nSubMediaType;
	int nFourCC;

	int nFrameNum;
	int	nTimeScale;
	int64_t llTimeDuration;

	int nReserved1[32];

	//音频类型
	int nProfile;

	//音频采样率
	int nSamplesPerSec;
	//音频声道数
	int nChannels;
	//音频位宽
	int nBitsPerSample;
	//音频码率（单位为kbps）
	int nBitrate;
	//1: VBR方式
	int nVBR;

	// 0不存在LFE
	// 1  存在LFE 
	int nLfeFlag;

	//声道映射
	int64_t llChannelLayout;

	int nLangName;

	//音频每帧的大小(-1表示每帧大小不固定)
	int nFrameSize;

	//音频每帧的采样点个数
	int nSamplesPerFrame;

	//音频打包方式(eVXSDKAudioPackMode)
	int nAudioPackMode;

	//音频格式(eVXSDKAudioSampleType)
	int nAudioSampleType;

	//码率输出类型(编码有效)
	//不同的MediaID需要配置不同的参数,具体参看头文件中的枚举定义
	int nOutputFormat;

	int nBytesPerPacket;

	int nReserved2[48];

	stVXSDKAudioStreamInfo()
	{
		memset(this, 0, sizeof(stVXSDKAudioStreamInfo));
	}
};

//通用系统流信息定义
struct stVXSDKSystemStreamInfo
{
	int nMediaID;
	int nSubMediaType;
	int nFourCC;

	int nFrameNum;
	int nTimeScale;
	int64_t llTimeDuration;

	int nReserved[64];

	stVXSDKSystemStreamInfo()
	{
		memset(this, 0, sizeof(stVXSDKSystemStreamInfo));
	}
};

//通用数据流信息定义
struct stVXSDKDataStreamInfo
{
	int nMediaID;
	int nDataStreamType;
	int nFourCC;

	int nFrameNum;
	int nTimeScale;
	int64_t llTimeDuration;

	int nReserved[64];

	stVXSDKDataStreamInfo()
	{
		memset(this, 0, sizeof(stVXSDKDataStreamInfo));
	}
};


/**
 * @brief 键值对数据定义。
 *
 * strKey和strValue都是以\0结尾的字符串。
 *
 */
struct stVXSDKMetaData
{
    const char* strKey;
    const char* strValue;
};

/**
 * @brief 节目信息的数据结构。
 *
 * 一般可以使用VXStream::ReadProgram接口读取流中所有的节目信息，
 * 需要注意的是arrMetaData字段中的strKey和strValue数据是使用接口
 * 内部的内存。
 *
 */
struct stVXSDKProgramInfo
{
    int nId;
    int nFlags;
    int nDiscard;
    int arrStreamIndex[32];///节目中包含的流索引，为了后续的业务扩展，这里没有区分音视频流索引，需要通过相关接口获取
    int nStreamNum;///arrStreamIndexes中有效数据的数量
    stVXSDKMetaData arrMetaData[64];///节目的信息，例如节目名，服务名
    int nMetaDataNum;///arrMetaData中有效数据的数量
    int nProgramNumber;///节目编号
    int nPmtPid;
    int nPcrPid;
    int nPmtVersion;
};


//Dash Writer扩展参数,在调用StartWrite前通过writer的ConfigureObj接口传入
//ConfigureObj(VX_CONFIG_PARAM_TYPE_SET_DASH_WRITER_EXTRA_INFO, &stVXDashWriterExtraInfo, sizeof(stVXDashWriterExtraInfo));
const int VX_CONFIG_PARAM_TYPE_SET_DASH_WRITER_EXTRA_INFO = 0x01;
struct stVXDashWriterExtraInfo
{
    int nValid;//扩展参数是否有效
    int nWriteThumb;//是否生成缩略图
    int nUpdatePeriodTime;//MPD的刷新周期时间(单位为ms)
    //缩略图相关参数
    int nThumbSegmentDuration;//缩略图分段长度(多少张缩略图写到同一个jpeg图片中)
    int nThumbWidth;//缩略图分辨率（必须为16的整数倍）
    int nThumbHeight;
    int nThumbSampleRate;//多少帧采一张缩略图（必须是视频Gop长度的整数倍）
    int nThumbQuality;//缩略图质量(0-99)

    //保留扩展字段
    int nReserved[8];

	stVXDashWriterExtraInfo()
    {
        memset(this, 0, sizeof(stVXDashWriterExtraInfo));
    }
};

// Smtt Writer扩展参数,在调用StartWrite前通过writer的ConfigureObj接口传入
// ConfigureObj(VX_CONFIG_PARAM_TYPE_SET_SMTT_WRITER_EXTRA_INFO, &stVXSmttWriterExtraInfo, sizeof(stVXSmttWriterExtraInfo));
const int VX_CONFIG_PARAM_TYPE_SET_SMTT_WRITER_EXTRA_INFO = 0x02;
struct stVXSmttWriterExtraInfo
{
    int nValid;             //扩展参数是否有效
    int nTotalFragmentNumber; //分片数量
    int nTotalVideoFrameCount; //总视频帧数
    int nCurFragmentMediaIn; //当前分片入点
    int nCurFragmentMediaOut; //当前文件出点

    //保留扩展字段
    int nReserved[11];

    stVXSmttWriterExtraInfo()
    {
        memset(this, 0, sizeof(stVXDashWriterExtraInfo));
    }
};

//日志输出功能(统一管理)
#define VX_LOG_LEVEL_ERROR		1
#define VX_LOG_LEVEL_WARNING	2
#define VX_LOG_LEVEL_INFO		4




#endif