#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex g_mtx;
std::condition_variable g_cv;
std::string g_data;
bool g_bReady = false;
bool g_bProcessed = false;

void worker_thread()
{
    {
        //wait until main() sends data
        std::unique_lock<std::mutex> lk(g_mtx);
        g_cv.wait(lk, []{return g_bReady;});

        //after the wait, we own the lock
        std::cout << "Worker thread is processing data\n";
        g_data += " after processing ";

        //send data back to main()
        g_bProcessed = true;
        std::cout << "Worker thread signals data processing completed\n";

    }    
    g_cv.notify_one();

}


int main()
{
    std::thread worker(worker_thread);

    g_data = "Example data";

    //send data to worker thread
    {
        std::unique_lock<std::mutex> lk(g_mtx);
        g_bReady = true;
        std::cout << "main() signals data ready for processing\n";
    }
    g_cv.notify_one();

    //wait for the worker
    {
        std::unique_lock<std::mutex> lk(g_mtx);
        g_cv.wait(lk, []{return g_bProcessed;});
    }
    std::cout << "Back in main(), data = " << g_data << "\n";

    worker.join();

    return 0;
}