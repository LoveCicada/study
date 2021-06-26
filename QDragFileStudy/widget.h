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

	void dragEnterEvent(QDragEnterEvent* e)
	{
		if (e->mimeData()->hasUrls())
			e->accept();
		else
			e->ignore();
	}

	void dropEvent(QDropEvent* e)
	{
		const QMimeData* pMd = e->mimeData();
		QList<QUrl> u = pMd->urls();
		QString strPath = u.at(0).toLocalFile();
		if (!strPath.isEmpty())
		{
			QFile file(strPath);
			if (file.open(QIODevice::ReadOnly))
			{
				QTextStream in(&file);
				setText(in.readAll());
			}
		}
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
