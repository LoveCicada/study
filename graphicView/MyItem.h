#pragma once

#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem> 
#include <QGraphicsSceneMouseEvent>

class MyItem : public QGraphicsItem
{

public:
	explicit MyItem(QGraphicsItem *parent = Q_NULLPTR);
	~MyItem();
	QRectF boundingRect() const;
	void paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option, QWidget* widget);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
	QColor m_Color;
};

