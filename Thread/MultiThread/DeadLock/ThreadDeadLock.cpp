/**
 * @file ThreadWaitMutex.cpp
 * @author your name (you@domain.com)
 * @brief  
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
mutex g_mtxB;
int g_idx = 0;

void testA(string str)
{
    cout << "create thread " << str << endl;
    std::unique_lock<std::mutex> lkA(g_mtxA);
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkB(g_mtxB);
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    
    std::cout << "g_idx: " << ++g_idx 
                << " tid name: " << str 
                << " tid: " << this_thread::get_id() 
                << std::endl;
}

void testB(string str)
{
    cout << "create thread " << str << endl;
    std::unique_lock<std::mutex> lkB(g_mtxB);
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkA(g_mtxA);
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    
    std::cout << "g_idx: " << ++g_idx 
                << " tid name: " << str 
                << " tid: " << this_thread::get_id() 
                << std::endl;
}

int main(int argc, char * argv[])
{

    thread t1(testA, "A");
    thread t2(testB, "B");

    t1.join();
    t2.join();

    return 0;
}