#ifndef __TTNEWSTANDARDDEF_H__
#define __TTNEWSTANDARDDEF_H__

//////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "./ITTAdaptWinDefine.h"
#include "./TTNewStandardPushMacro.h"

#define  MAX_COLORSPACE  64
enum TTESCANMODE
{
	ttScanMode_Invalid      = 0,
	ttScanMode_Field        = 1,   //���༭
	ttScanMode_Progressive  = 2    //֡�༭
};

enum TTEDEINTERLACETYPE 
{
	ttDeinterlaceType_Invalid        = 0,
	ttDeinterlaceType_TopFirst       = 1,   //��������
	ttDeinterlaceType_BottomFirst    = 2    //�׳�����
};

struct  stuTTVideoStandard
{
private:
	DWORD				m_dwVersion;                     //�汾��
	DWORD				m_dwEditWidth;                   //�༭�߶�
	DWORD				m_dwEditHeight;                  //�༭����
	DWORD				m_dwFrameRateFrequency;			 //֡��
	DWORD				m_dwFrameRateScale;				 //֡�ʱ���
	short				m_sWidthAspectRatio;             //������ȱ�
	short				m_sHeightAspectRatio;            //����߶ȱ�
	short				m_sWidthPixRatio;				 //���ؿ��ȱ�
	short				m_sHeightPixRatio;				 //���ظ߶ȱ�
	short				m_sViewNum;                      //3D˫Ŀ/������
	short				m_sBitCount;                     //λ��
	TTESCANMODE			m_eScanMode;					 //֡,���༭
	TTEDEINTERLACETYPE	m_eDeinterlaceType;				 //����/�׳�����
	TCHAR				m_chColorsSpace[MAX_COLORSPACE]; //��ɫ�ռ�

	//������ʽ����
public:
	//stuTTVideoStandard()
	//{
	//	m_dwVersion				= 0;                     
	//	m_dwEditWidth			= 0;                   
	//	m_dwEditHeight			= 0;                  
	//	m_dwFrameRateFrequency	= 0;			 
	//	m_dwFrameRateScale		= 0;				 
	//	m_sWidthAspectRatio		= 0;            
	//	m_sHeightAspectRatio	= 0;           
	//	m_sWidthPixRatio		= 1;				
	//	m_sHeightPixRatio		= 1;				 
	//	m_sViewNum				= 1;                     
	//	m_sBitCount				= 0;                     
	//	m_eScanMode				= ScanMode_Invalid;					 
	//	m_eDeinterlaceType		= DeinterlaceType_Invalid;				 
	//	memset(m_chColorsSpace, 0, MAX_COLORSPACE*sizeof(TCHAR));
	//}
	//virtual ~stuTTVideoStandard()
	//{
	//}

	BOOL Default()
	{
		m_dwVersion				= 2;                     
		m_dwEditWidth			= 720;                   
		m_dwEditHeight			= 576;                  
		m_dwFrameRateFrequency	= 25;			 
		m_dwFrameRateScale		= 1;				 
		m_sWidthAspectRatio		= 4;            
		m_sHeightAspectRatio	= 3;           
		m_sWidthPixRatio		= 1;				
		m_sHeightPixRatio		= 1;				 
		m_sViewNum				= 1;                     
		m_sBitCount				= 8;                     
		m_eScanMode				= ttScanMode_Invalid;					 
		m_eDeinterlaceType		= ttDeinterlaceType_Invalid;				 
		memset(m_chColorsSpace, 0, MAX_COLORSPACE*sizeof(TCHAR));
		return TRUE;
	}

	BOOL Reset()
	{
		m_dwVersion				= 2;                     
		m_dwEditWidth			= 0;                   
		m_dwEditHeight			= 0;                  
		m_dwFrameRateFrequency	= 0;			 
		m_dwFrameRateScale		= 0;				 
		m_sWidthAspectRatio		= 0;            
		m_sHeightAspectRatio	= 0;           
		m_sWidthPixRatio		= 1;				
		m_sHeightPixRatio		= 1;				 
		m_sViewNum				= 1;                     
		m_sBitCount				= 0;                     
		m_eScanMode				= ttScanMode_Invalid;					 
		m_eDeinterlaceType		= ttDeinterlaceType_Invalid;				 
		memset(m_chColorsSpace, 0, MAX_COLORSPACE*sizeof(TCHAR));
		return TRUE;
	}

