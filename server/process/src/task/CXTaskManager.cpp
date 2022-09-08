

#include "CXTaskManager.h"
#include <iostream>
using namespace std;


CXTaskManager::CXTaskManager()
{

}

CXTaskManager::~CXTaskManager()
{

}

void CXTaskManager::SetCallBack(OnOutputVecGroup pfn)
{
    m_pfnOutputVecGroup = pfn;
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
        OutputVec outputVec;
        bRet = pTask->GetOutputVec(outputVec);
        if(!bRet)
        {
            //!
            cout << __FUNCTION__ << ": " << __LINE__ << " fail" << endl;
        }
        m_outputVecGroup.push_back(std::move(outputVec));
    }

    NotifyOutputVecGroup(m_outputVecGroup);
}

bool CXTaskManager::GetOutputVecGroup(OutputVecGroup& outputVecGroup)
{
    bool bRet = true;

    outputVecGroup = m_outputVecGroup;

    return bRet;
}

void CXTaskManager::NotifyOutputVecGroup(const OutputVecGroup& outputVecGroup)
{
    if(m_pfnOutputVecGroup)
    {
        m_pfnOutputVecGroup(outputVecGroup);
    }
}
