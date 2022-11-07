
#include <QPainter>
#include "VXCustomWidget.h"

            
constexpr int CUSTOM_TOOLBAT_HEIGHT = 25;

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
	m_pHBLayout->setMargin(0);

	m_pBtnFull = new VXCustomButton();
	m_pBtnFull->setText("full");
	m_pBtnMin = new VXCustomButton();
	m_pBtnMin->setText("min");
	m_pBtnMax = new VXCustomButton();
	m_pBtnMax->setText("max");
	m_pBtnClose = new VXCustomButton();
	m_pBtnClose->setText("close");
	m_pHBLayout->addWidget(m_pBtnFull);
	m_pHBLayout->addWidget(m_pBtnMin);
	m_pHBLayout->addWidget(m_pBtnMax);
	m_pHBLayout->addWidget(m_pBtnClose);

	connect(m_pBtnFull, SIGNAL(clicked()), this, SLOT(OnBtnFullClicked()));
	connect(m_pBtnMin, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));
	connect(m_pBtnMax, SIGNAL(clicked()), this, SLOT(OnBtnMaxClicked()));
	connect(m_pBtnClose, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));


	//setFixedHeight(CUSTOM_TOOLBAT_HEIGHT);
}

void VXCustomWidget::OnBtnFullClicked()
{
	if (this->parentWidget()->isFullScreen())
	{
		this->parentWidget()->setWindowState(windowState() & ~Qt::WindowFullScreen);
	}
	else
	{
		hide();
		this->parentWidget()->setWindowState(windowState() | Qt::WindowFullScreen);
	}
}

void VXCustomWidget::OnBtnMinClicked()
{
	this->parentWidget()->showMinimized();
}

void VXCustomWidget::OnBtnMaxClicked()
{
	this->parentWidget()->setWindowState(Qt::WindowMaximized);
}

void VXCustomWidget::OnBtnCloseClicked()
{
	this->parentWidget()->close();
}

void VXCustomWidget::paintEvent(QPaintEvent* e)
{
	Q_UNUSED(e);

	QPainter p(this);
	p.setPen(Qt::NoPen);
	/* 设置红色 */
	p.setBrush(Qt::red);
	p.drawRect(rect());

	QWidget::paintEvent(e);
}

void VXCustomWidget::leaveEvent(QEvent* e)
{
	if (parentWidget()->isFullScreen())
	{
		hide();
	}
	QWidget::leaveEvent(e);
}
