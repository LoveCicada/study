
#ifndef __tp_base_fcc_define__header__
#define __tp_base_fcc_define__header__


#ifndef mmioFOURCC
#define mmioFOURCC( ch0, ch1, ch2, ch3 ) ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) | ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
#endif

#ifndef FCC
#define FCC(ch4) ((((DWORD)(ch4) & 0xFF) << 24) | (((DWORD)(ch4) & 0xFF00) << 8) | (((DWORD)(ch4) & 0xFF0000) >> 8) | (((DWORD)(ch4) & 0xFF000000) >> 24))
#endif

// 3d Agent FCC begin
#define fcc3DAgentVideo		'3DAV'
#define fcc3DAgentAudio		'3DAA'
// 3d Agent FCC end

// 深度信息FCC
#define fcc3DDepthVideo 'PEDF' 
#define fccPureDataUYVY 'UYVY'
#define fccPureDataYUYV 'YUYV'
#define fcc3DAVMIXED '3DVM'

//fcc
#define fcc3DWMV			'3DWM'
#define fcc3DMPEG4			'3DM4'
#define fcc3DIF422			'3DIF'
#define fcc3DH264			'3DH2'
#define fcc3DMXFHIBP		'3DMI'
#define fcc3DTSH264		'3DTH'
//]]


#define fccHDSR				'SRDH'


//定义E7里使用的FOURCC
//ljj:添加fcc定义时，务必起个很容易理解的名字。
////////////////////////视频/////////////////////////////
//------------标清--------------
//PAL：720*576
//NTSC：720*486
//个别的一些：352*288，320*240
//E7中主要使用720*576
#define fccMPEG4			'2VSM'
#define fccMSV3				'3VSM'
#define fccPROXY			'YXOP'/*mmioFOURCC('P','O','X','Y')*/
#define fccDVCAM			'DSVD'
#define fccDVSD				'DSVD'
#define fccDVCPRO25			'52VD'
#define fccDV25				'52VD'
#define fccDVCPRO50			'05VD'
#define fccDV50				'05VD'
#define fccMPEGIFRAME		'   I'
#define fccI				'   I'
#define fccIMX				' XMI'
#define fccIBP				' PBI'
#define fccIBP720			' PBI'
#define fccAVI2SD			'IVAS'
#define fccMPG4				'4GPM'
#define fccMPEG2			'2GPM'
#define fccMPEG1			'1GPM'
#define fccDVD				' DVD'
#define fccSVCD				'DCVS'
#define fccVCD				' DCV'
#define fccWMV9				'9VMW'
#define fccWMV8				'8VMW'
#define fccWMV				' VMW'
#define fccREAL				'9LER'
#define fccMPEG2_HIBP		FCC('HIBP')
#define fccMPEG2_SIBP		FCC('SIBP')

//Matrox SD AVI files:
#define fccMATROXDVSD		' VDM'
#define fccMATROXDVCAM		' VDM'
#define fccMATROXDVCPRO25	'52DM'
#define fccMATROXDV25		'52DM'
#define fccMATROXDVCPRO50	'05DM'
#define fccMATROXDV50		'05DM'
#define fccMATROXIF422SD	'22IS'
#define fccMATROXIBP420SD 	'0PBS'
#define fccMATROXIBP422SD 	'2PBS'
#define fccMATROXYUV422SD 	'VUYS'

//MXF SD Files
#define fccMXFIMX50			'5IXM'
#define fccMXFIMX40			'4IXM'
#define fccMXFIMX30			'3IXM'
#define fccMXFDVCAM			'VDXM'
#define fccMXFDVSD			'VDXM'
#define fccMXFPROXY			'XMPS'
#define fccMXFEX35			'XEPM'
#define fccMXFEX25			'2EPM'


#define fccXDCAM_HD15       fccMXFMPEG2HD15
#define fccXDCAM_HD25       fccMXFMPEG2HD25 
#define fccXDCAM_HD35       fccMXFMPEG2HD35 
#define fccXDCAM_HD50       fccMXFMPEG2HD50_ 
#define fccXDCAM_EX35       fccMXFEX35 
#define fccXDCAM_EX25		fccMXFEX25


#define fccDIVX				'XVID'

#define fccSDRGBA			'BGRS'
#define fccSDYUVA			'AUYS'
#define fccQTMOV			'  TQ'
#define	fccMXK2				'2KXM'
#define	fccMXF_K2			'2KXM'

#define fccDV				'  VD'

#define fccMSYU				'UYSM'

#define fccP2DVCPRO25		'2XMP'
#define fccP2DVCPRO50		'5XMP'
#define fccP2AVC50			'5V2P'
#define fccP2AVC100			'1V2P'
#define fccP2AUDIO			'AP2P'
#define fccP2DVHP			'PHDP'
#define fccP2DVH6			'6XMP'	//P2 MXF DVCProHD 60i
#define fccP2DVH5			'HVDP'	//P2 MXF DVCProHD 50i