	BOOL	Init(DWORD dwEditWidth, DWORD dwEditHeight, DWORD dwFrameRateFrequency, DWORD dwFrameRateScale,
		short sWidthAspectRatio, short sHeightAspectRatio, TTESCANMODE eScanMode, short sBitCount)
	{
		Reset();
		if(dwEditWidth <= 0 || dwEditHeight <= 0 || dwFrameRateFrequency <= 0 || dwFrameRateScale <= 0
			|| sWidthAspectRatio <= 0 || sHeightAspectRatio <= 0 || eScanMode <= 0 || sBitCount <= 0)
			return FALSE;

		m_dwEditWidth			= dwEditWidth;
		m_dwEditHeight			= dwEditHeight;
		m_dwFrameRateFrequency	= dwFrameRateFrequency;
		m_dwFrameRateScale		= dwFrameRateScale;
		m_sWidthAspectRatio		= sWidthAspectRatio;
		m_sHeightAspectRatio	= sHeightAspectRatio;
		m_sBitCount				= sBitCount;
		m_eScanMode				= eScanMode;
		memset(m_chColorsSpace, 0, sizeof(m_chColorsSpace));

		return TRUE;
	}

	BOOL	Init(DWORD dwEditWidth, DWORD dwEditHeight, DWORD dwFrameRateFrequency, DWORD dwFrameRateScale,
		short sWidthAspectRatio, short sHeightAspectRatio, TTESCANMODE eScanMode, short sBitCount,
		short sViewNum, TTEDEINTERLACETYPE eDeinterlaceType, TCHAR* pColorsSpace, short sWidthPixRation,
		short sHeightPixRation)
	{
		Reset();
		if(dwEditWidth <= 0 || dwEditHeight <= 0 || dwFrameRateFrequency <= 0 || dwFrameRateScale <= 0
			|| sWidthAspectRatio <= 0 || sHeightAspectRatio <= 0 || eScanMode <= 0 || sBitCount <= 0)
			return FALSE;

		m_dwEditWidth			= dwEditWidth;
		m_dwEditHeight			= dwEditHeight;
		m_dwFrameRateFrequency	= dwFrameRateFrequency;
		m_dwFrameRateScale		= dwFrameRateScale;
		m_sWidthAspectRatio		= sWidthAspectRatio;
		m_sHeightAspectRatio	= sHeightAspectRatio;
		m_sBitCount				= sBitCount;
		m_eScanMode				= eScanMode;
		m_sWidthPixRatio		= sWidthPixRation;
		m_sHeightPixRatio		= sHeightPixRation;
		m_sViewNum				= sViewNum;
		m_eDeinterlaceType		= eDeinterlaceType;
		if (pColorsSpace)
        {
#if 0
            _tcscpy_s(m_chColorsSpace, pColorsSpace);
#endif
        }

		else
			memset(m_chColorsSpace, 0, sizeof(m_chColorsSpace));

		return TRUE;
	}

	//���ð汾��
	DWORD	GetVersion() const
	{
		return  m_dwVersion;
	}
	//����༭
	DWORD	GetEditWidth() const 
	{
		return m_dwEditWidth;
	}
	DWORD	GetEditHeight() const 
	{
		return m_dwEditHeight;
	}
	BOOL	GetEditWidthHeight(DWORD& dwEditWidth, DWORD& dwEditHeight) const
	{
		dwEditWidth  = m_dwEditWidth;
		dwEditHeight = m_dwEditHeight;
		return TRUE;
	}
	BOOL	SetEditWidth(DWORD dwEditWidth)
	{
		if(dwEditWidth <= 0)
			return FALSE;

		m_dwEditWidth = dwEditWidth;
		return TRUE;
	}
	BOOL	SetEditHeight(DWORD dwEditHeight)
	{
		if(dwEditHeight <= 0 || dwEditHeight%2 == 1)
			return FALSE;

		m_dwEditHeight= dwEditHeight;
		return TRUE;

	}
	BOOL	SetEditWidthHeight(DWORD dwEditWidth, DWORD dwEditHeight)
	{
		if(dwEditWidth <= 0 || dwEditHeight <= 0 || dwEditHeight%2 == 1)
			return FALSE;

		m_dwEditWidth = dwEditWidth; 
		m_dwEditHeight= dwEditHeight;
		return TRUE;
	}

