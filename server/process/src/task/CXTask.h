
#pragma once

#include "../process/CXProcess.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

/**
 * @brief every single subtask, maybe have multiple input or output.
 * 
 */

class CXSubTask
{
public:
    class Input
    {

    };

    class Output
    {

    };

    class ExecParam
    {
    public:
        string name;
        string cmd;
        vector<string> args;
    };

public:
    //! create CXProcess to process subTask
    bool Run();


public:
    vector<Input> m_inputVec;
    vector<Output> m_outputVec;
    ExecParam m_execParam;
};

typedef vector<CXSubTask> CXSubTaskVec;
typedef shared_ptr<CXSubTask> CXSubTaskPtr;
typedef vector<CXSubTaskPtr> CXSubTaskPtrVec;


/**
 * @brief CXTask inner use multiple CXProcess to process CXSubTask
 * 
 */
class CXTask
{
public:


    bool AddTask(CXSubTaskPtr& pTask);
    bool DelTask(CXSubTaskPtr& pTask);
public:
    bool Run();

public:
    CXSubTaskPtrVec m_pTaskVec;

};

typedef vector<CXTask> CXTaskVec;
typedef shared_ptr<CXTask> CXTaskPtr;
typedef vector<CXTaskPtr> CXTaskPtrVec;