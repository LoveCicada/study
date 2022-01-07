#include <stdio.h>
#include <stdarg.h>


double SumOfFloat(int count, ...)
{
    va_list ap;
    double sum = 0;
    //获得变长列表的句柄ap
    va_start(ap, count);
    for(int i = 0; i < count; i++)
    {
        //每次获得一个参数
        sum += va_arg(ap, double);
    }
    va_end(ap);
    return sum;
}

int main()
{
    //10.200000
    printf("%f\n", SumOfFloat(3, 1.2f, 3.4, 5.6));
    return 0;
}