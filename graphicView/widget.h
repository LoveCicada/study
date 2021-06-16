#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "MyItem.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

	void initCtrl();
	void initData();

private slots:
	
private:	

	QVBoxLayout* m_pVLayout;

};

#endif // WIDGET_H
