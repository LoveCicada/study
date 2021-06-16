#pragma once

#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem> 

class MyItem : public QGraphicsItem
{
public:
	QRectF boundingRect() const;
	void paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget);
};

