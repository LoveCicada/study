#ifndef VX_BASE_MEDIA_FILE_FORMAT_DEFINE_INCLUDED_
#define VX_BASE_MEDIA_FILE_FORMAT_DEFINE_INCLUDED_


//////////////////////////// Media Type ID defination  ///////////////////////
///////general
#define XH_TRANS_MEDIA_NONE                 0x0000          //do not produce file
#define XH_TRANS_MEDIA_UNKNOWN              0x0001          //unknown file format
#define XH_TRANS_MEDIA_UNCARE               0x0002          //do not care about the file format

///////Base-band
#define XH_TRANS_VIDEO_BASEBAND             0x0004          //indicate video is RGB/YUV


///////video DV
#define XH_TRANS_VIDEO_DV					0x0010          //DV general
#define XH_TRANS_VIDEO_DVSD					0x0011          //DVCAM or DVSD
#define XH_TRANS_VIDEO_DV25					0x0012          //DVCPRO or DV25
#define XH_TRANS_VIDEO_DV50					0x0013          //DVCPRO50 or DV50
#define XH_TRANS_VIDEO_DVH5                 0x0014          //DVCPROHD 1080/50i
#define XH_TRANS_VIDEO_DVH6                 0x0015          //DVCPROHD 1080/60i
#define XH_TRANS_VIDEO_DVHP                 0x0016          //DVCPROHD 720/50p or 720/60p
#define XH_TRANS_VIDEO_CDVC                 0x0017          //CDVC

///////video MPEG-4
#define XH_TRANS_VIDEO_MPEG4				0x0020          //MPEG4 general
#define XH_TRANS_VIDEO_MPEG4_MSV2			0x0021          //Microsoft MPEG-4 V2
#define XH_TRANS_VIDEO_MPEG4_MSV3			0x0022          //Microsoft MPEG-4 V3
#define XH_TRANS_VIDEO_MPEG4_DIVXV5			0x0023          //DivX MPEG-4 V5
#define XH_TRANS_VIDEO_MPEG4_REALMAGIC		0x0024          //RealMagic ISO MPEG-4
#define XH_TRANS_VIDEO_MPEG4_H264			0x0025          //mpeg4 H264
#define XH_TRANS_VIDEO_MPEG4_MSVC			0x0026          //mpeg4 msvc1
#define XH_TRANS_VIDEO_MPEG4_AVCIntra       0x0027          //mpeg4 AVCIntra
#define XH_TRANS_VIDEO_H263                 0x0028          //h263

#define XH_TRANS_VIDEO_MPEG4_H264_3D        0x0029 

#define XH_TRANS_VIDEO_SORENSON_H263		0x002A			//Sorenson H.263

#define XH_TRANS_VIDEO_MVC					0x002B
#define XH_TRANS_VIDEO_MVC_INDEPENDENT		0x002C
#define XH_TRANS_VIDEO_MVC_DEPENDENT		0x002D

///////video MPEG4 ISO
#define XH_TRANS_VIDEO_MPEG4_ISO            0x0030          //ISO MPEG4 general 
#define XH_TRANS_VIDEO_MPEG4_ISO_SP         0x0031          //ISO MPEG4 SP 
#define XH_TRANS_VIDEO_MPEG4_ISO_ASP        0x0032          //ISO MPEG4 ASP 
#define XH_TRANS_VIDEO_MPEG4_SONY_PROXY     0x0033          //SONY Proxy MPEG4
#define XH_TRANS_VIDEO_MPEG4_XVID			0x0034			//XVID

//////video mpeg4 SR
#define XH_TRANS_VIDEO_MPEG4_HDCAM_SR       0x0035          //hcacm_sr

///////video MPEG-1
#define XH_TRANS_VIDEO_MPEG1				0x0040          // MPEG1 - standard
#define XH_TRANS_VIDEO_MPEG1_VCD			0x0041          // MPEG1 - VCD

