

#include <QObject>
#include <QGraphicsItem>

enum EItemShape
{
	EIS_Circle,
	EIS_Rectangle
};

class CCustomGraphicsItem : public QGraphicsItem
{
public:
	explicit CCustomGraphicsItem(QGraphicsItem* parent = nullptr);

	void Init();

public:
	bool IsDrag();
	void SetShape(EItemShape eShape);
	void SetRadius(int nRadius);

protected:
	QRectF boundingRect() const override;
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
	QColor color;
	EItemShape m_eItemShape = EItemShape::EIS_Circle;
	int m_nRadius = 30;
	bool m_bDrag = false;
};
