#include "RDWebSocketClient.h"


int protocol_client_callback(struct lws* wsi, enum lws_callback_reasons reason, void* user, void* in, size_t len)
{
    static_cast<void*>(user);
    RDLwsUserData* pUserData = nullptr;

    lws_context* context = lws_get_context(wsi);

    if (context != nullptr)
    {
        pUserData = (RDLwsUserData *)lws_context_user(context);
    }

   //printf("nReason:%d\n", reason);

    switch (reason)
    {
    case LWS_CALLBACK_CLIENT_ESTABLISHED:
        if (pUserData)
        {
            pUserData->pCallback->OnClientConnected();
            pUserData->SetInitComplete();
        }
        break;
    case LWS_CALLBACK_CLIENT_RECEIVE:
        if (pUserData)
        {
            pUserData->PackReceiveBuffer((uint8_t*)in, (int)len, (int)lws_remaining_packet_payload(wsi), (int)lws_is_first_fragment(wsi), lws_is_final_fragment(wsi));

            if (pUserData->ReceiveBufferComplete() && pUserData->pCallback)
            {
                pUserData->pCallback->OnLwsReceiveResult(1, pUserData->GetReceiveBufferPtr(), pUserData->GetReceiveBufferSize());

                pUserData->ResetReceiveBuffer();
            }
        }
        break;
    case LWS_CALLBACK_CLIENT_WRITEABLE: 
        if (pUserData && pUserData->SendBufferComplete())
        {
            lws_write(wsi, pUserData->GetSendBufferPtr(), pUserData->GetSendBufferSize(), LWS_WRITE_BINARY);
            pUserData->ResetSendBuffer();
        }
        break;
    }
    return 0;
}

struct lws_protocols client_protocol[] =
{
    {
        "lws_data_transfer", protocol_client_callback, 0, RDWebSocket::nRxBufferSize, 0, NULL, 0
    },
    LWS_PROTOCOL_LIST_TERM
};



RDWebSocketClient::RDWebSocketClient()
{

}

RDWebSocketClient::~RDWebSocketClient()
{

}


int RDWebSocketClient::Connect( const char* cAddress, int nPort)
{
    int nRet = 0;

    m_stCtxInfo.port = CONTEXT_PORT_NO_LISTEN;
    m_stCtxInfo.iface = NULL;
    m_stCtxInfo.protocols = client_protocol;
    m_stCtxInfo.gid = -1;
    m_stCtxInfo.uid = -1;
    m_stCtxInfo.user = &m_cUserData;
    m_cUserData.pCallback = m_pCallback;

    m_pCtx = lws_create_context(&m_stCtxInfo);

    if (!m_pCtx)
    {
        return 0;
    }

    struct lws_client_connect_info conn_info = { 0 };
    conn_info.context = m_pCtx;
    conn_info.address = cAddress;
    conn_info.port = nPort;
    conn_info.ssl_connection = 0;
    conn_info.path = "/";
    conn_info.host = cAddress;
    conn_info.origin = cAddress;
    conn_info.protocol = client_protocol[0].name;

    m_pClient = lws_client_connect_via_info(&conn_info);

    if (!m_pClient)
    {
        return 0;
    }

    //建立连接完成才返回
    while (!m_cUserData.InitComplete())
    {
        nRet = lws_service(m_pCtx, 0);
    }

    return 1;
}

int RDWebSocketClient::SendData(uint8_t* pData, int nDataLen)
{
    int nRet = 1;

    m_cUserData.PackSendBuffer(pData, nDataLen);

    lws_callback_on_writable_all_protocol(m_pCtx, m_stCtxInfo.protocols);

    return nRet;
}

int RDWebSocketClient::Destroy()
{
    RDWebSocket::Destroy();

    if (m_pCtx != nullptr)
    {
        lws_context_destroy(m_pCtx);
        m_pCtx = nullptr;
        m_pClient = nullptr;
    }

    return 1;
}

