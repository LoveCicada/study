#pragma once

#include <QFrame>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include "CXEBaseTitleBar.h"

class CXETitleBarNT : public CXEBaseTitleBar
{
    Q_OBJECT
public:
    CXETitleBarNT(QWidget* parent);

    void initData();
    void initUi();
    void initConnections();

public:
    virtual void showControls();
    virtual void hideControls();
    virtual void setMinVisible(bool bable);
    virtual void setMaxVisible(bool bable, bool isMaxed = false);
    virtual void setTitleContent(QString strContent);
    virtual void setBackgroundColor(QRgb nColor);

protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void resizeEvent(QResizeEvent* event) override;
private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();
    void onButtonShowFpsClicked();
    void onButtonSetClicked();
    void onButtonFullScreenClicked();

signals:
    void ShowFpsInfo();
    void ShowSetMenu();
    void ShowWindowMaximized();
    void ShowWindowFullScreen();

private:
    QLabel* m_pTitleContent;
    QToolButton* m_pButtonMin;
    QToolButton* m_pButtonMax;
    QToolButton* m_pButtonRestore;
    QToolButton* m_pButtonClose;
    QToolButton* m_pButtonShow;
    QToolButton* m_pButtonSet;
    QToolButton* m_pButtonFull;

    QRgb m_clBack;
};

/************** CXETitleBarNT ******************/
class CXETitleBarNTEx : public CXETitleBarNT
{
    Q_OBJECT
public:
    CXETitleBarNTEx(QWidget* parent = nullptr);

protected:
    virtual void leaveEvent(QEvent* e) override;
};