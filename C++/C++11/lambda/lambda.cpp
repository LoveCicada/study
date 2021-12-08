#include <iostream>
using namespace std;


void test()
{
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y){
        return x + y;
    };

    auto nRes = totalChild(girls, boys);
    std::cout << "nRes = " << nRes << std::endl;

}

int main()
{
    test();

    return 0;
}