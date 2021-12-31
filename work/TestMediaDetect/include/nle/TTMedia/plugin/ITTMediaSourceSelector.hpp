
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
 @brief Selector管理器，管理ITTMediaSourceSelector
 */
struct ITTMediaSourceSelectorManager
{
    /** 
     @brief 获取对应名字的ITTMediaSourceSelector
     @param guidSelecltor selecor的id
     @return 找到!= NULL, 否则NULL
     */
    virtual ITTMediaSourceSelector* FindSelector(const wchar_t* name) = 0;

    /** 
     @brief 获取对应GUID的ITTMediaSourceSelector
     @param guidSelecltor selecor的id
     @return 找到!= NULL, 否则NULL
     */
    virtual ITTMediaSourceSelector* FindSelector(const GUID& guidSelecltor) = 0;

    /** 
     @brief 注册新的ITTMediaSourceSelector
     @param ITTMediaSourceSelector
     @remark 如果ID已经使用，将导致注册失败； 在注册ITTMediaSourceSelector前，一定要先注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Registe(ITTMediaSourceSelector*) = 0;
    /** 
     @brief 取消注册ITTMediaSourceSelector
     @param ITTMediaSourceSelector
     @remark 在反注册ITTMediaSourcePlugin前，一定要先反注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Unregiste(ITTMediaSourceSelector*) = 0;

    /** 
     @brief 返回所有注册的ITTMediaSourceSelector
     */
    virtual ITTMediaSourceSelector** GetSelector() = 0;

    /** 
     @brief 返回注册的ITTMediaSourceSelector的个数
     */
    virtual int GetSelectorCount() = 0;
};

/** 
 @brief 源插件管理器，管理ITTMediaSourcePlugin
 */
struct ITTMediaSourcePluginManager
{
    /** 
     @brief 注册新的ITTMediaSourcePlugin, 如果ITTMediaSourcePlugin的名字已经使用则返回失败
     @remark 如果ID已经使用，将导致注册失败； 在注册ITTMediaSourceSelector前，一定要先注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit；注册完毕需要调用ITTMediaSourcePluginManager::UpdateMediaSourcePlugin更新信息
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Registe(ITTMediaSourcePlugin*) = 0;

    /** 
     @brief 取消注册指定的ITTMediaSourcePlugin
     @remark 在反注册ITTMediaSourcePlugin前，一定要先反注册ITTMediaSourcePlugin，否则会导致ITTMediaSourceSelector频繁调用ITTMediaSourceSelector::Init以及ITTMediaSourceSelector::Uninit；注册完毕需要调用ITTMediaSourcePluginManager::UpdateMediaSourcePlugin更新信息
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Unregiste(ITTMediaSourcePlugin*) = 0;

    /** 
     @brief 更新MediaSourcePlguin信息, 例如：通知更新ITTMediaSourceSelector
     */
    virtual int UpdateMediaSourcePlugin() = 0;

    /** 
     @brief 返回所有注册的ITTMediaSourceSelector
     */
    virtual ITTMediaSourcePlugin** GetSourcePlugin() = 0;

    /** 
     @brief 返回注册的ITTMediaSourcePlugin的个数
     */
    virtual int GetSourcePluginCount() = 0;
};

/** 
 @brief 当ITTMediaSourceSelectorManager打开文件时，查找合适的ITTMediaSourcePlugin，以实现采用不同的策略打开文件
 */
struct ITTMediaSourceSelector
{
    /** 
     @brief 初始化Selector, 当向ITTMediaSourceSelectorManager注册时，ITTMediaSourceSelectorManager的实现负责初始化Selector
     @param arrPlugins 当前ITTMediaSourceSelectorManager实现所支持的ITTMediaSourcePlugin
     @param iPluginCount ITTMediaSourcePlugin的个数
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Init(ITTMediaSourcePlugin** arrPlugins, int iPluginCount) = 0;

    /** 
     @brief 返回Selector 的名字
     */
    virtual const wchar_t* GetSelectorName() = 0;
    
    /** 
     @brief 根据传入的文件返回合适的ITTMediaSourcePlugin
     @param pFilename 将要打开的文件名或者路径名
     @return 找到 != NULL, 否则 NULL
     */
    virtual ITTMediaSourcePlugin* FindMediaSourcePlugin(const wchar_t* pFilename) = 0;

    /** 
     @brief 根据传入的文件返回合适的ITTMediaSource
     @param pFilename 将要打开的文件名或者路径名
     @return 找到 != NULL, 否则 NULL
     */
    virtual ITTMediaSource* FindOpen(const wchar_t* lpszFilename, int uiOpenFlags, ITTNotify* pErrorInfo) = 0;

    /** 
     @brief 反初始化Selector, 向ITTMediaSourceSelectorManager反注册时，有ITTMediaSourceSelectorManager的实现调用
     @return 成功 >= 0, 失败 < 0
     */
    virtual int Uninit() = 0;
};


#endif
