/**
 * @file lock.cpp
 * @author your name (you@domain.com)
 * @brief 先获得资源再加锁（当有足够资源的时候再加锁）
 * 先获得所有的锁再进行加锁操作。注意或的锁拥有权的过程中，不要进行加锁操作。

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
    
    // 拥有锁，但不去调动加锁。只获取拥有权，不调动加锁
    std::unique_lock<std::mutex> lkA(g_mtxA, std::defer_lock);
    std::cout << "thread " << str << " get mutx A" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkB(g_mtxB, std::defer_lock);
    std::cout << "thread " << str << " get mutx B" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    
    // 前两者都拥有锁之后，再加锁
    std::lock(lkA, lkB);

    std::cout << "g_idx: " << ++g_idx 
                << " tid name: " << str 
                << " tid: " << this_thread::get_id() 
                << std::endl;
}

void testB(string str)
{
    cout << "create thread " << str << endl;

    std::unique_lock<std::mutex> lkA(g_mtxA, std::defer_lock);
    std::cout << "thread " << str << " get mutx A" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkB(g_mtxB, std::defer_lock);
    std::cout << "thread " << str << " get mutx B" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    
    // 前两者都拥有锁之后，再加锁
    std::lock(lkA, lkB);

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

/**
 * @result 

 */