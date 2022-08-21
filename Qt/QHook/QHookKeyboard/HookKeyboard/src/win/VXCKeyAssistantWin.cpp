
#ifdef _WIN32
#include "Windows.h"
#endif  // _WIN32

#include "VXCKeyAssistantWin.h"
#include "../log/VXLog.h"
#include <iostream>
#include <sstream>
using namespace std;

static HHOOK g_hKeyBoard = nullptr;
static bool g_bActive = false;

//! bottom keyboard system caller, filter alt+tab
static LRESULT CALLBACK KeyBoardProc(int code, WPARAM wParam, LPARAM lParam)
{
    if (!g_bActive)
    {
        return ::CallNextHookEx(g_hKeyBoard, code, wParam, lParam);
    }

    if (code == HC_ACTION)
    {
        PKBDLLHOOKSTRUCT p;

        switch (wParam)
        {
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYUP:
            p = (PKBDLLHOOKSTRUCT)lParam;
            //LOG_DEBUG("KeyBoard Hook=[flags: {}, vkCode: {}, scanCode: {}, dwExtraInfo: {}]", p->flags, p->vkCode, p->scanCode, p->dwExtraInfo);
            cout << "[Hook]: "
                << " flags: " << hex << p->flags
                << " dwExtraInfo: " << hex << p->dwExtraInfo
                << " scanCode: " << hex << p->scanCode
                << " vkCode: " << hex << p->vkCode
                << " wParam: " << hex << wParam
                << " lParam: " << hex << lParam
                << endl;

            stringstream ss;
            ss << "[Hook]: "
                << " flags: " << hex << p->flags
                << " dwExtraInfo: " << hex << p->dwExtraInfo
                << " scanCode: " << hex << p->scanCode
                << " vkCode: " << hex << p->vkCode
                << " wParam: " << hex << wParam
                << " lParam: " << hex << lParam
                << endl;

            string str = ss.str();
            LOG(str);

            //! alt + tab
            if ((p->vkCode == VK_TAB) && ((p->flags & LLKHF_ALTDOWN) != 0))
            {
                
            }
            //! left/right win + l, L key value = 0x4C
            else if ((p->vkCode == 0x4C))
            {
                
            }
            //! ctrl + alt + delete
            else if (p->vkCode == VK_DELETE)
            {
            }

            //! ctrl + alt + tab

            break;
        }
    }

    return ::CallNextHookEx(g_hKeyBoard, code, wParam, lParam);
}

//! register global hook
static void SetHookEx()
{
    if (g_hKeyBoard)
    {
        return;
    }

#ifdef UNICODE
    HMODULE hModuleUser = LoadLibraryW(L"user32.dll");
    g_hKeyBoard = SetWindowsHookExW(WH_KEYBOARD_LL, KeyBoardProc, hModuleUser, 0);
#else
    HMODULE hModuleUser = LoadLibraryA("user32.dll");
    g_hKeyBoard = SetWindowsHookExA(WH_KEYBOARD_LL, KeyBoardProc, hModuleUser, 0);
#endif  // UNICODE

    DWORD err = GetLastError();
    if (err != 0)
    {
        //LOG_ERROR("SetWindowsHookEx failed, err = [{}]", err);
    }
}

//! unregister global hook
static void UnSetHookEx()
{
    if (g_hKeyBoard)
    {
        bool bOk = UnhookWindowsHookEx(g_hKeyBoard);
        if (!bOk)
        {
            //LOG_ERROR("UnhookWindowsHookEx failed");
        }
        DWORD err = GetLastError();
        if (err != 0)
        {
            //LOG_ERROR("UnhookWindowsHookEx failed, err = [{}]", err);
        }
    }

    g_hKeyBoard = nullptr;
}

static void ActiveEx()
{
    g_bActive = true;
}

static void UnActiveEx()
{
    g_bActive = false;
}

CKeyAssistantWin::CKeyAssistantWin()
{
    InitHanlde();
    SetHook();
    Active();
}

CKeyAssistantWin::~CKeyAssistantWin()
{
    UnSetHook();
    UnActive();
}

void CKeyAssistantWin::InitHanlde()
{
}

void CKeyAssistantWin::Process() {}

void CKeyAssistantWin::SetHook()
{
    SetHookEx();
}

void CKeyAssistantWin::UnSetHook()
{
    UnSetHookEx();
}

void CKeyAssistantWin::Active()
{
    ActiveEx();
}

void CKeyAssistantWin::UnActive()
{
    UnActiveEx();
}