///////video MPEG-2
#define XH_TRANS_VIDEO_MPEG2				0x0050          // MPEG2 - standard
#define	XH_TRANS_VIDEO_MPEG2_MPML			0x0051          // MPEG2 - MP@ML, 4:2:0
#define	XH_TRANS_VIDEO_MPEG2_422PML			0x0052          // MPEG2 - 422P@ML, 4:2:2 
#define	XH_TRANS_VIDEO_MPEG2_MPHL			0x0053          // MPEG2 - MP@HL, 4:2:0
#define	XH_TRANS_VIDEO_MPEG2_MPH1440L		0x0054          // MPEG2 - MP@H1440L, 4:2:0
#define	XH_TRANS_VIDEO_MPEG2_HPHL			0x0055          // MPEG2 - HP@HL, 4:2:2
#define	XH_TRANS_VIDEO_MPEG2_HPH1440L		0x0056          // MPEG2 - HP@H1440L, 4:2:2
#define	XH_TRANS_VIDEO_MPEG2_DVD			0x0057          // MPEG2 - DVD
#define	XH_TRANS_VIDEO_MPEG2_SVCD			0x0058          // MPEG2 - SVCD

#define	XH_TRANS_VIDEO_MPEG2_SONY_IMX		0x005a          // MPEG2 - SONY IMX format
#define	XH_TRANS_VIDEO_MPEG2_MATROX_I		0x005b          // MPEG2 - Matrox I
#define	XH_TRANS_VIDEO_MPEG2_MATROX_IBP		0x005c          // MPEG2 - Matrox IBP

#define	XH_TRANS_VIDEO_MPEG2_3D_MATROX_I		0x005d      // MPEG2 - 3D Matrox I
#define	XH_TRANS_VIDEO_MPEG2_3D_MATROX_IBP		0x005e      // MPEG2 - 3D Matrox IBP

///////video WMV
#define XH_TRANS_VIDEO_WMV					0x0060          //WMV general
#define XH_TRANS_VIDEO_WMV8					0x0061          //WMV8
#define XH_TRANS_VIDEO_WMV9					0x0062          //WMV9

///////video RealVideo
#define XH_TRANS_VIDEO_REAL				    0x0070          //Real general
#define XH_TRANS_VIDEO_REAL9				0x0071          //Real video 9

///////video QuickTime
#define XH_TRANS_VIDEO_QT                   0x0080          //QuickTime general
#define XH_TRANS_VIDEO_SVQ3					0x0081			//QT SVQ3

///////video png
#define XH_TRANS_VIDEO_PNG                  0x0085          //PNG
#define XH_TRANS_VIDEO_RLE					0x0086			//RLE

///////video M-JPEG
#define XH_TRANS_VIDEO_MJPEG                0x0090          //Motion JPEG
#define XH_TRANS_VIDEO_MJPEG2000            0x0091          //Motion JPEG2000
#define XH_TRANS_VIDEO_QT_MJPEGA			0x0092			//QuickTime Motion-JPEG(format A)
#define XH_TRANS_VIDEO_QT_MJPEGB			0x0093			//QuickTime Motion-JPEG(format B)
#define XH_TRANS_VIDEO_ODML_MJPEG			0x0094			//OpenDML Motion JPEG


///////sony NPS1
#define XH_TRANS_VIDEO_SONY_NPS1_MPEG       0x00a0          //sony NPS1 MPEG

//////matrox hd file, open with matrox card
#define XH_TRANS_VIDEO_MPEG2_HD_MATROX_CARD		0x00a5      //MPEG-2 HD, DECODE BY MATROX CARD

/////flash
#define XH_TRANS_VIDEO_FLASH_VETOR				0x00a9
//avid dnx

#define XH_TRANS_VIDEO_DNXHD                0x0082         //Avid DNxHD

