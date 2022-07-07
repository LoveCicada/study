
#pragma once

/**
 * @file templateMethod.h
 * @author your name (you@domain.com)
 * @brief 定义一个操作中算法的骨架（稳定），而将一些步骤延迟（变化）到子类中。
 * 		template method使得子类可以不改变（复用）一个算法的结构即可，只需要
 * 		重定义（override重写）该算法的某些特定步骤。
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

class Library
{
private:
	
public:
	Library()
	{
		cout << __func__ << endl;
	}

	virtual ~Library()
	{
		cout << __func__ << endl;
	}

public:
	void Run()
	{
		cout << __func__ << endl;

		Step1();
		Step2();
		Step3();
		Step4();
		Step5();
	}

	virtual void Step1()
	{
		cout << __func__ << endl;
	}

	virtual void Step2()
	{
		cout << __func__ << endl;
	}

	virtual void Step5()
	{
		cout << __func__ << endl;
	}

protected:
	virtual void Step3() = 0;
	virtual void Step4() = 0;
};

class Application : public Library
{
public:
	Application()
	{
		cout << __func__ << endl;				
	}

	~Application()
	{
		cout << __func__ << endl;				
	}

public:

	void Step3() override
	{
		cout << __func__ << endl;
	}

	void Step4() override
	{
		cout << __func__ << endl;
	}

};
