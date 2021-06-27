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
	m_pHB = new QHBoxLayout(this);

	QPushButton* pBtnA = new QPushButton;
	pBtnA->setText("AAA");
	pBtnA->setStyle(QStyleFactory::create("fusion"));

	QPushButton* pBtnB = new QPushButton;
	pBtnB->setText("BBB");

	QPushButton* pBtnC = new QPushButton;
	pBtnC->setText("CCC");

	m_pHB->addWidget(pBtnA);
	m_pHB->addWidget(pBtnB);
	m_pHB->addWidget(pBtnC);

	qApp->setStyle(QStyleFactory::create("windows"));
}