#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "VXCKeyAssistantFactory.h"

class Widget : public QWidget
{
    Q_OBJECT

private:
    typedef std::unique_ptr<CKeyAssistant> CKeyAssistantPtr;

public:
    Widget(QWidget *parent = 0);
    ~Widget();
protected:
    virtual void keyPressEvent(QKeyEvent* e) override;
    virtual void keyReleaseEvent(QKeyEvent* e) override;
    virtual void focusInEvent(QFocusEvent* e) override;
    virtual void focusOutEvent(QFocusEvent* e) override;

private:
    CKeyAssistantPtr m_pCKeyAssistant;
};

#endif // WIDGET_H
