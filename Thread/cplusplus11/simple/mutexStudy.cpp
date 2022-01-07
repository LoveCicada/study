
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <mutex>

std::map<std::string, std::string> g_pages;
std::mutex g_pages_mtx;

void save_page(const std::string& url)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";

#if 1
    std::lock_guard<std::mutex> guard(g_pages_mtx);
#endif
    static int i = 0;
    i++;
    std::cout << "idx = " << i <<"\n";
    g_pages[url] = result;

}

int main()
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();

    for(const auto& pair:g_pages)
    {
        std::cout << pair.first << " => " << pair.second << "\n";
    }        


    return 0;
}
