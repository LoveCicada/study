#include <iostream>
using namespace std;

//递归终止条件
template<typename T>
void MyPrint(T t)
{
    cout << t << endl;
}

template<typename T, typename... U>
void MyPrint(T t, U... u)
{
    cout << t << " ";
    MyPrint(u...);
}

void test()
{
    MyPrint(1, "11", 2, "22", 3.0f, "3.0f");
}

int main()
{
    test();

    return 0;
}