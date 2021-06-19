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
	m_pScene = new QGraphicsScene;
	for (int i = 0; i < 5; ++i)
	{
		MyItem* pItem = new MyItem;
		pItem->setPos(i * 50 + 20, 100);
		m_pScene->addItem(pItem);
	}

	QGraphicsLineItem* pLine = new QGraphicsLineItem(0, 50, 300, 50);
	m_pScene->addItem(pLine);

	RectItem* pRect = new RectItem;
	qDebug() << pRect->shape();
	qDebug() << pRect->boundingRect();
	pRect->setPos(100, 200);
	m_pScene->addItem(pRect);

	m_pView = new QGraphicsView;
	m_pView->setScene(m_pScene);
	m_pView->resize(400, 300);
	m_pView->show();

	m_pVLayout->addWidget(m_pView);

	m_pBtn = new QPushButton();
	m_pVLayout->addWidget(m_pBtn);

	QObject::connect(m_pBtn, &QPushButton::clicked, this, &Widget::buttonSlot);

	QObject::connect(&m_Timer, &QTimer::timeout, m_pScene, &QGraphicsScene::advance);
	
}

void Widget::initData()
{
	
}

void Widget::buttonSlot()
{
#if 1

	m_Timer.start(1000);

#else

	if (m_pScene)
		m_pScene->advance();

#endif // 0

}
