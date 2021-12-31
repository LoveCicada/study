
#ifndef __def_media_file_api__header__
#define __def_media_file_api__header__

#include "./MediaFileReaderHelperAPI.h"
#include "./MediaFileSelectorAPI.h"

#ifdef TT_MEDIA_SOURCE_API

struct TTMediaFileReaderManageContext;

/** Reader�����������ڴ���VFR Reader, CFR Reader */
struct TT_MEDIA_SOURCE_API TTMediaFileReaderManage
{
public:
    static TTMediaFileReaderManage& instance();

public:
    // creator
    /**
     ����Reader, Ŀǰ��ΪVFR(��֡�ʶ�ȡ�ӿ�), CFR(�̶�֡��ͬ���ӿ�);
     @note VFR Reader ��Ҫ������ͬ����Ƶ��Ƶ
    */
    ITTMediaReader*         CreateMeidaReader(const wchar_t* TTMediaReaderType = TTMediaReaderType_VFR);

    /**
     ����Writer��ĿǰֻӴ TPFile ʵ�ַ�ʽ��Wirter
    */
    ITTMediaWriter*         CreateMeidaWriter(const wchar_t* TTMediaWriterType= TTMEDIAWRITER_Default);

    // selector
    /**
     ָ�������Selector�����ļ���ʱ������ָ�����ļ��Ĳ��
    */
    TTSelectPluginSpec&     SelectPluginSpec();

    /**
    ָ�����˳���Selector�����ļ���ʱ������ָ�����ļ��Ĳ����˳��
    */
    TTSelectPluginInOder&   SelectPluginInOrder();

private:
    TTMediaFileReaderManage();
    TTMediaFileReaderManage(const TTMediaFileReaderManage&);
    TTMediaFileReaderManage& operator =(const TTMediaFileReaderManage&);
    ~TTMediaFileReaderManage();
private:
    TTMediaFileReaderManageContext* m_pContext;
};

#endif

#endif
