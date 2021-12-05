#include <iostream>
#include <array>
#include <type_traits>
using namespace std; 

template<typename... Ts>
constexpr auto make_array(Ts&&... ts)
{
    using CT = std::common_type_t<Ts...>;
    return std::array<CT, sizeof...(Ts)>{std::forward<CT>(ts)...};
}

void test()
{
    std::array<double, 4ul> arr = make_array(1, 2.17f, 3.14, 'a');
    std::cout << "arr = { ";
    for(auto s{arr.size()}; double elem : arr)
    {
        std::cout << elem << (--s ? ", " : " ");
    }
    std::cout << "}\n";
}

template<typename... Args>
void fun(Args... args)
{
    cout << "args nums: " << sizeof...(args) << endl;
}

void test_fun()
{
    fun(1,2,3,4);
}

int main()
{
    test();
    test_fun();

    return 0;
}