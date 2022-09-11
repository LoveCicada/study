
#pragma once

#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <future>
#include <memory>
#include <atomic>
#include <algorithm>

//! THREAD POOL
namespace tp
{
    using std::atomic;
    using std::future;
    using std::thread;
    using std::mutex;
    using std::unique;
    using std::vector;
    using std::queue;
    using std::unique_ptr;
    using std::unique_lock;
    using std::packaged_task;
    /**
     * @brief safe release thread
     *
     */
    class ThreadGuard
    {
    public:
        explicit ThreadGuard(vector<thread>& _threads)
            : m_threads(_threads)
        {
        }

        ~ThreadGuard()
        {
            for (auto &&th : m_threads)
            {
                if (th.joinable())
                {
                    th.join();
                }
            }
        }

    private:
        vector<thread>& m_threads;
    };

    /**
     * @brief
     *
     */
    class FunctionWrapper
    {
        class PrivateBase
        {
        public:
            virtual ~PrivateBase() {}

            virtual void Call() = 0;
        };

        template <typename F>
        class PrivateImpl : public PrivateBase
        {
        public:
            explicit PrivateImpl(F &&_f) : f(std::move(_f))
            {
            }

            void Call() override
            {
                f();
            }

        public:
            F f;
        };

        /**
         * @brief
         *
         */

    public:
        template <typename F>
        FunctionWrapper(F &&_f)
            : m_impl(new PrivateImpl<F>(std::forward<F>(_f)))
        {
        }

        FunctionWrapper(FunctionWrapper &&_wrapper) noexcept
            : m_impl(std::move(_wrapper.m_impl))
        {
        }

        FunctionWrapper &operator=(FunctionWrapper &&_wrapper) noexcept
        {
            m_impl = std::move(_wrapper.m_impl);
            return *this;
        }

        void operator()()
        {
            m_impl->Call();
        }

        FunctionWrapper() = default;
        FunctionWrapper(const FunctionWrapper &) = delete;
        FunctionWrapper &operator=(FunctionWrapper &) = delete;

    private:
        unique_ptr<PrivateBase> m_impl;
    };

    /**
     * @brief
     *
     */
    class ThreadPool
    {
    public:
        explicit ThreadPool(uint8_t _threadNum = std::thread::hardware_concurrency())
            : m_bFinished(false), m_threadGuard(m_threads)
        {
            try
            {
                for (int _n = 0; _n < _threadNum; _n++)
                {
                    m_threads.emplace_back(thread(&ThreadPool::worker_thread, this));
                }
            }
            catch (...)
            {
                m_bFinished = true;
                throw std::runtime_error("add thread error");
            }
        }

        ~ThreadPool()
        {
            m_bFinished = true;
        }

        template <typename FuncType>
        future<typename std::result_of<FuncType()>::type> Submit(FuncType _f)
        {
            using resultType = typename std::result_of<FuncType()>::type;
            packaged_task<resultType()> task(std::move(_f));
            future<resultType> res(task.get_future());
            m_queue.push(std::move(task));
            return res;
        }

    private:
        void worker_thread()
        {
            while (!m_bFinished)
            {
                unique_lock<mutex> lk(m_mtx);
                if (!m_queue.empty())
                {
                    auto&& t = m_queue.front();
                    t();
                    m_queue.pop();
                }
                else
                {
                    std::this_thread::yield();
                }
            }
        }

    private:
        atomic<bool> m_bFinished;
        queue<FunctionWrapper> m_queue;
        vector<thread> m_threads;
        ThreadGuard m_threadGuard;
        mutex m_mtx;
    };

}
