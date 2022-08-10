
#pragma once

/**
 * @file callback.h
 * @author cicada (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
#include <iostream>
#include <functional>
using namespace std;

class Module
{
public:
	class Observer
	{
	public:
		virtual ~Observer(){}
		virtual void OnCall(const string &str) = 0;
	};

public:
	Module(Observer* pObs = nullptr)
	{
		m_pObs = pObs;
	}

	void OnFuncString(const string &str)
	{
		if(m_pObs)
		{
			cout << __func__ << endl;
			m_pObs->OnCall(str);
		}
	}

private:
	Observer* m_pObs;
};


class ObserverImp final : public Module::Observer
{
public:
	virtual void OnCall(const string &str) final
	{	
		cout << __func__ << ": " << str << endl;
	}
};