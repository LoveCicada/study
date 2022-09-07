
#pragma once

/**
 * @file CXProcess.h
 * @author duanayfeng (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <cstdint>
using std::string;

class CXProcess
{
public:
    class ProcessParams
    {
    public:
        string name;
        string args;

    public:
        ProcessParams()
        {
            name = "";
            args = "";
        }
    };

    class ProcessInfo
    {
    public:
        //! pid
        int pid;
        //! parent pid
        int ppid;

    public:
        ProcessInfo()
        {
            pid = 0;
            ppid = 0;
        }
    };

public:
    virtual ~CXProcess() {}

public:
    virtual bool Init(const ProcessParams& params) = 0;
    virtual bool Release() = 0;
    virtual bool Start() = 0;
    virtual bool Stop() = 0;

protected:
    ProcessParams m_processParams;
    ProcessInfo m_processInfo;
};