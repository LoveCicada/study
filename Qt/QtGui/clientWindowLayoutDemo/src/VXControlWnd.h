
#pragma once

#include <QWidget>

class VXControlWnd : public QWidget
{
	Q_OBJECT
public:
	VXControlWnd(QWidget* p = nullptr);
	~VXControlWnd();

protected:
	virtual void paintEvent(QPaintEvent* e) override;
	virtual void mouseMoveEvent(QMouseEvent* e) override;
};