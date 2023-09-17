
#pragma once

#include "ICenterManager.h"

class CCenterManager : 
	public CenterManager::ICenterManager, 
	public CenterManager::IModuleA,
	public CenterManager::IModuleB
{
public:
	CCenterManager();
	~CCenterManager();

	CCenterManager(const CCenterManager&) = delete;
	CCenterManager& operator=(const CCenterManager&) = delete;

protected:	//ICenterManager

	bool Collect() override;

	bool Notify() override;

protected:	//IObserverA
	bool DispatchA() override;

protected:	//IObserverB
	bool DispatchB() override;

private:



};