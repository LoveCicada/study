#include <iostream>
#include <future>
#include <thread>
using namespace std;

void test1()
{
    //来自packaged_task 的 future
    std::packaged_task<int()> task(
        [](){
        return 7;
    });

    //获取future
    std::future<int> f1 = task.get_future();

    //在线程上运行
    std::thread(std::move(task)).detach();

    //来自async()的future
    std::future<int> f2 = std::async(std::launch::async,
        [](){
            return 8;
        });


    //来自promise的future
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread(
        [&p](){
            p.set_value_at_thread_exit(9);
        }).detach();

    std::cout<<"waiting..."<<std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout<<"Done!\nResults are: "
            <<f1.get()<<" "<<f2.get()<<" "
            <<f3.get()<<"\n";



}

int main()
{
    cout<<"hello cmake"<<endl;

    test1();

    system("pause");
    return 0;
}