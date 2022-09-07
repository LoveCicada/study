
#include "CXProcessLinux.h"
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using std::cout;
using std::endl;

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

    int pid = fork();
    if(pid == 0)
    {
        //! child process
        cout << __func__ << " " << __LINE__ << " " << "child process" << endl;
    }
    else if(pid == -1)
    {
        //! error
        
    }
    else
    {
        //! parent process

    }


    return bRet;
}

bool CXProcessLinux::Stop()
{
    bool bRet = true;


    return bRet;
}