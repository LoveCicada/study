
/**
 * @file inherit-singleton.cpp
 * @author dyf (you@domain.com)
 * @brief a singleton base class offering an easy way to create singleton
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

template<class T>
class Singleton
{
public:
    static T& Inst() noexcept
    {
        static T inst;
        return inst;
    }

    virtual ~Singleton()
    {
        std::cout << "Singleton delete" << std::endl;
    }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton()
    {
        std::cout << "Singleton construct" << std::endl;
    }

};

class DerivedSingle : public Singleton<DerivedSingle>
{
private:
    friend Singleton<DerivedSingle>;

public:
    DerivedSingle(const DerivedSingle&) = delete;
    DerivedSingle& operator=(const DerivedSingle&) = delete;

public:
    const std::string& GetClassName() const
    {
        return m_strClassName;
    }
private:
    DerivedSingle()
    {
        m_strClassName = "DerivedSingle";
    }

private:
    std::string m_strClassName;

};

void test()
{
    DerivedSingle& d1 = DerivedSingle::Inst();
    DerivedSingle& d2 = DerivedSingle::Inst();

    std::cout << "class name: " << d1.GetClassName() << std::endl;
    std::cout << "class name: " << d1.GetClassName() << std::endl;

    if( &d1 == &d2 )
    {
        std::cout << "the same instance" << std::endl;
    }
}

int main()
{
    test();

    return 0;
}