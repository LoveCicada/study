#pragma once
#include "RDWebSocket.h"

class LIB_EXPORT RDWebSocketServer : public RDWebSocket
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