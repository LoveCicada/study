#pragma once

#include <QString>
#include <QFrame>
#include <QWidget>

class CXEBaseTitleBar : public /*QFrame*/QWidget
{
public:
    CXEBaseTitleBar(QWidget* parent)
        : /*QFrame*/QWidget(parent)
    {
    }
    virtual void showControls() = 0;
    virtual void hideControls() = 0;
    virtual void setMinVisible(bool bable) = 0;
    virtual void setMaxVisible(bool bable, bool isMaxed = false) = 0;
    virtual void setTitleContent(QString strContent) = 0;
    virtual void setBackgroundColor(QRgb nColor) = 0;
};
