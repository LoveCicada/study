
#include <iostream>
#include <list>
// #include "include/Container.h"
#include "Container.h"
using namespace std;

using ListInt_t = std::list<int>;
using ListIntSafe_t = SafeContainer<std::list<int>>;

void test()
{
    
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListInt_t l(a,a+sizeof(a)/sizeof(int));
    auto itor = l.begin();
    cout<<"****** print ListInt_t ******"<<endl;
    printContainer(l);

    ListIntSafe_t lt;
    lt.PushBackMultiple(l);
    auto container = lt.GetContainer();
    cout<<"****** print ListIntSafe_t ******"<<endl;
    printContainer(container);

}

int main()
{
    test();

    cout <<" Container "<< endl;
    return 0;
}

