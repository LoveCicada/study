
#pragma once

/**
 * @file callback.h
 * @author cicada (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <iostream>
#include <functional>
using namespace std;

class PrintString
{
public:
	void PrintStr(const string& str)
	{
		cout << __func__ << ": " << str << endl;
	}
};

class Module
{
	typedef std::function<void(const string&)> FuncString;
public:
	Module(FuncString pFuncString = nullptr)
	{
		mFuncString = pFuncString;
	}

	void OnFuncString(const string& str)
	{
		if(mFuncString)
		{
			cout << __func__ << endl;
			mFuncString(str);
		}
	}
private:
	FuncString mFuncString;
};

