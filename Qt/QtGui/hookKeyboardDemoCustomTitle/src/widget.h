#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "VXCKeyAssistantFactory.h"
#include "CXETitleBar_Win.h"
#include "VXCustomWidget.h"

#define TEST 0  

class Widget : public QWidget
{
    Q_OBJECT

private:
    typedef unique_ptr<CKeyAssistant> CKeyAssistantPtr;

public:
    Widget(QWidget* parent = 0);
    void InitCtrl();
    ~Widget();

protected:
    virtual void keyPressEvent(QKeyEvent* e) override;
    virtual void keyReleaseEvent(QKeyEvent* e) override;
    virtual void focusInEvent(QFocusEvent* e) override;
    virtual void focusOutEvent(QFocusEvent* e) override;

private:
    CKeyAssistantPtr m_pCKeyAssistant;
    QVBoxLayout* m_pVLayout;

#if TEST
    CXETitleBarNT* m_pTitleBar;
#else
    VXCustomWidget* m_pTitleBar;
#endif // 0

    QWidget* m_pControlWnd;
};

#endif  // WIDGET_H
