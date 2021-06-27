#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	initCtrl();
}

Widget::~Widget()
{

}

void Widget::initCtrl()
{
	m_pHBLayout = new QHBoxLayout(this);

	MyPushButton* pBtnA = new MyPushButton("AAA");
	pBtnA->setText("AAA");
	MyPushButton* pBtnB = new MyPushButton("BBB");
	pBtnB->setText("BBB");
	MyPushButton* pBtnC = new MyPushButton("CCC");
	pBtnC->setText("CCC");

	pBtnA->setAcceptDrops(false);
	pBtnB->setAcceptDrops(true);
	pBtnC->setAcceptDrops(false);

	m_pHBLayout->addWidget(pBtnA);
	m_pHBLayout->addWidget(pBtnB);
	m_pHBLayout->addWidget(pBtnC);

}