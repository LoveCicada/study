
#pragma once

#include <QWidget>

class QScrollArea;
class VXControlWnd;
class VXControlMainWnd : public QWidget
{
	Q_OBJECT
public:
	VXControlMainWnd(QWidget* p = nullptr);
	~VXControlMainWnd();

protected:
	virtual void paintEvent(QPaintEvent* e) override;
	virtual void mouseMoveEvent(QMouseEvent* e) override;

private:
	VXControlWnd* m_pVXControlWnd;
	QScrollArea* m_pScroll;
};