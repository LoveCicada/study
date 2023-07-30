
#pragma once

#include "ExceptionCollectExport.h"
#include <map>
#include <Windows.h>

////////////////////CThreadMonitor////////////////////
class CThreadMonitor : public ExceptionCollect::IThreadMonitor, public std::enable_shared_from_this<CThreadMonitor>
{
public:
	CThreadMonitor();
	~CThreadMonitor();
	CThreadMonitor(const CThreadMonitor&) = delete;
	CThreadMonitor& operator=(const CThreadMonitor&) = delete;

public:
	void Init();
	void UnInit();

public:
	void SetObserver(std::shared_ptr<ExceptionCollect::IThreadMonitor::Observer> pObs) override;
	void Add() override;
	void Del() override;

private:
	std::shared_ptr<Observer> m_pObs = nullptr;
	GUID m_guid = GUID_NULL;
};


////////////////////CThreadMonitorManager////////////////////
class CThreadMonitorManager : public ExceptionCollect::IThreadMonitorManager
{
	struct GUIDComparer
	{
		bool operator()(const GUID& l, const GUID& r) const
		{
			// comparison logic goes here
			// @see https://www.jianshu.com/p/57ce10190101
			return memcmp(&l, &r, sizeof(GUID)) < 0;
		}
	};

public:
	class ManagerObserver : public ExceptionCollect::IThreadMonitor::Observer
	{
	public:
		ManagerObserver(CThreadMonitorManager* pM) { m_pM = pM; }
		virtual ~ManagerObserver() { m_pM = nullptr; }

		void Add(std::pair<GUID, std::weak_ptr<ExceptionCollect::IThreadMonitor>> pair) override;
		void Del(GUID guid) override;

	private:
		CThreadMonitorManager* m_pM = nullptr;
	};

public:
	CThreadMonitorManager();
	~CThreadMonitorManager();
	CThreadMonitorManager(const CThreadMonitorManager&) = delete;
	CThreadMonitorManager& operator=(const CThreadMonitorManager&) = delete;

public:
	void Init();
	void UnInit();
	void AddThreadMonitor(std::pair<GUID, std::weak_ptr<ExceptionCollect::IThreadMonitor>> pair);
	void DelThreadMonitor(GUID guid);

public:
	std::shared_ptr<ExceptionCollect::IThreadMonitor::Observer> GetObserver() override;

private:
	std::shared_ptr<ExceptionCollect::IThreadMonitor::Observer> m_pObs = nullptr;
	std::map<GUID, std::weak_ptr<ExceptionCollect::IThreadMonitor>, GUIDComparer> m_mapThreadMonitor;

};