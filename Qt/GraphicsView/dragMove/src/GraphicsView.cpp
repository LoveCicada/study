
#include "GraphicsView.h"
#include <QGraphicsItem>
#include <QDebug>

GraphicsView::GraphicsView(QWidget* parent)
	: QGraphicsView(parent)
{
	Init();
}

void GraphicsView::Init()
{
	InitControl();
	InitProperty();
}

void GraphicsView::InitControl()
{
	//setFixedSize(518, 520);

	m_pGraphicsScene = new QGraphicsScene();
	m_pGraphicsScene->setSceneRect(-200, -200, 200, 200);
	m_pGraphicsItemSquare = new CCustomGraphicsItem();
	m_pGraphicsScene->addItem(m_pGraphicsItemSquare);

	setScene(m_pGraphicsScene);
	setMaximumSize(518, 529);
}

void GraphicsView::InitProperty()
{
	// 禁用水平滚动条
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// 禁用垂直滚动条
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setRenderHint(QPainter::Antialiasing);
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	setBackgroundBrush(QColor(4, 158, 109));
}

void GraphicsView::InitSignalSlot()
{

}

void GraphicsView::UpateItemPosition()
{
	if (!m_pGraphicsItemSquare)
		return;

	QRect rt = rect();
	qDebug() << "rt: " << rt;

	QPointF scenePos = m_pGraphicsItemSquare->scenePos();
	qDebug() << "scenePos: " << scenePos;

	QPointF pos = m_pGraphicsItemSquare->pos();
	qDebug() << "pos: " << pos;

	// 模拟图元移动
	qreal qOffset = 10.0f;
	m_pGraphicsItemSquare->setPos(pos.x(), pos.y() + qOffset);
}

void GraphicsView::SetShape(EItemShape SetShape)
{
	if (m_pGraphicsItemSquare)
	{
		m_pGraphicsItemSquare->SetShape(SetShape);
	}
}

void GraphicsView::SetRadius(int nRadius)
{
	if (m_pGraphicsItemSquare)
	{
		m_pGraphicsItemSquare->SetRadius(nRadius);
	}
}
