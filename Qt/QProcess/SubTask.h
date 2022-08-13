
#pragma once

#include <QObject>
#include <QProcess>
#include <QString>
#include <cstdint> 

class SubTask : public QObject
{
	Q_OBJECT

public:

	enum class TaskType : int8_t
	{
		UNKNOWN,
		SCRIPT,
		EXE
	};

	class TaskParams
	{
	public:
		TaskType taskType;
		QString processName;
		QStringList processParams;
	};

public:
	SubTask();
	void Init(TaskParams taskParams);
	void Start();
	void Stop();

protected:
	void TagTaskType(const QString& str);
	void FixTaskParams();
public slots:
	void startedSlots();
	void finisedSlots(int exitCode, QProcess::ExitStatus exitStatus);
	void stateChangedSlots(QProcess::ProcessState state);

private:
	TaskParams m_taskParams;
	QProcess* m_pProcess;
};