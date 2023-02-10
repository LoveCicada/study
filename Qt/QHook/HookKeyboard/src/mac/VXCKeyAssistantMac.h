
#pragma once

#include "../VXCKeyAssistant.h"

#if defined(__APPLE__) && defined(__MACH__)

/*
@brief
*/

class CKeyAssistantMac final : public CKeyAssistant
{
public:
    CKeyAssistantMac();
    ~CKeyAssistantMac();
    void InitHanlde();

public:
    virtual void Process() override;

    /*
     * @brief SetHook() <--> UnSetHook()
     *           1:1
     */
    virtual void SetHook() override;
    virtual void UnSetHook() override;
    virtual void Active() override;
    virtual void UnActive() override;
};

#endif