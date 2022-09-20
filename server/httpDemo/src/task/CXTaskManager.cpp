

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

bool CXTaskManager::BuildTask()
{
    bool bRet = true;

    m_pTaskVec.clear();

    for(auto& pTaskData : m_pTaskDataVec)
    {
        CXTaskPtr pTaskPtr(new CXTask);
        for(auto& pSubTaskData : pTaskData->m_SubTaskDataPtrVec)
        {
            CXSubTaskPtr pSubTaskPtr(new CXSubTask);
            CXSubTask::ExecParam execParam;
            // pSubTaskData->codeLanguage;
            execParam.args.push_back(pSubTaskData->algorithmAddress);
            execParam.cmd = pSubTaskData->cmd;
            pSubTaskPtr->m_execParam = execParam;
            pTaskPtr->m_pTaskVec.push_back(pSubTaskPtr);
        }
        m_pTaskVec.push_back(pTaskPtr);
    }

    return bRet;
}

bool CXTaskManager::Json2TaskData(Json& json)
{
    bool bRet = true;
    m_pTaskDataVec.clear();

    bool bArray = json.is_array();
    if(bArray)
    {
        cout << "Array" << endl;
    }
    bool bObject = json.is_object();
    if(bObject)
    {
        cout << "Object" << endl;
        auto array = json["taskList"];
        bArray = array.is_array();
        if(bArray)
        {
            cout << "Array" << endl;
        }
        int nSize = (int)array.size();
        for(int n = 0; n < nSize; ++n)
        {
            CXSubTaskDataPtr pSubTaskDataPtr(new CXSubTaskData);
            auto obj = array[n];
            pSubTaskDataPtr->cmd = obj["cmd"];
            pSubTaskDataPtr->algorithmAddress = obj["algorithmAddress"];
            CXTaskDataPtr pTaskDataPtr(new CXTaskData);
            pTaskDataPtr->m_SubTaskDataPtrVec.push_back(pSubTaskDataPtr);
            m_pTaskDataVec.push_back(pTaskDataPtr);
        }
    }

    return bRet;
}

bool CXTaskManager::Result2Json(Json& json)
{
    bool bRet = true;

    for (auto& outputVec : m_outputVecGroup)
    {
        Json _outputVec;
        //! every single taskList
        for (auto& output : outputVec)
        {
            Json _outputArray /*= Json::array()*/;
            //! single task
            int idx = 0;
            for (auto& result : output.outputResult)
            {
                Json _resultJson;
                CXSubTask::Result _result;
                _result.nLine = idx++;
                _result.str = result;
                ToJson(_resultJson, _result);
                _outputArray["consoleResult"].push_back(std::move(_resultJson));
            }
            _outputVec["consoleOutput"].push_back(std::move(_outputArray));
        }
        json["outputList"].push_back(std::move(_outputVec));
    }

    return bRet;
}

void CXTaskManager::NotifyOutputVecGroup(const OutputVecGroup& outputVecGroup)
{
    if(m_pfnOutputVecGroup)
    {
        m_pfnOutputVecGroup(outputVecGroup);
    }
}

void CXTaskManager::ToJson(Json& j, const CXSubTask::Result& result)
{
    /**
     * @brief single line result
     * {
            "line": 1,
            "result":"1111"
        }
     */

    j = Json{
                {"line", result.nLine},
                {"result",result.str}
            };
    


}