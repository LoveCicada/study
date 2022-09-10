
#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>
using std::string;
using std::vector;
using std::shared_ptr;

/**
 * @brief 
 * 
 */

//! example data, json 
/*
{

    "taskList": [
        {
            "index": 0,
            "algorithmName": "taskQuery",
            "subFlowName": "taskQuery00",
            "algorithmAddress": "url00",
            "input": "input00",
            "output": "output00",
            "codeLanguage": "python"
        },
        {
            "index": 1,
            "algorithmName": "taskQuery",
            "subFlowName": "taskQuery01",
            "algorithmAddress": "url01",
            "input": "input01",
            "output": "output01",
            "codeLanguage": "sql"
        }
    ]
}
*/

class CXSubTaskData
{
public:

    //! sub task index
    int8_t index;
    //! algorithm name
    string algorithmName;
    //! sub work flow name
    string subFlowName;
    //! algorithm Address, url
    string algorithmAddress;
    //! cmd, python3
    string cmd;
    //! input
    string input;
    //! output
    string output;
    //! algorithm code language, MySql, Python, Java
    string codeLanguage;

public:
    CXSubTaskData()
    {
        Init();
    }

public:
    void Init()
    {
        index = 0;
        algorithmName = "";
        subFlowName = "";
        algorithmAddress = "";
        cmd = "";
        input = "";
        output = "";
        codeLanguage = "";
    }

};

typedef vector<CXSubTaskData> CXSubTaskDataVec;
typedef shared_ptr<CXSubTaskData> CXSubTaskDataPtr;
typedef vector<CXSubTaskDataPtr> CXSubTaskDataPtrVec;


/**
 * @brief 
 * 
 */
class CXTaskData
{
public:
    bool AddTask(CXSubTaskDataPtr& pSubTaskData)
    {
        bool bRet = true;

        if(!pSubTaskData)
        {
            return false;
        }
        m_SubTaskDataPtrVec.push_back(pSubTaskData);

        return bRet;
    }

    bool DelTask(CXSubTaskDataPtr& pSubTaskData)
    {
        bool bRet = true;

        (void)(pSubTaskData);

        return bRet;
    }

public:
    CXSubTaskDataPtrVec m_SubTaskDataPtrVec;
};

typedef vector<CXTaskData> CXTaskDataVec;
typedef shared_ptr<CXTaskData> CXTaskDataPtr;
typedef vector<CXTaskDataPtr> CXTaskDataPtrVec;