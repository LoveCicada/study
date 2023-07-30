
#include <iostream>
#include "ExceptionCollectExport.h"
using namespace std;
using namespace ExceptionCollect;

void test()
{
    std::shared_ptr<IThreadMonitor> pThreadMonitor = CreateThreadMonitor();
    pThreadMonitor->Add();

}

int main(int argc, char* argv[])
{
    test();


    return 0;
}
