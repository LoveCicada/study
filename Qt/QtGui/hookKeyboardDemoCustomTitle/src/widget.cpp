#include "widget.h"
#include <QKeyEvent>
#include <iostream>
#include <string>
#include <sstream>
#include "log/VXLog.h"

using namespace std;

Widget::Widget(QWidget* parent)
    : QWidget(parent, Qt::FramelessWindowHint)
    , m_pVLayout(nullptr)
    , m_pTitleBar(nullptr)
    , m_pControlWnd(nullptr)
{
    setFocusPolicy(Qt::StrongFocus);

    m_pCKeyAssistant = std::move(CreateKeyAssistant());
    InitCtrl();
}

void Widget::InitCtrl()
{
    m_pVLayout = new QVBoxLayout(this);

#if TEST
    m_pTitleBar = new CXETitleBarNT(nullptr);
#else   
    m_pTitleBar = new VXCustomWidget(nullptr);
#endif // 0
    m_pVLayout->addWidget(m_pTitleBar);
    m_pTitleBar->setFixedHeight(30);

    m_pControlWnd = new QWidget();
    m_pVLayout->addWidget(m_pControlWnd);
    setFixedSize(800, 600);
}

Widget::~Widget() {}

void Widget::keyPressEvent(QKeyEvent* e)
{
    string strKey = e->text().toStdString();
    int32_t key = e->key();
    int32_t nativeScanCode = e->nativeScanCode();
    int32_t nativeVirtualKey = e->nativeVirtualKey();
    int32_t nativeModifiers = e->nativeModifiers();
    int32_t modifiers = e->modifiers();

    cout << "[Press]    "
         << " strKey: " << strKey << " key: " << hex << key << " nativeScanCode: " << hex << nativeScanCode << " nativeVirtualKey: " << hex << nativeVirtualKey
         << " nativeModifiers: " << hex << nativeModifiers << " modifiers: " << hex << modifiers << endl;

    stringstream ss;
    ss << "[Press]    "
       << " strKey: " << strKey << " key: " << hex << key << " nativeScanCode: " << hex << nativeScanCode << " nativeVirtualKey: " << hex << nativeVirtualKey
       << " nativeModifiers: " << hex << nativeModifiers << " modifiers: " << hex << modifiers << endl;

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
         << " strKey: " << strKey << " key: " << hex << key << " nativeScanCode: " << hex << nativeScanCode << " nativeVirtualKey: " << hex << nativeVirtualKey
         << " nativeModifiers: " << hex << nativeModifiers << " modifiers: " << hex << modifiers << endl;
    cout << "*************" << endl;
    cout << endl;

    stringstream ss;
    ss << "[Release]  "
       << " strKey: " << strKey << " key: " << hex << key << " nativeScanCode: " << hex << nativeScanCode << " nativeVirtualKey: " << hex << nativeVirtualKey
       << " nativeModifiers: " << hex << nativeModifiers << " modifiers: " << hex << modifiers << endl
       << "*************" << endl
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
