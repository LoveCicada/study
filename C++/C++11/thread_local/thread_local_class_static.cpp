
#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

std::mutex cout_mutex;

class B
{
public:
    B()
    {
        std::unique_lock<std::mutex> lk(cout_mutex);
        cout << "B construct" << " this: " << this << std::endl;
    }

    ~B()
    {
        cout << "B delete" << " this: " << this << std::endl;
    }
    
    //thread_local int m_nValue = 0;
    thread_local static int m_thread_local_static_value;
    static int m_static_value;
    int m_value = 30;
};

thread_local int B::m_thread_local_static_value = 20;
int B::m_static_value = 10;

void thread_fun(const std::string& thread_name)
{
    B b;
    for(int i = 0; i < 3; ++i)
    {
        b.m_value--;
        b.m_thread_local_static_value--;
        b.m_static_value--;
        std::unique_lock<std::mutex> lock(cout_mutex);
        std::cout << "thread[" << thread_name << "]: m_value:" << b.m_value 
            << ", b.m_thread_local_static_value:" << b.m_thread_local_static_value 
            << ", b.m_static_value:" << b.m_static_value << '\n';

        std::cout << "thread[" << thread_name << "]: B::key:" << B::m_thread_local_static_value 
            << ", b_value:" << b.m_value 
            << ", b_static: " << B::m_static_value << '\n';
    }

}

int main()
{
    {
        std::thread t1(thread_fun, "t1");
        std::thread t2(thread_fun, "t2");

        t1.join();
        t2.join();
    }

    return 0;
}

/**
 * @see https://murphypei.github.io/blog/2020/02/thread-local.html
 * @brief 
 * m_thread_local_static_value 是 thread_local，虽然其也是 static 的，
 * 但是每个线程中有一个，每次线程中的所有调用共享这个变量。
 * b_static 是真正的 static，全局只有一个，所有线程共享这个变量。
 */

/**
 * @result 
 * 
    B construct this: 0x7f581a091d88
    thread[t1]: m_value:29, b.m_thread_local_static_value:19, b.m_static_value:9
    thread[t1]: B::key:19, b_value:29, b_static: 9
    thread[t1]: m_value:28, b.m_thread_local_static_value:18, b.m_static_value:8
    thread[t1]: B::key:18, b_value:28, b_static: 8
    thread[t1]: m_value:27, b.m_thread_local_static_value:17, b.m_static_value:7
    thread[t1]: B::key:17, b_value:27, b_static: 7
    B delete this: 0x7f581a091d88
    B construct this: 0x7f5819890d88
    thread[t2]: m_value:29, b.m_thread_local_static_value:19, b.m_static_value:6
    thread[t2]: B::key:19, b_value:29, b_static: 6
    thread[t2]: m_value:28, b.m_thread_local_static_value:18, b.m_static_value:5
    thread[t2]: B::key:18, b_value:28, b_static: 5
    thread[t2]: m_value:27, b.m_thread_local_static_value:17, b.m_static_value:4
    thread[t2]: B::key:17, b_value:27, b_static: 4
    B delete this: 0x7f5819890d88
 */