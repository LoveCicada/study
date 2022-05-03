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

void printIdx(const std::string& thread_name)
{
    while(true)
    {
        std::this_thread::sleep_for(1000ms);
        ++idx;
        std::unique_lock<std::mutex> lk(cout_mutex);
        std::cout << "thread_name: " << thread_name << " &idx: " << std::addressof(idx) 
              << " idx: " << idx <<'\n';
    }

}

int main(int argc, char** argv)
{
    std::thread a(printIdx, "a");
    std::thread b(printIdx, "b");

    a.join();
    b.join();

    return 0;
}

/**
* @result 
* 
*  thread_name: a &idx: 0x7fc6def136fc idx: 1
*  thread_name: b &idx: 0x7fc6de7126fc idx: 1
*  thread_name: a &idx: 0x7fc6def136fc idx: 2
*  thread_name: b &idx: 0x7fc6de7126fc idx: 2
*  thread_name: a &idx: 0x7fc6def136fc idx: 3
*  thread_name: b &idx: 0x7fc6de7126fc idx: 3
*  thread_name: a &idx: 0x7fc6def136fc idx: 4
*  thread_name: b &idx: 0x7fc6de7126fc idx: 4
*  thread_name: a &idx: 0x7fc6def136fc idx: 5
*  thread_name: b &idx: 0x7fc6de7126fc idx: 5
*  thread_name: a &idx: 0x7fc6def136fc idx: 6
*  thread_name: b &idx: 0x7fc6de7126fc idx: 6
*  thread_name: a &idx: 0x7fc6def136fc idx: 7
*  thread_name: b &idx: 0x7fc6de7126fc idx: 7
*  thread_name: a &idx: 0x7fc6def136fc idx: 8
*  thread_name: b &idx: 0x7fc6de7126fc idx: 8
*  thread_name: a &idx: 0x7fc6def136fc idx: 9
*  thread_name: b &idx: 0x7fc6de7126fc idx: 9
*  thread_name: a &idx: 0x7fc6def136fc idx: 10
*  thread_name: b &idx: 0x7fc6de7126fc idx: 10
*/