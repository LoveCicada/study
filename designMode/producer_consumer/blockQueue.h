
#pragma once

#include <queue>
#include <atomic>
#include <mutex>
#include <iostream>
#include <condition_variable>

using std::cout;
using std::atomic;
using std::mutex;
using std::queue;
using std::unique_lock;
using std::condition_variable;

template<typename T>
class XYYBlockQueue
{
public:
	XYYBlockQueue() = default;

	~XYYBlockQueue()
	{
		Stop();
		m_cvProducer.notify_all();
		m_cvConsumer.notify_all();
	}

	void SetCapacity(int nCapacity)
	{
		m_nCapacity = nCapacity;
	}

	void Stop()
	{
		m_bStop.store(true);
		m_cvConsumer.notify_all();
	}

	bool Available()
	{
		return !Stopped() || !Empty();
	}

	void Push(const T& data)
	{
		unique_lock lk(m_mtx);
		while (Full())
		{
			m_cvConsumer.notify_one();
			cout << "Queue is full, notify one consumer...\n";
			m_cvProducer.wait(lk);
		}

		m_q.push(data);
		m_cvConsumer.notify_one();
	}

	void Pop(T& data)
	{
		unique_lock<mutex> lk(m_mtx);
		while (Empty())
		{
			if (Stopped())
				return;

			m_cvProducer.notify_one();
			cout << "Queue is empty, notify one producer...\n";

			m_cvConsumer.wait(lk, []() {return true; });

			//m_cvConsumer.wait(lk, [&]()
			//	{
			//		return this->Stopped() || this->empty();
			//	});

			data = m_q.front();
			m_q.pop();
			m_cvProducer.notify_one();
		}
	}

private:
	bool Stopped()
	{
		return m_bStop.load();
	}

	bool Empty()
	{
		return m_q.empty();
	}

	bool Full()
	{
		return m_q.size() == m_nCapacity ? true : false;
	}

private:
	mutex m_mtx;
	condition_variable m_cvProducer;
	condition_variable m_cvConsumer;
	queue<T> m_q;
	atomic<bool> m_bStop = false;
	int m_nCapacity = 8;
};