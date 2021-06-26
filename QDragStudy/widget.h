#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QHBoxLayout>

class MyPushButton :public QPushButton
{
public:
	MyPushButton(QString str = "", QWidget* parent = nullptr)
		:QPushButton(parent)
	{

	}
	void mousePressEvent(QMouseEvent* e)
	{
		Q_UNUSED(e);
		QDrag* pDg = new QDrag(this);
		QMimeData* pMd = new QMimeData;
		pMd->setText(text());
		pDg->setMimeData(pMd);
		pDg->exec();
	}

	void dragEnterEvent(QDragEnterEvent* e)
	{
		e->accept();
	}

	void dropEvent(QDropEvent* e)
	{
		setText(e->mimeData()->text());
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
	QHBoxLayout* m_pHBLayout;

};

#endif // WIDGET_H
