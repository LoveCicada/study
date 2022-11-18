
#include <ratio>
#include <chrono>
#include <iostream>
#include <QPainter>
#include "VXControlWnd.h"

using namespace std;

VXControlWnd::VXControlWnd(QWidget* p)
	: QWidget(p)
{
	setMouseTracking(true);
}

VXControlWnd::~VXControlWnd()
{
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
