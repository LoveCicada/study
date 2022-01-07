
#include <iostream>
#include <string>
#include "ThreadPool.h"
using namespace std;

int main()
{
    std::mutex mtx;
#define TEST 0
#if TEST
    std::condition_variable cv;
#endif // 0
    
    try
    {
        tp::ThreadPool _tp;
        std::vector<std::future<int>> _vfi;
        std::vector<std::future<void>> _vfv;

        for(int i = 0; i<=10; ++i)
        {
            auto ans = _tp.add( [](int answer){ return answer; }, i);
            _vfi.push_back(std::move(ans));
        }
        
        for(int j = 0; j<=5; ++j)
        {
            auto ans = _tp.add( [&](const std::string& strl, const std::string& strr)
            {
#if TEST        
                std::cout << "_vfv.idx= " << j << "\n";
                {
                    std::unique_lock<std::mutex> lk(mtx);
                    cv.wait(lk);
                    std::string str = strl + " " + std::to_string(j) + " " + strr;
                    std::cout << str << std::endl;
                }
                cv.notify_one();
                
#else // 0
                std::unique_lock<std::mutex> lk(mtx);
                std::string str = strl + " " + std::to_string(j) + " " + strr;
                std::cout << str << std::endl;
#endif // 0
                return;
            }, "hello", "world");
            _vfv.push_back(std::move(ans));
        }

        for(auto& _v : _vfi)
        {
            std::unique_lock<std::mutex> lk(mtx);
            std::cout << _v.get() << std::endl;
        }

        for(auto& _vv : _vfv)
        {
#if TEST
            {
                std::unique_lock<std::mutex> lk(mtx);
                cv.wait(lk);
                _vv.get();
            }
            cv.notify_one();

#else // 0
            _vv.get();
#endif // 0
        }

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << " over finish " << std::endl;
#undef TEST
    return 0;
}