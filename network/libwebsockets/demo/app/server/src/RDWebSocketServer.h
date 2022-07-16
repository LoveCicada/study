#pragma once
#include "RDWebSocket.h"

class RDWebSocketServer : public RDWebSocket
{
public:

	RDWebSocketServer();

	virtual ~RDWebSocketServer();

	int Listen(int nPort);

	int GetConnectedClientCount();

	int SendData(uint8_t* pData, int nDataLen);

	int Destroy();

private:

	int m_nListenPort = 0;
};