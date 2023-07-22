

#include <QApplication>
#include "MainWnd.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    CMainWnd cltWnd;
    cltWnd.show();

    return a.exec();
}
