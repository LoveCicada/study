#include "widget.h"
#include <QKeyEvent>
#include <iostream>
#include <string>
#include <sstream>
#include "log/VXLog.h"

#if defined(_WIN32)
#include <Windows.h>
#endif

using namespace std;


#if defined(_WIN32)
void recordKeyCode(MSG* pMsg)
{
    if (!pMsg)
        return;

    switch (pMsg->message)
    {
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
        if (pMsg->wParam == VK_RETURN)
        {
            std::cout << __FUNCTION__ << " Press: " << "VK_RETURN" << std::endl;
        }
        if (pMsg->wParam == VK_LWIN)
        {
            std::cout << __FUNCTION__ << " Press: " << "VK_LWIN" << std::endl;
        }


        break;
    case WM_KEYUP:
    case WM_SYSKEYUP:
        if (pMsg->wParam == VK_RETURN)
        {
            std::cout << __FUNCTION__ << " Release: " << "VK_RETURN" << std::endl;
        }
        if (pMsg->wParam == VK_LWIN)
        {
            std::cout << __FUNCTION__ << " Release: " << "VK_LWIN" << std::endl;
        }

        break;
    default: break;
    }
}
#endif


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    m_pCKeyAssistant = std::move(CreateKeyAssistant());

#if defined(_WIN32)
    //m_pCKeyAssistant.reset(new CKeyAssistantWin);
#elif defined(__APPLE__) && defined(__MACH__)
    m_pCKeyAssistant.reset(new CKeyAssistantMac);
#else

#endif

}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent* e)
{
    string strKey = e->text().toStdString();
    int32_t key = e->key();
    int32_t nativeScanCode = e->nativeScanCode();
    int32_t nativeVirtualKey = e->nativeVirtualKey();
    int32_t nativeModifiers = e->nativeModifiers();
    int32_t modifiers = e->modifiers();

    cout <<"[Press]    " 
        << " strKey: " << strKey
        << " key: " << hex << key 
        << " nativeScanCode: "      << hex << nativeScanCode
        << " nativeVirtualKey: "    << hex << nativeVirtualKey
        << " nativeModifiers: "     << hex << nativeModifiers
        << " modifiers: "           << hex << modifiers
        << endl;

    stringstream ss;
    ss << "[Press]    "
        << " strKey: " << strKey
        << " key: " << hex << key
        << " nativeScanCode: " << hex << nativeScanCode
        << " nativeVirtualKey: " << hex << nativeVirtualKey
        << " nativeModifiers: " << hex << nativeModifiers
        << " modifiers: " << hex << modifiers
        << endl;

    string str = ss.str();
    LOG(str);

    e->ignore();
}

void Widget::keyReleaseEvent(QKeyEvent* e)
{
    string strKey = e->text().toStdString();
    int32_t key = e->key();
    int32_t nativeScanCode = e->nativeScanCode();
    int32_t nativeVirtualKey = e->nativeVirtualKey();
    int32_t nativeModifiers = e->nativeModifiers();
    int32_t modifiers = e->modifiers();

    cout << "[Release]  "
        << " strKey: " << strKey
        << " key: " << hex << key
        << " nativeScanCode: " << hex << nativeScanCode
        << " nativeVirtualKey: " << hex << nativeVirtualKey
        << " nativeModifiers: " << hex << nativeModifiers
        << " modifiers: " << hex << modifiers
        << endl;
    cout << "*************" << endl;
    cout << endl;

    stringstream ss;
    ss << "[Release]  "
        << " strKey: " << strKey
        << " key: " << hex << key
        << " nativeScanCode: " << hex << nativeScanCode
        << " nativeVirtualKey: " << hex << nativeVirtualKey
        << " nativeModifiers: " << hex << nativeModifiers
        << " modifiers: " << hex << modifiers
        << endl
        << "*************"
        << endl
        << endl;

    string str = ss.str();
    LOG(str);

    e->ignore();
}

void Widget::focusInEvent(QFocusEvent* e)
{

    QWidget::focusInEvent(e);
}

void Widget::focusOutEvent(QFocusEvent* e)
{

    QWidget::focusOutEvent(e);
}

bool Widget::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    (void*)(message);
    (void*)(result);
    if (eventType == "windows_generic_MSG")
    {
        PMSG msg = static_cast<PMSG>(message);
        (void*)(msg);
        recordKeyCode(msg);
        if (msg->message == WM_KEYDOWN || msg->message == WM_SYSKEYDOWN
            || msg->message == WM_KEYUP || msg->message == WM_SYSKEYUP)
        {
            return true;
        }
        return false;
    }

    return false;
}

