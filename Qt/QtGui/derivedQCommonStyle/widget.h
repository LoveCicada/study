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
#include <QCommonStyle>
#include <QColor>
#include <QBrush>

class MyCommonStyle :public QCommonStyle
{
	Q_OBJECT

public:
	void drawControl(ControlElement e, const QStyleOption* op,
		QPainter *pr, const QWidget* w = Q_NULLPTR)const
	{
		QPen pen(QColor(1, 111, 1));				//green
		QBrush brushGray(QColor(111, 111, 111));	//gray
		QBrush brushRed(QColor(111, 1, 1));		//red
		QBrush brushWhite(QColor(222, 222, 222));	//white

		const QStyleOptionButton* pb = qstyleoption_cast<const QStyleOptionButton*>(op);
		QRect rt = pb->rect;
		if (pb->state&QStyle::State_MouseOver)
		{
			pr->fillRect(rt, brushRed);
		}
		else if (pb->state&QStyle::State_Raised)
		{
			pr->fillRect(rt, brushGray);
		}

		if (pb->state&QStyle::State_Sunken)
		{
			pr->fillRect(rt, brushWhite);
		}

		if (pb->state&QStyle::State_HasFocus)
		{
			pr->save();
			pen.setWidth(4);
			pen.setStyle(Qt::DashLine);
			pr->setPen(pen);
			pr->drawRect(rt.adjusted(1, 1, -2, -2));
			pr->restore();
		}

		pr->drawText(rt, Qt::AlignCenter, pb->text);

	}

	void polish(QWidget* w)
	{
		w->setAttribute(Qt::WA_Hover, true);
	}

	void unpolish(QWidget* w)
	{
		w->setAttribute(Qt::WA_Hover, false);
	}

};


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
