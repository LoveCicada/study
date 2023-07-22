
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTimer>
#include "GraphicsView.h"

struct CSpeed
{
	enum OrientationType
	{
		EOT_VerticalUp,
		EOT_VerticalDown
	};

	float m_fSpeed = 1.0;


};


//////////////////////////////
class CMainWnd : public QWidget
{
	Q_OBJECT
public:
	CMainWnd(QWidget* p = nullptr);
	~CMainWnd();

	void Init();
	void InitCtronol();
	void InitTimer();
	void InitSignalSlot();

public slots:
	void slotTimer();
	void slotShapeChaned(const QString& text);
	void slotRadiusChange(const QString& text);

private:

	// control
	QLabel* m_pLabelShape = nullptr;
	QComboBox* m_pComboxShape = nullptr;
	QPushButton* m_pBtnSave = nullptr;

	QLabel* m_pLabelRadius = nullptr;
	QLineEdit* m_pEditRadius = nullptr;
	QPushButton* m_pBtnLoad = nullptr;

	QGridLayout* m_pGridLayout = nullptr;

	GraphicsView* m_pGraphicsView = nullptr;

	QVBoxLayout* m_pVLayout = nullptr;

private:
	// data
	QTimer* m_pTimer = nullptr;
};