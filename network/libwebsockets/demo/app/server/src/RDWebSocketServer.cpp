#include "RDWebSocketServer.h"


static int protocol_server_callback(struct lws* wsi, enum lws_callback_reasons reason, void* user, void* in, size_t len)
{
    static_cast<void*>(user);
    RDLwsUserData* pUserData = nullptr;

    lws_context* context = lws_get_context(wsi);

    if (context != nullptr)
    {
        pUserData = (RDLwsUserData*)lws_context_user(context);
    }

    printf("nReason:%d\n", reason);

    switch (reason)
    {
    case LWS_CALLBACK_PROTOCOL_INIT:
        break;
    case LWS_CALLBACK_ESTABLISHED:      
        if(pUserData)
        {
            pUserData->pCallback->OnClientConnected();
            pUserData->nConnectedClientCount++;
            pUserData->wsi = wsi;
        }
        break;
    case LWS_CALLBACK_CLOSED:
        if (pUserData)
        {
            pUserData->nConnectedClientCount--;
        }
        break;
    case LWS_CALLBACK_RECEIVE:
        if (pUserData)
        {
            pUserData->PackReceiveBuffer((uint8_t *)in, (int)len, (int)lws_remaining_packet_payload(wsi), (int)lws_is_first_fragment(wsi), lws_is_final_fragment(wsi));

            if (pUserData->ReceiveBufferComplete() && pUserData->pCallback)
            {
                pUserData->pCallback->OnLwsReceiveResult(1, pUserData->GetReceiveBufferPtr(), pUserData->GetReceiveBufferSize());

                pUserData->ResetReceiveBuffer();
            }
        }
        break;
    case LWS_CALLBACK_SERVER_WRITEABLE:
        //if(pUserData && pUserData->SendBufferComplete())
        //{
        //    if (pUserData->nSendClientCount-- > 0)
        //    {
        //        lws_write(wsi, pUserData->GetSendBufferPtr(), pUserData->GetSendBufferSize(), LWS_WRITE_BINARY);
        //    }
        //    if (pUserData->nSendClientCount == 0)
        //    {
        //        pUserData->ResetSendBuffer();
        //    }
        //}
        break;
    case LWS_CALLBACK_EVENT_WAIT_CANCELLED:
        if (pUserData)
        {
            pUserData->SetInitComplete();
        }    
        break;
    }

    return 0;
}

struct lws_protocols server_protocol[] =
{
    {
        "lws_data_transfer", protocol_server_callback, 0, RDWebSocket::nRxBufferSize, 0, NULL, 0
    },
    LWS_PROTOCOL_LIST_TERM
};


RDWebSocketServer::RDWebSocketServer()
{

}


RDWebSocketServer::~RDWebSocketServer()
{


}

int RDWebSocketServer::Listen(int nPort)
{
    int nRet = 1;

    m_nListenPort = nPort;

    m_stCtxInfo.port = m_nListenPort;
    m_stCtxInfo.iface = NULL;
    m_stCtxInfo.protocols = server_protocol;
    m_stCtxInfo.gid = -1;
    m_stCtxInfo.uid = -1;
    m_stCtxInfo.user = this;
    m_stCtxInfo.user = &m_cUserData;
    m_cUserData.pCallback = m_pCallback;

    m_pCtx = lws_create_context(&m_stCtxInfo);

    //建立连接完成才返回
    while (!m_cUserData.InitComplete())
    {
        nRet = lws_service(m_pCtx, 0);
    }

    return 1;
}

int RDWebSocketServer::GetConnectedClientCount()
{
    return m_cUserData.nConnectedClientCount;
}

int RDWebSocketServer::SendData(uint8_t* pData, int nDataLen)
{
    if (m_cUserData.nConnectedClientCount > 0)
    {
        m_cUserData.PackSendBuffer(pData, nDataLen);

        if (m_cUserData.SendBufferComplete())
        {
            lws_write(m_cUserData.wsi, m_cUserData.GetSendBufferPtr(), m_cUserData.GetSendBufferSize(), LWS_WRITE_BINARY);

            m_cUserData.ResetSendBuffer();
        }
    }

    return 1;
}


int RDWebSocketServer::Destroy()
{
    RDWebSocket::Destroy();

    if (m_pCtx != nullptr)
    {
        lws_cancel_service(m_pCtx);
        lws_context_destroy(m_pCtx);
        m_pCtx = nullptr;
    }

    return 1;
}
