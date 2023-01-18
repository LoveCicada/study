
#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QMovie;
QT_END_NAMESPACE

class VXControlWnd : public QWidget
{
	Q_OBJECT
public:
	VXControlWnd(QWidget* p = nullptr);
	~VXControlWnd();

protected:
	virtual void paintEvent(QPaintEvent* e) override;
	virtual void mouseMoveEvent(QMouseEvent* e) override;
	virtual void resizeEvent(QResizeEvent* e) override;
private:

	QLabel* m_pLabelLoading;
	QMovie* m_pMovie;
};