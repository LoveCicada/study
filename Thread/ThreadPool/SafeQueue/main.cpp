
#include <iostream>
#include <thread>
using namespace std;
using std::thread;

#define v1 1
#ifdef v1
#include "./v1/safe_queue_v1.h"
using namespace util;
#endif


template<typename T>
void Producer(util::SafeQueue<T>& _t, T& _v)
{
    cout << __func__ << " id: " << std::this_thread::get_id() << endl;
    _t.Push(_v);
    cout << _v << endl;
}

template<typename T>
void Consumer(util::SafeQueue<T>& _t, T& _v)
{
    cout << __func__ << " id: " << std::this_thread::get_id() << endl;
    _t.Pop(_v);
    _t.Push(_v);
}

int main(int argc, char* argv[])
{

    util::SafeQueue<int> q;
    int n = 1;
    thread t1(Producer<int>, std::ref(q), n);
    thread t2(Consumer<int>, std::ref(q), n);



    return 0;
}