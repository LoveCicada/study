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

class MimeData
{
public:
	MimeData()
	{
		str = "";
		i = 0;
	}

	MimeData(QIcon _ic, QString _str, int _i)
	{
		ic = _ic;
		str = _str;
		i = _i;
	}

	QIcon ic;
	QString str;
	int i;
};

class MyMimeData : public QMimeData
{
public:
	MimeData data;
	QStringList strType;

	void setMyType(QString _strType,MimeData _data)
	{
		if (!hasFormat(_strType))
			strType.append(_strType);
		data.ic = _data.ic;
		data.str = _data.str;
	}

	MimeData MyType(QString _strType) const
	{
		if (hasFormat(_strType))
			return data;
		else
			return MimeData();
	}

	QStringList formats()const
	{
		return strType;
	}

	bool hasFormats(const QString& _strType)const
	{
		if (strType.contains(_strType))
			return true;
		else
			return QMimeData::hasFormat(_strType);
	}

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
		
		MimeData data{ic,str,0};
		pMd->setMyType("XXX", data);
		
		pMd->strType << "CCC" << "DDD";
		QString picPath2 = strPath + "excite.png";
		MimeData data2;
		data2.ic = QIcon(picPath2);
		data2.str = "test2";
		pMd->setMyType("CCC", data2);

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
		if (pMd->hasFormat("CCC"))
		{
			setIcon(pMd->MyType("CCC").ic);
			setText(pMd->MyType("CCC").str);
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
