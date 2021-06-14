#ifndef TEST_H
#define TEST_H

/*
study c++11

*/

#include <iostream>
#include <tuple>
using namespace std;

/*
*
* ��ֵ����
* https://www.cnblogs.com/qicosmos/p/4283455.html
*/

class A 
{
public:
	A()
	{
		static int nConstructNum = 0;
		nConstructNum++;
		cout << "construct: " << nConstructNum << endl;
	}

	A(const A& a)
	{
		static int nCopyConstructNum = 0;
		nCopyConstructNum++;
		cout << "copy constructNum: " << nCopyConstructNum << endl;
	}
	~A()
	{
		static int nDestructNum = 0;
		nDestructNum++;
		cout << "destructNum: " << nDestructNum << endl;
	}
};

A GetA()
{
	return A();
}


template<class T>
void f(T&& param)
{

}

template<class T>
class TestClass
{
	TestClass(TestClass&& rhs)
	{

	}
};






/*
* 
* ����֮��--C++11�ɱ�ģ�����������
* https://www.cnblogs.com/qicosmos/p/4325949.html
*/





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


//���͹�������

template<class T,class ... Args>
T* Instance(Args&& ... args)
{
	return new T(std::forward<Args>(args)...);
}


//4 �ɱ����ģ��ʵ�ַ�����delegate

template<class T,class R,class... Args>
class MyDelegate
{
public:
	MyDelegate(T* t, R (T::* f)(Args...))
		:m_t(t), m_f(f)
	{

	}

	R operator()(Args&&... args)
	{
		return (m_t->*m_f)(std::forward<Args>(args)...);
	}

private:
	T* m_t;
	R (T::* m_f)(Args...);
};

template<class T,class R,class ... Args>
MyDelegate<T, R, Args...> CreateDelegate(T* t, R (T::*f)(Args ...))
{
	return MyDelegate<T, R, Args...>(t, f);
}

struct AA
{
	void Fun(int i)
	{
		cout << i << endl;
	}
	void Fun1(int i, double d)
	{
		cout << i + d << endl;
	}
};

// copy and swap

/*
https://light-city.club/sc/codingStyleIdioms/copy-swap/
*/

namespace A_A
{
	template<typename T>
	class smart_ptr
	{
	public:
		smart_ptr() noexcept :ptr_(new T())
		{

		}

		smart_ptr(smart_ptr& rhs) noexcept
		{
			ptr_ = rhs.release();
		}

		void swap(smart_ptr& rhs) noexcept
		{
			using std::swap;
			swap(ptr_, rhs.ptr_);
		}

		T* release() noexcept
		{
			T* ptr = ptr_;
			ptr_ = nullptr;
			return ptr;
		}

		T* get() const noexcept
		{
			return ptr_;
		}

	private:
		T* ptr_;
	};

	template<typename T>
	void swap(A_A::smart_ptr<T>& lhs, A_A::smart_ptr<T>& rhs) noexcept
	{
		lhs.swap(rhs);
	}

}



#endif // TEST_H
