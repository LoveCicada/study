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
	m_pHB = new QGridLayout(this);

	QPushButton* pBtnA = new QPushButton("AAA");
	QPushButton* pBtnB = new QPushButton("BBB");
	QLabel* pLabel = new QLabel("CCC");
	QLineEdit* pLineEdit = new QLineEdit("DDD");
	QComboBox* pComBo = new QComboBox;
	pComBo->addItem("EEE");
	pComBo->addItem("FFF");
	QPlainTextEdit* pPlainTextEdit = new QPlainTextEdit("GGGGG");

	//1
	m_pHB->addWidget(pBtnA, 0, 0);
	m_pHB->addWidget(pBtnB, 0, 1);

	//2
	m_pHB->addWidget(pLabel, 1, 0);

	//3
	m_pHB->addWidget(pLineEdit, 2, 0);
	
	//4
	m_pHB->addWidget(pComBo, 3, 0);

	//5
	m_pHB->addWidget(pPlainTextEdit, 4, 0);

	//set palette color
	QPalette p;
	p.setColor(QPalette::Window, QColor(111, 1, 1));
	p.setColor(QPalette::WindowText, QColor(1, 111, 1));
	p.setColor(QPalette::Base, QColor(111, 111, 1));
	p.setColor(QPalette::Text, QColor(111, 1, 111));
	p.setColor(QPalette::Button, QColor(111, 255, 111));
	p.setColor(QPalette::ButtonText, QColor(255, 255, 0));
	p.setColor(QPalette::Highlight, QColor(255, 255, 255));
	p.setColor(QPalette::HighlightedText, QColor(1, 1, 255));
	p.setColor(QPalette::Light, QColor(1, 1, 255));
	// set widget 3D effect
	p.setColor(QPalette::Dark, QColor(255, 1, 255));
	p.setColor(QPalette::Shadow, QColor(255, 1, 255));
	setPalette(p);

	qApp->setStyle(QStyleFactory::create("windows"));
}