#include <iostream>
using namespace std;

struct A
{
    A(){}
    A(const A& a)
    {
        cout << "Copy Constructed " << __func__ <<endl;
    }
    A(A&& a)
    {
        cout << "Move Constructed " << __func__ <<endl;
    }
};

struct B
{
    B(){}
    B(const B& b)
    {
        cout << "Copy Constructed " << __func__ <<endl;
    }
    B(B&& b)
    {
        cout << "Move Constructed " << __func__ <<endl;
    }
};

//变长模板的定义
template<typename... T>
struct MultiTypes;

template<typename T1, typename... T>
struct MultiTypes<T1, T...> : public MultiTypes<T...>
{
    T1 t1;
    MultiTypes<T1, T...>(T1 a, T... b):
        t1(a), MultiTypes<T...>(b...)
        {
            cout << "MultiTypes<T1, T...>(T1 a, T... b) " << __FILE__ << " " << __func__ << " " <<  __LINE__ << endl;
        }
};

template<>
struct MultiTypes<>
{
    MultiTypes<>()
    {
        cout << "MultiTypes<>() " << __func__ <<endl;
    }
};

//完美转发的变长模板
template <
    template<typename...> class VariadcType, typename... Args
    >
VariadcType<Args...> Build(Args&&... args)
{
    return VariadcType<Args...>(std::forward<Args>(args)...);
}

int main()
{
    A a;
    B b;
    Build<MultiTypes>(a, b);

    return 0;
}