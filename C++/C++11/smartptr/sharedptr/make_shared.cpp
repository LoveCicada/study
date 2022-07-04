
#include <iostream>
#include <memory>
using namespace std;

class MyTest
{
public:
    MyTest()
    {
        cout << __func__ << endl;
    }

    ~MyTest()
    {
        cout << __func__ << endl;
    }

};

int main(int argc, char **argv)
{
    {
        cout << "first test" << endl;
        shared_ptr<MyTest> myTest;
        myTest = make_shared<MyTest>();
    }

    {
        cout << "second test" << endl;
        shared_ptr<MyTest> myTest;
        //myTest = make_shared<MyTest>(new MyTest);
    }

    return 0;
}