
#include <iostream>
#include <memory>
using namespace std;

// weak_ptr基本用法
void fun1()
{
    std::shared_ptr<int> pSharedPtr = std::make_shared<int>(10);
    std::cout << "pSharedPtr.use_count(): " << pSharedPtr.use_count() << std::endl;

    std::weak_ptr<int> pWeakPtr(pSharedPtr);
    std::cout << "pWeakPtr.use_count(): " << pWeakPtr.use_count() << std::endl;

    // check whether pSharedPtr is valid
    if (!pWeakPtr.expired())
    {
        std::shared_ptr<int> pSharedPtr2 = pWeakPtr.lock();
        *pSharedPtr2 = 111;
        std::cout << "pWeakPtr.use_count(): " << pWeakPtr.use_count() << std::endl;

        pSharedPtr2.reset();
        std::cout << "pWeakPtr.use_count(): " << pWeakPtr.use_count() << std::endl;
        std::cout << "pWeakPtr.expire(): " << std::boolalpha << pWeakPtr.expired() << std::endl;

        pSharedPtr.reset();
        std::cout << "pWeakPtr.use_count(): " << pWeakPtr.use_count() << std::endl;
        std::cout << "pWeakPtr.expire(): " << std::boolalpha << pWeakPtr.expired() << std::endl;
    }
}

// 循环引用案例
////////////////////////////////////////////////////////////////
class B;

class A
{
public:
    A() { std::cout << __FUNCTION__ << std::endl; }
    ~A(){ std::cout << __FUNCTION__ << std::endl; }

    std::shared_ptr<B> m_pB = nullptr;
};

class B
{
public:
    B() { std::cout << __FUNCTION__ << std::endl; }
    ~B() { std::cout << __FUNCTION__ << std::endl; }

    std::shared_ptr<A> m_pA = nullptr;
};

void fun2()
{
    std::shared_ptr<A> pA = std::make_shared<A>();
    std::shared_ptr<B> pB = std::make_shared<B>();

    std::cout << "line: " << __LINE__ << " pA.use_count(): " << pA.use_count() << std::endl;
    std::cout << "line: " << __LINE__ << " pB.use_count(): " << pB.use_count() << std::endl;

    pA->m_pB = pB;
    pB->m_pA = pA;

    std::cout << "line: " << __LINE__ << " pA.use_count(): " << pA.use_count() << std::endl;
    std::cout << "line: " << __LINE__ << " pB.use_count(): " << pB.use_count() << std::endl;
}

/*
* @result
*   A::A
    B::B
    line: 59 pA.use_count(): 1
    line: 60 pB.use_count(): 1
    line: 65 pA.use_count(): 2
    line: 66 pB.use_count(): 2
*/


////////////////////////////////////////////////////////////////
// 循环引用解决案例
////////////////////////////////////////////////////////////////
class BB;

class AA
{
public:
    AA() { std::cout << __FUNCTION__ << std::endl; }
    ~AA() { std::cout << __FUNCTION__ << std::endl; }

    std::weak_ptr<BB> m_pB;
};

class BB
{
public:
    BB() { std::cout << __FUNCTION__ << std::endl; }
    ~BB() { std::cout << __FUNCTION__ << std::endl; }

    std::shared_ptr<AA> m_pA = nullptr;
    //std::weak_ptr<AA> m_pA;
};

void fun3()
{
    std::shared_ptr<AA> pA = std::make_shared<AA>();
    std::shared_ptr<BB> pB = std::make_shared<BB>();

    std::cout << "line: " << __LINE__ << " pA.use_count(): " << pA.use_count() << std::endl;
    std::cout << "line: " << __LINE__ << " pB.use_count(): " << pB.use_count() << std::endl;

    pA->m_pB = pB;
    pB->m_pA = pA;

    std::cout << "line: " << __LINE__ << " pA.use_count(): " << pA.use_count() << std::endl;
    std::cout << "line: " << __LINE__ << " pB.use_count(): " << pB.use_count() << std::endl;
}

/*
* @result
*   AA::AA
    BB::BB
    line: 109 pA.use_count(): 1
    line: 110 pB.use_count(): 1
    line: 115 pA.use_count(): 2
    line: 116 pB.use_count(): 1
    BB::~BB
    AA::~AA
*/

int main(int argc, char* argv[])
{
    //fun1();
    //fun2();
    fun3();

    return  0;
}