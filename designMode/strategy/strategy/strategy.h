
#pragma once

/**
 * @file strategy.h
 * @author cicada (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief 策略模式
 *
 */

#include <typeinfo> // typeid need
#include <cxxabi.h> // abi need

#ifdef __linux__
//! get class name
static int demangle_status; //注意这里必须是static，否则会运行时报错多重定义
#define __CLASS__ __class__
#define __class__ abi::__cxa_demangle(typeid(*this).name(), 0, 0, &demangle_status)
#else
#define __CLASS__ ""
#endif

/**
 * @brief abstract class
 * 
 */
class Strategy
{
public:
	Strategy() {
		cout << __func__ << endl;
	}
	virtual ~Strategy() {
		cout << __func__ << endl;
	}

public:
	virtual void Do() = 0;
};

/**
 * @brief deride class
 * 
 */
class CNStrategy : public Strategy
{
public:
	CNStrategy(){
		cout << __func__ << endl;
	}

	~CNStrategy(){
		cout << __func__ << endl;
	}

public:
	virtual void Do() {
		cout << __func__ << endl;
	}

};

class FRStrategy : public Strategy
{
public:
	FRStrategy(){
		cout << __func__ << endl;
	}

	~FRStrategy(){
		cout << __func__ << endl;
	}

public:
	virtual void Do() {
		cout << __func__ << endl;
	}

};

class AMStrategy : public Strategy
{
public:
	AMStrategy(){
		cout << __func__ << endl;
	}

	~AMStrategy(){
		cout << __func__ << endl;
	}

public:
	virtual void Do() {
		cout << __func__ << endl;
	}

};


class SalesOrder
{
public:
	SalesOrder(Strategy* p) : m_pStrategy(p) { 
		cout << __func__ << endl;
	}
	~SalesOrder() {
		delete m_pStrategy;
		cout << __func__ << endl;
	}
public:
	double Calc() {
		//...
		if(m_pStrategy) {
			m_pStrategy->Do();
		}

		//...
		return 0;
	}

private:
	Strategy* m_pStrategy;
};
