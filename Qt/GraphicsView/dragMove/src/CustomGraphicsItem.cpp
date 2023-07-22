
#include "CustomGraphicsItem.h"
#include <QPainter>
#include <QCursor>
#include <QPointF>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

CCustomGraphicsItem::CCustomGraphicsItem(QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
    Init();
}

void CCustomGraphicsItem::Init()
{
    setAcceptDrops(true);
    setFlag(QGraphicsItem::ItemIsMovable); // 可移动项
    setFlag(QGraphicsItem::ItemIsSelectable); // 可选择项
}

bool CCustomGraphicsItem::IsDrag()
{
    return m_bDrag;
}

void CCustomGraphicsItem::SetShape(EItemShape eShape)
{
    m_eItemShape = eShape;
}

void CCustomGraphicsItem::SetRadius(int nRadius)
{
    m_nRadius = nRadius;
}

QRectF CCustomGraphicsItem::boundingRect() const
{
	return QRectF(-15.5, -15.5, 34, 34);
}

void CCustomGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::white));
    painter->setBrush(Qt::white);
    
    if (EItemShape::EIS_Circle == m_eItemShape)
    {
        painter->drawEllipse(-12, -12, m_nRadius, m_nRadius);
    }
    else if (EItemShape::EIS_Rectangle == m_eItemShape)
    {
        painter->drawRect(-12, -12, m_nRadius, m_nRadius);
    }
 }

void CCustomGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    Q_UNUSED(event);
    setCursor(Qt::ClosedHandCursor);
    m_bDrag = true;
}

void CCustomGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        setPos(mapToScene(event->pos()));
    }
    else {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void CCustomGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    Q_UNUSED(event);
    setCursor(Qt::OpenHandCursor);
    m_bDrag = false;
}
