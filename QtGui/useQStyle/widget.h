#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPalette>
#include <QStyleFactory>
#include <QPainter>
#include <QStyleOptionButton>

class MyPushButton : public QPushButton
{
	Q_OBJECT

public:
	bool m_bEnter;
	bool m_bPress;
	MyPushButton(QString s = "", QWidget* parent = nullptr)
		:QPushButton(s,parent)
	{
		m_bEnter = false;
		m_bPress = false;
	}

	void mousePressEvent(QMouseEvent* e)
	{
		m_bPress = true;
		update();
		QPushButton::mousePressEvent(e);
	}

	void mouseReleaseEvent(QMouseEvent* e)
	{
		m_bPress = false;
		update();
		QPushButton::mouseReleaseEvent(e);
	}

	void enterEvent(QEvent* e)
	{
		m_bEnter = true;
		update();
		QPushButton::enterEvent(e);
	}

	void leaveEvent(QEvent* e)
	{
		m_bEnter = false;
		update();
		QPushButton::leaveEvent(e);
	}

	void paintEvent(QPaintEvent* e)
	{
		QPainter painter(this);
		QStyleOptionButton psb;
		psb.rect = rect();
		psb.text = "FFF";

		psb.features = QStyleOptionButton::HasMenu;
		style()->drawControl(QStyle::CE_PushButton, &psb, &painter, this);

	}
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

	void initCtrl();
private:
	QVBoxLayout* m_pHB;
};

#endif // WIDGET_H
