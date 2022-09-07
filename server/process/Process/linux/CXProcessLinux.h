

#pragma once

#include "../CXProcess.h"

class CXProcessLinux : public CXProcess
{
public:

public:
    virtual bool Init(const ProcessParams& params) override;
    virtual bool Release() override;
    virtual bool Start() override;
    virtual bool Stop() override;  


};
