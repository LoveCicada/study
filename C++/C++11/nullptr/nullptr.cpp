#include <iostream>
#include <typeinfo>
using namespace std;

void test()
{
    //nullptr 可以隐式转换为char*
    char* cp = nullptr;
    nullptr_t nptr;
    if(nptr == nullptr){
        cout << "nullptr_t nptr == nullptr" << endl;
    }
    else{
        cout << "nullptr_t nptr == nullptr" << endl;
    }

    if(nptr<nullptr){
        cout << "nullptr_t nptr < nullptr" << endl;
    }else{
        cout << "nullptr_t nptr !< nullptr" << endl;
    }

    auto nSzie = sizeof(nullptr);
    cout << "sizeof(nullptr) = " << nSzie << endl;
    const type_info& info = typeid(nullptr);
    cout << info.name() << " " << info.hash_code() << endl;
    throw(nullptr);
}

int main()
{
    test();

    return 0;
}