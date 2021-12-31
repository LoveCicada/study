 /*********************************************************
 * Filename: SBT_MediaDetect.h
 * Contents: Class/Interface of Media Info Detection SDK 
 * Authors: Qiaohai Pan, Bo Song
 * Date: July, 22, 2003
 * Revised: Sep., 30, 2003  
 * Version 2.0.1.1, bulid 031010
 * All Rights Reserved
 * Media Process & Analysis Group
 * Sobey Basic Research Department
 * Sobey Inc, P.R.China
 **********************************************************
 * [Version history]
 *
 * Version 1.0.1.1: for evaluation, some very basic media file info detecting
 *
 * Version 2.0.1.1: for release, 
 *                  (1) add GOP info and FOURCC detecting
 *                  (2) correct errors for detect AVI file
 *                  (3) more reliable detect results
 *                  (4) improved detect speed
 * Version 2.0.2.2: based on 2.0.1.1
 *                  (1) modify erros in fourcc and media type ID detecting
 * Version 2.0.3.5: based on 2.0.2.2
 *                  (1) modify erros in sample ICON extractor for MPEG2 AVI file
 *                  (2) add M-JPEG detecting
 * Version 2.0.4.6: base on V2.0.3.5
 *                  (1) removed all resource leaks
 * Version 2.0.5.7: base on V2.0.5.7
 *                  (1) safe detecting avi and wav file info
 *          
*/


#if !defined(AFX_SBT_MEDIADETECT_H__6F98D096_5233_4552_813B_F62C7E675423__INCLUDED_)
#define AFX_SBT_MEDIADETECT_H__6F98D096_5233_4552_813B_F62C7E675423__INCLUDED_



#include "../../LinuxTTMedia/ITTAdaptWinDefine.h"
#include "SBT_TransBaseDefine.h"
#include <cstring>

/////////////////////////// struct defination //////////////////////////
struct XH_GOP_INFO_ST  //GOP info struct
{
	UINT nGopCount;	
	UINT nGOP_I_FrameCount;
	UINT nGOP_B_FrameCount;
	UINT nGOP_P_FrameCount;
	XH_GOP_INFO_ST()
	{
		nGopCount = 0;
		nGOP_I_FrameCount = 0;
		nGOP_B_FrameCount = 0;
		nGOP_P_FrameCount = 0;
	}
};

struct XH_MEDIA_BASE_INFO_ST  //media base info 
{
	std::string strFileName;         //file name (CComBSTR --> string)
	BOOL bReadAble;               //readable flag
	BOOL bWriteAble;              //to indicate if the file is during creating/transfering
								  // = FALSE: file is creating/transfering
	                              // = TRUE:  file is not creating/transfering, and it could be writable
	LONGLONG llFileSize;          //file size in BYTE count

	int nFileFormatID;            //file format ID,see defination in "SBT_TransBaseDefine.h"
 
	int nVideoMediaTypeID;        //video media format ID, see defination in "SBT_TransBaseDefine.h"
	BOOL bVideoStreamExist;       //TRUE: video stream exist
	int nVideoStreamNum;          //video stream num, commonly = 1
	LONGLONG llVideoDuration;     //video stream duration, in 100ns
	double dbFrameRate;           //video frame rate
	int nFrameNum;                //total frame number count 
	BITMAPINFOHEADER stBmpInfo;   //bitmap info of the video stream

	int nAudioMediaTypeID;        //audio media format ID, see defination in "SBT_TransBaseDefine.h"
	BOOL bAudioStreamExist;       //TRUE: audio stream exist
	int nAudioStreamNum;          //audio stream num, commonly = 1
	LONGLONG llAudioDuration;     //audio stream duration, in 100ns
	WAVEFORMATEX stWavFormat;     //audio WAV format information

	///////////////extra information
	XH_GOP_INFO_ST stGOPInfo;     //valid for MPEG2 Matrox AVI file
	FOURCC dwFourcc;              //only valid for AVI file
	
