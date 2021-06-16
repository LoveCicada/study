#pragma once

#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem> 

class MyItem : public QGraphicsItem
{

public:
	explicit MyItem(QGraphicsItem *parent = Q_NULLPTR);
	~MyItem();
	QRectF boundingRect() const;
	void paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget);
};

