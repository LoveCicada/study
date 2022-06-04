
#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::unique_lock;

mutex g_mtxA;
mutex g_mtxB;
int g_idx = 0;

void fun(mutex& _l, mutex& _r) {

    unique_lock<mutex> lkl(_l, std::defer_lock);
    cout << "get the first mutex" << " in thread " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    unique_lock<mutex> lkr(_r, std::defer_lock);
    cout << "get the second mutex" << " in thread " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::lock(lkl, lkr);
    cout << "tid: " << std::this_thread::get_id() 
        << " g_idx: " << ++g_idx << endl;

}

int main(int argc, char * argv[]) {

    thread t1([&](){fun(g_mtxA, g_mtxB);});
    thread t2([&](){fun(g_mtxB, g_mtxA);});

    t1.join();
    t2.join();

    return 0;
}

/**
 * @result
 *  get the first mutexget the first mutex in thread 140531915323136
    in thread 140531923715840
    get the second mutex in thread 140531923715840
    get the second mutex in thread 140531915323136
    tid: 140531923715840 g_idx: 1
    tid: 140531915323136 g_idx: 2
 */