	//////////////reserved data;
	DWORD dwReserved[8];          //extend use
                                  //dwReserved[0]: for video yuv sample mode,1 for 420,2 for 422,3 for 411,4 for 444
                                  //dwReserved[1]: for video bitrate,in bps unit
                                  //dwReserved[2]: for EC StartPos,in edit unit
                                  //dwReserved[3]: for VBR MP3, 0 for CBR , 1 for VBR
                                  //               bit1-bit5 for wav dolbyE ContainerBitWidth(16,20 or 24)
                                  //               mxf StartTimecode(TimecodeComponent) (for mxf)
                                  //dwReserved[4]: if = 1, DV AVI TYPE1; default = 0
                                  //               bit1-bit31 for wav dolbyE FrameNum
                                  //dwReserved[5]: 0 is not dbe, otherwise is dbe: 1--stream0 is dbe, 2--stream1 is dbe, 4--stream2 is dbe, 8--stream3 is dbe...
                                  //dwReserved[6]: bit0 for DF or NDF. dwReserved[6] bit0 is 1 for DF, 0 for NDF.
                                  //dwReserved[6]: bit1 for progressive/interlaced. dwReserved[6] bit1 is 1 for progressive, 0 for interlaced.
                                  //dwReserved[6]: bit2 for video 10bit/8bit compresion. dwReserved[6] bit2 is 1 for 10bit, 0 for 8bit.
                                  //dwReserved[6]: bit3 for mxf closed caption. 1 for CC, 0 for No CC.
								  //dwReserved[6]: bit4 is last_frame_incomplete_flag. 0: last frame is complete, 1: last frame is incomplete.
                                  //dwReserved[6]: bit5 for top/bottom field first. 0 = tff; 1 = bff.
                                  //dwReserved[6]: bit6-7 for aspect ratio: 0, unknown; 1, 1:1; 2, 4:3; 3, 16:9. 
                                  //dwReserved[6]: bit8 indicate the Fixed Frame Rate or Variable Frame Rate
                                  //               bit8 is 1 for Variable Frame Rate
                                  //               bit8 is 0 for Fixed	 Frame Rate
                                  //               bit9 is 1 for mix dolbyE&Pcm
                                  //               bit10 is 1 for dolbyE only
                                  //               bit11 for aspect ratio, bit11+bit7+bit6:0, unknown; 1, 1:1; 2, 4:3; 3, 16:9, 4,2.21:1, 5,5:4, 6,3:2
                                  //               bit12-13 indicate that how the decoder works: 1 for CloseGopAsync, 2 for OpenGopAsync, 3 for Sync 
                                  //               bit14-21 profile_and_level_indication for MPEG2
                                  //
                                  //               0x14 =     HP@HL     0x16 =     HP@H-14			  
                                  //               0x44 =     MP@HL     0x46 =     MP@H-14     0x48 =  MP@ML
                                  //               0x82 =   422P@HL     0x85 =   422P@ML			
                                  //   
                                  //               bit14-21 profile_idc for H264/H265(UnSupported)
                                  //               bit22-29 level_idc   for H264/H265(UnSupported)
                                  //
                                  //               bit30-31 for Rotation:  0x0 = 0��, 0x1 = 90��, 0x2 = 180��, 0x3 = 270��
                                  //
                                  //dwReserved[7~7]::bit31(set): create dvbs when create index;
                                  //               bit0-bit7:afd
 	                              //               bit8-bit11: HDR Clip Type: 0x0 = Unknown, 0x1 = HDR Vivid, 0x2 = SR-Live

	

	///////////////////////////////default
	XH_MEDIA_BASE_INFO_ST()
	{
		bReadAble = FALSE;
		bWriteAble = FALSE;
		llFileSize = 0;
		nFileFormatID = 0x0801;
		nVideoMediaTypeID = 0x0001;
		bVideoStreamExist = FALSE;
		nVideoStreamNum = 0;
		llVideoDuration = 0;
		dbFrameRate = 0;
		nFrameNum = 0;
		memset(&stBmpInfo, 0, sizeof(BITMAPINFOHEADER));

		nAudioMediaTypeID = 0x0001;
		bAudioStreamExist = FALSE;
		nAudioStreamNum = 0;
		llAudioDuration = 0;
		memset(&stWavFormat, 0, sizeof(WAVEFORMATEX));
		
		//new add
		dwFourcc = 0;

		memset(&dwReserved[0],0,sizeof(DWORD)*8);
	}
}; 




#endif // !defined(AFX_SBT_MEDIADETECT_H__6F98D096_5233_4552_813B_F62C7E675423__INCLUDED_)
