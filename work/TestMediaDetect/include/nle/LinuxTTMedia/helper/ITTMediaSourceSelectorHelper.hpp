
#ifndef __media_source_selector__helper__header__
#define __media_source_selector__helper__header__

#include "./TTMediaLogMsghelper.hpp"
#include "../ITTMediaSourcePlugin.hpp"

__declspec(novtable) struct ITTMediaSourceSelectorCImpl : public ITTMediaSourceSelector
{
    ITTMediaSourceSelectorCImpl(const wchar_t* lpszSelectorName = NULL)
        : m_lpszSelectorName(lpszSelectorName)
    {

    }

    ~ITTMediaSourceSelectorCImpl()
    {
   
    }

    virtual int Init(ITTMediaSourcePlugin** arrPlugins, int iPluginCount)
    {
        return ERR_Success;
    }
    
    virtual const wchar_t* GetSelectorName()
    {
        return m_lpszSelectorName;
    }
    
    virtual ITTMediaSourcePlugin* FindMediaSourcePlugin(const wchar_t* pFilename)
    {
        return NULL;
    }
    
    virtual ITTMediaSource* FindOpen(const wchar_t* lpszFilename, int uiOpenFlags, ITTNotify* pErrInfo)
    {
        ITTMediaSourcePlugin* pSourcePlugin = FindMediaSourcePlugin(lpszFilename);
        if (pSourcePlugin)
        {
            ITTMediaSource* pSource = pSourcePlugin->Create();
            if (pSource)
            {
                NOTIFY_Trace(pErrInfo, 0, L"try plugin: %s\n", pSourcePlugin->GetPluginname());
                if (pSource->Open(lpszFilename, uiOpenFlags, pErrInfo) > -1)
                {
                    NOTIFY_Trace(pErrInfo, 0, L"try plugin: %s. ok\n", pSourcePlugin->GetPluginname());
                    return pSource;
                }
            }
            pSource->Destroy();
        }
        return NULL;
    }

    virtual int Uninit()
    {
        return ERR_Success;
    }

    const wchar_t* m_lpszSelectorName;
};


#endif
