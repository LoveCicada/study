/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include <functional>
#include <semaphore.h>

// @lc code=start
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
// @lc code=end

