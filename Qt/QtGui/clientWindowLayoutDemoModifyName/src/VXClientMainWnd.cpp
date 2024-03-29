#include "VXClientMainWnd.h"
#include <QApplication>
#include <QTimer>
#include <QPainter>
#include "VXFramelessHelper.h"
#include "VXCustomWidget.h"
#include "VXControlMainWnd.h"

VXClientMainWnd::VXClientMainWnd(QWidget *parent)
    : QWidget(parent)
	, m_pFramelessHelper(nullptr)
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

	m_pFramelessHelper = new VXFramelessHelper(this);
	m_pFramelessHelper->activateOn(this);
	m_pFramelessHelper->setWidgetResizable(true);
	m_pFramelessHelper->setWidgetDbClickable(true);

	m_pVB = new QVBoxLayout(this);
	m_pVB->setSpacing(0);
	m_pVB->setMargin(0);

	m_pTitleBar = new VXCustomWidget();
	m_pTitleBar->setFixedHeight(34);
	
	m_pControlMainWnd = new VXControlMainWnd();
	m_pVB->addWidget(m_pTitleBar);
	m_pVB->addWidget(m_pControlMainWnd);
	
	//! signal 
	connect(m_pTitleBar, &VXCustomWidget::ShowWindowFullScreen, this, &VXClientMainWnd::OnShowFullScreen);

	//updateAppName();
}

void VXClientMainWnd::updateAppName()
{
	QGuiApplication::setApplicationName("loveCicada");
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

void VXClientMainWnd::OnShowFullScreen()
{
	if (isFullScreen())
	{
		m_pFramelessHelper->removeFrom(this);
	}
	else
	{
		m_pFramelessHelper->activateOn(this);
	}
}

void VXClientMainWnd::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter p(this);
	p.setPen(Qt::NoPen);
	/* ���ú�ɫ */
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
			m_pTitleBar->show();
		}
	}

	printf(" *-*-*-* VXClientMainWnd::mouseMoveEvent\n");
	QWidget::mouseMoveEvent(e);
}
