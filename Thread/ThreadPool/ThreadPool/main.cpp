
#include "ThreadPool.h"
#include <iostream>
#include <future>
using namespace std;
using namespace tp;

int main(int argc, char* argv[])
{
    tp::ThreadPool threadpool;
    auto f = threadpool.Submit([]()
    {
        cout << "Submit task test" << endl;
        return 0x0911;
    });

    threadpool.Submit([ff = f.share()]()
    {
        cout << ff.get() << endl;
    });

    return 0;
}