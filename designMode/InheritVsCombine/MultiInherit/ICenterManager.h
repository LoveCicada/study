

#pragma once

#include <memory>

namespace CenterManager
{
    struct ICenterManager
    {
        virtual ~ICenterManager() = default;

        virtual bool Collect() = 0;

        virtual bool Notify() = 0;
    };
    
    struct IModuleA
    {
        virtual ~IModuleA() = default;
        virtual bool DispatchA() = 0;
    };

    struct IModuleB
    {
        virtual ~IModuleB() = default;
        virtual bool DispatchB() = 0;
    };

    std::shared_ptr<ICenterManager> CreateCenterManager();

}




