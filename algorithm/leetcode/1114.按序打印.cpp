/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include <functional>
#include <semaphore.h>
#include <mutex>
#include <condition_variable>
using namespace std;
// @lc code=start
class Foo {
private:
    bool m_bSecond;
    bool m_bThird;
    std::mutex m_mtx;
    std::condition_variable m_cv;
public:
    Foo() {
        m_bSecond = false;
        m_bThird = false;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(m_mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_bSecond = true;
        m_cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m_mtx);
        m_cv.wait(lk, [this](){return m_bSecond;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_bThird = true;
        m_cv.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m_mtx);
        m_cv.wait(lk, [this](){return m_bThird;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m_cv.notify_one();
    }
};
// @lc code=end

