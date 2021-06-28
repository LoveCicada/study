#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>

class MyPushButton : public QPushButton
{
	Q_OBJECT

public:
	MyPushButton(QString str = "", QWidget* parent = nullptr)
		:QPushButton(str,parent)
	{
		connect(this, &MyPushButton::clicked, this, &MyPushButton::mySignal);
		connect(this, &MyPushButton::mySignal, this, &MyPushButton::testMySignal);
	}

signals:
	void mySignal(bool checked = false);

public slots:
	void testMySignal(bool checked = false)
	{
		qDebug() << "test my signal";
	}


};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
	QHBoxLayout* m_pHB;
};

#endif // WIDGET_H