	//֡������
	BOOL	SetFrameRate(DWORD dwFrameRateFrequency, DWORD dwFrameRateScale)
	{
		if(dwFrameRateFrequency <= 0 || dwFrameRateScale <= 0)
			return FALSE;

		m_dwFrameRateFrequency = dwFrameRateFrequency;
		m_dwFrameRateScale	   = dwFrameRateScale;
		return TRUE;
	}
	BOOL	SetFrameRateFrequency(DWORD dwFrameRateFrequency)
	{
		if(dwFrameRateFrequency <= 0)
			return FALSE;

		m_dwFrameRateFrequency = dwFrameRateFrequency;
		return TRUE;
	}
	BOOL	SetFrameRateScale(DWORD dwFrameRateScale)
	{
		if(dwFrameRateScale <= 0)
			return FALSE;

		m_dwFrameRateScale	   = dwFrameRateScale;
		return TRUE;
	}
	double	GetFrameRate() const 
	{
		if( m_dwFrameRateScale <= 0)
			return 0.0;
		return (double)m_dwFrameRateFrequency/m_dwFrameRateScale;
	}
	DWORD	GetFrameRateFrequency() const
	{
		return m_dwFrameRateFrequency;
	}
	DWORD	GetFrameRateScale() const
	{
		return m_dwFrameRateScale;
	}

	//���߱�����
	BOOL	SetAspectRatio(short sWidthAspectRatio, short sHeightAspectRatio)
	{
		if(sWidthAspectRatio <= 0 || sHeightAspectRatio <= 0)
			return FALSE;

		m_sWidthAspectRatio  = sWidthAspectRatio;
		m_sHeightAspectRatio = sHeightAspectRatio;
		return TRUE;
	}

	BOOL	SetWidthAspectRatio(short sWidthAspectRatio)
	{
		if(sWidthAspectRatio <= 0)
			return FALSE;

		m_sWidthAspectRatio  = sWidthAspectRatio;
		return TRUE;
	}
	BOOL	SetHeightAspectRatio(short sHeightAspectRatio)
	{
		if(sHeightAspectRatio <= 0)
			return FALSE;

		m_sHeightAspectRatio = sHeightAspectRatio;
		return TRUE;
	}
	float	GetAspectRatio() const
	{
		if(m_sHeightAspectRatio <= 0)
			return 0.0;

		return (float)m_sWidthAspectRatio/m_sHeightAspectRatio;
	}
	BOOL	GetWidthHeightAspect(short& sWidthAspectRatio, short& sHeightAspectRatio) const
	{
		sWidthAspectRatio  = m_sWidthAspectRatio;
		sHeightAspectRatio = m_sHeightAspectRatio;
		return TRUE;
	}
	short	GetWidthAspectRatio() const 
	{
		return m_sWidthAspectRatio;
	}
	short	GetHeightAspectRatio() const
	{
		return m_sHeightAspectRatio;
	}

