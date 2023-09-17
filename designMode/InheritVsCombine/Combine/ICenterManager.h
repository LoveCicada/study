
#pragma once

#include <memory>

namespace CenterManager
{
    struct IModuleA
    {
        struct Observer
        {
            virtual ~Observer() = default;
            virtual bool Dispatch() = 0;
        };

        virtual ~IModuleA() = default;
        virtual bool SetObserver(std::shared_ptr<Observer> pObs) = 0;
        virtual bool DispatchA() = 0;
    };

    struct IModuleB
    {
        struct Observer
        {
            virtual ~Observer() = default;
            virtual bool Dispatch() = 0;
        };

        virtual ~IModuleB() = default;
        virtual bool SetObserver(std::shared_ptr<Observer> pObs) = 0;
        virtual bool DispatchB() = 0;
    };

    struct ICenterManager
    {
        virtual ~ICenterManager() = default;

        virtual bool Collect() = 0;

        virtual bool Notify() = 0;

        virtual bool GetObserver(std::shared_ptr<IModuleA::Observer> pObs) = 0;

        virtual bool GetObserver(std::shared_ptr<IModuleB::Observer> pObs) = 0;
    };

    std::shared_ptr<IModuleA> CreateIModuleA();
    std::shared_ptr<IModuleB> CreateIModuleB();
    std::shared_ptr<ICenterManager> CreateCenterManager();

}




