
#pragma once

#include "CXTask.h"
#include "CXTaskData.h"
#include <functional>
#include "wfrest/json.hpp"
using Json = nlohmann::json;

/**
 * @brief CXTaskVec -- thread
 * 1. every CXTaskVec use one thread
 * 2. CXTaskVec inner use multiple CXProcess to process CXTask
 * 3. keep CXTaskVec sync run
 */

class CXTaskManager
{
public:
    //! callback notify OutputVecGroup
    typedef std::function<void(const OutputVecGroup&)> OnOutputVecGroup;
public:
    CXTaskManager();
    ~CXTaskManager();

    void SetCallBack(OnOutputVecGroup pfn);
    bool AddTask(CXTaskPtr& pTask);
    bool DelTask(CXTaskPtr& pTask);
public:
    //! process CXTaskVec, thread func
    void Run();
    bool GetOutputVecGroup(OutputVecGroup& outputVecGroup);
    //! taskData --> task
    bool BuildTask();
    //! json --> task
    bool Json2TaskData(Json& json);
private:
    void NotifyOutputVecGroup(const OutputVecGroup& outputVecGroup);

public:
    CXTaskPtrVec m_pTaskVec;
    OutputVecGroup m_outputVecGroup;
    OnOutputVecGroup m_pfnOutputVecGroup;
    CXTaskDataPtrVec m_pTaskDataVec;
};