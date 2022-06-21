
/**
 * @file singleton.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton
{
public:
    static T* GetInstance() { 
        static T instance;
        return &instance;
    }

protected:
    Singleton(){
        cout << __func__ << endl;
    }
    ~Singleton(){
        cout << __func__ << endl;
    }
    Singleton(const Singleton&){}
    Singleton& operator=(const Singleton&){
        return *this;
    }
    
};

class SingletonDerived : public Singleton<SingletonDerived>
{
    friend Singleton;   //Singleton can visit SingletonDerived private member and function
private:
    SingletonDerived(){
        cout << __func__ << endl;
    }
    ~SingletonDerived(){
        cout << __func__ << endl;
    }
    SingletonDerived(const SingletonDerived&){}
    SingletonDerived& operator=(const SingletonDerived&){
        return *this;
    }
public:
    void print() {
        cout << __func__ << " this: " << this << endl;
    }
};

int main(int argc, char* argv[]) {
    SingletonDerived* pSd = SingletonDerived::GetInstance();
    pSd->print();

    SingletonDerived* pSd2 = SingletonDerived::GetInstance();
    pSd2->print();

    if(pSd == pSd2) {
        cout << "the same object." << endl;
    }

    return 0;
}

/**
 * @result 
 *  Singleton
    SingletonDerived
    print this: 0x55e3bca0c152
    print this: 0x55e3bca0c152
    the same object.
    ~SingletonDerived
    ~Singleton
 */

/**
 * @brief 
 *  例如，以下语句说明类B是类A的友元类：
    class A
    {
    …
    public:
        friend class B;
    …
    };
    经过以上说明后，类B的所有成员函数都是类A的友元函数，
    能存取类A的私有成员和保护成员。
 */