
#include "CXProcessLinux.h"
#include <unistd.h>
#include <sys/wait.h>
//#include "subprocess.hpp"
#include <iostream>
using std::cout;
using std::endl;

CXProcessLinux::CXProcessLinux()
{

}

CXProcessLinux::~CXProcessLinux()
{
    
}

bool CXProcessLinux::Init(const ProcessParams& params)
{
    bool bRet = true;

    m_processParams = params;

    return bRet;
}

bool CXProcessLinux::Release()
{
    bool bRet = true;


    return bRet;
}

bool CXProcessLinux::Start()
{
    bool bRet = true;

    std::string cmd;
    std::vector<std::string> argv;
    m_pSubProcess.reset(new subprocess::popen(m_processParams.cmd, m_processParams.args));
    
    return bRet;
}

bool CXProcessLinux::Stop()
{
    bool bRet = true;


    return bRet;
}

bool CXProcessLinux::Wait()
{
    bool bRet = true;

    m_pSubProcess->wait();

    return bRet;
}

bool CXProcessLinux::GetResults(vector<string> &vs)
{
    bool bRet = true;

    bRet = m_pSubProcess->getResults(vs);

    return bRet;
}

void CXProcessLinux::PrintResults(std::vector<std::string> &vs)
{
    m_pSubProcess->printResults(vs);
}