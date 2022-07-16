#include "RDWebSocket.h"


void LwsThreadWork(lws_context* pCtx, int *pExit)
{
	while (!*pExit)
	{
		lws_service(pCtx, 0);
	}
}


int RDWebSocket::StartThread()
{
	if (!m_nStartThread)
	{
		m_nExit = 0;

		m_pThread = new std::thread(LwsThreadWork, m_pCtx, &m_nExit);

		m_nStartThread = 1;
	}

	return 1;
}

int RDWebSocket::Destroy()
{
	if (m_nStartThread)
	{
		m_nExit = 1;

		if (m_pThread != nullptr)
		{
			lws_cancel_service(m_pCtx);

			m_pThread->join();

			delete m_pThread;

			m_pThread = nullptr;
		}
		m_nStartThread = 0;

	}

	return 1;
}







