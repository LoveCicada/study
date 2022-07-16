#pragma once

#include <libwebsockets.h>
#include <thread>
#include <mutex>
#include <condition_variable>


class RDLwsReceiveCallback 
{
public:
	virtual void OnLwsReceiveResult(int nResult, uint8_t *pData, int nDataLen) = 0;

    virtual void OnClientConnected() = 0;
protected:
	virtual ~RDLwsReceiveCallback() {}
};


class RDLwsUserData
{
public:
    RDLwsUserData() = default;
    ~RDLwsUserData()
    {
        if (pRecvBuffer != nullptr)
        {
            delete[]pRecvBuffer;
            pRecvBuffer = nullptr;
        }

        if (pSendBuffer != nullptr)
        {
            delete[]pSendBuffer;
            pSendBuffer = nullptr;
        }
    };

    int nInit = 0;

    struct lws* wsi;

    void SetInitComplete() { nInit = 1; }

    int InitComplete() { return nInit; }

    RDLwsReceiveCallback* pCallback = nullptr;

    int nConnectedClientCount = 0;
    int nSendClientCount = 0;

    uint8_t* pRecvBuffer = nullptr;
    int nRecvBufferSize = 0;
    int nRecvBufferAllocSize = 0;
    int nRecvBufferComplete = 0;

    uint8_t* pSendBuffer = nullptr;
    int nSendBufferSize = 0;
    int nSendBufferAllocSize = 0;
    int nSendBufferComplete = 0;

    std::condition_variable cvSendFinish;
    std::mutex mutexSendBuffer;


    void PackReceiveBuffer(uint8_t* pData, int nDataLen, int nRemainLen, int first_fragment, int final_fragment)
    {
        if (first_fragment)
        {
            ResetReceiveBuffer();
        }

        if (nRecvBufferSize + nRemainLen + nDataLen > nRecvBufferAllocSize)
        {
            nRecvBufferAllocSize = nRecvBufferSize + nRemainLen + nDataLen + 1024 * 1024;

            uint8_t* pNewBuffer = new uint8_t[nRecvBufferAllocSize];

            if (pRecvBuffer && nRecvBufferSize > 0)
            {
                memcpy(pNewBuffer, pRecvBuffer, nRecvBufferSize);
                delete[] pRecvBuffer;
            }

            pRecvBuffer = pNewBuffer;
        }

        memcpy(pRecvBuffer + nRecvBufferSize, pData, nDataLen);
        nRecvBufferSize += nDataLen;

        if (final_fragment)
        {
            nRecvBufferComplete = 1;
        }
    }

    int ReceiveBufferComplete() { return nRecvBufferComplete; }

    void ResetReceiveBuffer() 
    {
        nRecvBufferComplete = 0;
        nRecvBufferSize = 0;
    }

    int SendBufferComplete() 
    {
        std::unique_lock<std::mutex> lock(mutexSendBuffer);
        return nSendBufferComplete;
    }

    void ResetSendBuffer() 
    { 
        std::unique_lock<std::mutex> lock(mutexSendBuffer);

        nSendBufferComplete = 0;

        cvSendFinish.notify_all();
    }

    uint8_t* GetReceiveBufferPtr() { return pRecvBuffer; }

    int GetReceiveBufferSize() { return nRecvBufferSize; }

    void PackSendBuffer(uint8_t* pData, int nDataLen)
    {
        std::unique_lock<std::mutex> lock(mutexSendBuffer);

        //!
        if (nSendBufferComplete)
        {
            cvSendFinish.wait(lock);
        }

        if (nDataLen + LWS_PRE > nSendBufferAllocSize)
        {
            if (pSendBuffer != nullptr)
            {
                delete[] pSendBuffer;
            }

            nSendBufferAllocSize = nDataLen + LWS_PRE + 1024 * 1024;

            pSendBuffer = new uint8_t[nSendBufferAllocSize];
        }

        memcpy(pSendBuffer + LWS_PRE, pData, nDataLen);
        nSendBufferSize = nDataLen;

        nSendBufferComplete = 1;
    }

    uint8_t* GetSendBufferPtr() { return pSendBuffer + LWS_PRE; }

    int GetSendBufferSize() { return nSendBufferSize; };
};

class RDWebSocket
{
public:

	static const int nRxBufferSize = 64 * 1024;

	virtual ~RDWebSocket() = default;

	//!
	//

	//!
	void SetReceivcCallBack(RDLwsReceiveCallback* pCallBack)
	{
		m_pCallback = pCallBack;
	}

	//!
	int StartThread();

	//!
	virtual int SendData(uint8_t* pData, int nDataLen) = 0;

	virtual int Destroy();


protected:

	lws_context_creation_info m_stCtxInfo = { 0 };

	lws_context* m_pCtx = nullptr;

	RDLwsReceiveCallback* m_pCallback = nullptr;

    RDLwsUserData m_cUserData;

private:

	int m_nStartThread = 0;

	int m_nExit = 0;

	std::thread* m_pThread = nullptr;
};



