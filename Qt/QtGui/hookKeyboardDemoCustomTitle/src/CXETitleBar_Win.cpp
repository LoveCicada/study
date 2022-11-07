#include <QPainter>
#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QGradient>
#include <QMenu>

#include "CXETitleBar_Win.h"

CXETitleBarNT::CXETitleBarNT(QWidget* parent)
    : CXEBaseTitleBar(parent)
{
    initData();
    initUi();
    initConnections();
}

void CXETitleBarNT::initData()
{
    m_pTitleContent = new QLabel(this);
    QPixmap pix(":/Login/Blue/logo.png");
    pix = pix.scaled(QSize(70, 30), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    m_pTitleContent->setPixmap(pix);
    //m_pTitleContent->setFocusPolicy(Qt::NoFocus);

    m_pButtonMin = new QToolButton(this);
    m_pButtonMin->setObjectName(QString("titleToolButton"));
    m_pButtonMin->setFocusPolicy(Qt::NoFocus);

    m_pButtonMax = new QToolButton(this);
    m_pButtonMax->setObjectName(QString("titleToolButton"));
    m_pButtonMax->setFocusPolicy(Qt::NoFocus);

    m_pButtonRestore = new QToolButton(this);
    m_pButtonRestore->setObjectName(QString("titleToolButton"));
    m_pButtonRestore->setFocusPolicy(Qt::NoFocus);

    m_pButtonClose = new QToolButton(this);
    m_pButtonClose->setObjectName(QString("close"));
    m_pButtonClose->setFocusPolicy(Qt::NoFocus);

    m_pButtonShow = new QToolButton(this);
    m_pButtonShow->setObjectName(QString("titleToolButton"));
    m_pButtonShow->setFocusPolicy(Qt::NoFocus);

    m_pButtonSet = new QToolButton(this);
    m_pButtonSet->setObjectName(QString("titleToolButton"));
    m_pButtonSet->setFocusPolicy(Qt::NoFocus);

    m_pButtonFull = new QToolButton(this);
    m_pButtonFull->setObjectName(QString("titleToolButton"));
    m_pButtonFull->setFocusPolicy(Qt::NoFocus);
}

void CXETitleBarNT::initUi()
{
    setObjectName(QString("WinTitleBar"));
    // setFixedHeight(30);
    setWindowFlags(Qt::FramelessWindowHint);

    m_pButtonMin->setToolTip(tr("IDS_COMMON_SYSMENU_MIN"));
    m_pButtonMax->setToolTip(tr("IDS_COMMON_SYSMENU_MAX"));
    m_pButtonRestore->setToolTip(tr("IDS_COMMON_SYSMENU_RESTORE"));
    m_pButtonClose->setToolTip(tr("IDS_COMMON_SYSMENU_CLOSE"));

    m_pButtonMin->setFixedSize(20, 15);
    m_pButtonMax->setFixedSize(20, 15);
    m_pButtonRestore->setFixedSize(20, 15);
    m_pButtonClose->setFixedSize(20, 15);
    m_pButtonShow->setFixedSize(25, 20);
    m_pButtonSet->setFixedSize(25, 20);
    m_pButtonFull->setFixedSize(25, 20);

    m_pButtonMax->setIcon(QIcon(":/Login/Blue/max2.png"));
    m_pButtonRestore->setIcon(QIcon(":/Login/Blue/max.png"));
    m_pButtonMin->setIcon(QIcon(":/Login/Blue/min1.png"));
    m_pButtonClose->setIcon(QIcon(":/Login/Blue/close1.png"));
    m_pButtonShow->setIcon(QIcon(":/Login/Blue/showFps.png"));
    m_pButtonSet->setIcon(QIcon(":/Login/Blue/set.png"));
    m_pButtonFull->setIcon(QIcon(":/Login/Blue/set.png"));

    m_pButtonRestore->setVisible(false);

    QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addStretch();
    mylayout->addWidget(m_pTitleContent);
    mylayout->addStretch();
    mylayout->addWidget(m_pButtonShow);
    mylayout->addWidget(m_pButtonSet);
    mylayout->addWidget(m_pButtonMin);
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);

    mylayout->setContentsMargins(5, 0, 0, 0);
    mylayout->setSpacing(0);
    setLayout(mylayout);
}

