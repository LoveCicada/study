#include "widget.h"
#include <QApplication>
#include <QMovie>
#include <QMessageBox>

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

	m_pBtnStart = new QPushButton("Start");
	m_pBtnEnd = new QPushButton("End");
	m_pBtnCloseExe = new QPushButton("Close Exe");

	m_pLabelLoading = new QLabel();
	m_pLabelLoading->setText("Label");
	m_pMoveLoading = new QMovie("D:\\file\\ui\\loading.gif");
	m_pLabelLoading->setMovie(m_pMoveLoading);

	connect(m_pBtnStart, &QPushButton::clicked, this, &Widget::OnStart);
	connect(m_pBtnEnd, &QPushButton::clicked, this, &Widget::OnStop);
	connect(m_pBtnCloseExe, &QPushButton::clicked, this, &Widget::OnClose);

	m_pHB->addWidget(pBtnA);
	m_pHB->addWidget(pBtnB);
	m_pHB->addWidget(m_pBtnStart);
	m_pHB->addWidget(m_pBtnEnd);
	m_pHB->addWidget(m_pBtnCloseExe);
	m_pHB->addWidget(m_pLabelLoading);

	this->setStyleSheet("background-color:rgb(211,111,211)");
}

void Widget::OnStart()
{
	m_pLabelLoading->show();
	m_pMoveLoading->start();
}

void Widget::OnStop()
{
	m_pLabelLoading->hide();
	m_pMoveLoading->stop();
}

void Widget::OnClose()
{
	QMessageBox::information(this, "Widget", "close exe");
	close();
}
