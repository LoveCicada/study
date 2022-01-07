#include <iostream>
using namespace std;

//定义
template<typename I, template<typename> class... B>
struct Container
{

};

//模板偏特化
template<typename I, template<typename> class A, template<typename> class... B>
struct Container<I, A, B...>
{
    A<I> a;
    Container<I, B...> b;
};

//边界条件
template<typename I>
struct Container<I>
{
    
};


int main()
{


    return 0;
}