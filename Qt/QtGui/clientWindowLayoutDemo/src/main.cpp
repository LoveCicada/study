#include "VXClientMainWnd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VXClientMainWnd w;
    w.show();

    return a.exec();
}
