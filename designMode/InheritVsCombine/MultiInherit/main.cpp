
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

	auto pModuleA = dynamic_pointer_cast<CenterManager::IModuleA>(pCenterManager);
	if (!pModuleA)
		return 0;
	pModuleA->DispatchA();

	auto pModuleB = dynamic_pointer_cast<CenterManager::IModuleB>(pCenterManager);
	if (!pModuleB)
		return 0;
	pModuleB->DispatchB();


	return 0;
}

/**
 * @result 
 *
 *  CCenterManager::Collect
 *	CCenterManager::Notify
 *	CCenterManager::DispatchA
 *	CCenterManager::DispatchB
 * 
 */