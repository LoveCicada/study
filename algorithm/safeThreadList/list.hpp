#pragma once

#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>
using std::list;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::condition_variable;

template<typename T>
class SafeThread
{
public:
	SafeThread()
	{
		m_thread = std::move(thread(&SafeThread::ThreadProcess, this));
	}

	~SafeThread()
	{
		{
			unique_lock<mutex> lk(m_mtx);
			while (!m_lWorkList.empty())
			{
				T* p = m_lWorkList.front();
				m_lWorkList.pop_front();
				m_lIdleList.push_back(p);
			}

			m_lWorkList.push_back(nullptr);
		}

		m_cv.notify_all();

		if (m_thread.joinable())
		{
			m_thread.join();
		}

		while (!m_lIdleList.empty())
		{
			T* p = m_lIdleList.front();
			m_lIdleList.pop_front();
			delete p;
		}

	}

public:
	bool SendData(T* _p)
	{
		unique_lock<mutex> lk(m_mtx);
		T* p = nullptr;
		if (m_lIdleList.empty())
		{
			p = new T;
		}
		else
		{
			p = m_lIdleList.front();
			m_lIdleList.pop_front();
		}

		*p = *_p;

		m_lWorkList.push_back(p);
		m_cv.notify_all();

		return true;
	}

protected:
	virtual void Process(T* p) = 0;

private:
	void ThreadProcess()
	{
		while (true)
		{
			T* p = nullptr;

			{
				unique_lock<mutex> lk(m_mtx);

				while (m_lWorkList.empty())
				{
					m_cv.wait(lk);
				}

				p = m_lWorkList.front();
				m_lWorkList.pop_front();
			}

			if (!p)
			{
				break;
			}

			Process(p);

			{
				unique_lock<mutex> lk(m_mtx);
				m_lIdleList.push_back(p);
			}

		}
	}

private:
	thread m_thread;
	mutex m_mtx;
	condition_variable m_cv;
	list<T*> m_lWorkList;
	list<T*> m_lIdleList;
};

//template<typename T>
//bool SafeThread::SendData(T* p)
//{
//
//	return true;
//}
//
//template<typename T>
//void SafeThread::ThreadProcess()
//{
//
//}