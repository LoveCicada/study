#ifndef A_H
#define A_H

#include<memory>


class A
{
public:
	A();
	~A();
	void doSomething();
private:
	struct Impl;
	std::shared_ptr<Impl> m_pImpl;
};




#endif // A_H
