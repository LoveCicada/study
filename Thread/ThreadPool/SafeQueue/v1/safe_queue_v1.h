
#pragma once

#include <queue>
#include <mutex>
#include <memory>
#include <condition_variable>

namespace util
{
    using std::mutex;
    using std::queue;
    using std::unique_lock;
    using std::condition_variable;

    template <typename T>
    class SafeQueue
    {
    public:
        SafeQueue() = default;
        ~SafeQueue()
        {
            Clear();
        }

        void Push(const T &_v)
        {
            unique_lock<mutex> lk(m_mtx);
            m_q.push(_v);
            m_cv.notify_one();
        }

        void Pop(T &_v)
        {
            unique_lock<mutex> lk(m_mtx);
            m_cv.wait(lk, [this]()
                      { return !m_q.empty(); });
            _v = std::move(m_q.front());
            m_q.pop();
        }

        void Clear()
        {
            if (!m_q.empty())
            {
                queue<T> _q;
                m_q.swap(_q);
            }
        }

    private:
        queue<T> m_q;
        mutex m_mtx;
        condition_variable m_cv;
    };

}
