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

int main()
{
    test();

    return 0;
}