//DVCProHD 720p: by ljj@2011-1-24
#define	fccDVHP				'PHVD'
//-------------标清结束---------

//------------高清--------------
#define fccHDV				' VDH'
#define fccIBP1440			'PBIS'
//下面的所有HD分辨率都是1920*1080
#define fccIBP1920422		'PBIT'
#define fccIBP1920420		'PBIH'
#define fccIBP1920			'PBIH'
#define fccI1920422			'22DH'
#define fccI1920420			'02DH'
#define fccI1920			'02DH'
#define fccAVI2HD			'IVAH'

//Matrox HD AVI files:
#define fccMATROXIF422HD	'22IH'
#define fccMATROXIF420HD    '02IH'
#define fccMATROXIBP420HD 	'0PBH'
#define fccMATROXIBP422HD 	'2PBH'
#define fccMATROXYUV422HD 	'VUYH'
#define fccMATROXHDOFFLINE 	'FODH'
#define fccMATROXHDMX	 	'XMDH'

//MXF HD files
#define fccMXFMPEG2HD15		'1HXM'
#define fccMXFMPEG2HD25		'2HXM'
#define fccMXFMPEG2HD35		'3HXM'
#define fccMXFMPEG2HD50_    '4HXM'
#define fccMXFMPEG2HD50		'LHXM'
#define	fccHDRGBA			'BGRH'
#define	fccHDYUVA			'AUYH'
#define	fccSMP4				'4PMS'
// 10~60Mbps

#define	fccDVCPROHD50is		'5hvd'

#define fccDVCPROHD50i		'5HVD'
#define	fccDVCPROHD60i		'6HVD'
// 固定 150M码率

#define fccAVCIold			'ICVA'

//ljj@2011-1-21:新加：avc 720p
#define fccAVCp				'PCVA'

#define	fccAVC50			'2CVA'
#define	fccAVC50M			'0CVA'
#define fccAVC100			'1CVA'
#define	fccAVC100M			'1CVA'
#define fccAVC200M          '@CVA' /**< @ = Shift + 2 */
#define	fccJPEG2K			'k2jm'
#define	fccMJPEG_A			'APJM'
#define	fccMJPEG_B			'BPJM'
#define	fccMJPEG		    FCC('MJPG')
#define	fccOdmlMJPEG		FCC('MJPO')
#define	fccVP8		        FCC('VP8 ')
#define	fccVP9		        FCC('VP9 ')

#define fccH263				'362H'
#define fccH264				'462H'
#define fccH265				'562H'
#define fccH264_422         '2462'
#define fccAVI2				'2IVA'
#define fccCC				FCC('*CC*')

#define fccMXHD				'DHXM'

#define fccMPEX				'XEPM'

#define fccMPE2				'2EPM'

#define fccMHYU				'UYHM'

#define fccP2DVCPROHD		'HVDP'

#define fccDNXHD			'HXND'
#define fccDNXHD_AVdn		mmioFOURCC('A','V','d','n')

#define fccDNxHR            FCC('AVxh')
#define fccDNxHR_LB			FCC('AVxl')             /*SBR_DnxHR_Profile_LB*/
#define fccDNxHR_SQ			FCC('AVxm')             /*SBR_DnxHR_Profile_SQ*/
#define fccDNxHR_HQ			FCC('AVxH')             /*SBR_DnxHR_Profile_HQ*/
#define fccDNxHR_HQX		FCC('AVxe')             /*SBR_DnxHR_Profile_HQX*/
#define fccDNxHR_444		FCC('AVx4')             /*SBR_DnxHR_Profile_444*/

#define fccPRORES422_PROXY      mmioFOURCC('P','R','4','P')
#define fccPRORES422_LT         mmioFOURCC('P','R','4','L')
#define fccPRORES422_STANDARD   mmioFOURCC('P','R','4','2')
#define fccPRORES422_HQ         mmioFOURCC('P','R','4','H')
#define fccPRORES4444           mmioFOURCC('P','R','4','A')

#define fccPRORES_PROXY         fccPRORES422_PROXY
#define fccPRORES_LT            fccPRORES422_LT
#define fccPRORES_STANDARD      fccPRORES422_STANDARD
#define fccPRORES_HQ            fccPRORES422_HQ

#define fccPRORES_STANDARD_old  mmioFOURCC('P','R','O','s')
#define fccPRORES_PROXY_old     mmioFOURCC('P','R','O','p')
#define fccPRORES_LT_old        mmioFOURCC('P','R','O','l')
#define fccPRORES_HQ_old        mmioFOURCC('P','R','O','h')
#define fccPRORES_422_old       mmioFOURCC('P','R','O','R')
#define fccPRORES_4444_old      mmioFOURCC('P','R','O','4')
#define fccPRORES_422HQ_old     mmioFOURCC('P','R','O','H')

#define fccRLE_Video            mmioFOURCC('R','L','E','V')
#define fccPNG_Video            mmioFOURCC('P','N','G','V')

