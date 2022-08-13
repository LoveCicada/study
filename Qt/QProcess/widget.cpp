#include "widget.h"
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
	initCtrl();
	setFixedSize(480, 360);
	initData();
	initSignalSlot();
}

Widget::~Widget()
{

}

void Widget::initCtrl()
{
	m_pGridLayout = new QGridLayout(this);

	m_pLabelName = new QLabel();
	m_pLabelName->setText("exe name");
	m_pGridLayout->addWidget(m_pLabelName, 0, 0);
	m_pEditName = new QLineEdit();
	m_pGridLayout->addWidget(m_pEditName, 0, 1);

	m_pLabelParams = new QLabel();
	m_pLabelParams->setText("exe params");
	m_pGridLayout->addWidget(m_pLabelParams, 1, 0);

	m_pEditParams = new QLineEdit();
	m_pGridLayout->addWidget(m_pEditParams, 1, 1);

	m_pBtnStart = new QPushButton();
	m_pBtnStart->setText("start");
	m_pGridLayout->addWidget(m_pBtnStart, 2, 0);

	m_pBtnStop = new QPushButton();
	m_pBtnStop->setText("stop");
	m_pGridLayout->addWidget(m_pBtnStop, 2, 1);
}

void Widget::initData()
{
	m_pTask = new SubTask();
}

void Widget::initSignalSlot()
{
	connect(m_pBtnStart, &QPushButton::clicked, this, &Widget::startBtnSlots);
	connect(m_pBtnStop, &QPushButton::clicked, this, &Widget::stopBtnSlots);
}

void Widget::startBtnSlots()
{
	SubTask::TaskParams taskParams;
	taskParams.processName = m_pEditName->text();
	taskParams.processParams << m_pEditParams->text();
	m_pTask->Init(taskParams);
	m_pTask->Start();
}

void Widget::stopBtnSlots()
{

}