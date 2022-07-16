
#pragma once

#include "plugin.h"
#include "msgPlugin.h"

class Server
{
public:
    Server();
    ~Server();
    
public:
    void RegisterPlugin();
    void UnRegisterPlugin();
    void NotifyPlugin();
private:
    IPluginVec m_pluginVec;

};