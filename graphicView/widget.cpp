#include "widget.h"
#include <QList>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView> 
//////////////////////////////////////////////////////

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	initCtrl();
	initData();
}

Widget::~Widget()
{

}

void Widget::initCtrl()
{
	m_pVLayout = new QVBoxLayout(this);

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	QGraphicsScene* pScene = new QGraphicsScene;
	for (int i = 0; i < 5; ++i)
	{
		MyItem* pItem = new MyItem;
		pItem->setPos(i * 50 + 20, 100);
		pScene->addItem(pItem);
	}

	RectItem* pRect = new RectItem;
	pRect->setPos(100, 200);
	pScene->addItem(pRect);
	QGraphicsView* pView = new QGraphicsView;
	pView->setScene(pScene);
	pView->resize(400, 300);
	pView->show();

	m_pVLayout->addWidget(pView);

}

void Widget::initData()
{
	
}

