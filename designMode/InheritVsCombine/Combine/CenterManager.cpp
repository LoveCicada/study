

#include "CenterManager.h"
#include <iostream>
using namespace std;
using namespace CenterManager;

std::shared_ptr<ICenterManager> CenterManager::CreateCenterManager()
{
	return std::make_shared<CCenterManager>();
}

CCenterManager::ObserverA::ObserverA()
{
	cout << __FUNCTION__ << endl;
}

CCenterManager::ObserverA::~ObserverA()
{
	cout << __FUNCTION__ << endl;
}

/////////////////////////////////
bool CCenterManager::ObserverA::Dispatch()
{
	cout << __FUNCTION__ << endl;

	return true;
}

CCenterManager::ObserverB::ObserverB()
{
	cout << __FUNCTION__ << endl;
}

CCenterManager::ObserverB::~ObserverB()
{
	cout << __FUNCTION__ << endl;
}

bool CCenterManager::ObserverB::Dispatch()
{
	cout << __FUNCTION__ << endl;

	return true;
}

/////////////////////////////////
CCenterManager::CCenterManager()
{
	cout << __FUNCTION__ << endl;
	m_pObsA = std::make_shared<ObserverA>();
	m_pObsB = std::make_shared<ObserverB>();
}

CCenterManager::~CCenterManager()
{
	cout << __FUNCTION__ << endl;
}

bool CCenterManager::Collect()
{
	cout << __FUNCTION__ << endl;
	
	return true;
}

bool CCenterManager::Notify()
{
	cout << __FUNCTION__ << endl;

	return true;
}

bool CCenterManager::GetObserver(std::shared_ptr<CenterManager::IModuleA::Observer> pObs)
{
	cout << __FUNCTION__ << endl;

	pObs = m_pObsA;

	return true;
}

bool CCenterManager::GetObserver(std::shared_ptr<CenterManager::IModuleB::Observer> pObs)
{
	cout << __FUNCTION__ << endl;

	pObs = m_pObsB;

	return false;
}

bool CCenterManager::DispatchA()
{
	cout << __FUNCTION__ << endl;

	return true;
}

bool CCenterManager::DispatchB()
{
	cout << __FUNCTION__ << endl;

	return true;
}
