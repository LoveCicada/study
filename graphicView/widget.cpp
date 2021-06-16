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

	MyItem* pItem = new MyItem();
	QGraphicsScene* pScene = new QGraphicsScene();
	pScene->addItem(pItem);
	QGraphicsView* pView = new QGraphicsView();
	pView->setScene(pScene);

	m_pVLayout->addWidget(pView);

}

void Widget::initData()
{
	
}

