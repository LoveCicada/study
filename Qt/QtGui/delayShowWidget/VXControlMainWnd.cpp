
#include <QScrollArea>
#include <QPainter>
#include <QMouseEvent>
#include "VXControlMainWnd.h"
#include "VXControlWnd.h"

VXControlMainWnd::VXControlMainWnd(QWidget* p)
	: QWidget(p)
	, m_pVXControlWnd(nullptr)
	, m_pScroll(nullptr)
{
	setMouseTracking(true);

	m_pVXControlWnd = new VXControlWnd();
	m_pVXControlWnd->setFixedSize(280, 280);

	m_pScroll = new QScrollArea(this);
	m_pScroll->setFrameShape(QFrame::NoFrame);
	m_pScroll->setWidget(m_pVXControlWnd);
	m_pScroll->setGeometry(60, 60, 200, 240);
}

VXControlMainWnd::~VXControlMainWnd()
{
}

void VXControlMainWnd::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter p(this);
	p.setPen(Qt::NoPen);
	/* ÉèÖÃÀ¶É« */
	p.setBrush(Qt::blue);
	p.drawRect(rect());

	QWidget::paintEvent(e);
}

void VXControlMainWnd::mouseMoveEvent(QMouseEvent* e)
{
	//if (isFullScreen())
	{
		QRect rt(0, 0, geometry().width(), 1);

		int nx = e->pos().x();
		int ny = e->pos().y();
		if (rt.contains(e->pos()))
		{
			//m_pTitleBar->show();
		}
	}

	QWidget::mouseMoveEvent(e);
}
