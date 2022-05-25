
#include <iostream>
using namespace std;

class A;

class B
{
public:
    friend class A;  //声明A是B的友元类，那么A的所有成员函数都是B的友元函数，都可以访问另一个类中的隐藏信息
public:
    B(int x)
    {
        bx = x;
    }
    
    //int addSum(A a, B b) //因为A是B的友元类，所以A的成员函数才可以访问B私有变量
    //{
    //    // return (a.ax + b.bx); //error
    //    return 0;
    //}

private:
    int bx;
};

class A
{
public:
    A(int x)
    {
        ax = x;
    }
    int addSum(A a, B b) //因为A是B的友元类，所以A的成员函数才可以访问B私有变量
    {
        return (a.ax + b.bx);
    }
private:
    int ax;
};


int main()
{
    A a(5);
    B b(3);

    cout << "A为B的友元类时 : A.ax + B.bx = " << a.addSum(a, b) << endl;

    return 0;
}

/**
 * @result 
 * @see 

*/