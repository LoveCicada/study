
#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <type_traits>

using std::cout;
using std::endl;
using std::mutex;
using std::thread;
using std::unique_lock;
using std::lock_guard;
using std::bind;
using std::function;
using std::ref;

#define BIND 1

mutex g_mtxA;
mutex g_mtxB;
int g_idx = 0;

typedef function<void(mutex&, mutex&)> fm;


void fun(mutex& _l, mutex& _r) {

    std::lock(_l, _r);

    lock_guard<mutex> lkl(_l, std::adopt_lock);
    cout << "get the first mutex" << " in thread " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    lock_guard<mutex> lkr(_r, std::adopt_lock);
    cout << "get the second mutex" << " in thread " << std::this_thread::get_id() << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    cout << "tid: " << std::this_thread::get_id()
        << " g_idx: " << ++g_idx << endl;

}


int main(int argc, char* argv[]) {

    thread t1([&]() {fun(g_mtxA, g_mtxB); });
    thread t2([&]() {fun(g_mtxB, g_mtxA); });

#if BIND
    auto fmb = bind(fun, ref(g_mtxA), ref(g_mtxB));
    
    /*thread t3(bind(fun, ref(g_mtxA), ref(g_mtxB)));
    thread t4(bind(fun, ref(g_mtxB), ref(g_mtxA)));*/

    thread t3(fmb);
    thread t4(fmb);

#endif

    t1.join();
    t2.join();

#if BIND
    t3.join();
    t4.join();
#endif   

    return 0;
}

/**
 * @result
 *  get the first mutex in thread 139868588582656
    get the second mutex in thread 139868588582656
    tid: 139868588582656 g_idx: 1
    get the first mutex in thread 139868580189952
    get the second mutex in thread 139868580189952
    tid: 139868580189952 g_idx: 2
    get the first mutex in thread 139868596975360
    get the second mutex in thread 139868596975360
    tid: 139868596975360 g_idx: 3
    get the first mutex in thread 139868571797248
    get the second mutex in thread 139868571797248
    tid: 139868571797248 g_idx: 4
 */