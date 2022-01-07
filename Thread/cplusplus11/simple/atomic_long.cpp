#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

#define MAX_VALUE 1000LL

//原子数据类型
atomic_llong g_total{0};

void fun(int)
{
    for(long long i = 0; i<MAX_VALUE; ++i)
    {
        g_total += i;
        cout << "current: "<< "threadId: " << std::this_thread::get_id() <<" g_total = " << g_total << endl;
    }
}

int main()
{
    thread t1(fun, 0);
    thread t2(fun, 0);

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();
    cout << "g_total = " << g_total << endl;        

    return 0;
}