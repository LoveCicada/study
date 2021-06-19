#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "MyItem.h"
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

	void initCtrl();
	void initData();

public slots:
	void buttonSlot();

private:	

	QVBoxLayout* m_pVLayout;
	QGraphicsScene* m_pScene;
	QGraphicsView* m_pView;
	QPushButton* m_pBtn;

	QTimer m_Timer;
};

#endif // WIDGET_H