	BOOL	SetPixRatio(short sWidthPixRatio, short sHeightPixRatio)
	{
		if(sWidthPixRatio <= 0 || sHeightPixRatio <= 0)
			return FALSE;

		m_sWidthPixRatio  = sWidthPixRatio;
		m_sHeightPixRatio = sHeightPixRatio;
		return TRUE;
	}
	BOOL	SetWidthPixRatio(short sWidthPixRatio)
	{
		if(sWidthPixRatio <= 0)
			return FALSE;

		m_sWidthPixRatio  = sWidthPixRatio;
		return TRUE;
	}
	BOOL	SetHeightPixtRatio(short sHeightPixRatio)
	{
		if(sHeightPixRatio <= 0)
			return FALSE;

		m_sHeightPixRatio = sHeightPixRatio;
		return TRUE;
	}
	float	GetPixRatio()
	{
		if(m_sHeightPixRatio <= 0)
			return 0.0;

		return (float)m_sWidthPixRatio/m_sHeightPixRatio;
	}
	BOOL	GetWidthPixAspect(short& sWidthPixRatio, short& sHeightPixRatio) const
	{
		sWidthPixRatio  = m_sWidthPixRatio;
		sHeightPixRatio = m_sHeightPixRatio;
		return TRUE;
	}
	short	GetWidthPixRatio() const
	{
		return m_sWidthPixRatio;
	}
	short	GetHeightPixRatio() const
	{
		return m_sHeightPixRatio;
	}

	//��������
	BOOL	SetViewNum(short sViewNum)
	{
		if(sViewNum <= 0)
			return FALSE;

		m_sViewNum = sViewNum;
		return TRUE;
	}
	short	GetViewNum() const
	{
		return m_sViewNum;
	}

	//bitλ����
	BOOL	SetBitCount(short sBitCount)
	{
		if(sBitCount <= 0)
			return FALSE;
		m_sBitCount = sBitCount;
		return TRUE;
	}
	short	GetBitCount() const
	{
		return m_sBitCount;
	}

	// ��ɫ�ռ�
	BOOL	SetColorSpace(TCHAR* pColorSpace)
	{
		if(pColorSpace == NULL)
			return FALSE;
		memcpy(m_chColorsSpace, pColorSpace, sizeof(TCHAR) * MAX_COLORSPACE);	
		return TRUE;
	}
	TCHAR*	GetColorSpace()
	{
		return m_chColorsSpace;
	}
	const TCHAR* GetColorSpace() const 
	{
		return m_chColorsSpace;
	}

	//��ʽ�ж�
	BOOL	IsNstcFrameRation() const
	{
		if(2997 * m_dwFrameRateScale == 100 * m_dwFrameRateFrequency ||
			5994 * m_dwFrameRateScale == 100 * m_dwFrameRateFrequency)
			return TRUE;
		return FALSE;
	}
	BOOL    Is4KVideoStandard() const
	{
		if(m_dwEditWidth >= 3840 || m_dwEditHeight >= 2160)
			return TRUE;
		return FALSE;
	}
	BOOL	IsHDVideoStandard() const
	{
		if(m_sWidthAspectRatio * 9 == m_sHeightAspectRatio * 16)
			return TRUE;
		return FALSE;
	}
	BOOL	IsSDVideoStandard() const
	{
		if(m_sWidthAspectRatio * 3 == m_sHeightAspectRatio * 4)
			return TRUE;
		return FALSE;
	}
	BOOL	IsHDVVideoStandard() const
	{
		if(m_dwEditWidth == 1440 && m_dwEditHeight == 1080)
			return TRUE;
		return FALSE;
	}
	BOOL	IsProgressiveEdit() const 
	{
		if(m_eScanMode == ttScanMode_Progressive)
			return TRUE;
		return FALSE;
	}
	BOOL    IsInterlaceEdit() const
	{
		if(m_eScanMode == ttScanMode_Field)
			return TRUE;
		return FALSE;
	}
	BOOL    IsEqualFrameRate(const stuTTVideoStandard& stVideoStandard) const
	{
		if(m_dwFrameRateFrequency * stVideoStandard.GetFrameRateScale() == m_dwFrameRateScale * stVideoStandard.GetFrameRateFrequency())
			return TRUE;
		return FALSE;
	}
	BOOL	IsEqualAspectRatio(const stuTTVideoStandard& stVideoStandard) const
	{
		if(m_sWidthAspectRatio * stVideoStandard.GetHeightAspectRatio() == m_sHeightAspectRatio * stVideoStandard.GetWidthAspectRatio())
			return TRUE;
		return FALSE;
	}
	BOOL	Is4KColorSpace() const
	{
		if(wcscasecmp(m_chColorsSpace, L"Rec.2020") != 0)
			return  FALSE;
		return TRUE;
	}
	BOOL	IsHDColorSpace() const
	{
		if(wcscasecmp(m_chColorsSpace, L"Rec.709") != 0)
			return  FALSE;
		return TRUE;
	}
	BOOL	IsSDColorSpace() const
	{
		if(wcscasecmp(m_chColorsSpace, L"Rec.601") != 0)
			return  FALSE;
		return TRUE;
	}
	BOOL	IsStereoEdit() const
	{
		if(m_sViewNum >= 2)
			return TRUE;
		return FALSE;
	}

