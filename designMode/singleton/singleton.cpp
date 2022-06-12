
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
    friend T;
public:
    static T* GetInstance() { 
        static T instance;
        return &instance;
    }

private:
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
    friend Singleton;
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

    return 0;
}