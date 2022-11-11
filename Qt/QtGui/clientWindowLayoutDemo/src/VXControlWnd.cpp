
#include <QPainter>
#include "VXControlWnd.h"

VXControlWnd::VXControlWnd(QWidget* p)
	: QWidget(p)
{
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
