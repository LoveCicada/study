#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPalette>
#include <QStyleFactory>
#include <QPainter>
#include <QStyleOptionButton>

class VXCustomWidget;
class VXControlMainWnd;

class VXClientMainWnd : public QWidget
{
    Q_OBJECT

public:
    VXClientMainWnd(QWidget *parent = 0);
    ~VXClientMainWnd();

	void initCtrl();

public:
    //! 按原始比例显示，增加滚动条
    void originalScaleLayout();
    //! 自适应窗口显示
    void adaptLayout();

public slots:
    void OnHide();
    void OnShow();
    void OnOriginal();
    void OnAdapt();

protected:
    virtual void paintEvent(QPaintEvent* e) override;
    virtual void mouseMoveEvent(QMouseEvent* e) override;
    virtual void changeEvent(QEvent* e) override;

private:
    QVBoxLayout* m_pVB = nullptr;
    VXCustomWidget* m_pTitleBar = nullptr;
    VXCustomWidget* m_pTitleBarDup = nullptr;
    
    VXControlMainWnd* m_pControlMainWnd = nullptr;
    QWidget* m_pControlWnd = nullptr;

    QScrollArea* m_pControlWndScroll = nullptr;
    QHBoxLayout* m_pControlWndLayout = nullptr;

};

#endif // WIDGET_H
