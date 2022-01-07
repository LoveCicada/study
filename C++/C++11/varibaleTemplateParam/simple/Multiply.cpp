#include <iostream>
using namespace std;

template<long... nums>struct Multiply;

template<long first, long... last>
struct Multiply<first, last...>
{
    static const long val = first * Multiply<last...>::val;
    Multiply()
    {
        cout << " val = " << val << endl;
    }
};

template<>
struct Multiply<>
{
    static const long val = 1;
    Multiply()
    {
        cout << " val = " << val << endl;
    }
};



int main()
{
    //120
    cout << Multiply<2, 3, 4, 5>::val << endl;

    //
    cout << Multiply<22, 44, 66, 88, 9>::val << endl;

    //test
    Multiply<2, 3, 4, 5> m;

    return 0;
}