	BOOL	Is169VideoStandard() const
	{
		if(m_sWidthAspectRatio * 9 == m_sHeightAspectRatio * 16)
			return TRUE;
		return FALSE;
	}
	BOOL	IsValidVideoStandard() const
	{
		if(m_dwEditWidth <= 0 || m_dwEditHeight <= 0 || m_dwFrameRateFrequency <= 0 || m_dwFrameRateScale <= 0
			|| m_sWidthAspectRatio <= 0 || m_sHeightAspectRatio <= 0 || m_eScanMode <= 0 || m_sBitCount <= 0)
			return FALSE;
		return TRUE;
	}
	BOOL	IsEqualVideoStandard(const stuTTVideoStandard& stVideoStandard)const
	{
		if(m_dwEditWidth != stVideoStandard.m_dwEditWidth)
			return FALSE;
		if(m_dwEditHeight != stVideoStandard.m_dwEditHeight)
			return FALSE;
		if(m_dwFrameRateFrequency != stVideoStandard.m_dwFrameRateFrequency)
			return FALSE;
		if(m_dwFrameRateScale != stVideoStandard.m_dwFrameRateScale)
			return FALSE;
		if(m_sWidthAspectRatio != stVideoStandard.m_sWidthAspectRatio)
			return FALSE;
		if(m_sHeightAspectRatio != stVideoStandard.m_sHeightAspectRatio)
			return FALSE;
		if ( m_sWidthPixRatio != stVideoStandard.m_sWidthPixRatio )
			return FALSE;
		if ( m_sHeightPixRatio != stVideoStandard.m_sHeightPixRatio )
			return FALSE;
		if( m_sViewNum != stVideoStandard.m_sViewNum )
			return FALSE;
		if(m_sBitCount != stVideoStandard.m_sBitCount)
			return FALSE;
		if(m_eScanMode != stVideoStandard.m_eScanMode)
			return FALSE;
		if( m_eDeinterlaceType != stVideoStandard.m_eDeinterlaceType )
			return FALSE;

#if 0   //we need modify
		if( 0 != _tcscmp( m_chColorsSpace, stVideoStandard.m_chColorsSpace ) )
			return FALSE;
#endif
		return TRUE;
	}

	//�༭ģʽ
	BOOL	SetScanMode(TTESCANMODE eScanMode)
	{
		m_eScanMode = eScanMode;
		return TRUE;
	}
	TTESCANMODE	GetScanMode() const
	{
		return m_eScanMode;
	}
	BOOL		SetDeinterlaceType(TTEDEINTERLACETYPE eDeinterlaceType)
	{
		m_eDeinterlaceType = eDeinterlaceType;
		return TRUE;
	}
	TTEDEINTERLACETYPE	GetDeinterlaceType() const
	{
		return m_eDeinterlaceType;
	}

