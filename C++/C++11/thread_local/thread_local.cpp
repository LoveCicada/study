#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std; 

thread_local unsigned int rage = 1;
unsigned int _rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string& thread_name) 
{
    while (true)
    {
        std::this_thread::sleep_for(500ms);
        ++rage;
        ++_rage;
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << thread_name << " 的愤怒计数 rage: " << rage << " _rage: " << _rage << '\n';
    }
    
}

int main()
{
    std::thread a(increase_rage, "a");
    std::thread b(increase_rage, "b");

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "main 的愤怒计数 rage: " << rage << " _rage: " << _rage << '\n'; 
    }

    a.join();
    b.join();

    return 0;
}

/**
 * @result 
 * 
 * 
 *  main 的愤怒计数 rage: 1 _rage: 1
 *  b 的愤怒计数 rage: 2 _rage: 2
 *  a 的愤怒计数 rage: 2 _rage: 3
 *  a 的愤怒计数 rage: 3 _rage: 4
 *  b 的愤怒计数 rage: 3 _rage: 5
 *  a 的愤怒计数 rage: 4 _rage: 6
 *  b 的愤怒计数 rage: 4 _rage: 7
 *  a 的愤怒计数 rage: 5 _rage: 8
 *  b 的愤怒计数 rage: 5 _rage: 9
 *  a 的愤怒计数 rage: 6 _rage: 10
 *  b 的愤怒计数 rage: 6 _rage: 11
 *  a 的愤怒计数 rage: 7 _rage: 12
 *  b 的愤怒计数 rage: 7 _rage: 13
 *  a 的愤怒计数 rage: 8 _rage: 14
 *  b 的愤怒计数 rage: 8 _rage: 15
 *  a 的愤怒计数 rage: 9 _rage: 16
 *  b 的愤怒计数 rage: 9 _rage: 17
 *  a 的愤怒计数 rage: 10 _rage: 18
 *  b 的愤怒计数 rage: 10 _rage: 19
 *  a 的愤怒计数 rage: 11 _rage: 20
 */