#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
using namespace std;

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int n)
{
    //尝试获得锁
    while (lock.test_and_set(std::memory_order_acquire))
    {
        //自旋
        cout << "Waiting from thread " << n << endl;
    }
    cout << "Thread " << n << " starts working " << endl;
}

void g(int n)
{
    cout << "Thread " << n << " is going to start." << endl;
    lock.clear();
    cout << "Thread " << n << " starts working" << endl;
}

int main()
{
    lock.test_and_set();
    thread t1(f, 1);
    usleep(100);
    thread t2(g, 2);

    if(t1.joinable())
        t1.join();

    usleep(100);
    if(t2.joinable())
        t2.join();


    return 0;
}