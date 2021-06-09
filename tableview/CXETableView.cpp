#include <QPainter>
#include <QVariant>
#include "CXETableView.h"


#define TEXT_OFFSET "    "

CXETableView::CXETableView(QWidget* parent)
    : QTableView(parent)
{
    initData();
}

CXETableView::~CXETableView()
{

}

void CXETableView::initData()
{
    setStyleSheet(
        "QTableWidget {"
        "background-color: rgb(27,27,27);"
        "}"
        "QTableWidget::item {"
        //"background-color: rgb(46,46,46);"
        "font:20pt;"
        "color: rgb(255,255,255);"
        "}"
        "QHeaderView::section {"
        "background-color: rgb(80,80,80);"
        "color: rgb(255,255,255);"
        "}"
        "QTableView::item:selected{color:rgb(13,108,150);background:rgb(51,51,51);}"
    );


}

void CXETableView::paintEvent(QPaintEvent* event)
{
	QTableView::paintEvent(event);
}
