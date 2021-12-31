
#ifndef __def_media_file_selector__header__
#define __def_media_file_selector__header__

#include "./TTMediaFileReaderAPI.h"

#ifdef TT_MEDIA_SOURCE_API

struct TTSelectPluginSpecImpl;
struct TTSelectPluginInOderImpl;
struct TTSelectPluginInDefaultImpl;

/**指定插件的Selector，用于指定打开文件的插件*/
class TT_MEDIA_SOURCE_API TTSelectPluginSpec
{
public:
    static TTSelectPluginSpec& instance();

    /**
    获取Selector name, 用于在打开文件是指定 Selector, ITTMediaReader.Open的第3个参数lpszSelectorName
    @see ITTMediaReader.Open
    */
    const wchar_t* GetName();
    /**
    获取所有读文件插件的插件名
    */
    int GetPluginNameArray(wchar_t**& ppPluginNameArray, int& pCount);
    /**
    设置优先使用的插件名
    @param lpszPluginName 插件名
    @param bContinueIfFailed 指定的插件无法打开文件时，是否使用其他插件[(ture, 是), (false, 否)];
    */
    int SetCurrentPlugin(const wchar_t* lpszPluginName, bool bContinueIfFailed = false);

private:
    TTSelectPluginSpec();
    TTSelectPluginSpec(const TTSelectPluginSpec&);
    TTSelectPluginSpec& operator =(const TTSelectPluginSpec&);
    ~TTSelectPluginSpec();
private:
    TTSelectPluginSpecImpl* m_pContext;
};

/**指定插件顺序的Selector，用于设置打开文件插件的顺序, 打开文件是将会使用指定的插件顺序来打开文件*/
class TT_MEDIA_SOURCE_API TTSelectPluginInOder
{
public:
    static TTSelectPluginInOder& instance();

    /**
    获取Selector name, 用于在打开文件是指定 Selector, ITTMediaReader.Open的第3个参数lpszSelectorName
    @see ITTMediaReader.Open
    */
    const wchar_t* GetName();
    /**
    获取所有读文件插件的插件名
    */
    int GetPluginNameArray(wchar_t**& ppPluginNameArray, int& pCount);
    /**
    设置打开文件时使用的插件顺序
    @param ppPluginNameArray 插件名数组
    @param iCount 插件名个数
    @param bContinueIfFailed 指定的插件无法打开文件时，是否使用其他插件[(ture, 是), (false, 否)];
    */
    int SetPluginOrder(wchar_t** ppPluginNameArray, int iCount, bool bContinueIfFailed = false);

private:
    TTSelectPluginInOder();
    TTSelectPluginInOder(const TTSelectPluginInOder&);
    TTSelectPluginInOder& operator =(const TTSelectPluginInOder&);
    ~TTSelectPluginInOder();
private:
    TTSelectPluginInOderImpl* m_pContext;
};

/**默认的Selector, 按插件加载顺序来打开文件*/
class TT_MEDIA_SOURCE_API TTSelectPluginDefault
{
public:
    static TTSelectPluginDefault& instance();

    /**
    获取Selector name, 用于在打开文件是指定 Selector, ITTMediaReader.Open的第3个参数lpszSelectorName
    @see ITTMediaReader.Open
    */
    const wchar_t* GetName();
private:
    TTSelectPluginDefault();
    TTSelectPluginDefault(const TTSelectPluginDefault&);
    TTSelectPluginDefault& operator =(const TTSelectPluginDefault&);
    ~TTSelectPluginDefault();
private:
    TTSelectPluginInDefaultImpl* m_pContext;
};

#endif

#endif
