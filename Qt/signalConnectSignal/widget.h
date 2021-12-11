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
		connect(this, &MyPushButton::clicked, [this](bool checked = false) {
			emit mySignal2(checked);
		}
		);
		connect(this, &MyPushButton::mySignal, this, &MyPushButton::testMySignal);
		connect(this, &MyPushButton::mySignal2, this, &MyPushButton::testMySignal2);
	}

signals:
	void mySignal(bool checked = false);
	void mySignal2(bool checked = false);

public slots:
	void testMySignal(bool checked = false)
	{
		qDebug() << "test my signal";
	}

	void testMySignal2(bool checked = false)
	{
		qDebug() << "test my signal2";
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
