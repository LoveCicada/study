
#include <QtWidgets>
#include <QtTest/QtTest>
#include <QDebug>

//! [0]
class TestGui: public QObject
{
    Q_OBJECT
public:
    TestGui(QObject* parent = nullptr);

private slots:
    void testGui_data();
    void testGui();
    void testGui2();
    void testGui3();
};
//! [0]



