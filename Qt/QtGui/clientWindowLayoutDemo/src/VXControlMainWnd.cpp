
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
	QWidget::mouseMoveEvent(e);
}

void VXControlMainWnd::resizeEvent(QResizeEvent* event)
{
	QRect rt = rect();
	QRect rtCtrl = rt;

	constexpr int nXoffset = 80;
	constexpr int nYoffset = 60;

	QRect rtScroll = rtCtrl.adjusted(nXoffset * 2, nYoffset * 2, -nXoffset * 2, -nYoffset * 2);
	m_pScroll->setGeometry(rtScroll);

	QRect rtControlWnd = rtCtrl.adjusted(nXoffset, nYoffset, -nXoffset, -nYoffset);
	m_pVXControlWnd->setGeometry(rtControlWnd);

	QWidget::resizeEvent(event);
}
