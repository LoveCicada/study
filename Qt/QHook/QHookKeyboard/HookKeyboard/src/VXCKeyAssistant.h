
#pragma once

/*
@brief
*/
#include <functional>

class CKeyAssistant
{
public:
    typedef std::function<void(void* cmdData)> CallBack;

public:
    virtual ~CKeyAssistant() {}

public:
    CKeyAssistant();
    void Init();

    //! set callback
    void SetCallBack(CallBack cb);

public:
    virtual void Process() = 0;
    virtual void SetHook() = 0;
    virtual void UnSetHook() = 0;
    virtual void Active() = 0;
    virtual void UnActive() = 0;

protected:
    CallBack m_pCb;
};
