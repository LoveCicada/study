
#include "VXCustomWidget.h"

VXCustomWidget::VXCustomWidget(QWidget* p)
	:QWidget(p)
	, m_pHBLayout(nullptr)
	, m_pBtnMin(nullptr)
	, m_pBtnMax(nullptr)
{
	InitCtrl();
}

VXCustomWidget::~VXCustomWidget()
{
	
}

void VXCustomWidget::InitCtrl()
{
	m_pHBLayout = new QHBoxLayout(this);
	m_pBtnMin = new VXCustomButton();
	m_pBtnMin->setText("min");
	m_pBtnMax = new VXCustomButton();
	m_pBtnMax->setText("max");
	m_pBtnClose = new VXCustomButton();
	m_pBtnClose->setText("close");
	m_pHBLayout->addWidget(m_pBtnMin);
	m_pHBLayout->addWidget(m_pBtnMax);
	m_pHBLayout->addWidget(m_pBtnClose);

	//setTabletTracking(false);
}
