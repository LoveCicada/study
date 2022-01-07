#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <future>
#include <queue>
#include <vector>
#include <type_traits>
#include <utility>

//C++11 version threadpool
namespace tp
{
    class ThreadsGuard
    {
    public:
        ThreadsGuard(std::vector<std::thread>& v)
            : m_Threads(v)
        {

        }

        ~ThreadsGuard()
        {
            for(auto& td : m_Threads)
            {
                if(td.joinable()){
                    td.join();
                }
            }
        }
    private:
        ThreadsGuard(ThreadsGuard&&) = delete;
        ThreadsGuard& operator = (ThreadsGuard&&) = delete;
        ThreadsGuard(const ThreadsGuard&) = delete;
        ThreadsGuard& operator = (ThreadsGuard&) = delete;
    private:
        std::vector<std::thread>& m_Threads;  
    };

    class ThreadPool
    {
    public:
        typedef std::function<void()> task_type;

    public:
        explicit ThreadPool(int n = 0);

        ~ThreadPool()
        {
            Stop();
            m_cv.notify_all();
        }

        void Stop()
        {
            m_bStop.store(true, std::memory_order_release);
        }

        template<class Function, class... Args>
        std::future<typename std::result_of<Function(Args...)>::type> add(Function&&, Args&&...);

    private:
        std::atomic<bool> m_bStop;
        std::mutex m_mtx;
        std::condition_variable m_cv;

        std::queue<task_type> m_qTasks;
        std::vector<std::thread> m_threads;
        tp::ThreadsGuard m_tg;
    };

    inline ThreadPool::ThreadPool(int n)
        : m_bStop(false), m_tg(m_threads)
    {
        int nThreadNums = n;
        if(nThreadNums <= 0)
        {
            nThreadNums = std::thread::hardware_concurrency();
            std::cout << "hardware_concurrency: "<< nThreadNums << std::endl;
            nThreadNums = (nThreadNums == 0 ? 2 : nThreadNums);
        }

        /*
        * std::memory_order_acquire 本线程中，所有后续的读操作必须在本条原子操作完成后执行
        */

        for(int i = 0; i<nThreadNums; ++i)
        {
            m_threads.push_back(std::thread([this]{
                while (!m_bStop.load(std::memory_order_acquire))
                {
                    task_type task;
                    {
                        std::unique_lock<std::mutex> lk(this->m_mtx);
                        /*
                        * true: stop = true, or tasks is not empty
                        * false: stop = false, or tasks is empty
                        */
                        this->m_cv.wait(lk,[this]{
                            return m_bStop.load(std::memory_order_acquire) || !this->m_qTasks.empty();
                        });

                        /*
                        * when stop is true, we must stop, otherwise we can continue do task
                        */
                        if(m_bStop.load(std::memory_order_acquire)){
                            return;
                        }
                        task = std::move(this->m_qTasks.front());
                        this->m_qTasks.pop();
                        std::cout << "begin do task \n";
                    }
                    task();
                     
                }
            }));
        }
    }

    template<class Function, class... Args>
    std::future< typename std::result_of<Function(Args...) >::type>
        ThreadPool::add(Function&& fcn, Args&&... args)
    {
        typedef typename std::result_of<Function(Args...)>::type return_type;
        typedef std::packaged_task<return_type()> task;

        auto t = std::make_shared<task>(std::bind(std::forward<Function>(fcn), std::forward<Args>(args)...));
        auto ret = t->get_future();
        {
            std::unique_lock<std::mutex> lk(m_mtx);
            if(m_bStop.load(std::memory_order_acquire)){
                throw std::runtime_error("thread pool has stopped");
            }
            m_qTasks.emplace( [t]{ (*t)(); } );
        }
        m_cv.notify_one();
        return ret;
    }

}
