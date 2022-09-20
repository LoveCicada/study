
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
    public:
        vector<string> outputResult;
    };

    class Result
    {
    public:
        int nLine;
        string str;
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
    bool GetOutput(Output& output);

public:
    vector<Input> m_inputVec;
    vector<Output> m_outputVec;
    Output m_pOutput;
    ExecParam m_execParam;
};

typedef vector<CXSubTask::Output> OutputVec;
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
    bool GetOutputVec(OutputVec& outputVec);
public:
    CXSubTaskPtrVec m_pTaskVec;
    OutputVec m_pOutputVec;
};

//! multiple Task flow result
typedef vector<OutputVec> OutputVecGroup;
typedef vector<CXTask> CXTaskVec;
typedef shared_ptr<CXTask> CXTaskPtr;
typedef vector<CXTaskPtr> CXTaskPtrVec;