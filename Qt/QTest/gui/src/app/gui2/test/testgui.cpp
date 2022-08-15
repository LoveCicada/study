
#include "testgui.h"


TestGui::TestGui(QObject* parent)
    :QObject(parent)
{

}

//! [1]
void TestGui::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";

    QTestEventList list3;
    list3.addMouseDClick(Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    QTest::newRow("addMouseDClick") << list3 << "";
}
//! [1]

//! [2]
void TestGui::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;
    events.simulate(&lineEdit);
    QCOMPARE(lineEdit.text(), expected);
}
//! [2]

void TestGui::testGui2()
{
    qDebug() << __FUNCTION__;
    QWidget q;
    QTest::mouseClick(&q, Qt::LeftButton);
}

void TestGui::testGui3()
{
    qDebug() << __FUNCTION__;
    QWidget q;
    QTest::keyClick(&q, 'A');
}
