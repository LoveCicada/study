
#include <iostream>
#include <setjmp.h>

using namespace std;

void test()
{
    jmp_buf _env;
    int i = 0, j = 0;
    i = setjmp(_env);
    std::cout << "i = " << i << std::endl;
    if(j == 10)
    {
        std::cout << "i will return" << std::endl;

        return;
    }
    longjmp(_env, ++j);

    std::cout << "over" << std::endl;
}

int main()
{
    test();

    return 0;
}

