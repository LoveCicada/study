
/**
 * @file alternatePrint.cpp
 * @author your name (you@domain.com)
 * @brief 交替打印
 * @version 0.1
 * @date 2022-05-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

void printFoo()
{
    cout << "Foo ----->" << '\n';
}

void printBar()
{
    cout << "Bar <-----" << '\n';
}

class FooBar {
private:
    int n;
    mutex m_mtx;
    condition_variable m_cv;
    bool m_bFoo;
public:
    FooBar(int n) {
        this->n = n;
        m_bFoo = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m_mtx);
            m_cv.wait(lk, [this](){ return m_bFoo == true; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            m_bFoo = false;
            m_cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(m_mtx);
            m_cv.wait(lk, [this](){return m_bFoo == false;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            m_bFoo = true;
            m_cv.notify_one();
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 10;
    if(argc >= 2)
    {
        n = atoi(argv[1]);
    }
    FooBar fb(n);
    thread t1(&FooBar::foo, &fb, printFoo);
    thread t2(&FooBar::bar, &fb, printBar);

    t1.join();
    t2.join();

    return 0;
}