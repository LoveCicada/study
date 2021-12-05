/*
* 
* std::function 可以绑定到全局函数/类静态成员函数（全局函数与类静态成员函数无差异），
* 如果要绑定到类的非静态成员函数（即普通成员函数），则需要使用std::bind
*/

#include <iostream>
#include <functional>
using namespace std;

typedef std::function<void()> fp;
typedef std::function<void(int)> fpi;

void g_fun()
{
    cout << "global function: " << __func__ << endl;
}

void g_func_int(int i)
{
    cout << "global function: " << __func__ << " i: " << i << endl;
}

class A
{
public:
    static void A_fun_static()
    {
        cout << "class static function: " << __func__ << endl;
    }

    void A_fun()
    {
        cout << "clcass non static function: " << __func__ << endl;
    }

    void A_fun_int(int i)
    {
        cout << "clcass non static function: " << __func__ << endl; 
    }
};

void test()
{
    A a;

    fp fp_class_static_func = std::bind(&A::A_fun_static);
    fp_class_static_func();

    fp fp_class_non_static_func = std::bind(&A::A_fun, &a);
    fp_class_non_static_func();

    fpi fp_class_non_static_func_param = std::bind(&A::A_fun_int, &a, std::placeholders::_1);
    fp_class_non_static_func_param(1);

    fp fp_global_func = std::bind(&g_fun);
    fp_global_func();

    fpi fp_global_func_param = std::bind(&g_func_int, std::placeholders::_1);
    fp_global_func_param(2);

}

int main()
{
    test();

    return 0;
}