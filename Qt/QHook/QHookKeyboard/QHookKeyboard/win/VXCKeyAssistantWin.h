
#pragma once

#include "../VXCKeyAssistant.h"
/*
@brief
*/

class CKeyAssistantWin final : public CKeyAssistant
{
public:
    CKeyAssistantWin();
    ~CKeyAssistantWin();
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
