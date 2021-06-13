#ifndef TEST_H
#define TEST_H

/*
study c++11

*/

/*
* 
* 泛化之美--C++11可变模版参数的妙用
* https://www.cnblogs.com/qicosmos/p/4325949.html
*/


#include <iostream>
using namespace std;


// 2.1 可变模板参数函数

template<class ...T>
void func(T ... args)
{
	//打印可变参数的个数
	cout << "args num is = " << sizeof...(args) << endl;
}

// 2.1 递归函数方式展开参数包

//递归终止函数
template<class T>
void print(T t)
{
	cout << "parameter " << t << endl;
}

//展开函数
template<class T,class ... Args>
void print(T head, Args... rest)
{
	cout << "parameter " << head << endl;
	print(rest...);
}

///////

template<class T>
T sum(T t)
{
	return t;
}

template<class T,class ... Types>
T sum(T first, Types ... rest)
{
	return first + sum<T>(rest...);
}

template<class T>
void printarg(T t)
{
	cout << t << endl;
}

template<class ...Args>
void expand(Args...args)
{
	int arr[] = { (printarg(args),0)... };
}

template<class F, class...Args>
void expandEx(const F& f, Args&& ...args)
{
	//完美转发
	initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
}


//2.2 可变模板参数类



//2.2.1 模板偏特化和递归方式来展开参数包
//前向声明
template<class... Args>
struct Sum;

//基本定义
template<class First,class...Rest>
struct Sum<First, Rest...>
{
	enum {
		value = Sum<First>::value + Sum<Rest...>::value
	};
};

//递归终止
template<class Last>
struct Sum<Last>
{
	enum {
		value = sizeof(Last)
	};
};





#endif // TEST_H
