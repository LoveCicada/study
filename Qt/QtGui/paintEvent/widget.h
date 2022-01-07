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
		QBrush greyBrush(QColor(111, 111, 111));
		QBrush redBrush(QColor(111, 1, 1));
		QBrush whiteBrush(QColor(222, 222, 222));
		QBrush greenBrush(QColor(0, 222, 0));

		QPen pen(Qt::DotLine);
		pen.setColor(QColor(1, 111, 1));
		QRect rt = rect();

		if (!m_bEnter)
		{
			painter.fillRect(rt, greyBrush);
			painter.drawText(rt, Qt::AlignCenter,text());
		}
		else
		{
			painter.fillRect(rt, redBrush);
			painter.drawText(rt, Qt::AlignCenter, text());
		}

		if (m_bEnter && m_bPress)
		{
			painter.fillRect(rt, whiteBrush);
			painter.drawText(rt, Qt::AlignCenter, text());
		}

		if (!m_bEnter && !m_bPress)
		{
			painter.fillRect(rt, greenBrush);
			painter.drawText(rt, Qt::AlignCenter, text());
		}

		if (hasFocus())
		{
			painter.setPen(pen);
			painter.drawRect(rt.adjusted(1, 1, -2, -2));
		}
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
