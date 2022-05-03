#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

/**
 * @brief thread_local声明的对象的存储在每个线程开始时分配，在线程结束是销毁。
 * 每一个thread_local变量在每个线程有一份独立实体，各个线程的变量互不干扰。
 * @see https://zh.cppreference.com/w/cpp/language/storage_duration
 */

thread_local int idx = 0;
std::mutex cout_mutex;
std::mutex cout_mutex2;

class A
{
public:
    A()
    {
        std::unique_lock<std::mutex> lock(cout_mutex);
        cout << "A construct ..." << " this: " << std::addressof(*this) << endl;
    }

    ~A()
    { 
        std::unique_lock<std::mutex> lock(cout_mutex);
        cout << "... A delete" << " this: " << std::addressof(*this) << endl;
    }

    int m_counter = 0;
    int get_value()
    {
        return m_counter++;
    }
};

void thread_fun(const std::string& thread_name)
{
    for(int i = 0; i < 3; ++i)
    {
        thread_local A a;
        std::unique_lock<std::mutex> lock(cout_mutex);
        cout << "thread[" << thread_name << "]: a.m_counter = " 
            << a.get_value() << " &a: " << std::addressof(a) << '\n';
    }
}

void thread_fun2(const std::string& thread_name)
{
    for(int i = 0; i < 3; ++i)
    {
        A a2;
        std::unique_lock<std::mutex> lk(cout_mutex2);
        cout << "thread[" << thread_name << "]: a2.m_counter = " 
            << a2.get_value() << " &a2: " << std::addressof(a2) << '\n';
    }
}

int main(int argc, char** argv)
{
    {
        std::thread a(thread_fun, "a");
        std::thread b(thread_fun, "b");

        a.join();
        b.join();
    }

    cout << "--------------------------------" << endl;

    {
        std::thread a2(thread_fun2, "a2");
        std::thread b2(thread_fun2, "b2");

        a2.join();
        b2.join();
    }

    return 0;
}

/**
* @result 
* 
    A construct ... this: 0x7ff65cf566f4
    thread[a]: a.m_counter = 0 &a: 0x7ff65cf566f4
    thread[a]: a.m_counter = 1 &a: 0x7ff65cf566f4
    thread[a]: a.m_counter = 2 &a: 0x7ff65cf566f4
    ... A delete this: 0x7ff65cf566f4
    A construct ... this: 0x7ff65c7556f4
    thread[b]: a.m_counter = 0 &a: 0x7ff65c7556f4
    thread[b]: a.m_counter = 1 &a: 0x7ff65c7556f4
    thread[b]: a.m_counter = 2 &a: 0x7ff65c7556f4
    ... A delete this: 0x7ff65c7556f4
    --------------------------------
    A construct ... this: 0x7ff65c754d88
    thread[a2]: a2.m_counter = 0 &a2: 0x7ff65c754d88
    ... A delete this: 0x7ff65c754d88
    A construct ... this: 0x7ff65c754d88
    thread[a2]: a2.m_counter = 0 &a2: 0x7ff65c754d88
    ... A delete this: 0x7ff65c754d88
    A construct ... this: 0x7ff65c754d88
    thread[a2]: a2.m_counter = 0 &a2: 0x7ff65c754d88
    ... A delete this: 0x7ff65c754d88
    A construct ... this: 0x7ff65cf55d88
    thread[b2]: a2.m_counter = 0 &a2: 0x7ff65cf55d88
    ... A delete this: 0x7ff65cf55d88
    A construct ... this: 0x7ff65cf55d88
    thread[b2]: a2.m_counter = 0 &a2: 0x7ff65cf55d88
    ... A delete this: 0x7ff65cf55d88
    A construct ... this: 0x7ff65cf55d88
    thread[b2]: a2.m_counter = 0 &a2: 0x7ff65cf55d88
    ... A delete this: 0x7ff65cf55d88
*/