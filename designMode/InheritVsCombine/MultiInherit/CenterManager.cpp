

#include "CenterManager.h"
#include <iostream>
using namespace std;
using namespace CenterManager;

std::shared_ptr<ICenterManager> CenterManager::CreateCenterManager()
{
	return std::make_shared<CCenterManager>();
}


CCenterManager::CCenterManager()
{

}

CCenterManager::~CCenterManager()
{

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
