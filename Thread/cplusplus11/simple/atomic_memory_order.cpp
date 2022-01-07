
#include <atomic>
#include <thread>
#include <iostream>
using namespace std;

#if 1
atomic<int> a{0};
atomic<int> b{0};
#else
int a = 0;
int b = 0;

#endif


int ValueSet(int)
{
    int t = 1;

#if 0    
    a = t;
    b = 2;
#else
    a.store(t, memory_order_relaxed);
    b.store(2, memory_order_relaxed);
#endif
    
    return 0;
}

int Observer(int)
{
    cout << "(" << a << ", "<< b << ")" << endl;
    return 0;
}

int main()
{

    thread t1(ValueSet, 0);
    thread t2(Observer, 0);

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();

    cout << "Got (" << a << ", "<< b << ")" << endl;        

    return 0;
}