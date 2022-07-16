
#pragma once

#include "plugin.h"

class MsgPlugin : public IPlugin
{
public:
	MsgPlugin() {

	}

	~MsgPlugin() {
		cout << __func__ << endl;
		m_pThread->join();
		delete m_pThread;
	}

public:
	void Init() override {
		cout << __func__ << endl;
		m_pThread = new thread(&MsgPlugin::ThreadFun, this);
	}

	void UnInit() override {
		cout << __func__ << endl;
	}

	void CallBack(Cb cb) override {
		cout << __func__ << endl;
		m_cb = cb;
	}

	void Do() override  {
		cout << __func__ << endl;
	}

public:
	void ThreadFun() {
		cout << __func__ << endl;
	}

};