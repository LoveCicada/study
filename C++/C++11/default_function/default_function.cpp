#include <iostream>
#include <type_traits>
using namespace std;

class TwoCstor
{
public:
    //提供了带参数版本的构造函数，再指示编译器
    //提供默认版本，则本自定义类型依然是POD类型
    TwoCstor() = default;
    TwoCstor(int i) : data(i) {}
    TwoCstor(const TwoCstor&) = delete;

private:
    int data;
};

class DefaultedOptr
{
public:
    DefaultedOptr() = default;
    DefaultedOptr& operator = (const DefaultedOptr&);
};

inline DefaultedOptr& DefaultedOptr::operator = (const DefaultedOptr&) = default;


void test()
{
    cout << is_pod<TwoCstor>::value << endl;
    TwoCstor a;
    //TwoCstor b(a);


}

int main()
{
    test();

    return 0;
}