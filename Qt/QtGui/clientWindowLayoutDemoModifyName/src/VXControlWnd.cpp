
#include <ratio>
#include <chrono>
#include <iostream>
#include <QPainter>
#include <QLabel>
#include <QMovie>
#include "VXControlWnd.h"

using namespace std;

VXControlWnd::VXControlWnd(QWidget* p)
	: QWidget(p)
{
	setMouseTracking(true);

	m_pLabelLoading = new QLabel(this);
	m_pLabelLoading->setText("Label");
	m_pMovie = new QMovie(":/Login/Blue/connect.gif");
	m_pLabelLoading->setMovie(m_pMovie);
	m_pMovie->start();
}

VXControlWnd::~VXControlWnd()
{
	m_pMovie->stop();
}

void VXControlWnd::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter p(this);
	p.setPen(Qt::NoPen);
	/* …Ë÷√∫Ï…´ */
	p.setBrush(Qt::darkCyan);
	p.drawRect(rect());
}

void VXControlWnd::mouseMoveEvent(QMouseEvent* e)
{
	uint64_t ts_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	cout << ts_ms << " $+$+$+$ VXControlWnd::mouseMoveEvent" << endl;

	QWidget::mouseMoveEvent(e);
}

void VXControlWnd::resizeEvent(QResizeEvent* e)
{
	if (m_pMovie && m_pLabelLoading)
	{
		QRect rt = this->rect();
		//! gif w x h: 120x120
		int nXpos = rt.width() / 2 - 60;
		int nYpos = rt.height() / 2 - 60;
		m_pLabelLoading->move(nXpos, nYpos);
		//m_pLabelLoading->show();
		//m_pMovie->start();
	}

	QWidget::resizeEvent(e);
}
