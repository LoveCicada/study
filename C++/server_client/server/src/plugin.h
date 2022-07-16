
#pragma once

#include <iostream>
#include <vector>
#include <thread>
using std::vector;
using std::cout;
using std::endl;
using std::thread;

class IPlugin;

typedef vector<IPlugin*> IPluginVec;
typedef void (*Cb)(void* user, void* param);

class IPlugin
{
public:
	virtual ~IPlugin() {
		cout << __func__ << endl;
	}

public:
	virtual void Init() = 0;
	virtual void UnInit() = 0;
	virtual void CallBack(Cb cb) = 0;

	virtual void Do() = 0;
protected:
	Cb m_cb;
	thread* m_pThread;
};