#define XH_TRANS_VIDEO_DNX_220X_1080p		0x00b1 ///<  1080p, 10 bit, 220 mbps
#define XH_TRANS_VIDEO_DNX_145_1080p		0x00b2 ///<  1080p,  8 bit, 145 mbps
#define XH_TRANS_VIDEO_DNX_220_1080p		0x00b3///<  1080p,  8 bit, 220 mbps
#define XH_TRANS_VIDEO_DNX_220X_720p		0x00b4 ///<  720p,  10 bit, 220 mbps 
#define XH_TRANS_VIDEO_DNX_220_720p			0x00b5///<  720p,  8 bit,  220 mbps
#define XH_TRANS_VIDEO_DNX_145_720p			0x00b6 ///<  720p,  8 bit,  145 mbps
#define XH_TRANS_VIDEO_DNX_220X_1080i		0x00b7 ///<  1080i, 10 bit, 220 mbps
#define XH_TRANS_VIDEO_DNX_145_1080i		0x00b8///<  1080i,  8 bit, 145 mbps
#define XH_TRANS_VIDEO_DNX_220_1080i		0x00b9 ///<  1080i,  8 bit, 220 mbps
#define XH_TRANS_VIDEO_DNX_145_1440_1080i	0x00ba ///<  1080i,  8 bit, 145 mbps, thin raster
#define XH_TRANS_VIDEO_DNX_36_1080p			0x00bb ///<  1080p,  8 bit,  36 mbps
#define XH_TRANS_VIDEO_DNX_50_1080i			0x00bc ///<  1080i,  8 bit,  50 mbps

#define XH_TRANS_VIDEO_DNXHR				0x01b0
#define XH_TRANS_VIDEO_DNXHR_444			0x01b1
#define XH_TRANS_VIDEO_DNXHR_HIGH_EXT		0x01b2
#define XH_TRANS_VIDEO_DNXHR_HIGH			0x01b3
#define XH_TRANS_VIDEO_DNXHR_MEDIUM			0x01b4
#define XH_TRANS_VIDEO_DNXHR_LOW			0x01b5

#define XH_TRANS_VIDEO_PRORES422			0x00c0
#define XH_TRANS_VIDEO_PRORES422_1080i		0x00c1
#define XH_TRANS_VIDEO_PRORES422_720p		0x00c2
#define XH_TRANS_VIDEO_PRORES422_1080p		0x00c3
#define XH_TRANS_VIDEO_PRORES422_1440_1080p	0x00c4

#define XH_TRANS_VIDEO_PRORES422_HQ			0x00d0
#define XH_TRANS_VIDEO_PRORES422_HQ_1080i	0x00d1
#define XH_TRANS_VIDEO_PRORES422_HQ_720p	0x00d2
#define XH_TRANS_VIDEO_PRORES422_HQ_1080p	0x00d3
#define XH_TRANS_VIDEO_PRORES422_HQ_1440_1080p	0x00d4

//New Prores Type Defination
#define XH_TRANS_VIDEO_PRORES_PROXY			0x00dc
#define XH_TRANS_VIDEO_PRORES_LT			0x00dd
#define XH_TRANS_VIDEO_PRORES_STANDARD		0x00de
#define XH_TRANS_VIDEO_PRORES_HQ			0x00df
#define XH_TRANS_VIDEO_PRORES_4444			0x00e0

//video v210
#define XH_TRANS_VIDEO_V210                 0x00f0

//Video VP8
#define XH_TRANS_VIDEO_VP8					0x0100

//Video Canopus HQ
#define XH_TRANS_VIDEO_CanopusHQ_CUVC		0x0110
//Video Canopus HQX
#define XH_TRANS_VIDEO_CanopusHQX			0x0111

///////audio 
#define XH_TRANS_AUDIO_LPCM                 0x0410
#define XH_TRANS_AUDIO_MP1                  0x0411
#define XH_TRANS_AUDIO_MP2                  0x0412
#define XH_TRANS_AUDIO_MP3                  0x0413
#define XH_TRANS_AUDIO_WMA                  0x0414
#define XH_TRANS_AUDIO_REAL                 0x0415
#define XH_TRANS_AUDIO_ALAW                 0x0416 // alaw
#define XH_TRANS_AUDIO_AAC                  0x0417
#define XH_TRANS_AUDIO_AC3                  0x0418
#define XH_TRANS_AUDIO_EC3                  0x041A

