
#include <QtWidgets>
#include <QtTest/QtTest>

//! [0]
class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void testGui_data();
    void testGui();
};
//! [0]

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

//! [3]
QTEST_MAIN(TestGui)
#include "testgui.moc"
//! [3]