#define fccSonyRAW              mmioFOURCC('W','A','R','S') /*nx.'SRAW'*/
#define fccXOCN                 FCC('XOCN')
#define fccXOCN_ST              FCC('OCNS')
#define fccXOCN_LT              FCC('OCNL')
#define fccR3DV		            mmioFOURCC('R','3','D','V')
#define fccR3DA		            mmioFOURCC('R','3','D','A')


#define fccXAVC                 mmioFOURCC('X','A','V','C') /*nova.8.1*/
#define fccAVCU                 mmioFOURCC('A','V','C','U') /*nova.8.1*/
#define fccAVCU_LT              mmioFOURCC('A','V','C','L')
#define fccAVCULongGop          mmioFOURCC('V','C','U','1') /*nova.8.1*/
#define fccXAVCLongGop          mmioFOURCC('X','V','C','1') /*nova.8.1*/

#define fccTBC                  mmioFOURCC('T','B','C',' ')
#define fccOTC                  mmioFOURCC('O','T','C',' ')
#define fccSVQ3                 FCC('SVQ3')
#define fccSobeyCodec           FCC('SOBY')
#define fccV210                 FCC('V210')

#define fccMACE_3_1             FCC('MAC3')
#define fccMACE_6_1             FCC('MAC6')
#define fccACE_2_1              FCC('ACE2')
#define fccACE_8_3              FCC('ACE8')

#define fccVRT_3rd              mmioFOURCC('V','R','T',' ')
#define fccORAD_3rd             mmioFOURCC('O','R','A','D')

// 无码率


//其他格式
#define fccFLASHVIDEO		' VLF'
#define fccFLASHAUDIO_MP3	'3ALF'
#define fccFLASHAUDIO_QTQDM2 'QALF'

#define fccK2MXF_422_SD		'2KXM'
#define fccK2MXF_420_SD		'2K0M'
#define fccK2MXF_422_HD		'HKXM'
#define fccK2MXF_420_HD		'HK0M'

#define fccDPX				'XPDS'

#define fccProRes422		'24RP'
#define fccProRes422HQ		'H4RP'

#define fccXviD				'DivX'	//XviD
#define fccXVID				'DIVX'	//XviD
#define fccCRM				' WRC'
#define fccCFHD				'DHFC'
#define fccUHDC				'CDHU'
#define fccBRAW				'WARB'
#define fccSHQ				' QHS'
#define fccAVS3             '3SVA'
#define fccSSVC				'CVSS'
#define fccJPXS				'SXPJ'
#define fccSEVC				'CVES'
///////////////////////////视频结束//////////////////////

///////////////////////////音频/////////////////////////
#define fccWAV				'MCPL'
#define fccLPCM				'MCPL'
#define fccLPCM4            mmioFOURCC('P','C','M','4')
#define fccLPCM8            mmioFOURCC('P','C','M','8')
#define fccMP3				' 3PM'
#define fccMP2				' 2PM'
#define fccMP1				' 1PM'
#define fccWMA				' AMW'
#define fccRMA				' AMR'
#define fccAAC				' CAA'
#define fccAC3				' 3CA'
#define fccEC3				' 3CE'
#define fccBWF				' FWB'
#define fccDTS				FCC('DTS ')
#define fccDRA				FCC('DRA ')

#define fccDBE				'AEBD'

//以下用于XDCAM MXF音频
#define fccL168				'861L'
#define fccL164				'461L'
#define fccL162				'261L'
#define fccL244				'442L'
#define fccL248				'842L'
#define fccSPMA				'AMPS'
#define fccPCM4				'4MCP'
#define fccPCM8				'8MCP'
#define fccPMXA				'AXMP'
#define fccALAW				'WALA'

#define fccAREL				'LERA'
#define fccDolby            FCC('doby')
#define fccDDE              ' EDD'
#define fccDDEWAV           'WEDD'
#define fccIMAD             'IMAD' // XH_TRANS_AUDIO_IMAADPCM
#define fccADPCM		'MCPA'

#define fccAPE          FCC('APE ')
#define fccFLAC         FCC('FLAC')
#define fccOGG          FCC('OGG ')
#define fccAMR          FCC('AMR ')
#define fccIMA4         FCC('IMA4')
#define fccARRI			FCC('ARRI')
#define fccVorbis		FCC('VRBS')

/////////////////////////音频结束///////////////////////


//////////////////////////图片//////////////////////////
#define fccBIMP				'PMIB'
#define fccBMP				'PMIB'
#define fccTAGA				'AGAT'
#define fccTGA				'AGAT'
#define fccJEPG				'GPEJ'
#define fccJPG				'GPEJ'
#define fccPKEY				'YEKP'
#define fccKEY				'YEKP'
#define fccGIF				' FIG'
#define fccTIF				' FIT'
#define fccTIFF				' FIT'
#define fccPCX				' XCP'
#define fccPNG				' GNP'
#define fccPSD				' DSP'
#define fccDNG				' GND'
#define fccGIF2				'2FIG'
/////////////////////////图片结束/////////////////////////

#define fccAudioFrameGenerator FCC('A-->')

#endif