// by or 2008.9.10 for quicktime audio info.
#define XH_TRANS_AUDIO_ULAW                 0x0419 // Ulaw 2:1
#define XH_TRANS_AUDIO_MAC3                 0x0420 // MACE 3:1.
#define XH_TRANS_AUDIO_MAC6                 0x0421 // MACE 6:1.
#define XH_TRANS_AUDIO_RAW					0x0424 // raw Samples are stored uncompressed
#define XH_TRANS_AUDIO_MP4					0x0425 // MPEG-4 audio
#define XH_TRANS_AUDIO_DVCA	                0x0426 // DV Audio
#define XH_TRANS_AUDIO_IMA4					0x0427 // IMA 4:1.
					
#define XH_TRANS_AUDIO_NOCOMP				0x0428 // uncompressed	
#define XH_TRANS_AUDIO_FL32					0x0429 // 32-bit floating point	
#define XH_TRANS_AUDIO_FL64					0x0430 // 64-bit floating point	
#define XH_TRANS_AUDIO_IN24                 0x0431 // 24-bit integer
#define XH_TRANS_AUDIO_IN32					0x0432 // 32-bit integer	
#define XH_TRANS_AUDIO_QDM2					0x0433 // QDesign music version 2
#define XH_TRANS_AUDIO_QDMC					0x0434 // QDesign music		
#define XH_TRANS_AUDIO_QCLP					0x0435 // QUALCOMM PureVoice	
#define XH_TRANS_AUDIO_MP3V1				0x0436 // MPEG-1 layer 3, CBR only (pre-QT4.1)
#define XH_TRANS_AUDIO_ADPCM				0x0437 // Microsoft ADPCM-ACM code 2
#define XH_TRANS_AUDIO_IMAADPCM				0x0438 // DVI/Intel IMAADPCM-ACM code 17
#define XH_TRANS_AUDIO_AMR                  0x0439 // amr
#define XH_TRANS_AUDIO_DRA					0x043A // DRA 
#define XH_TRANS_AUDIO_DTS					0x043B // DTS	
#define XH_TRANS_AUDIO_M4A					0x0440 // M4A          
#define XH_TRANS_AUDIO_DDE					0x0441 // DDE--DolbyE .dde文件         
#define XH_TRANS_AUDIO_VORBIS				0x0442 // VORBIS
#define XH_TRANS_AUDIO_FLAC					0x0443 // FLAC
#define XH_TRANS_AUDIO_APE					0x0444 // APE
#define XH_TRANS_AUDIO_ACE2					0x0445 // ACE 2:1
#define XH_TRANS_AUDIO_ACE8					0x0446 // ACE 8:3
		
//////audio SONY NPS1
#define XH_TRANS_AUDIO_SONY_NPS1_LPCM       0x0500          //sony NPS1 audio
/////audio flash
#define XH_TRANS_AUDIO_FLASH_MP3			0x0510			//flash mp3
#define XH_TRANS_AUDIO_FLASH_QDM2			0X0511			//QT qdm2

#define XH_TRANS_AUDIO_DOLBY                0x0600  // mxf dolby-E audio    
#define XH_TRANS_AUDIO_DOLBY_WAV            0x0601  // wav dolby-E audio,符合smpte 337标准的non-pcm wav文件    

#define XH_TRANS_SUB_DVB					0x701 
#define XH_TRANS_SUB_DVD					0x702          

#define XH_TRANS_DATA_CC					0x710 //Closed caption          

////////////////////////// media file format ID defination  ///////////////////////
/////general
#define XH_TRANS_FILE_NONE                  0x0800     //do not produce file
#define XH_TRANS_FILE_UNKNOWN               0x0801     //unknown file format
#define XH_TRANS_FILE_UNCARE                0x0802     //do not care about the file format

