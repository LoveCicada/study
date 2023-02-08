

#include <iostream>
#include <functional>


/*
* @brief 可变参数定义的函数指针,在接收普通函数指针赋值后,
* 再调用函数指针实现时, M1(mac arm)运行时, 函数实参有误.
* 非arm架构正常
* 
* 与C++版本无关
* windows: OK
* C++ version: 199711
* outCall->addr[0]: bool (__cdecl*)(void * __ptr64 * __ptr64)
* data: 00000208C4F136B0, addr[0]: 00007FF6E3E01384
* CXExplorerHost::CreateExplorer: bool (__cdecl*)(void * __ptr64 * __ptr64)
* data: 00000208C4F136B0, hostData: 00000208C4F136B0
* -----------------
* CXExplorerHost::CreateExplorer: bool (__cdecl*)(void * __ptr64 * __ptr64)
* data: 00000208C4F136B0, hostData: 00000208C4F136B0
* 
* mac M1: error
* 
*/

typedef void* x_callData;
typedef x_callData* x_callDataPtr;

#if 0
typedef bool (*x_callbackProcPtr)(...);

//! not support (win/linux/mac)
//typedef std::function<bool(...)> x_callbackProcPtr;

#else
typedef bool (*x_callbackProcPtr)(x_callDataPtr);
#endif

struct x_callbacks
{
    x_callDataPtr     data;
    x_callbackProcPtr addr[2];
};

typedef x_callbacks* x_callbacksPtr;

struct X_PrivateArgs
{
    int outHostAPIVersion;
    x_callbacksPtr  outCallbacks;
};

class CXExplorerHost
{
private:
    struct HostData
    {
        x_callbacksPtr _pCall;
    };

public:

    static bool InitCallbacks(x_callbacksPtr& outCall)
    {
        outCall = new x_callbacks;
        HostData* pHostData = new HostData;
        pHostData->_pCall = outCall;
        outCall->data = reinterpret_cast<x_callDataPtr>(pHostData);
        outCall->addr[0] = (x_callbackProcPtr)CXExplorerHost::CreateExplorer;
        std::cout << "outCall->addr[0]: " << typeid(outCall->addr[0]).name() << std::endl;
        printf("data: %p, addr[0]: %p \r\n", outCall->data, outCall->addr[0]);
        return true;
    }

    static bool CreateExplorer(x_callDataPtr data)
    {
        HostData* hostData = reinterpret_cast<HostData*>(data);
        std::cout << "CXExplorerHost::CreateExplorer: " << typeid(&CXExplorerHost::CreateExplorer).name() << std::endl;
        printf("data: %p, hostData: %p \r\n", data, hostData);
        return true;
    }
};

void testpfn()
{
    std::cout << "C++ version: " << __cplusplus << std::endl;
    CXExplorerHost* pExplorerHost = new CXExplorerHost();
    X_PrivateArgs args;
    args.outHostAPIVersion = 0;
    args.outCallbacks = nullptr;
    pExplorerHost->InitCallbacks(args.outCallbacks);

    x_callbacksPtr explorerCallbacks;
    explorerCallbacks = args.outCallbacks;
    explorerCallbacks->addr[0](explorerCallbacks->data);

    std::cout << "-----------------" << std::endl;

    CXExplorerHost::CreateExplorer(explorerCallbacks->data);

    delete pExplorerHost;
    pExplorerHost = nullptr;
}

int main(int argc, char* argv[])
{
    testpfn();

    return 0;
}
