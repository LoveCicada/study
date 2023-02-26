
#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QToolButton>
#include "VXCustomButton.h"

class VXCustomWidget : public QWidget
{
	Q_OBJECT
public:
	VXCustomWidget(QWidget* p = nullptr);
	~VXCustomWidget();

public:
	void InitCtrl();

private slots:
	void OnBtnFullClicked();
	void OnBtnMinClicked();
	void OnBtnMaxClicked();
	void OnBtnCloseClicked();

signals:
	void ShowWindowFullScreen();

protected:
	virtual void paintEvent(QPaintEvent* e) override;
	virtual void leaveEvent(QEvent* e) override;
private:
	QHBoxLayout* m_pHBLayout;
	VXCustomButton* m_pBtnFull;
	VXCustomButton* m_pBtnMin;
	VXCustomButton* m_pBtnMax;
	VXCustomButton* m_pBtnClose;
};