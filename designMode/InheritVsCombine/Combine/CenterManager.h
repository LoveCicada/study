
#pragma once

#include "ICenterManager.h"

class CCenterManager : 
	public CenterManager::ICenterManager
{
public:
	struct ObserverA : public CenterManager::IModuleA::Observer
	{
		ObserverA();
		~ObserverA();
		bool Dispatch() override;
	};


public:
	struct ObserverB : public CenterManager::IModuleB::Observer
	{
		ObserverB();
		~ObserverB();
		bool Dispatch() override;
	};

public:
	CCenterManager();
	~CCenterManager();

	CCenterManager(const CCenterManager&) = delete;
	CCenterManager& operator=(const CCenterManager&) = delete;

protected:	//ICenterManager

	bool Collect() override;

	bool Notify() override;

	bool GetObserver(std::shared_ptr<CenterManager::IModuleA::Observer> pObs) override;

	bool GetObserver(std::shared_ptr<CenterManager::IModuleB::Observer> pObs) override;

protected:	
	bool DispatchA();

protected:	
	bool DispatchB();

private:
	std::shared_ptr<ObserverA> m_pObsA = nullptr;
	std::shared_ptr<ObserverB> m_pObsB = nullptr;

};