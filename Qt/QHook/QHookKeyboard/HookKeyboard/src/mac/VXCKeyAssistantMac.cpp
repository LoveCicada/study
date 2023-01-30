
#if defined(__APPLE__) && defined(__MACH__)

#include "VXCKeyAssistantMac.h"
#include "../log/VXLog.h"
#include <iostream>
#include <sstream>
using namespace std;


CKeyAssistantMac::CKeyAssistantMac()
{
    InitHanlde();
    SetHook();
    Active();
}

CKeyAssistantMac::~CKeyAssistantMac()
{
    UnSetHook();
    UnActive();
}

void CKeyAssistantMac::InitHanlde()
{
}

void CKeyAssistantMac::Process() {}

void CKeyAssistantMac::SetHook()
{
    //SetHookEx();
}

void CKeyAssistantMac::UnSetHook()
{
    //UnSetHookEx();
}

void CKeyAssistantMac::Active()
{
    //ActiveEx();
}

void CKeyAssistantMac::UnActive()
{
    //UnActiveEx();
}

#endif