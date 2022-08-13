
#pragma once

#include <tuple>
using namespace std;

template<class... Args>
class Fx
{
public:
    tuple<Args...> members;
public:
    void Handle()
    {
        for(size_t i = 0; i<sizeof...(Args); ++i)
        {
            auto tuple_element<0, members> t;
            t.Handle();
        }
        
    }

};