	//��ȡHASHֵ
	long GetHashKey() const
	{
		long lKey = 0;
		lKey = 0;
		lKey += m_dwVersion;
		lKey += m_dwEditHeight;
		lKey += m_dwEditWidth;
		lKey += m_dwFrameRateFrequency;
		lKey += m_dwFrameRateScale;
		lKey += m_sWidthAspectRatio;
		lKey += m_sHeightAspectRatio;
		lKey += m_sWidthPixRatio;
		lKey += m_sHeightPixRatio;
		lKey += m_sViewNum;
		lKey += m_sBitCount;
		lKey += m_eScanMode;
		lKey += m_eDeinterlaceType;

		//2020-06-04,zhangfan,�������ʼ��Ϊ0���������һЩ�����ֵ��Ӱ��lKey�ļ��㡣
		TCHAR pColorsSpace[MAX_COLORSPACE] = {0};

#if 0   //we need modify
		_tcscpy_s(pColorsSpace, m_chColorsSpace);
		//��������û����ɫ�ռ���ز���ɫ�ռ��ʼ��ΪRec.709
		if(IsHDVideoStandard() && 
			(lstrcmp(m_chColorsSpace, _T("")) == 0 || 
			lstrcmp(m_chColorsSpace, _T("Unknown")) == 0))
		{
			_tcscpy_s(pColorsSpace, _T("Rec.709"));
		}
#endif
		//��ɫ
		const TCHAR * p = pColorsSpace; 
		for (int i = 0; i < MAX_COLORSPACE; i++)
			lKey += p[i];
		return lKey;
	}

	BOOL	Copy(const stuTTVideoStandard& stVideoStandard)
	{
		m_dwVersion				= stVideoStandard.GetVersion();
		m_dwEditWidth			= stVideoStandard.GetEditWidth();
		m_dwEditHeight			= stVideoStandard.GetEditHeight();
		m_dwFrameRateFrequency	= stVideoStandard.GetFrameRateFrequency();
		m_dwFrameRateScale		= stVideoStandard.GetFrameRateScale();
		m_sWidthAspectRatio		= stVideoStandard.GetWidthAspectRatio();
		m_sHeightAspectRatio	= stVideoStandard.GetHeightAspectRatio();
		m_sWidthPixRatio		= stVideoStandard.GetWidthPixRatio();
		m_sHeightPixRatio		= stVideoStandard.GetHeightPixRatio();
		m_sViewNum				= stVideoStandard.GetViewNum();
		m_sBitCount				= stVideoStandard.GetBitCount();
		m_eScanMode				= stVideoStandard.GetScanMode();
		m_eDeinterlaceType		= stVideoStandard.GetDeinterlaceType();
		memcpy(m_chColorsSpace,stVideoStandard.GetColorSpace(), sizeof(TCHAR) * MAX_COLORSPACE);

		return TRUE;
	}

	// serialize & deserialize
	unsigned int GetSize() const
	{
		return 0
			+ sizeof(m_dwVersion)
			+ sizeof(m_dwEditWidth)
			+ sizeof(m_dwEditHeight)
			+ sizeof(m_dwFrameRateFrequency)
			+ sizeof(m_dwFrameRateScale)
			+ sizeof(m_sWidthAspectRatio)
			+ sizeof(m_sHeightAspectRatio)
			+ sizeof(m_sWidthPixRatio)
			+ sizeof(m_sHeightPixRatio)
			+ sizeof(m_sViewNum)
			+ sizeof(m_sBitCount)
			+ sizeof(m_eScanMode)
			+ sizeof(m_eDeinterlaceType)
			+ sizeof(m_chColorsSpace)
			;
	}

