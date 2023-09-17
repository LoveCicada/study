
#include <iostream>
#include "ICenterManager.h"

using namespace std;
using namespace CenterManager;


int main(int argc, char **argv)
{

	auto pCenterManager = CreateCenterManager();
	if (!pCenterManager)
		return 0;
	pCenterManager->Collect();
	pCenterManager->Notify();

	auto pModuleA = CreateIModuleA();
	if (!pModuleA)
		return 0;
	std::shared_ptr<IModuleA::Observer> pObsA = nullptr;
	pCenterManager->GetObserver(pObsA);
	pModuleA->SetObserver(pObsA);
	pModuleA->DispatchA();

	auto pModuleB = CreateIModuleB();
	if (!pModuleB)
		return 0;
	std::shared_ptr<IModuleB::Observer> pObsB = nullptr;
	pCenterManager->GetObserver(pObsB);
	pModuleB->SetObserver(pObsB);
	pModuleB->DispatchB();

	return 0;
}

/**
 * @result 
 *
 *	CCenterManager::CCenterManager
 *	CCenterManager::ObserverA::ObserverA
 *	CCenterManager::ObserverB::ObserverB
 *	CCenterManager::Collect
 *	CCenterManager::Notify
 *	CModuleA::CModuleA
 *	CCenterManager::GetObserver
 *	CModuleA::SetObserver
 *	CModuleA::DispatchA
 *	CModuleB::CModuleB
 *	CCenterManager::GetObserver
 *	CModuleB::SetObserver
 *	CModuleB::DispatchB
 *	CModuleB::~CModuleB
 *	CModuleA::~CModuleA
 *	CCenterManager::~CCenterManager
 *	CCenterManager::ObserverB::~ObserverB
 *	CCenterManager::ObserverA::~ObserverA
 * 
 */