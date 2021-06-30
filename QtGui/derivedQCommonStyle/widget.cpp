#include "widget.h"
#include <QApplication>

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
	m_pHB = new QVBoxLayout(this);

	MyPushButton* pBtnA = new MyPushButton("AAA");
	MyPushButton* pBtnB = new MyPushButton("BBB");
	
	pBtnA->setStyle(new MyCommonStyle());

	m_pHB->addWidget(pBtnA);
	m_pHB->addWidget(pBtnB);

}