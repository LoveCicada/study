

#pragma once

#include <memory>
#include "../CXProcess.h"
#include "subprocess.hpp"
using namespace subprocess;
//class subprocess::popen;
typedef std::unique_ptr<subprocess::popen> CXSubProcessPtr;

class CXProcessLinux : public CXProcess
{
public:
    CXProcessLinux(); 
    ~CXProcessLinux();
public:
    virtual bool Init(const ProcessParams& params) override;
    virtual bool Release() override;
    virtual bool Start() override;
    virtual bool Stop() override;
    virtual bool Wait() override;  
    virtual bool GetResults(vector<string> &vs) override;
    virtual void PrintResults(std::vector<std::string> &vs) override;
private:
    CXSubProcessPtr m_pSubProcess;

};
