
#include <iostream>
#include <thread>
using namespace std;


class MyTest
{
public:
    MyTest()
    {
        std::cout << "MyTest Construct \n";
    }

    ~MyTest()
    {
        std::cout << "MyTest Delete \n";
    }

    void Do()
    {
        int nCount = 5;
        while(nCount>0)
        {
            std::cout << nCount << " the process will break..." << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            --nCount;
        }
        int* p = nullptr;
        *p = 1;
    }

};

void test()
{
    MyTest mt;
    std::thread t(&MyTest::Do,&mt);
    if(t.joinable()){
        t.join();
    }
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}