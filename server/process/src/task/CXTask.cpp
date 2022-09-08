

#include "CXTask.h"
#include <iostream>
using namespace std;


bool CXSubTask::Run()
{
    bool bRet = true;

    CXProcess* p = CXProcess::Create();
    CXProcess::ProcessParams processParams;
    processParams.name = m_execParam.name;
    processParams.cmd = m_execParam.cmd;
    processParams.args = m_execParam.args;

    bRet = p->Init(processParams);
    if(!bRet)
    {
        cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
    }

    bRet = p->Start();
    if(!bRet)
    {
        cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
    }

    bRet = p->Wait();
    if(!bRet)
    {
        cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
    }

    vector<string> vs;
    bRet = p->GetResults(vs);
    if(!bRet)
    {
        cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
    }

//#ifdef _DEBUG
    p->PrintResults(vs); 
//#endif

    if(p)
    {
        delete p;
    }

    return bRet;
}

//////////////////////////////////////////////

bool CXTask::AddTask(CXSubTaskPtr& pTask)
{
    bool bRet = true;

    if(!pTask)
    {
        return false;
    }
    m_pTaskVec.push_back(pTask);

    return bRet;
}

bool CXTask::DelTask(CXSubTaskPtr& pTask)
{
    bool bRet = true;

    if(!pTask)
    {
        return false;
    }

    return bRet;
}

bool CXTask::Run()
{
    bool bRet = true;

    for(const auto& pTask : m_pTaskVec)
    {
        bRet = pTask->Run();
        if(!bRet)
        {
            //!
            cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
        }
    }

    return bRet;    
}