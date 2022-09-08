
#pragma once

#include "CXTask.h"

/**
 * @brief CXTaskVec -- thread
 * 1. every CXTaskVec use one thread
 * 2. CXTaskVec inner use multiple CXProcess to process CXTask
 * 3. keep CXTaskVec sync run
 */

class CXTaskManager
{
public:
    CXTaskManager();
    ~CXTaskManager();

    bool AddTask(CXTaskPtr& pTask);
    bool DelTask(CXTaskPtr& pTask);
public:
    //! process CXTaskVec, thread func
    void Run();

public:
    CXTaskPtrVec m_pTaskVec;

};