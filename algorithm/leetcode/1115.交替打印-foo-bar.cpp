/*
 * @lc app=leetcode.cn id=1115 lang=cpp
 *
 * [1115] 交替打印 FooBar
 */

// @lc code=start
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
// @lc code=end

