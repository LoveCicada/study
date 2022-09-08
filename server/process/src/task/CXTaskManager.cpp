

#include "CXTaskManager.h"
#include <iostream>
using namespace std;


CXTaskManager::CXTaskManager()
{

}

CXTaskManager::~CXTaskManager()
{

}


bool CXTaskManager::AddTask(CXTaskPtr& pTask)
{
    bool bRet = true;

    m_pTaskVec.push_back(pTask);

    return bRet;
}

bool CXTaskManager::DelTask(CXTaskPtr& pTask)
{
    bool bRet = true;

    if(!pTask)
    {
        return false;
    }

    return bRet;
}

void CXTaskManager::Run()
{
    bool bRet = true;
    for(const auto& pTask : m_pTaskVec)
    {
        //! every CXTaskVec use one thread, wait modify
        bRet = pTask->Run();
        if(!bRet)
        {
            //!
            cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
        }
    }

}
