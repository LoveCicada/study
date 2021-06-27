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

class MyMimeData :public QMimeData
{
public:
	QIcon ic;
	QString str;
	int i;
};

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
		MyMimeData* pMd = new MyMimeData;

		QString strPath = getImagesDir(); 
		QString picPath = strPath + "smile.png";

		QIcon ic(picPath);
		QString str = "test";
		
		pMd->ic = ic;
		pMd->str = str;
		pMd->i = 0;
		pDg->setMimeData(pMd);
		pDg->exec();
	}

	void dragEnterEvent(QDragEnterEvent* e)
	{
		e->acceptProposedAction();
	}

	void dropEvent(QDropEvent* e)
	{
		const MyMimeData* pMd = (MyMimeData*)(e->mimeData());
		setIcon(pMd->ic);
		setText(pMd->str);
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
