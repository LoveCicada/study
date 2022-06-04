/**
 * @file ThreadWaitMutex.cpp
 * @author your name (you@domain.com)
 * @brief Thread Wait Mutex
 *         Thread A use mutex, so thread B still wait mutex,
 *         can not run thread. 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <string>

using namespace std;

mutex g_mtxA;
int g_idx = 0;

void test(string str)
{
    cout << "create thread " << str << endl;
    
    while (true) {
        std::unique_lock<std::mutex> lkA(g_mtxA);
        std::cout << "g_idx: " << ++g_idx 
                << " tid name: " << str 
                << " tid: " << this_thread::get_id() 
                << std::endl;
        this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    }
    
}


int main(int argc, char * argv[])
{

    thread t1(test, "A");
    thread t2(test, "B");

    t1.join();
    t2.join();

    return 0;
}