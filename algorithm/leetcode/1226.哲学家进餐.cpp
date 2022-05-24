/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */

// @lc code=start
class DiningPhilosophers {
private:
    mutex m_mtx[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		int left = (philosopher % 5);
        int right = (philosopher + 1) % 5;
        if(philosopher % 2) {
            swap(left, right);
        }

        unique_lock<mutex> left_lk(m_mtx[left]);
        unique_lock<mutex> right_lk(m_mtx[right]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};
// @lc code=end

