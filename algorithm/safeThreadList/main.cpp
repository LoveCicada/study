
#include <iostream>
#include <string>
#include <sstream>
#include "list.hpp"

using namespace std;

class FrameData
{
public:
	FrameData()
	{
		std::cout << __FUNCTION__ << " tid: " << std::this_thread::get_id() << std::endl;
		std::stringstream ss;
		ss << std::this_thread::get_id();
		str = ss.str();
	}
	~FrameData()
	{
		std::cout << __FUNCTION__ << " tid: " << std::this_thread::get_id() << std::endl;
	}

	void PrintTid()
	{
		std::cout << __FUNCTION__ << " tid: " << str << std::endl;
	}

private:
	std::string str;
};

class FrameThread : public SafeThread<FrameData>
{
public:
	virtual void Process(FrameData* p) override
	{
		if (p)
		{
			p->PrintTid();
		}
	}
};

int main(int argc, char* argv[])
{
	std::cout << "safe list" << endl;

	{
		FrameThread ft;
		for (int i = 0; i < 1000; i++)
		{
			FrameData fd;
			ft.SendData(&fd);
		}
	}

	return 0;
}
