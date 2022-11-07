
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

private:
	QHBoxLayout* m_pHBLayout;
	VXCustomButton* m_pBtnMin;
	VXCustomButton* m_pBtnMax;
	VXCustomButton* m_pBtnClose;
};