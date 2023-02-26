#pragma once

#include <QObject>
#include <QRubberBand>

class QWidget;
class FramelessHelperPrivate;

class VXFramelessHelper : public QObject
{
    Q_OBJECT
public:
    explicit VXFramelessHelper(QObject *parent = 0);
    ~VXFramelessHelper();
        // �����
    void activateOn(QWidget *topLevelWidget);
    // �Ƴ�����
    void removeFrom(QWidget *topLevelWidget);
    // ���ô����ƶ�
    void setWidgetMovable(bool movable);
    // ���ô�������
    void setWidgetResizable(bool resizable);
    //���ô���˫��
    void setWidgetDbClickable(bool dbclickable);
    // ������Ƥ���ƶ�
    void setRubberBandOnMove(bool movable);
    // ������Ƥ������
    void setRubberBandOnResize(bool resizable);
    // ���ñ߿�Ŀ��
    void setBorderWidth(uint width);
    // ���ñ������߶�
    void setTitleHeight(uint height);
    bool widgetResizable();
    bool widgetMovable();
    bool rubberBandOnMove();
    bool rubberBandOnResisze();
    uint borderWidth();
    uint titleHeight();

protected:
    // �¼����ˣ������ƶ������ŵ�
    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    FramelessHelperPrivate *d;
};

/*****
 * FramelessHelperPrivate
 * �洢�����Ӧ�����ݼ��ϣ��Լ��Ƿ���ƶ�������������
*****/
class WidgetData;
class FramelessHelperPrivate
{
public:
    QHash<QWidget*, WidgetData*> m_widgetDataHash;
    bool m_bWidgetMovable        : true;
    bool m_bWidgetResizable      : true;
    bool m_bRubberBandOnResize   : true;
    bool m_bRubberBandOnMove     : true;
    bool m_bWidgetDbClickable    : true;
};

/*****
 * CursorPosCalculator
 * ��������Ƿ�λ�����ϡ��ҡ��¡����Ͻǡ����½ǡ����Ͻǡ����½�
*****/

class CursorPosCalculator
{
public:
    explicit CursorPosCalculator();
    void reset();
    void recalculate(const QPoint &globalMousePos, const QRect &frameRect);

public:
    bool m_bOnEdges              : true;
    bool m_bOnLeftEdge           : true;
    bool m_bOnRightEdge          : true;
    bool m_bOnTopEdge            : true;
    bool m_bOnBottomEdge         : true;
    bool m_bOnTopLeftEdge        : true;
    bool m_bOnBottomLeftEdge     : true;
    bool m_bOnTopRightEdge       : true;
    bool m_bOnBottomRightEdge    : true;

    static int m_nBorderWidth;
    static int m_nTitleHeight;
};

/*****
 * WidgetData
 * ���������ʽ���ƶ����塢���Ŵ���
*****/
class WidgetData
{
public:
    explicit WidgetData(FramelessHelperPrivate *d, QWidget *pTopLevelWidget);
    ~WidgetData();
    QWidget* widget();
    // ��������¼�-���������¡��ͷš��ƶ�
    void handleWidgetEvent(QEvent *event);
    // ������Ƥ��״̬
    void updateRubberBandStatus();

private:
    // ���������ʽ
    void updateCursorShape(const QPoint &gMousePos);
    // ���ô����С
    void resizeWidget(const QPoint &gMousePos);
    // �ƶ�����
    void moveWidget(const QPoint &gMousePos);
    // ������갴��
    void handleMousePressEvent(QMouseEvent *event);
    // ��������ͷ�
    void handleMouseReleaseEvent(QMouseEvent *event);
    // ��������ƶ�
    void handleMouseMoveEvent(QMouseEvent *event);
    // ��������뿪
    void handleLeaveEvent(QEvent *event);
    // ����������
    void handleHoverMoveEvent(QHoverEvent *event);
    // �������˫��
    void handleMouseDbClickEvent(QMouseEvent *event);

private:
    FramelessHelperPrivate *d;
    QRubberBand *m_pRubberBand;
    QWidget *m_pWidget;
    QPoint m_ptDragPos;
    CursorPosCalculator m_pressedMousePos;
    CursorPosCalculator m_moveMousePos;
    bool m_bLeftButtonPressed;
    bool m_bCursorShapeChanged;
    bool m_bLeftButtonTitlePressed;
    bool m_bLeftButtonDbClicked;
    Qt::WindowFlags m_windowFlags;
};
