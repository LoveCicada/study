#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

void accumulate(std::vector<int>::iterator first,
    std::vector<int>::iterator last,
    std::promise<int> accumulate_promise)
{
    auto sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);
}

void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    barrier.set_value();
}

void test()
{
    std::vector<int> numbers = { 1,2,3,4,5,6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
        std::move(accumulate_promise));
    accumulate_future.wait();
    std::cout << "result = " << accumulate_future.get() << std::endl;
    work_thread.join();

    std::promise<void> barrier;
    std::future<void> barrier_future = barrier.get_future();
    std::thread new_work_thread(do_work, std::move(barrier));
    barrier_future.wait();
    new_work_thread.join();

}

int main()
{
    cout<<"hello cmake"<<endl;

    test();

    system("pause");
    return 0;
}