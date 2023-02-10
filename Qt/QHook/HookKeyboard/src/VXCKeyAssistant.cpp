
#include "VXCKeyAssistant.h"

CKeyAssistant::CKeyAssistant()
{
    Init();
}

void CKeyAssistant::Init() {}

void CKeyAssistant::SetCallBack(CallBack cb)
{
    m_pCb = cb;
}
