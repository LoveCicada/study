#include "MyItem.h"
#include <QLineF> 
#include <QApplication>
#include <QVariant>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QMenu>


RectItem::RectItem()
{
	setAcceptDrops(true);
	setFlag(QGraphicsItem::ItemIsMovable);
	m_Color = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const
{
	return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setBrush(!collidingItems().isEmpty() ? Qt::red : Qt::green);
	painter->drawRect(0, 0, 50, 50);
}

QPainterPath RectItem::shape()
{
	QPainterPath path;
	path.addRect(0, 0, 50, 50);
	return path;
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{
	if (event->mimeData()->hasColor())
	{
		event->setAccepted(true);
		m_bDragOver = true;
		update();
	}
	else
	{
		event->setAccepted(false);
	}
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent* event)
{
	Q_UNUSED(event);
	m_bDragOver = false;
	update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent* event)
{
	m_bDragOver = false;
	if (event->mimeData()->hasColor())
	{
		m_Color = qvariant_cast<QColor>(event->mimeData()->colorData());
		update();
	}
}

////////////////////////////////////////////////

MyItem::MyItem(QGraphicsItem *parent)
	:QGraphicsItem(parent)
{
	setToolTip("Click and drag me!");
	setCursor(Qt::OpenHandCursor);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFlag(QGraphicsItem::ItemIsMovable);

	QGraphicsItemAnimation *pAnim = new QGraphicsItemAnimation;
	pAnim->setItem(this);
	QTimeLine* pTimeLine = new QTimeLine(1000);
	pTimeLine->setLoopCount(0);
	pAnim->setTimeLine(pTimeLine);
	pAnim->setRotationAt(0.5, 180);
	pAnim->setRotationAt(1, 360);
	pTimeLine->start();

	m_Color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);

}

MyItem::~MyItem()
{

}

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
	painter->setBrush(m_Color);
	painter->drawEllipse(0, 0, 20, 20);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (event->button() != Qt::LeftButton)
	{
		event->ignore();
		return;
	}
	setCursor(Qt::ClosedHandCursor);
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	if (QLineF(event->screenPos(), event->buttonDownScenePos(Qt::LeftButton)).length()
		<QApplication::startDragDistance())
	{
		//如果鼠标按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回
		return;
	}

	QDrag* pDrag = new QDrag(event->widget());
	QMimeData* pMime = new QMimeData;
	pDrag->setMimeData(pMime);
	pMime->setColorData(m_Color);

	QPixmap pix(21, 21);
	pix.fill(Qt::red);
	QPainter painter(&pix);
	paint(&painter, 0, 0);
	pDrag->setPixmap(pix);

	pDrag->setHotSpot(QPoint(10, 15));
	pDrag->exec();
	setCursor(Qt::OpenHandCursor);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	Q_UNUSED(event);
	setCursor(Qt::OpenHandCursor);
}

void MyItem::keyPressEvent(QKeyEvent* event)
{
	Q_UNUSED(event);
	moveBy(0, 10);
}

void MyItem::advance(int phase)
{
	if (!phase)
		return;
	moveBy(0, 10);
}

void MyItem::moveTo()
{
	setPos(0, 0);
}

void MyItem::contextMenuEvent(QGraphicsSceneContextMenuEvent* event)
{
	QMenu menu;
	QAction* pAction = menu.addAction("moveTo(0,0)");
	connect(pAction, &QAction::triggered, this, &MyItem::moveTo);
	menu.exec(event->screenPos());
}