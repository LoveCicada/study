
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

class CXMultiTaskManager
{
public:
    //! callback notify OutputVecGroup
    typedef std::function<void(const OutputVecGroup&)> OnOutputVecGroup;
public:
    CXMultiTaskManager();
    ~CXMultiTaskManager();

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
    //! result --> json
    bool Result2Json(Json& json);
private:
    void NotifyOutputVecGroup(const OutputVecGroup& outputVecGroup);
    void ToJson(Json& j, const CXSubTask::Result& result);

public:
    CXTaskPtrVec m_pTaskVec;
    OutputVecGroup m_outputVecGroup;
    OnOutputVecGroup m_pfnOutputVecGroup;
    CXTaskDataPtrVec m_pTaskDataVec;
};