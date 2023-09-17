
#pragma once
#include "ICenterManager.h"

class CModuleA :
	public CenterManager::IModuleA
{
public:
	CModuleA();
	~CModuleA();
	CModuleA(const CModuleA&) = delete;
	CModuleA& operator=(const CModuleA&) = delete;

protected:
	bool SetObserver(std::shared_ptr<CenterManager::IModuleA::Observer> pObs) override;
	bool DispatchA() override;

private:

	std::shared_ptr<CenterManager::IModuleA::Observer> m_pObs = nullptr;
};