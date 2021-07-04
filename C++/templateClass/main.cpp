#include <QCoreApplication>
#include "templateClass.h"

void test()
{
	CVX_Mpc_Test cvx_mpc_test("test");
	std::cout << "class name : " << cvx_mpc_test.ClassName() << std::endl;
	
	CVX_Mpc_Test cvx_mpc_hello("hello");
	std::cout << "class name : " << cvx_mpc_hello.ClassName() << std::endl;

	MPC_CLASS(Test) _test(__func__);

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	test();

    return a.exec();
}
