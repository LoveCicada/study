#include "MyItem.h"

QRectF MyItem::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
		20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter* painter,
	const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(Qt::green);
	painter->drawRect(0, 0, 50, 50);
}
