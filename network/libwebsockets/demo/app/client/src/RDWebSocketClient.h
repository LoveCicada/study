#pragma once
#include "RDWebSocket.h"

class RDWebSocketClient : public RDWebSocket
{
public:

	RDWebSocketClient();

	virtual ~RDWebSocketClient();

	int Connect(const char* cAddress, int nPort);

	int SendData(uint8_t* pData, int nDataLen);

	int Destroy();

private:

	lws* m_pClient = nullptr;
};


