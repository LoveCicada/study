
#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

using namespace std;

int a = 30;
int b = 20;
std::mutex mtxa;
std::mutex mtxb;

void thread_funcA()
{	
	// 拥有锁，但不去调动加锁 。 只获取拥有权，不调动加锁
	std::unique_lock<std::mutex> uqka(mtxa, std::defer_lock);
	std::unique_lock<std::mutex> uqkb(mtxb, std::defer_lock);
	std::lock(uqka, uqkb);	// 前两者都拥有锁之后，再加锁
	cout << "线程1 拿到a 资源，  获得mtxa 锁\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));	// 睡眠1000毫秒
	cout << "线程1 准备拿取b 资源，  尝试进行加锁操作...\n" << endl;

	int c = a + b;
	cout << "T_A : " << c << endl;
}
void thread_funcB()
{	
	// 拥有锁，但不去调动加锁 。 只获取拥有权，不调动加锁
	std::unique_lock<std::mutex> uqkb(mtxb, std::defer_lock);
	std::unique_lock<std::mutex> uqka(mtxa, std::defer_lock);
	std::lock(uqka, uqkb);	// 前两者都拥有锁之后，再加锁
	cout << "线程2 拿到b 资源，  获得mtxb 锁\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));	// 睡眠1000毫秒
	cout << "线程2 准备拿取a 资源，  尝试进行加锁操作...\n" << endl;
	
	int c = a - b;
	cout << "T_A : " << c << endl;
}

int main() 
{
	thread t1(thread_funcA);
	thread t2(thread_funcB);
	t1.join();
	t2.join();

	return 0;
}