	unsigned int Save(BYTE* pBuffer, unsigned int iBufferSize)
	{
		BYTE* pBufIter = pBuffer;
		memcpy(pBufIter, &m_dwVersion, sizeof(m_dwVersion)); pBufIter += sizeof(m_dwVersion);
		memcpy(pBufIter, &m_dwEditWidth, sizeof(m_dwEditWidth)); pBufIter += sizeof(m_dwEditWidth);
		memcpy(pBufIter, &m_dwEditHeight, sizeof(m_dwEditHeight)); pBufIter += sizeof(m_dwEditHeight);
		memcpy(pBufIter, &m_dwFrameRateFrequency, sizeof(m_dwFrameRateFrequency)); pBufIter += sizeof(m_dwFrameRateFrequency);
		memcpy(pBufIter, &m_dwFrameRateScale, sizeof(m_dwFrameRateScale)); pBufIter += sizeof(m_dwFrameRateScale);
		memcpy(pBufIter, &m_sWidthAspectRatio, sizeof(m_sWidthAspectRatio)); pBufIter += sizeof(m_sWidthAspectRatio);
		memcpy(pBufIter, &m_sHeightAspectRatio, sizeof(m_sHeightAspectRatio)); pBufIter += sizeof(m_sHeightAspectRatio);
		memcpy(pBufIter, &m_sWidthPixRatio, sizeof(m_sWidthPixRatio)); pBufIter += sizeof(m_sWidthPixRatio);
		memcpy(pBufIter, &m_sHeightPixRatio, sizeof(m_sHeightPixRatio)); pBufIter += sizeof(m_sHeightPixRatio);
		memcpy(pBufIter, &m_sViewNum, sizeof(m_sViewNum)); pBufIter += sizeof(m_sViewNum);
		memcpy(pBufIter, &m_sBitCount, sizeof(m_sBitCount)); pBufIter += sizeof(m_sBitCount);
		memcpy(pBufIter, &m_eScanMode, sizeof(m_eScanMode)); pBufIter += sizeof(m_eScanMode);
		memcpy(pBufIter, &m_eDeinterlaceType, sizeof(m_eDeinterlaceType)); pBufIter += sizeof(m_eDeinterlaceType);
		memcpy(pBufIter, m_chColorsSpace, sizeof(m_chColorsSpace)); pBufIter += sizeof(m_chColorsSpace);

		return pBufIter - pBuffer;
	}

	unsigned int Restore(BYTE* pBuffer, unsigned int iBufferSize)
	{
		BYTE* pBufIter = pBuffer;
		memcpy(&m_dwVersion, pBufIter, sizeof(m_dwVersion)); pBufIter += sizeof(m_dwVersion);
		memcpy(&m_dwEditWidth, pBufIter, sizeof(m_dwEditWidth)); pBufIter += sizeof(m_dwEditWidth);
		memcpy(&m_dwEditHeight, pBufIter, sizeof(m_dwEditHeight)); pBufIter += sizeof(m_dwEditHeight);
		memcpy(&m_dwFrameRateFrequency, pBufIter, sizeof(m_dwFrameRateFrequency)); pBufIter += sizeof(m_dwFrameRateFrequency);
		memcpy(&m_dwFrameRateScale, pBufIter, sizeof(m_dwFrameRateScale)); pBufIter += sizeof(m_dwFrameRateScale);
		memcpy(&m_sWidthAspectRatio, pBufIter, sizeof(m_sWidthAspectRatio)); pBufIter += sizeof(m_sWidthAspectRatio);
		memcpy(&m_sHeightAspectRatio, pBufIter, sizeof(m_sHeightAspectRatio)); pBufIter += sizeof(m_sHeightAspectRatio);
		memcpy(&m_sWidthPixRatio, pBufIter, sizeof(m_sWidthPixRatio)); pBufIter += sizeof(m_sWidthPixRatio);
		memcpy(&m_sHeightPixRatio, pBufIter, sizeof(m_sHeightPixRatio)); pBufIter += sizeof(m_sHeightPixRatio);
		memcpy(&m_sViewNum, pBufIter, sizeof(m_sViewNum)); pBufIter += sizeof(m_sViewNum);
		memcpy(&m_sBitCount, pBufIter, sizeof(m_sBitCount)); pBufIter += sizeof(m_sBitCount);
		memcpy(&m_eScanMode, pBufIter, sizeof(m_eScanMode)); pBufIter += sizeof(m_eScanMode);
		memcpy(&m_eDeinterlaceType, pBufIter, sizeof(m_eDeinterlaceType)); pBufIter += sizeof(m_eDeinterlaceType);
		memcpy(m_chColorsSpace, pBufIter, sizeof(m_chColorsSpace)); pBufIter += sizeof(m_chColorsSpace);

		return pBufIter - pBuffer;
	}

};

#include "./TTNewStandardPopMacro.h"

#endif // __TTNEWSTANDARDDEF_H__
