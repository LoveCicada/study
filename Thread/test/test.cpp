
#include <iostream>
#include <thread>
#include <sstream>
using namespace std;

void test()
{
    std::ostringstream oss;
    oss << std::this_thread::get_id();
    printf("id:%s\n", oss.str().c_str());
    std::cout << "this_id:" << std::this_thread::get_id() << std::endl;   
}

int main()
{
    test();

    return 0;
}