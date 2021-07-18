#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <future>
#include <thread>
#include <mutex>
using namespace std;


std::mutex m;
struct X
{
    void foo(int i,const std::string& str)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout<<str<<" "<<i<<std::endl;
    }

    void bar(const std::string& str)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout<<str<<std::endl;
    }

    int operator()(int i)
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout<<i<<std::endl;
        return i+10;
    }

};

template<typename RandomIt>
int parallel_sum(RandomIt beg,RandomIt end)
{
    auto len = end-beg;
    if(len<1000)
        return std::accumulate(beg,end,0);

    RandomIt mid = beg+len/2;
    auto handle = std::async(std::launch::async,partial_sum<RandomIt>,
        mid,end);
    int sum = partial_sum(beg,mid);
    return sum+handle.get();
}


void test1()
{
    std::vector<int> v(10000,1);
    std::cout<<"The sum is "<<parallel_sum(v.begin(),v.end())<<std::endl;

    


}

int main()
{
    cout<<"hello cmake"<<endl;

    test1();

    system("pause");
    return 0;
}