#include <iostream>
#include "variableParams.hpp"
using namespace std;

class T1
{
public:
    void Handle()
    {
        cout << __func__ << endl;
    }
};

class T2
{
public:
    void Handle()
    {
        cout << __func__ << endl;
    }
};

class T3
{
public:
    void Handle()
    {
        cout << __func__ << endl;
    }
};


void test()
{
    Fx<T1, T2, T3> fx;
    fx.Handle();
}

int main()
{
    test();

    return 0;
}