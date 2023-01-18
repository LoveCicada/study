
#include "VXCustomButton.h"
#include <QKeyEvent>

VXCustomButton::VXCustomButton(QWidget* p)
	:QToolButton(p)
{
	InitCtrl();
}

VXCustomButton::~VXCustomButton()
{
	
}

void VXCustomButton::InitCtrl()
{
    setFocusPolicy(Qt::NoFocus);
}

void VXCustomButton::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key::Key_Tab)
    {
        e->ignore();
        return;
    }

    QToolButton::keyPressEvent(e);
}

void VXCustomButton::keyReleaseEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key::Key_Tab)
    {
        e->ignore();
        return;
    }

    QToolButton::keyReleaseEvent(e);
}
