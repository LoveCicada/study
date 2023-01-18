#include "VXClientMainWnd.h"
#include <QApplication>
#include <QDebug>

//! InRD.exe -ip 192.168.62.128 -port 6789
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //! 
    VXClientMainWnd w;
    w.updateAppName();
    w.setWindowTitle("new app name");
    w.show();
    return a.exec();
}
