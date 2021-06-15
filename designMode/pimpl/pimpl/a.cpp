#include <iostream>
#include "a.h"

//define
struct A::Impl
{
	int m_nCount;
	Impl();
	~Impl();
	void doPrivateThing();
};

A::Impl::Impl()
	:m_nCount(0)
{

}

A::Impl::~Impl()
{

}

void A::Impl::doPrivateThing()
{
	std::cout << "count = " << ++m_nCount << std::endl;
}

A::A()
	:m_pImpl(new Impl)
{

}

A::~A()
{

}

void A::doSomething()
{
	m_pImpl->doPrivateThing();
}