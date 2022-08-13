#include "SubTask.h"
#include <functional>
#include <iostream>
using namespace std;

SubTask::SubTask():m_pProcess(nullptr)
{
	m_pProcess = new QProcess(this);

	bool bOk = connect(m_pProcess, &QProcess::started, this, &SubTask::startedSlots);
	if (!bOk)
	{
		cout << "connect failed " << __LINE__ << " " << __FUNCTION__ << endl;
	}
	bOk = connect(m_pProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finisedSlots(int, QProcess::ExitStatus)));
	if (!bOk)
	{
		cout << "connect failed " << __LINE__ << " " << __FUNCTION__ << endl;
	}
	bOk = connect(m_pProcess, SIGNAL(stateChanged(QProcess::ProcessState state)), this, SLOT(stateChangedSlots(QProcess::ProcessState)));
	if (!bOk)
	{
		cout << "connect failed " << __LINE__ << " " << __FUNCTION__ << endl;
	}

}

void SubTask::Init(TaskParams taskParams)
{
	m_taskParams = taskParams;
	TagTaskType(m_taskParams.processName);
}

void SubTask::Start()
{
	cout << "processName: " << m_taskParams.processName.toStdString() << endl;
	switch (m_taskParams.taskType)
	{
	case TaskType::SCRIPT:

		break;
	case TaskType::EXE:

#if 1
		m_taskParams.processParams.clear();
		//m_taskParams.processParams << "/c";
		m_taskParams.processParams << "python.exe D:/code/private/py/1.py";

#endif // 0

		m_pProcess->start(m_taskParams.processName, m_taskParams.processParams);
		break;
	default:
		break;
	}
	
}

void SubTask::Stop()
{
}

void SubTask::TagTaskType(const QString& str)
{
	//! check task wether is script or exe
	/*
	* @brief script: MySql: .sql, Python: .py, Js: .js
	*		 exe: C++: .exe, Java: 
	*/

	if (str.isEmpty()) {
		return;
	}

	cout << "str: " << str.toStdString() << endl;

	QString strSuffix = str.mid(str.lastIndexOf(".") + 1, str.length());
	cout << "strSuffix: " << strSuffix.toStdString() << endl;

	QStringList strScriptList, strExeList;
	strScriptList << "sql" << "py" << "js";
	strExeList << "exe";
	if (strScriptList.contains(strSuffix))
	{
		//! script
		m_taskParams.taskType = TaskType::SCRIPT;
	}
	else if(strExeList.contains(strSuffix))
	{
		 //! exe
		m_taskParams.taskType = TaskType::EXE;
	}
	else
	{
		m_taskParams.taskType = TaskType::UNKNOWN;
	}

}

void SubTask::startedSlots()
{
	cout << "started " << endl;
}

void SubTask::finisedSlots(int exitCode, QProcess::ExitStatus exitStatus)
{
	cout << "exitCode: " << exitCode << " exitStatus: " << exitStatus << endl;
}

void SubTask::stateChangedSlots(QProcess::ProcessState state)
{
	cout << "state: " << state << endl;
}
