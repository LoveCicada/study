#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QPalette>
#include <QStyleFactory>
#include <QPainter>
#include "SubTask.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

	void initCtrl();
    void initData();
    void initSignalSlot();
public slots:
    void startBtnSlots();
    void stopBtnSlots();

private:
    //! ui
    QGridLayout* m_pGridLayout;
    QLabel* m_pLabelName;
    QLabel* m_pLabelParams;
    QLineEdit* m_pEditName;
    QLineEdit* m_pEditParams;

    QPushButton* m_pBtnStart;
    QPushButton* m_pBtnStop;

    //! data
    SubTask* m_pTask;
};

#endif // WIDGET_H
