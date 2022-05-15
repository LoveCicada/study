
#include <iostream>
using namespace std;

void test()
{
    {
        int i1 = 10;
        int i2 = 20;
        //! can not modify *p, but can modify p
        const int* p = &i1;
        printf("*p = %d\n", *p);
        p = &i2;
        printf("*p = %d\n", *p);
        i2 = 30;
        printf("*p = %d\n", *p);
        printf("--------------\n");
    }

    {
        int i1 = 10;
        int i2 = 20;
        //! can not modify p, but can modify *p
        int* const p = &i1;
        *p = 11;
        printf("*p = %d\n", *p);
        printf("i1 = %d\n", i1);
        i1 = 12;
        printf("*p = %d\n", *p);
        printf("i1 = %d\n", i1);
        printf("--------------\n");
    }

    {
        const int i = 10;
        int *p;
        //! cast type
        p= (int *) &i;
        printf("*p = %d\n", *p);
        //! valid
        *p = 20;
        printf("i = %d\n",i);
        printf("*p = %d\n",*p);
        printf("p = %p\n", p);
        printf("&i = %p\n", &i);
        printf("--------------\n");
    }

}

int main()
{
    test();

    return 0;
}

/**
 * @result 
 * @see http://c.biancheng.net/view/329.html
    *p = 10
    *p = 20
    *p = 30
    --------------
    *p = 11
    i1 = 11
    *p = 12
    i1 = 12
    --------------
    *p = 10
    i = 10
    *p = 20
    p = 0x7ffc9c97dd38
    &i = 0x7ffc9c97dd38
    --------------
*/