/////AVI file format
#define XH_TRANS_FILE_AVI                   0x0810     // avi file general 
#define XH_TRANS_FILE_RIFF_AVI              0x0811     //.avi
#define XH_TRANS_FILE_OPDML_AVI             0x0812     //.avi
#define XH_TRANS_FILE_AVMIXED_AVI2          0x0813     //.avi, AV mixed           
#define XH_TRANS_FILE_DV_AVI                0x0814

/////video DV diff file format
#define XH_TRANS_FILE_DV_DIFF               0x0820     //.dv

/////video MPEG file format
#define XH_TRANS_FILE_MPEG                  0x0830     // mpg file general
#define XH_TRANS_FILE_MPEG_ES               0x0831     //.m2v, .m2a
#define XH_TRANS_FILE_MPEG_PS               0x0832     //.mpg, .ps
#define XH_TRANS_FILE_MPEG_TS               0x0833     //.mpg, .ts
#define XH_TRANS_FILE_MPEG_DVD              0x0834     //.vob
#define XH_TRANS_FILE_MPEG_VCD              0x0835     //.dat
#define XH_TRANS_FILE_MPEG_SVCD             0x0836     //
#define XH_TRANS_FILE_MPEG_MP4              0x0837     //
#define XH_TRANS_FILE_MPEG_M2P				0x0838     //.m2p
#define XH_TRANS_FILE_MPEG_M2T				0x0839	   //.m2t	

#define XH_TRANS_FILE_MPEG_M4V				0x084A	   //.m4v

/////video WMV file format
#define XH_TRANS_FILE_MS_WMV                0x0840     //.wmv
#define XH_TRANS_FILE_MS_ASF                0x0841     //.asf

/////video RM file format
#define XH_TRANS_FILE_REAL_RM               0x0850     //.rm

/////video QuickTime file format
#define XH_TRANS_FILE_QT_MOV                0x0860     //.mov

/////video MXG
#define XH_TRANS_FILE_PROMPEG_MXF           0x0870     //.mxf
#define XH_TRANS_FILE_IMX_MXF               0x0871     //.mxf

/////broadcast file format, manufacturer oriented
#define XH_TRANS_FILE_MATROX_AVI            0x0880     //.avi
#define XH_TRANS_FILE_SONY_IMX              0x0881     //.mxf
#define XH_TRANS_FILE_SONY_MAV70            0x0882     //.
#define XH_TRANS_FILE_SEACHANGE             0x0883     //.gxf
#define XH_TRANS_FILE_GVG_GXF               0x0884     //.gxf

//file format of 3gp
#define XH_TRANS_FILE_3GP                   0x0890     //.3gp

//file format of ismv
#define XH_TRANS_FILE_ISMV                  0x0895    //.ismv


/////file format of Sony NPS1
#define XH_TRANS_FILE_SONY_NPS1             0x08A0     //sony NPS1    

////drm file format
#define XH_TRANS_FILE_SOBEY_DRM				0x08B0	   //Sobey DRM

////file format for flash
#define XH_TRANS_FILE_FLASH_SWF				0x08B0		//swf
#define XH_TRANS_FILE_FLASH_EXE				0x08B1		//exe
#define XH_TRANS_FILE_FLASH_FLV				0x08B2		//flv
#define XH_TRANS_FILE_F4V				    0x08B3		//flv

//file format for mfs
#define XH_TRANS_FILE_MFS					0x08C0      //mfs

//file picture
#define XH_TRANS_FILE_PIC_BMP				0X8D0		//bmp
#define XH_TRANS_FILE_PIC_JPG				0X8D1		//jpg
#define XH_TRANS_FILE_PIC_TGA				0X8D2		//tga
#define XH_TRANS_FILE_PIC_DPX				0X8D3		//dpx


