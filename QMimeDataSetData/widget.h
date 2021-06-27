#ifndef WIDGET_
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QHBoxLayout>
#include <QApplication>
#include <QDebug>
#include <QPixmap>
#include <QIcon>

inline QString getImagesDir()
{
	QString strPath = QApplication::applicationDirPath();
	strPath += "/../images/";
	return strPath;
}

inline QString getFilesDir()
{
	QString strPath = QApplication::applicationDirPath();
	strPath += "/../files/";
	return strPath;
}

class MyPushButton :public QPushButton
{
public:
	MyPushButton(QString str = "", QWidget* parent = nullptr)
		:QPushButton(parent)
	{

	}

	void mouseMoveEvent(QMouseEvent* e)
	{
		Q_UNUSED(e);
		QDrag* pDg = new QDrag(this);
		QMimeData* pMd = new QMimeData;

		QString strPath = getImagesDir(); 
		QString picPath = strPath + "smile.png";

		QIcon ic(picPath);
		QString s = "test";
		QByteArray ba;
		QDataStream in(&ba, QIODevice::WriteOnly);
		in << ic << s;

		//XXX-> define type
		pMd->setData("XXX", ba);
		pDg->setMimeData(pMd);
		pDg->exec();

	}

	void dragEnterEvent(QDragEnterEvent* e)
	{
		e->acceptProposedAction();
	}

	void dropEvent(QDropEvent* e)
	{
		const QMimeData* pMd = e->mimeData();
		
		if (pMd->hasFormat("XXX"))
		{
			QByteArray ba = pMd->data("XXX");
			QDataStream out(&ba, QIODevice::ReadOnly);
			QIcon ic;
			QString s;
			out >> ic >> s;
			setIcon(ic);
			setText(s);
		}
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
