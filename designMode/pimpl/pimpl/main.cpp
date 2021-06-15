#include <QCoreApplication>
#include "a.h"

void test()
{
	A a;
	a.doSomething();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	test();

    return a.exec();
}
