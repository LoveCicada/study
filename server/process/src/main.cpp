
#include <iostream>
#include <memory>
#include "./Process/CXProcess.h"
using namespace std;

int main(int argc, char* argv[])
{
    //auto p = std::make_unique<CXProcess>(CXProcess::Create());

    CXProcess* p = CXProcess::Create();
    CXProcess::ProcessParams processParams;

    if(argc >= 2)
    {
        processParams.cmd = std::string(argv[1]);
        if(argc >= 3)
        {
            for(int i = 2; i < argc; i++)
            {
                processParams.args.push_back(std::string(argv[i]));
            }
        }
    }
    else
    {
        return 0;
    }

#if 0
    processParams.cmd = "python3";
    processParams.args.push_back("/mnt/d/code/private/test/linux/subProcess/1.py");
#endif // 0

    p->Init(processParams);
    p->Start();
    p->Wait();
    vector<string> vs;
    p->GetResults(vs);
    p->PrintResults(vs);

    delete p;

    return 0;
}

/**
 * @test 
 *  ./process python3 /mnt/d/code/private/test/linux/subProcess/1.py
    df8:
         name     sex  age city  year
    0     li  female   20   北京  1994
    1  zhang  female   21   上海  1995
    df9:
       name     sex  age city  year
    0   li  female   20   北京  1994
    df10:
         name     sex   age city    year
    0     li  female  20.0   北京  1994.0
    1  zhang  female  21.0   上海  1995.0
    2    NaN     NaN   NaN  NaN     NaN
    3    NaN     NaN   NaN  NaN     NaN
    4    NaN     NaN   NaN  NaN     NaN
 */