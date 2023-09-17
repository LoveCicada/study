
#include "ModuleB.h"
#include <iostream>
using namespace std;
using namespace CenterManager;

std::shared_ptr<IModuleB> CenterManager::CreateIModuleB()
{
	return std::make_shared<CModuleB>();
}


CModuleB::CModuleB()
{
	cout << __FUNCTION__ << endl;
}

CModuleB::~CModuleB()
{
	cout << __FUNCTION__ << endl;
}

bool CModuleB::SetObserver(std::shared_ptr<CenterManager::IModuleB::Observer> pObs)
{
	cout << __FUNCTION__ << endl;

	m_pObs = pObs;

	return true;
}

bool CModuleB::DispatchB()
{
	cout << __FUNCTION__ << endl;

	if (m_pObs)
	{
		m_pObs->Dispatch();
	}

	return true;
}