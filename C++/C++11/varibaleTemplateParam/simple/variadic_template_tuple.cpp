#include <iostream>

using namespace std;

//变长模板的声明
template<typename... Elements> class MyTuple;

//递归的偏特化定义
template<typename Head, typename... Tail>
class MyTuple<Head, Tail...> : private MyTuple<Tail...>
{
    Head head;
};

//边界条件
template<>
class MyTuple<>
{

};


/***
 * MyTuple<double, int, char, float>
 * 递归创建
 * 1. MyTuple<> 
 * 2. MyTuple<float>
 * 3. MyTuple<char, float>
 * 4. MyTuple<int, char, float>
 * 5. MyTuple<double, int, char, float>
*/

int main()
{

    return 0;
}