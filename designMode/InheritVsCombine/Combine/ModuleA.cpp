
#include "ModuleA.h"
#include <iostream>
using namespace std;
using namespace CenterManager;

std::shared_ptr<IModuleA> CenterManager::CreateIModuleA()
{
	return std::make_shared<CModuleA>();
}


CModuleA::CModuleA()
{
	cout << __FUNCTION__ << endl;
}

CModuleA::~CModuleA()
{
	cout << __FUNCTION__ << endl;
}

bool CModuleA::SetObserver(std::shared_ptr<CenterManager::IModuleA::Observer> pObs)
{
	cout << __FUNCTION__ << endl;

	m_pObs = pObs;

	return true;
}

bool CModuleA::DispatchA()
{
	cout << __FUNCTION__ << endl;

	if (m_pObs)
	{
		m_pObs->Dispatch();
	}

	return true;
}