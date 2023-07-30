
#include "ThreadMonitor.h"
using namespace ExceptionCollect;

////////////////////CThreadMonitor////////////////////
CThreadMonitor::CThreadMonitor()
{
	Init();
}

CThreadMonitor::~CThreadMonitor()
{
	UnInit();
}

void CThreadMonitor::Init()
{
	SetObserver(GetThreadMonitorManager()->GetObserver());
	HRESULT hr = CoCreateGuid(&m_guid);
	if (E_FAIL == hr)
		return;
}

void CThreadMonitor::UnInit()
{
	Del();
}


void CThreadMonitor::SetObserver(std::shared_ptr<ExceptionCollect::IThreadMonitor::Observer> pObs)
{
	m_pObs = pObs;
}

void CThreadMonitor::Add()
{
	if (m_pObs)
	{
		if (GUID_NULL == m_guid)
		{
			HRESULT hr = CoCreateGuid(&m_guid);
			if (E_FAIL == hr)
				return;
		}

		m_pObs->Add({ m_guid, enable_shared_from_this::shared_from_this() });
	}
}

void CThreadMonitor::Del()
{
	if (m_pObs)
	{
		m_pObs->Del(m_guid);
	}
}

////////////////////CThreadMonitorManager////////////////////
void CThreadMonitorManager::ManagerObserver::Add(std::pair<GUID, std::weak_ptr<IThreadMonitor>> pair)
{
	if(m_pM)
	{
		m_pM->AddThreadMonitor(pair);
	}
}

void CThreadMonitorManager::ManagerObserver::Del(GUID guid)
{
	if (m_pM)
	{
		m_pM->DelThreadMonitor(guid);
	}
}


CThreadMonitorManager::CThreadMonitorManager()
{
	Init();
}

CThreadMonitorManager::~CThreadMonitorManager()
{
}

void CThreadMonitorManager::Init()
{
	m_pObs = std::make_shared<ManagerObserver>(this);
}

void CThreadMonitorManager::UnInit()
{

}

void CThreadMonitorManager::AddThreadMonitor(std::pair<GUID, std::weak_ptr<IThreadMonitor>> pair)
{
	auto itor = m_mapThreadMonitor.find(pair.first);
	if (itor != m_mapThreadMonitor.end())
		return;

	m_mapThreadMonitor.insert(pair);
}

void CThreadMonitorManager::DelThreadMonitor(GUID guid)
{
	auto itor = m_mapThreadMonitor.find(guid);
	if (itor != m_mapThreadMonitor.end())
	{
		m_mapThreadMonitor.erase(guid);
	}
}

std::shared_ptr<IThreadMonitor::Observer> CThreadMonitorManager::GetObserver()
{
	return m_pObs;
}