void CXETitleBarNT::initConnections()
{
    connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
    connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
    connect(m_pButtonShow, SIGNAL(clicked()), this, SLOT(onButtonShowFpsClicked()));
    connect(m_pButtonSet, SIGNAL(clicked()), this, SLOT(onButtonSetClicked()));
    connect(m_pButtonFull, SIGNAL(clicked()), this, SLOT(onButtonFullScreenClicked()));
}

void CXETitleBarNT::showControls() {}

void CXETitleBarNT::hideControls()
{
    m_pButtonMin->setVisible(false);
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(false);
    m_pButtonShow->setVisible(false);
    m_pButtonSet->setVisible(false);
    m_pButtonFull->setVisible(false);
}

void CXETitleBarNT::setMinVisible(bool bable)
{
    m_pButtonMin->setVisible(bable);
}

void CXETitleBarNT::setMaxVisible(bool bable, bool isMaxed)
{
    m_pButtonMax->setVisible(bable);
    if (isMaxed)
        m_pButtonRestore->setVisible(!bable);
}

void CXETitleBarNT::setTitleContent(QString strContent)
{
    m_pTitleContent->setText(strContent);
}

void CXETitleBarNT::setBackgroundColor(QRgb nColor)
{
    m_clBack = nColor;
}

void CXETitleBarNT::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), QColor(255, 255, 255));
}

void CXETitleBarNT::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    QRect rt = rect();
    QRect rtLabel;
    rtLabel.setTop(rt.top());
    rtLabel.setBottom(rt.bottom());
    rtLabel.setLeft(rt.left());
    rtLabel.setRight(rt.left() + 70);
    if (m_pTitleContent)
        m_pTitleContent->setGeometry(rtLabel);

    QRect rtCtrl;
    rtCtrl.setTop(rt.top());
    rtCtrl.setBottom(rt.bottom());
    rtCtrl.setRight(rt.right());
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonClose)
        m_pButtonClose->setGeometry(rtCtrl);

    rtCtrl.setRight(rtCtrl.left() - 10);
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonMax)
        m_pButtonMax->setGeometry(rtCtrl);
    if (m_pButtonRestore)
        m_pButtonRestore->setGeometry(rtCtrl);

    rtCtrl.setRight(rtCtrl.left() - 10);
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonMin)
        m_pButtonMin->setGeometry(rtCtrl);

    rtCtrl.setRight(rtCtrl.left() - 30);
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonSet)
        m_pButtonSet->setGeometry(rtCtrl);

    rtCtrl.setRight(rtCtrl.left() - 10);
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonShow)
        m_pButtonShow->setGeometry(rtCtrl);

    rtCtrl.setRight(rtCtrl.left() - 10);
    rtCtrl.setLeft(rtCtrl.right() - 20);
    if (m_pButtonFull)
        m_pButtonFull->setGeometry(rtCtrl);
}

// 以下为按钮操作响应的槽;
void CXETitleBarNT::onButtonMinClicked()
{
    this->parentWidget()->showMinimized();
}

void CXETitleBarNT::onButtonRestoreClicked()
{
    setMaxVisible(true, false);
    this->parentWidget()->showNormal();
}

void CXETitleBarNT::onButtonMaxClicked()
{
    setMaxVisible(false, true);
    this->parentWidget()->setWindowState(Qt::WindowMaximized);
    emit ShowWindowMaximized();
}

void CXETitleBarNT::onButtonCloseClicked()
{
    this->parentWidget()->close();
}

void CXETitleBarNT::onButtonShowFpsClicked()
{
    emit ShowFpsInfo();
}

void CXETitleBarNT::onButtonSetClicked()
{
    emit ShowSetMenu();
}

void CXETitleBarNT::onButtonFullScreenClicked()
{
    emit ShowWindowFullScreen();
}

/************** CXETitleBarNT ******************/
CXETitleBarNTEx::CXETitleBarNTEx(QWidget* parent)
    : CXETitleBarNT(parent)
{
}

void CXETitleBarNTEx::leaveEvent(QEvent* e)
{
    /*
     * @brief Implement auto hide top title
     * When parentWidget is fullScreen, we leave top custom title control,
     * we need hide.
     */
    if (parentWidget()->isFullScreen())
    {
        hide();
    }
    CXETitleBarNT::leaveEvent(e);
}
