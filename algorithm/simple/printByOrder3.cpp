

/**
 * @file printByOrder.cpp
 * @author your name (you@domain.com)
 * @brief 按序打印
 * @version 0.1
 * @date 2022-05-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*

（1）void wait(std::unique_lock<std::mutex>& lock)
先unlock之前获得的mutex，然后阻塞当前的执行线程。
把当前线程添加到等待线程列表中，该线程会持续 block 直到被 notify_all() 或 notify_one() 唤醒。
被唤醒后，该thread会重新获取mutex，获取到mutex后执行后面的动作。
线程block时候也可能被意外或者错误唤醒。

（2）template< class Predicate > void wait( std::unique_lock<std::mutex>& lock, Predicate pred );
该重载设置了第二个参数 Predicate， 只有当pred为false时，wait才会阻塞当前线程。盖崇仔等同于下面：
该情况下，线程被唤醒后，先重新判断pred的值。如果pred为false，则会释放mutex并重新阻塞在wait。
因此，该mutex必须有pred的权限。该重载消除了意外唤醒的影响。
*/


#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;

void printFirst()
{
    std::cout << "first" << '\n';
}

void printSecond()
{
    std::cout << "second" << '\n';
}

void printThird()
{
    std::cout << "third" << '\n';
}

class Foo {
private:
    bool m_bSecond;
    bool m_bThird;
    mutex m_mtx;
    condition_variable m_cv;
public:
    Foo() {
        m_bSecond = false;
        m_bThird = false;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(m_mtx);
        // printFirst() outputs "first". Do not change or remove this line.
    
        printFirst();
        m_bSecond = true;
        m_cv.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(m_mtx);
        m_cv.wait(lk, [this](){return m_bSecond;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_bThird = true;
        m_cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(m_mtx);
        m_cv.wait(lk, [this](){return m_bThird;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m_cv.notify_one();
    }
};


int main(int argc, char* argv[]) {

    Foo fo;

#if 0
    thread t1(&Foo::first, std::ref(fo), printFirst);
    thread t2(&Foo::second, std::ref(fo), printSecond);
    thread t3(&Foo::third, std::ref(fo), printThird);

#else

    thread t1(&Foo::first, (&fo), printFirst);
    thread t2(&Foo::second, (&fo), printSecond);
    thread t3(&Foo::third, (&fo), printThird);

#endif // 0

    t1.join();
    t2.join();
    t3.join();

    return 0;
}