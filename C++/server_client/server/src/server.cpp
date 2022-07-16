#include "server.h"

Server::Server()
{
	cout << __func__ << endl;
	RegisterPlugin();
}

Server::~Server()
{
	cout << __func__ << endl;
	UnRegisterPlugin();
}

void Server::RegisterPlugin()
{
	IPlugin* p = new MsgPlugin();
	p->Init();
	m_pluginVec.push_back(p);
}

void Server::UnRegisterPlugin()
{
	for (auto e : m_pluginVec) {
		if (e) {
			e->UnInit();
			delete e;
		}
	}
}

void Server::NotifyPlugin()
{
	for (auto e : m_pluginVec) {
		if (e) {
			e->Do();
			delete e;
		}
	}
}
