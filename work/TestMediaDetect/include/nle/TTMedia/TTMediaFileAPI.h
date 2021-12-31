
#ifndef __def_media_file_api__header__
#define __def_media_file_api__header__

#include "./MediaFileReaderHelperAPI.h"
#include "./MediaFileSelectorAPI.h"

#ifdef TT_MEDIA_SOURCE_API

struct TTMediaFileReaderManageContext;

/** Reader管理器，用于创建VFR Reader, CFR Reader */
struct TT_MEDIA_SOURCE_API TTMediaFileReaderManage
{
public:
    static TTMediaFileReaderManage& instance();

public:
    // creator
    /**
     创建Reader, 目前分为VFR(变帧率读取接口), CFR(固定帧率同步接口);
     @note VFR Reader 需要调用者同步音频视频
    */
    ITTMediaReader*         CreateMeidaReader(const wchar_t* TTMediaReaderType = TTMediaReaderType_VFR);

    /**
     创建Writer，目前只哟 TPFile 实现方式的Wirter
    */
    ITTMediaWriter*         CreateMeidaWriter(const wchar_t* TTMediaWriterType= TTMEDIAWRITER_Default);

    // selector
    /**
     指定插件的Selector，打开文件的时候，用于指定打开文件的插件
    */
    TTSelectPluginSpec&     SelectPluginSpec();

    /**
    指定插件顺序的Selector，打开文件的时候，用于指定打开文件的插件的顺序
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
