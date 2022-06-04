/**
 * @file lock.cpp
 * @author your name (you@domain.com)
 * @brief 统一加锁（所有资源一次性加锁）
 * 对所有的锁进行统一申请，lock(mt1, mt2, mt3…) ，通过lock_guard() 自动管理锁的释放。
    adopt_lock：全局量，假设当前已经获得锁资源。
    lock_guard：当一个lock_guard对象被创建后，它就会尝试去获得给到它的mutex的所有权。
    当控制权不在该lock_guard对象所被创建的那个范围后，该lock_guard就会被析构，从而mutex被释放。

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
    std::lock(g_mtxA, g_mtxB);
    std::unique_lock<std::mutex> lkA(g_mtxA, std::adopt_lock);
    std::cout << "thread " << str << " get mutx A" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkB(g_mtxB, std::adopt_lock);
    std::cout << "thread " << str << " get mutx B" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    
    std::cout << "g_idx: " << ++g_idx 
                << " tid name: " << str 
                << " tid: " << this_thread::get_id() 
                << std::endl;
}

void testB(string str)
{
    cout << "create thread " << str << endl;
    std::lock(g_mtxA, g_mtxB);
    std::unique_lock<std::mutex> lkB(g_mtxB, std::adopt_lock);
    std::cout << "thread " << str << " get mutx B" << std::endl;
    this_thread::sleep_for(std::chrono::milliseconds(1000)); 

    std::unique_lock<std::mutex> lkA(g_mtxA, std::adopt_lock);
    std::cout << "thread " << str << " get mutx A" << std::endl;
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

/**
 * @result 
 *  create thread A
    thread A get mutx A
    create thread B
    thread A get mutx B
    g_idx: 1 tid name: A tid: 139816379295488
    thread B get mutx B
    thread B get mutx A
    g_idx: 2 tid name: B tid: 139816370902784
 */