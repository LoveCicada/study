
#pragma once

/**
 * @file callback.h
 * @author cicada (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <string>
#include <iostream>
#include <functional>
using namespace std;


//Interface
struct ICalllback
{
	virtual ~ICalllback() = default;
	virtual void OnCall() = 0;
};

struct IDo
{
	virtual ~IDo() = default;
	virtual void SetCallback(ICalllback* pCb) = 0;
	virtual void Do() = 0;
};


//Implement
class CCallback final : public ICalllback
{
public:
	CCallback() = default;
	~CCallback() = default;
	CCallback(const CCallback&) = delete;
	CCallback& operator=(const CCallback&) = delete;

public:
	void OnCall() override
	{
		cout << __func__ << endl;
	}
};

class CDo final : public IDo
{
public:
	CDo() = default;
	~CDo() = default;
	CDo(const CDo&) = delete;
	CDo& operator=(const CDo&) = delete;

public:
	void SetCallback(ICalllback* pCb) override
	{
		m_pCb = pCb;
	}

	void Do() override
	{
		cout << __func__ << endl;
		if (m_pCb)
		{
			m_pCb->OnCall();
		}
	}

private:
	ICalllback* m_pCb = nullptr;
};