/////audio file format
#define XH_TRANS_FILE_WAV                   0x0910     //.wav
#define XH_TRANS_FILE_MP1                   0x0911     //.mp1
#define XH_TRANS_FILE_MP2                   0x0912     //.mp2
#define XH_TRANS_FILE_MP3                   0x0913     //.mp3
#define XH_TRANS_FILE_AAC                   0x0915     //.aac
#define XH_TRANS_FILE_WMA                   0x0916     //.wma
#define XH_TRANS_FILE_RMA                   0x0917     //.rm, real audio file
#define XH_TRANS_FILE_DDE                   0x0918     //.dde
#define XH_TRANS_FILE_S48                   0x0922	   //.s48
#define XH_TRANS_FILE_VORBIS                0x0923	   //.vorbis
#define XH_TRANS_FILE_FLAC                  0x0924	   //.flac
#define XH_TRANS_FILE_APE					0x0925	   //.ape
#define XH_TRANS_FILE_AIFF					0x0926	   //.aif .aiff

#define XH_TRANS_FILE_DVBS					0x0A10

#define XH_TRANS_FILE_MKV					0x0B10		//.mkv
#define XH_TRANS_FILE_WEBM					0x0B11		//.webm
	
#define XH_TRANS_FILE_M4A                   0x0C10	   //.m4a

#define XH_TRANS_FILE_CC                    0x0C12	   //.cc

#define XH_TRANS_FILE_SMTT                  0x0C13	   //.smtt

//////////////////////// Input SOURCE Mode defination//////////////////////
#define XH_TRANS_SOURCE_INVALID             -1        //invalid input
#define XH_TRANS_SOURCE_VIDEO_FILE          0x0000    //video file input
#define XH_TRANS_SOURCE_AUDIO_FILE          0x0001    //audio file input

#define XH_TRANS_SOURCE_VIDEO_NULL_BLACK    0x0400    //video null input, self generate BLACK frame
#define XH_TRANS_SOURCE_AUDIO_NULL          0x0800    //audio null input, self generate null voice



//////////////////////// Media Effect ID defination ///////////////////////
#define XH_TRANS_EFFECT_NONE                -1        //none effect
/////video effect
#define XH_TRANS_EFFECT_VIDEO_RESIZE        0x0000    //resize
#define XH_TRANS_EFFECT_VIDEO_BRIGHT        0x0001    //brightness 
#define XH_TRANS_EFFECT_VIDEO_CONTRAST      0x0002    //contrast
#define XH_TRANS_EFFECT_VIDEO_FILTER        0x0003    //video filtering 
#define XH_TRANS_EFFECT_VIDEO_CLRTEMP       0x0004    //color temp
#define XH_TRANS_EFFECT_VIDEO_BLUR          0x0005    //blur
#define XH_TRANS_EFFECT_VIDEO_SHARPEN       0x0006    //sharpen

/////audio effect
#define XH_TRANS_EFFECT_AUDIO_VOLUME        0x0800    //audio volume
#define XH_TRANS_EFFECT_AUDIO_BALANCE       0x0801    //audio balance
#define XH_TRANS_EFFECT_AUDIO_NOISECLR      0x0802    //audio noise clearance
#define XH_TRANS_EFFECT_AUDIO_BANDPASS      0x0803    //audio band pass
#define XH_TRANS_EFFECT_AUDIO_TONECHG       0x0804    //tone change



/////////////////////// Media Analysis ID defination ///////////////////////
#define XH_TRANS_ANALYSIS_NONE                 -1     //none analysis
#define XH_TRANS_ANALYSIS_SHOTDET           0x0000    //shot detection


/////////////////////// Plugin File Format ID Defination //////////////////////////////////////////
#define XH_TRANS_PLUGIN_FILE_ID_FLAG		0x46000000

//Plugin H265 Stream File
#define XH_TRANS_PLUGIN_FILE_H265           0x46146091

#define XH_TRANS_PLUGIN_FILE_LXF            0x46FCF855

#define XH_TRANS_PLUGIN_FILE_R3D            0x46FCD0DB

#define XH_TRANS_PLUGIN_FILE_TS             0x46FFF71D

#define XH_TRANS_PLUGIN_FILE_AMR            0x46FDB58A

