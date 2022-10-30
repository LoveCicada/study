#include "widget.h"
#include <QApplication>
#include "VXApplication.h"

int main(int argc, char *argv[])
{
    VXApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
