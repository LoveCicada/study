#include <iostream>
#include<memory>
using namespace std;


class MyClass
{
public:
    MyClass()
    {
        static int i=0;
        i++;
        m_nIndex = i;
        cout<<"Construct"<<endl;
    }

    void print()
    {
        cout<<"m_nIndex = "<<m_nIndex<<endl;
    }

    ~MyClass()
    {
        cout<<"delete"<<endl;
    }
    int m_nIndex;

};


using MyClass_t = std::shared_ptr<MyClass>;

void test()
{

    cout<<" ----- begin test ----- "<<endl;

    MyClass_t mt;
    {
        mt = std::shared_ptr<MyClass>();
        if(mt.get())
        {
            mt->print();
        }
    }

    cout<<" ----- end test ----- "<<endl;


    cout<<" ----- begin test 2----- "<<endl;

    {
        MyClass_t mt2;
        mt2 = std::shared_ptr<MyClass>();
        if(mt2.get())
        {
            mt2->print();
        }
    }

    cout<<" ----- end test 2----- "<<endl;


    cout<<" ----- begin test 3----- "<<endl;

    {
        MyClass_t mt3(new MyClass);
        if(mt3.get())
        {
            mt3->print();
        }
    }

    cout<<" ----- end test 3----- "<<endl;


    cout<<" ----- begin test 4----- "<<endl;

    {
        MyClass_t mt4 = std::shared_ptr<MyClass>(new MyClass);
        if(mt4.get())
        {
            mt4->print();
        }
    }

    cout<<" ----- end test 4----- "<<endl;


    cout<<" ----- begin test 5----- "<<endl;

    {
        MyClass_t mt5 = std::make_shared<MyClass>();
        if(mt5.get())
        {
            mt5->print();
        }
    }

    cout<<" ----- end test 5----- "<<endl;


}



int main()
{

    test();

    return 0;
}


