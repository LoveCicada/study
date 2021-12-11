#pragma once


#include <QTableView>


class CXETableView : public QTableView
{
    Q_OBJECT
public:
    CXETableView(QWidget* parent = NULL);
    virtual ~CXETableView();

    void initData();

public:


protected:
	virtual void paintEvent(QPaintEvent* event);

};
