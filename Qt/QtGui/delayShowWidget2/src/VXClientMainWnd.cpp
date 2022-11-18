#include "VXClientMainWnd.h"
#include <QApplication>
#include <QTimer>
#include <QPainter>
#include "VXCustomWidget.h"
#include "VXControlMainWnd.h"

constexpr int nTitleBarHeight = 34;

VXClientMainWnd::VXClientMainWnd(QWidget *parent)
    : QWidget(parent)
{
	initCtrl();
}

VXClientMainWnd::~VXClientMainWnd()
{

}

void VXClientMainWnd::initCtrl()
{
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	setMouseTracking(true);
	//setAttribute(Qt::WA_Hover, true);

	m_pVB = new QVBoxLayout(this);
	m_pVB->setSpacing(0);
	m_pVB->setMargin(0);

	m_pTitleBar = new VXCustomWidget();
	m_pTitleBar->setObjectName("TitleBar");
	m_pTitleBar->setFixedHeight(nTitleBarHeight);
	m_pTitleBar->setToolTip("Title Bar");

	m_pTitleBarDup = new VXCustomWidget(this);
	m_pTitleBarDup->setObjectName("TitleBarDup");
	m_pTitleBarDup->setFixedHeight(nTitleBarHeight);
	m_pTitleBarDup->setToolTip("Title Bar Dup");
	
	m_pControlMainWnd = new VXControlMainWnd();
	m_pControlMainWnd->setToolTip("ControlMainWnd");
	m_pVB->addWidget(m_pTitleBar);
	m_pVB->addWidget(m_pControlMainWnd);
	
}

void VXClientMainWnd::originalScaleLayout()
{
	if (m_pControlWndScroll && m_pControlWndLayout)
	{
		m_pControlWndScroll->setLayout(m_pControlWndLayout);
	}
}

void VXClientMainWnd::adaptLayout()
{
	if (m_pControlMainWnd && m_pControlWndLayout)
	{
		m_pControlMainWnd->setLayout(m_pControlWndLayout);
	}
}

void VXClientMainWnd::OnHide()
{
	/*QTimer::singleShot(1000, this, [=]() {
		m_pCustomWidgt->hide();
		});*/

	m_pTitleBar->hide();
}

void VXClientMainWnd::OnShow()
{
	/*QTimer::singleShot(1000, this, [=]() {
		m_pCustomWidgt->show();
		});*/

	m_pTitleBar->show();
}

void VXClientMainWnd::OnOriginal()
{
	originalScaleLayout();
}

void VXClientMainWnd::OnAdapt()
{
	adaptLayout();
}

void VXClientMainWnd::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter p(this);
	p.setPen(Qt::NoPen);
	/* ÉèÖÃºìÉ« */
	p.setBrush(Qt::yellow);
	p.drawRect(rect());

	QWidget::paintEvent(e);
}

void VXClientMainWnd::mouseMoveEvent(QMouseEvent* e)
{
	if (isFullScreen())
	{
		QRect rt(0, 0, geometry().width(), 1);

		//int nx = e->pos().x();
		//int ny = e->pos().y();
		if (rt.contains(e->pos()))
		{
			//m_pTitleBar->show();
			QRect rtTitleBar = rect();
			rtTitleBar.setHeight(nTitleBarHeight);
			m_pTitleBarDup->setGeometry(rtTitleBar);
#if 0
			m_pTitleBarDup->show();

#else
			m_pTitleBar->show();
#endif // 0

			
		}
	}

	QWidget::mouseMoveEvent(e);
}

void VXClientMainWnd::changeEvent(QEvent* e)
{
	int nType = e->type();
	if (nType == QEvent::WindowStateChange)
	{
		if (isFullScreen())
		{
			m_pTitleBarDup->raise();
		}
		else if(isMaximized())
		{
			m_pTitleBarDup->lower();
			m_pTitleBarDup->hide();
		}
		else if (isMinimized())
		{
			m_pTitleBarDup->lower();
			m_pTitleBarDup->hide();
		}
		else
		{
			m_pTitleBarDup->lower();
			m_pTitleBarDup->hide();
		}
	}

	QWidget::changeEvent(e);
}
