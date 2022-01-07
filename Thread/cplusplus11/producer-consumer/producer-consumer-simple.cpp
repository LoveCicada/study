#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <atomic>
#include <condition_variable>
using namespace std;
using namespace std::chrono;

int gIndex = 0;

/**
 * @brief 
 * 
 * @tparam T 
 */

template<typename T>
class BlockQueue
{
public:

    BlockQueue()
    {
        m_bStop.store(true);
    }

    void push(T* data)
    {
        std::unique_lock<std::mutex> lk(m_mtx);
        m_queue.push(data);
        m_cv.notify_one();
    }

    T* pop()
    {
        std::unique_lock<std::mutex> lk(m_mtx);
        while (m_queue.empty())
        {
            /*
			wait：当前线程调用cond.wait(lock)后将被阻塞，直到某个线程调用notify_*唤醒当前线程；
				当线程被阻塞时，该函数会自动(调用lock对象)释放锁，使得其它被阻塞在锁竞争上的线程得以继续执行。
				一旦当前线程获得通知(notify，通常是另外某个线程调用notify_*唤醒了当前线程)，wait()函数也是自动加锁(调用lock对象)。
			*/
            m_cv.wait(lk);
        }
        T* data = m_queue.front();
        m_queue.pop();
        m_cv.notify_one();
        return data;
    }

    int getQueueSize()
    {
        std::unique_lock<std::mutex> lk(m_mtx);
        return m_queue.size();
    }

    void setStop()
    {
        m_bStop.store(true);
    }

    bool isStop()
    {
        return m_bStop.load();
    }

private:
    std::queue<T*> m_queue;
    std::condition_variable m_cv;
    std::mutex m_mtx;
    std::atomic<bool> m_bStop;
};

template<typename T>
void producer(BlockQueue<T> *q, int index)
{
    cout << "producer index: " << index << "\n";
    for(int i = 0; i<10; i++)
    {
        T* d = new T(gIndex++);
        q->push(d);
        cout << "producer_" << index << "producer: " << *d << "\n";
        //std::this_thread::sleep_for(milliseconds(1)); 
    }
}

template<typename T>
void consumer(BlockQueue<T> *q, int index)
{
    cout << "consumer index: " << index << "\n";
    while(true)
    {
        if(q->isStop() && q->getQueueSize()<=0){
            cout << " it will stop " << "\n";
            break;
        }
        auto d = q->pop();
        cout << "consumer_" << index << " consumer: " << *d << "\n";
        delete d;
        //std::this_thread::sleep_for(microseconds(5));
    }
}

void test()
{
    BlockQueue<int> q;
    std::thread ts[7];
    int i = 0;
    for(; i<5; ++i)
    {
        ts[i] = std::thread(producer<int>, &q, i+1);
    }

    for(; i<7; ++i)
    {
        ts[i] = std::thread(consumer<int>, &q, i+1);
    }

    q.setStop();

    for(auto& th : ts)
    {
        if(th.joinable()){
            th.join();
        }
    }

    cout << "q.getQueueSize() = " << q.getQueueSize() << "\n";
}

int main()
{
    test();

    return 0;
}