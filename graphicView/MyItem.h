#pragma once

#include <QObject>
#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem> 
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneDragDropEvent>

class RectItem :public QGraphicsItem
{
public:
	RectItem();
	QRectF boundingRect() const;
	void paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape();

protected:
	void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent* event);
	void dropEvent(QGraphicsSceneDragDropEvent* event);
	

private:
	QColor m_Color;
	bool m_bDragOver;
};

////////////////////////////////////////////////

class MyItem : public QObject, public QGraphicsItem
{
	Q_OBJECT

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
	void keyPressEvent(QKeyEvent* event);

private:
	QColor m_Color;
};

