

#include <QGraphicsView>
#include <QGraphicsScene>
#include "CustomGraphicsItem.h"

class GraphicsView : public QGraphicsView
{
public:
	using QGraphicsView::QGraphicsView;

	explicit GraphicsView(QWidget* parent = nullptr);

	void Init();
	void InitControl();
	void InitProperty();
	void InitSignalSlot();

	void UpateItemPosition();

	void SetShape(EItemShape eShape);
	void SetRadius(int nRadius);

protected:
	
private:
	QGraphicsScene* m_pGraphicsScene = nullptr;
	CCustomGraphicsItem* m_pGraphicsItemSquare = nullptr;
};
