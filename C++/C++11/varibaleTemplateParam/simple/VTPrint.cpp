#include <iostream>
using namespace std;

template<typename... T>
void DummyWrapper(T... t)
{

}

template<typename T>
T pr(T t)
{
    cout << t << " ";
    return t;
}

template<typename... A>
void VTPrint(A... a)
{
#define TEST 1
#if TEST
    DummyWrapper(pr(a)...);
#else
    DummyWrapper(pr(a...));
#endif
#undef TEST
}

int main()
{   
    VTPrint(1, ", ", 1.2, ", abc");

    return 0;
}