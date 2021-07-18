#include <iostream>
#include <cmath>
#include <future>
#include <thread>
#include <functional>

using namespace std;

int f(int x, int y)
{
    return std::pow(x, y);
}

void task_lambad()
{
    std::packaged_task<int(int, int)> task([](int l, int r) {
        return std::pow(l, r);
        });
    std::future<int> result = task.get_future();
    task(2, 9);
    std::cout << "task_lambda: " << result.get() << std::endl;
}

void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();
    task();
    std::cout << "task_bind: " << result.get() << std::endl;
}

void task_thread()
{
    std::packaged_task<int(int, int)> task(f);
    std::future<int> result = task.get_future();
    std::thread task_thread(std::move(task), 2, 10);
    task_thread.join();
    std::cout << "task_thread: " << result.get() << std::endl;
}

void test()
{
    task_lambad();
    task_bind();
    task_thread();
}

int main()
{
    cout<<"hello cmake"<<endl;

    test();

    system("pause");
    return 0;
}