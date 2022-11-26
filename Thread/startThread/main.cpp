
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

class Login
{
public:
	Login()
	{
		m_pTd = new thread(&Login::ThreadImp, this);
	}

	~Login()
	{

		if (m_pTd && m_pTd->joinable())
		{
			m_pTd->join();
			delete m_pTd;
			m_pTd = nullptr;
		}
	}

public:
	void Start()
	{
		m_cv.notify_all();
	}

protected:
	void ThreadImp()
	{
		cout << __FUNCTION__ << "enter thread ---" << endl;
		unique_lock<mutex> lk(m_mtx);
		m_cv.wait(lk);
		do
		{
			cout << __FUNCTION__ << " thread run ..." << endl;

		} while (0);

		cout << __FUNCTION__ << "thread run over >>>" << endl;

	}

private:
	thread* m_pTd;
	mutex m_mtx;
	condition_variable m_cv;

};

class Login2
{
public:
	Login2()
	{
		m_bStart = false;
		m_pTd = new thread(&Login2::ThreadImp, this);
	}

	~Login2()
	{

		if (m_pTd && m_pTd->joinable())
		{
			m_pTd->join();
			delete m_pTd;
			m_pTd = nullptr;
		}
	}

public:
	void Start()
	{
		m_bStart = true;
	}

protected:
	void ThreadImp()
	{
		cout << __FUNCTION__ << "enter thread ---" << endl;

		while (!m_bStart)
		{
			if(m_bStart)
			{
				do
				{
					cout << __FUNCTION__ << " thread run ..." << endl;

				} while (0);
			}
		}

		cout << __FUNCTION__ << "thread run over >>>" << endl;

	}

private:
	thread* m_pTd;
	bool m_bStart;

};


int main(int argc, char* argv[])
{

	{
		Login l;

		this_thread::sleep_for(chrono::seconds(2));

		l.Start();
	}

	cout << "=============" << endl;


	{
		Login2 l2;

		this_thread::sleep_for(chrono::seconds(2));

		l2.Start();
	}

	cout << __FUNCTION__ << endl;
	return 0;
}