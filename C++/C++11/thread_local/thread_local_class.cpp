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
        cout << "A construct ..." << endl;
    }

    ~A()
    { 
        std::unique_lock<std::mutex> lock(cout_mutex);
        cout << "... A delete" << endl;
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
        thread_local A* pa = new A();
        std::unique_lock<std::mutex> lock(cout_mutex);
        cout << "thread[" << thread_name << "]: pa.m_counter = " 
            << pa->get_value() << " &pa: " << std::addressof(pa) 
            << " pa: " << pa << '\n';
    }
}

void thread_fun2(const std::string& thread_name)
{
    for(int i = 0; i < 3; ++i)
    {
        A* pa2 = new A();
        std::unique_lock<std::mutex> lk(cout_mutex2);
        cout << "thread[" << thread_name << "]: pa2.m_counter = " 
            << pa2->get_value() << " &pa2: " << std::addressof(pa2) 
            << " pa2: " << pa2 << '\n';
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
*   A construct ...
*   thread[a]: pa.m_counter = 0 &pa: 0x7f58ed7046f0 pa: 0x7f58e8000b60
*   thread[a]: pa.m_counter = 1 &pa: 0x7f58ed7046f0 pa: 0x7f58e8000b60
*   thread[a]: pa.m_counter = 2 &pa: 0x7f58ed7046f0 pa: 0x7f58e8000b60
*   A construct ...
*   thread[b]: pa.m_counter = 0 &pa: 0x7f58ecf036f0 pa: 0x7f58e0000b60
*   thread[b]: pa.m_counter = 1 &pa: 0x7f58ecf036f0 pa: 0x7f58e0000b60
*   thread[b]: pa.m_counter = 2 &pa: 0x7f58ecf036f0 pa: 0x7f58e0000b60
*   --------------------------------
*   A construct ...
*   thread[a2]: pa2.m_counter = 0 &pa2: 0x7f58ecf02d48 pa2: 0x7f58e0000b80
*   A construct ...
*   thread[a2]: pa2.m_counter = 0 &pa2: 0x7f58ecf02d48 pa2: 0x7f58e0000ba0
*   A construct ...
*   thread[b2]: pa2.m_counter = 0 &pa2: 0x7f58ed703d48 pa2: 0x7f58e8000f90
*   A construct ...
*   thread[a2]: pa2.m_counter = 0 &pa2: 0x7f58ecf02d48 pa2: 0x7f58e0000bc0
*   A construct ...
*   thread[b2]: pa2.m_counter = 0 &pa2: 0x7f58ed703d48 pa2: 0x7f58e8000fb0
*   A construct ...
*   thread[b2]: pa2.m_counter = 0 &pa2: 0x7f58ed703d48 pa2: 0x7f58e8000fd0
*/