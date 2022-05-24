

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

#include <iostream>
#include <functional>
#include <thread>

#include <semaphore>
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

protected:
    std::counting_semaphore m_firstSem(0);
    std::counting_semaphore m_secondSem(0);
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_firstSem.acquire();
    }

    void second(function<void()> printSecond) {
        m_firstSem.release();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_secondSem.acquire();
    }

    void third(function<void()> printThird) {
        m_secondSem.release();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};


int main(int argc, char* argv[]) {

    Foo fo;
    thread t1(&Foo::first, std::ref(fo), printFirst);
    thread t2(&Foo::second, std::ref(fo), printSecond);
    thread t3(&Foo::third, std::ref(fo), printThird);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}