#define XH_TRANS_PLUGIN_FILE_W64            0x46FC41A0

#define	XH_TRANS_PLUGIN_FILE_TIFF           0x463CF49D

#define XH_TRANS_PLUGIN_FILE_DPX            0x46FE164D

#define XH_TRANS_PLUGIN_FILE_DSD            0x46FCD70D

#define XH_TRANS_PLUGIN_FILE_RF64			0x461063DB

#define XH_TRANS_PLUGIN_FILE_PSD			0x46FCD719

#define XH_TRANS_PLUGIN_FILE_PNG			0x4641767F

#define XH_TRANS_PLUGIN_FILE_GIF			0x46FCF490

#define XH_TRANS_PLUGIN_FILE_DASH			0x4645C28D

#define XH_TRANS_PLUGIN_FILE_KEY			0x46FE2394

#define XH_TRANS_PLUGIN_FILE_EXR			0x46FDB84E

#define XH_TRANS_PLUGIN_FILE_CRM			0x46FD66CC

#define XH_TRANS_PLUGIN_FILE_BRAW	        0x4680A6CB

#define XH_TRANS_PLUGIN_FILE_ARI			0x46FD26CA

#define XH_TRANS_PLUGIN_FILE_VRW			0x46FE06DF

#define XH_TRANS_PLUGIN_FILE_DNG			0x46FD05CD

#define XH_TRANS_PLUGIN_FILE_AMFS			0x4670F58A

/////////////////////// Plugin Video Format ID Defination /////////////////////////////////////////
#define XH_TRANS_PLUGIN_VIDEO_ID_FLAG		0x56000000

//Plugin XAVC-Intra
#define XH_TRANS_PLUGIN_VIDEO_XAVC			0x5631F2A1
//Plugin AVCUltra-Intra
#define XH_TRANS_PLUGIN_VIDEO_AVCU		    0x5678C7CA
#define XH_TRANS_PLUGIN_VIDEO_AVCU_LT		0x5655E30A
//Plugin H.265/HEVC
#define XH_TRANS_PLUGIN_VIDEO_H265			0x56146091

//Plugin Sony RAW
#define XH_TRANS_PLUGIN_VIDEO_SONY_RAW      0x56EA46DC
//Sony RAW子类型根据FCC区分
//FCC == mmioFOURCC('S', 'R', 'A', 'W'), General Sony RAW
//FCC == mmioFOURCC('X', 'O', 'C', 'N'), General X-OCN
//FCC == mmioFOURCC('O', 'C', 'N', 'S'), X-OCN ST
//FCC == mmioFOURCC('O', 'C', 'N', 'L'), X-OCN LT

//Plugin XAVC-LongGOP
#define XH_TRANS_PLUGIN_VIDEO_XAVC_LONGGOP  0x5654C7E1
//Plugin AVCUltra-LongGOP
#define XH_TRANS_PLUGIN_VIDEO_AVCU_LONGGOP  0x5655E31F

#define XH_TRANS_PLUGIN_VIDEO_RED_RAW		0x5680A6DB
//Plugin SobeyCodec
#define XH_TRANS_PLUGIN_VIDEO_SOBEY_CODEC   0x56F25C9C
//Plugin TGA
#define XH_TRANS_PLUGIN_VIDEO_TGA			0x56FCA41D
//Plugin SpeedHQ
#define XH_TRANS_PLUGIN_VIDEO_SPEED_HQ		0x56FDA45C	
//Plugin Canopus Lossless
#define XH_TRANS_PLUGIN_VIDEO_CLLC			0x5631554C
//Plugin Canon RAW
#define XH_TRANS_PLUGIN_VIDEO_CANON_RAW		0x5680A6CC
//Plugin Arri RAW
#define XH_TRANS_PLUGIN_VIDEO_ARRI_RAW      0x5680A6CA
//Plugin Panasonic RAW
#define XH_TRANS_PLUGIN_VIDEO_PANASONIC_RAW	0x5680A6DF

