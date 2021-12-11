#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QHBoxLayout>
#include <QApplication>
#include <QDebug>

class MyPushButton :public QPushButton
{
public:
	MyPushButton(QString str = "", QWidget* parent = nullptr)
		:QPushButton(parent)
	{

	}
	
	void mousePressEvent(QMouseEvent* e)
	{
		m_pt = e->pos();
	}

	void mouseMoveEvent(QMouseEvent* e)
	{
		int distance = (e->pos() - m_pt).manhattanLength();
		if (distance > QApplication::startDragDistance())
		{
			QDrag* pDg = new QDrag(this);
			QMimeData* pMd = new QMimeData;
			pMd->setText("FFF");
			pDg->setMimeData(pMd);
			if (pDg->exec(Qt::CopyAction | Qt::MoveAction | Qt::LinkAction) == Qt::MoveAction)
			{
				qDebug() << text();
			}
		}
	}

	void dragEnterEvent(QDragEnterEvent* e)
	{
		if (e->mimeData()->text() != "FFF")
			e->ignore();
		else
			e->accept();
	}

	void dragMoveEvent(QDragMoveEvent* e)
	{
		if (e->keyboardModifiers() == Qt::CTRL)
			e->setDropAction(Qt::CopyAction);
		else if (e->keyboardModifiers() == Qt::SHIFT)
			e->setDropAction(Qt::MoveAction);
		else if (e->keyboardModifiers() == Qt::ALT)
			e->setDropAction(Qt::LinkAction);
		else
			e->setDropAction(Qt::CopyAction);

		QRect rt = rect();
		if (rt.contains(e->pos()))
		{
			e->accept();
		}
		else
		{
			e->ignore();
		}
	}

	void dropEvent(QDropEvent* e)
	{
		if (e->source() == this)
			return;
		setText(e->mimeData()->text());
		e->setDropAction(Qt::MoveAction);
		e->accept();
	}

private:
	QPoint m_pt;
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
