
#ifndef __def_media_file_selector__header__
#define __def_media_file_selector__header__

#include "./TTMediaFileReaderAPI.h"

#ifdef TT_MEDIA_SOURCE_API

struct TTSelectPluginSpecImpl;
struct TTSelectPluginInOderImpl;
struct TTSelectPluginInDefaultImpl;

/**ָ�������Selector������ָ�����ļ��Ĳ��*/
class TT_MEDIA_SOURCE_API TTSelectPluginSpec
{
public:
    static TTSelectPluginSpec& instance();

    /**
    ��ȡSelector name, �����ڴ��ļ���ָ�� Selector, ITTMediaReader.Open�ĵ�3������lpszSelectorName
    @see ITTMediaReader.Open
    */
    const wchar_t* GetName();
    /**
    ��ȡ���ж��ļ�����Ĳ����
    */
    int GetPluginNameArray(wchar_t**& ppPluginNameArray, int& pCount);
    /**
    ��������ʹ�õĲ����
    @param lpszPluginName �����
    @param bContinueIfFailed ָ���Ĳ���޷����ļ�ʱ���Ƿ�ʹ���������[(ture, ��), (false, ��)];
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

/**ָ�����˳���Selector���������ô��ļ������˳��, ���ļ��ǽ���ʹ��ָ���Ĳ��˳�������ļ�*/
class TT_MEDIA_SOURCE_API TTSelectPluginInOder
{
public:
    static TTSelectPluginInOder& instance();

    /**
    ��ȡSelector name, �����ڴ��ļ���ָ�� Selector, ITTMediaReader.Open�ĵ�3������lpszSelectorName
    @see ITTMediaReader.Open
    */
    const wchar_t* GetName();
    /**
    ��ȡ���ж��ļ�����Ĳ����
    */
    int GetPluginNameArray(wchar_t**& ppPluginNameArray, int& pCount);
    /**
    ���ô��ļ�ʱʹ�õĲ��˳��
    @param ppPluginNameArray ���������
    @param iCount ���������
    @param bContinueIfFailed ָ���Ĳ���޷����ļ�ʱ���Ƿ�ʹ���������[(ture, ��), (false, ��)];
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

/**Ĭ�ϵ�Selector, ���������˳�������ļ�*/
class TT_MEDIA_SOURCE_API TTSelectPluginDefault
{
public:
    static TTSelectPluginDefault& instance();

    /**
    ��ȡSelector name, �����ڴ��ļ���ָ�� Selector, ITTMediaReader.Open�ĵ�3������lpszSelectorName
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