/////////////////////// Plugin Audio Format ID Defination /////////////////////////////////////////
#define XH_TRANS_PLUGIN_AUDIO_ID_FLAG       0x41000000

#define XH_TRANS_PLUGIN_AUDIO_DSD           0x41FCD70D
//Dolby TrueHD
#define XH_TRANS_PLUGIN_AUDIO_TRUEHD	    0x41351D5D


///////////////////////// Picture format definatio //////////////////////////
//The BiCompression in BITMAPIBFOHEADER Should match one of the following defines
#define BI_RGB                              0x00000000      //RGB24 and RGB32
#define BI_ARGB                             0x42475241      //ARGB
#define BI_UYVY                             0x59565955      //UYVY 4:2:2, U0 Y0 V0 Y1
#define BI_YUY2                             0x32595559      //YUY2 4:2:2, Y0 U0 Y1 V0
#define BI_IYUV                             0x56555949      //YUV 4:2:0, one Y plane match 2*2 UV planes
#define BI_YUV6                             0x36565559      //YUV 4:2:0, Block 
#define BI_YUV8                             0x38565559      //YUV 4:2:2, Block 
#define BI_YUVC                             0x43565559      //YUV 4:4:4, Block 
#define BI_AYUV                             0x56555941      //AYUV 4:4:4, A0 Y0 U0 V0
#define BI_YUVA                             0x41565559      //YUVA 
#define BI_Y411								0x31313459		//YUV 4:1:1, Block
#define BI_V210								0x30313256		//YUV V210 10bit
#define BI_BGR								0x20524742		//BGR

//////////////// Encode return value(error code) defination ////////////////
#define ENC_SUCCESS                         1     //success  
#define ENC_FAILUE                          0     //failue 
#define ENC_SEVERE_ERROR                    -128  //severe error occured
#define ENC_AUTHORIZE_FAILUE                -1    //authorize failue 
#define ENC_PARAM_SETTING_ERROR             -2    //error in param setting
#define ENC_PARAM_LOAD_FAILUE               -3    //error in loading param to codec
#define ENC_TARGET_UNSUPPORTED              -4    //unsupported target format
#define ENC_VIDEO_INPUT_ILLEGAL             -5    //illegal input video format
#define ENC_AUDIO_INPUT_ILLEGAL             -6    //illegal input audio format
#define ENC_CODEC_OPEN_FAILUE               -7    //open codec failue
#define ENC_VIDEO_ENCODE_START_FAILUE       -8    //fail to start encoding
#define ENC_VIDEO_ENCODE_PROCESS_FAILUE     -9    //encoding process failue
#define ENC_AUDIO_ENCODE_START_FAILUE       -10   //fail to start encoding
#define ENC_AUDIO_ENCODE_PROCESS_FAILUE     -11   //encoding process failue
#define ENC_MUXER_OPEN_FAILUE               -12   //muxer open failue
#define ENC_OPMODE_UNSUPPORT                -13   //unsupported operation mode for encoder
#define ENC_VFILE_OPEN_WRITE_FAILUE         -14   //video file open write failue
#define ENC_AFILE_OPEN_WRITE_FAILUE         -15   //audio file open write failue
#define ENC_MUDULE_NOT_EXIST                -16   //related enc module not existed
#define ENC_VIDEO_FORMAT_UNSUPPORT          -17   //unsupported video format

///////////////////////////////////////////////////////////////////////////
//WAVE form wFormatTag IDs
#define   WAVE_FORMAT_PCM                   0x0001
#define   WAVE_FORMAT_ALAW                  0x0006
#define   WAVE_FORMAT_MPEG                  0x0050
#define   WAVE_FORMAT_MPEGLAYER3            0x0055
#define   WAVE_FORMAT_AC3                   0x2000 
#define   WAVE_FORMAT_AAC                   0xA106 //
#define	  WAVE_FORMAT_DTS_DS				0x0190	
#define   WAVE_FORMAT_AMR                   0x0010 //
#define	  WAVE_FORMAT_DRA					0x6882


#endif