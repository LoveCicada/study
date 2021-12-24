
#include <iostream>
using namespace std;

void byteOrder()
{
    union 
    {
        int data;
        char union_bytes[sizeof(int)];
    }test;
    test.data = 0x0102;

    bool b1 = test.union_bytes[0] == 1;
    bool b2 = test.union_bytes[1] == 2;
    if(b1 && b2)
    {
        std::cout << "big endian" << std::endl;
        std::cout << "&test.union_bytes[0]=" << &test.union_bytes[0] << std::endl;
        std::cout << "&test.union_bytes[1]=" << &test.union_bytes[1] << std::endl;
    }
    else
    {
        std::cout << "little endian" << std::endl;
        std::cout << "&test.union_bytes[0]=" << &test.union_bytes[0] << std::endl;
        std::cout << "&test.union_bytes[1]=" << &test.union_bytes[1] << std::endl;
    }

}

void test()
{

}

int main()
{
    byteOrder();
    test();


    return 0;
}