
#pragma once

#include <QWidget>

class VXControlWnd : public QWidget
{
	Q_OBJECT
public:
	VXControlWnd(QWidget* p = nullptr);
	~VXControlWnd();

protected:
	void paintEvent(QPaintEvent* e);

};