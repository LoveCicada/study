
#pragma once

/**
 * @file callback.h
 * @author cicada (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
#include <iostream>
#include <functional>
using namespace std;

class Father1
{
public:
	virtual ~Father1(){}
	virtual void Do1() = 0;
	void Handle()
	{
		cout << __FUNCTION__ << endl;
		Do1();
	}
};

class Father2
{
public:
	virtual ~Father2(){}
	virtual void Do2() = 0;
	void Handle()
	{
		cout << __FUNCTION__ << endl;
		Do2();
	}
};

class Father3
{
public:
	virtual ~Father3(){}
	virtual void Do3() = 0;
	void Handle()
	{
		cout << __FUNCTION__ << endl;
		Do3();
	}
};

class Son final : public Father1, public Father2, public Father3
{
public:
	void Process()
	{
		cout << __FUNCTION__ << endl;
		Father1::Handle();
		Father2::Handle();
		Father3::Handle();
	}
protected:
	virtual void Do1() final
	{
		cout << __FUNCTION__ << endl;
	}
	virtual void Do2() final
	{
		cout << __FUNCTION__ << endl;
	}
	virtual void Do3() final
	{
		cout << __FUNCTION__ << endl;
	}
};