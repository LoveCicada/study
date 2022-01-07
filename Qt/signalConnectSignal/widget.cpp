#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	m_pHB = new QHBoxLayout(this);
	MyPushButton* pBtn = new MyPushButton;
	m_pHB->addWidget(pBtn);
}

Widget::~Widget()
{

}
