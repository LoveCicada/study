
#ifndef __media_source_selector__header__
#define __media_source_selector__header__

#include <Guiddef.h>
#include "./ITTMediaSourcePlugin.hpp"
#include "./ITTMediaPlugin.hpp"

#define USING_AnalyzeExtName    "select.AnalyzeExtName"
#define USING_Configurations    "select.ByConfigurations"
#define USING_ConfigExtName     "select.ConfigExtName"
#define USING_Priority          "select.ByPriority"
#define USING_None              "select.none"

struct ITTNotify;
struct ITTMediaSource;
struct ITTMediaSourcePlugin;
struct ITTMediaSourcePluginManager;
struct ITTMediaSourceSelector;


/** 
 @brief Selector������������ITTMediaSourceSelector
 */
struct ITTMediaSourceSelectorManager
{
    /** 
     @brief ��ȡ��Ӧ���ֵ�ITTMediaSourceSelector
     @param guidSelecltor selecor��id
     @return �ҵ�!= NULL, ����NULL
     */
    virtual ITTMediaSourceSelector* FindSelector(const wchar_t* name) = 0;

    /** 
     @brief ��ȡ��ӦGUID��ITTMediaSourceSelector
     @param guidSelecltor selecor��id
     @return �ҵ�!= NULL, ����NULL
     */
    virtual ITTMediaSourceSelector* FindSelector(const GUID& guidSelecltor) = 0;

    /** 
     @brief ע���µ�ITTMediaSourceSelector
     @param ITTMediaSourceSelector
     @remark ���ID�Ѿ�ʹ�ã�������ע��ʧ�ܣ� ��ע��ITTMediaSourceSelectorǰ��һ��Ҫ��ע��ITTMediaSourcePlugin������ᵼ��ITTMediaSourceSelectorƵ������ITTMediaSourceSelector::Init�Լ�ITTMediaSourceSelector::Uninit
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Registe(ITTMediaSourceSelector*) = 0;
    /** 
     @brief ȡ��ע��ITTMediaSourceSelector
     @param ITTMediaSourceSelector
     @remark �ڷ�ע��ITTMediaSourcePluginǰ��һ��Ҫ�ȷ�ע��ITTMediaSourcePlugin������ᵼ��ITTMediaSourceSelectorƵ������ITTMediaSourceSelector::Init�Լ�ITTMediaSourceSelector::Uninit
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Unregiste(ITTMediaSourceSelector*) = 0;

    /** 
     @brief ��������ע���ITTMediaSourceSelector
     */
    virtual ITTMediaSourceSelector** GetSelector() = 0;

    /** 
     @brief ����ע���ITTMediaSourceSelector�ĸ���
     */
    virtual int GetSelectorCount() = 0;
};

/** 
 @brief Դ���������������ITTMediaSourcePlugin
 */
struct ITTMediaSourcePluginManager
{
    /** 
     @brief ע���µ�ITTMediaSourcePlugin, ���ITTMediaSourcePlugin�������Ѿ�ʹ���򷵻�ʧ��
     @remark ���ID�Ѿ�ʹ�ã�������ע��ʧ�ܣ� ��ע��ITTMediaSourceSelectorǰ��һ��Ҫ��ע��ITTMediaSourcePlugin������ᵼ��ITTMediaSourceSelectorƵ������ITTMediaSourceSelector::Init�Լ�ITTMediaSourceSelector::Uninit��ע�������Ҫ����ITTMediaSourcePluginManager::UpdateMediaSourcePlugin������Ϣ
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Registe(ITTMediaSourcePlugin*) = 0;

    /** 
     @brief ȡ��ע��ָ����ITTMediaSourcePlugin
     @remark �ڷ�ע��ITTMediaSourcePluginǰ��һ��Ҫ�ȷ�ע��ITTMediaSourcePlugin������ᵼ��ITTMediaSourceSelectorƵ������ITTMediaSourceSelector::Init�Լ�ITTMediaSourceSelector::Uninit��ע�������Ҫ����ITTMediaSourcePluginManager::UpdateMediaSourcePlugin������Ϣ
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Unregiste(ITTMediaSourcePlugin*) = 0;

    /** 
     @brief ����MediaSourcePlguin��Ϣ, ���磺֪ͨ����ITTMediaSourceSelector
     */
    virtual int UpdateMediaSourcePlugin() = 0;

    /** 
     @brief ��������ע���ITTMediaSourceSelector
     */
    virtual ITTMediaSourcePlugin** GetSourcePlugin() = 0;

    /** 
     @brief ����ע���ITTMediaSourcePlugin�ĸ���
     */
    virtual int GetSourcePluginCount() = 0;
};

/** 
 @brief ��ITTMediaSourceSelectorManager���ļ�ʱ�����Һ��ʵ�ITTMediaSourcePlugin����ʵ�ֲ��ò�ͬ�Ĳ��Դ��ļ�
 */
struct ITTMediaSourceSelector
{
    /** 
     @brief ��ʼ��Selector, ����ITTMediaSourceSelectorManagerע��ʱ��ITTMediaSourceSelectorManager��ʵ�ָ����ʼ��Selector
     @param arrPlugins ��ǰITTMediaSourceSelectorManagerʵ����֧�ֵ�ITTMediaSourcePlugin
     @param iPluginCount ITTMediaSourcePlugin�ĸ���
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Init(ITTMediaSourcePlugin** arrPlugins, int iPluginCount) = 0;

    /** 
     @brief ����Selector ������
     */
    virtual const wchar_t* GetSelectorName() = 0;
    
    /** 
     @brief ���ݴ�����ļ����غ��ʵ�ITTMediaSourcePlugin
     @param pFilename ��Ҫ�򿪵��ļ�������·����
     @return �ҵ� != NULL, ���� NULL
     */
    virtual ITTMediaSourcePlugin* FindMediaSourcePlugin(const wchar_t* pFilename) = 0;

    /** 
     @brief ���ݴ�����ļ����غ��ʵ�ITTMediaSource
     @param pFilename ��Ҫ�򿪵��ļ�������·����
     @return �ҵ� != NULL, ���� NULL
     */
    virtual ITTMediaSource* FindOpen(const wchar_t* lpszFilename, int uiOpenFlags, ITTNotify* pErrorInfo) = 0;

    /** 
     @brief ����ʼ��Selector, ��ITTMediaSourceSelectorManager��ע��ʱ����ITTMediaSourceSelectorManager��ʵ�ֵ���
     @return �ɹ� >= 0, ʧ�� < 0
     */
    virtual int Uninit() = 0;
};


#endif
