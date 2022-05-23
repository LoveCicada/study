

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
#include <semaphore.h>
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
    sem_t m_firstSem;
    sem_t m_secondSem;
public:
    Foo() {
        sem_init(&m_firstSem, 0, 0);
        sem_init(&m_secondSem, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&m_firstSem);
    }

    void second(function<void()> printSecond) {
        sem_wait(&m_firstSem);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&m_secondSem);
    }

    void third(function<void()> printThird) {
        sem_wait(&m_secondSem);
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