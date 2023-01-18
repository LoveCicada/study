
#pragma once

#include <QToolButton>

class VXCustomButton : public QToolButton
{
	Q_OBJECT
public:
	VXCustomButton(QWidget* p = nullptr);
	~VXCustomButton();

public:
	void InitCtrl();

protected:
	virtual void keyPressEvent(QKeyEvent* e) override;
	virtual void keyReleaseEvent(QKeyEvent* e) override;

private:

};