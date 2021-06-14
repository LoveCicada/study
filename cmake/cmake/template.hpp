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
* 右值引用
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
* 泛化之美--C++11可变模版参数的妙用
* https://www.cnblogs.com/qicosmos/p/4325949.html
*/





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


//泛型工厂函数

template<class T,class ... Args>
T* Instance(Args&& ... args)
{
	return new T(std::forward<Args>(args)...);
}


//4 可变参数模板实现泛化的delegate

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
