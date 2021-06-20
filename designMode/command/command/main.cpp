#include <QCoreApplication>
#include "command.h"

void test()
{
	ConcreteCommand1 cd1("Arg ###");
	ConcreteCommand2 cd2("Arg $$$");

	MacroCommand md;
	md.addCommand(&cd1);
	md.addCommand(&cd2);

	md.execute();

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	test();

    return a.exec();
}
