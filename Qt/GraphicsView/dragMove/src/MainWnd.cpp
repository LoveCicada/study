
#include "MainWnd.h"
#include <QMoveEvent>

CMainWnd::CMainWnd(QWidget* p)
	:QWidget(p)
{
	Init();
}

CMainWnd::~CMainWnd()
{

}

void CMainWnd::Init()
{
	InitCtronol();
	InitTimer();
	InitSignalSlot();
}

void CMainWnd::InitCtronol()
{
	setFixedSize(540, 600);

	m_pLabelShape = new QLabel("Shape");
	m_pComboxShape = new QComboBox();
	m_pComboxShape->addItem("Circle");
	m_pComboxShape->addItem("Square");
	m_pBtnSave = new QPushButton("Save");

	m_pLabelRadius = new QLabel("Radius");
	m_pEditRadius = new QLineEdit();
	m_pEditRadius->setText("30");
	m_pBtnLoad = new QPushButton("load");

	m_pGridLayout = new QGridLayout();
	m_pGridLayout->addWidget(m_pLabelShape, 0, 0);
	m_pGridLayout->addWidget(m_pComboxShape, 0, 1);
	m_pGridLayout->addWidget(m_pBtnSave, 0, 2);
	m_pGridLayout->addWidget(m_pLabelRadius, 1, 0);
	m_pGridLayout->addWidget(m_pEditRadius, 1, 1);
	m_pGridLayout->addWidget(m_pBtnLoad, 1, 2);

	m_pGraphicsView = new GraphicsView();

	m_pVLayout = new QVBoxLayout(this);
	m_pVLayout->addLayout(m_pGridLayout);
	m_pVLayout->addWidget(m_pGraphicsView);
}

void CMainWnd::InitTimer()
{
	m_pTimer = new QTimer(this);
	m_pTimer->setInterval(500);
}

void CMainWnd::InitSignalSlot()
{
	connect(m_pTimer, &QTimer::timeout, this, &CMainWnd::slotTimer);
	m_pTimer->start();

	connect(m_pComboxShape, &QComboBox::currentTextChanged, this, &CMainWnd::slotShapeChaned);
	connect(m_pEditRadius, &QLineEdit::textChanged, this, &CMainWnd::slotRadiusChange);

}

void CMainWnd::slotShapeChaned(const QString& text)
{
	if (!m_pGraphicsView)
		return;

	if ("Circle" == text)
	{
		m_pGraphicsView->SetShape(EItemShape::EIS_Circle);
	}
	else if ("Square" == text)
	{
		m_pGraphicsView->SetShape(EItemShape::EIS_Rectangle);
	}
}

void CMainWnd::slotRadiusChange(const QString& text)
{
	if (!m_pGraphicsView)
		return;

	int nRadius = text.toInt();

	m_pGraphicsView->SetRadius(nRadius);
}

void CMainWnd::slotTimer()
{
	if (!m_pGraphicsView)
		return;

	m_pGraphicsView->UpateItemPosition();
}