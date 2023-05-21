
#include <iostream>
#include <vector>
#include <thread>
#include "blockQueue.h"
using namespace std;

mutex g_mtx;

void Consumer(XYYBlockQueue<int> *q)
{
	while (q->Available())
	{
		int data = -1;
		q->Pop(data);
		{
			unique_lock<mutex> lk(g_mtx);
			cout << "<" << this_thread::get_id() << ">: " << data << " comsumed.\n";
		}
	}

	cout << "<" << this_thread::get_id() << ">: " << "consumer is done.\n";
}

void Producer(XYYBlockQueue<int> *q, int start, int maxNum)
{
	int i = 0;
	while (i++ < maxNum)
	{
		int data = i + start;
		q->Push(data);

		{
			unique_lock<mutex> lk(g_mtx);
			cout << "[" << this_thread::get_id() << "]: " << data << " produced.\n";
		}
	}

	cout << "[" << this_thread::get_id() << "]: " << "producer is done.\n";
}

int main(int argc, char* argv[])
{
	XYYBlockQueue<int> q;

	vector<thread> thsProd;
	constexpr int num = 5;
	for (int i = 0; i < num; ++i)
	{
		thsProd.emplace_back(Producer, &q, i * 100, num * 100);
	}

	vector<thread> thsCon;
	constexpr int numX = 5;
	for (int i = 0; i < numX; ++i)
	{
		thsCon.emplace_back(Consumer, &q);
	}

	for (auto& t : thsProd)
	{
		if (t.joinable())
			t.join();
	}

	for (auto& t : thsCon)
	{
		if (t.joinable())
			t.join();
	}

	return 0;
}