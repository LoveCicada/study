#ifndef TEST_H
#define TEST_H

/*
study c++11

*/

/*
* 
* ����֮��--C++11�ɱ�ģ�����������
* https://www.cnblogs.com/qicosmos/p/4325949.html
*/


#include <iostream>
using namespace std;


// 2.1 �ɱ�ģ���������

template<class ...T>
void func(T ... args)
{
	//��ӡ�ɱ�����ĸ���
	cout << "args num is = " << sizeof...(args) << endl;
}

// 2.1 �ݹ麯����ʽչ��������

//�ݹ���ֹ����
template<class T>
void print(T t)
{
	cout << "parameter " << t << endl;
}

//չ������
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
	//����ת��
	initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
}


//2.2 �ɱ�ģ�������



//2.2.1 ģ��ƫ�ػ��͵ݹ鷽ʽ��չ��������
//ǰ������
template<class... Args>
struct Sum;

//��������
template<class First,class...Rest>
struct Sum<First, Rest...>
{
	enum {
		value = Sum<First>::value + Sum<Rest...>::value
	};
};

//�ݹ���ֹ
template<class Last>
struct Sum<Last>
{
	enum {
		value = sizeof(Last)
	};
};





#endif // TEST_H
