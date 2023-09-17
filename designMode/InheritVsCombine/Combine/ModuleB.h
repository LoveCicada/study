
#pragma once
#include "ICenterManager.h"

class CModuleB :
	public CenterManager::IModuleB
{
public:
	CModuleB();
	~CModuleB();
	CModuleB(const CModuleB&) = delete;
	CModuleB& operator=(const CModuleB&) = delete;

protected:
	bool SetObserver(std::shared_ptr<CenterManager::IModuleB::Observer> pObs) override;
	bool DispatchB() override;

private:

	std::shared_ptr<CenterManager::IModuleB::Observer> m_pObs = nullptr;
};