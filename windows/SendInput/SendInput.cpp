
#include <windows.h>
#include <winuser.h>
#include <iostream>
using namespace std;


#define   VK_D	0x44

//**********************************************************************
//
// Sends Win + D to toggle to the desktop
//
//**********************************************************************
void ShowDesktop()
{
    cout << "Sending 'Win-D'\r\n";
    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;
   
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_D;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_D;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_LWIN;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    if (uSent != ARRAYSIZE(inputs))
    {
        HRESULT hResult = HRESULT_FROM_WIN32(GetLastError());
        static_cast<HRESULT>(hResult);
        DWORD err = GetLastError();
        cout << "SendInput failed: " << err << endl;
    } 
}