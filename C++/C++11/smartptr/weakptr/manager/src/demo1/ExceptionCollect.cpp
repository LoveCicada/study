
#include "ExceptionCollectExport.h"
#include "ThreadMonitor.h"

using namespace ExceptionCollect;

std::shared_ptr<ExceptionCollect::IExceptionCollect> ExceptionCollect::GetExceptionCollect()
{
    //return std::shared_ptr<IExceptionCollect>();
    return nullptr;
}

std::shared_ptr<ExceptionCollect::IThreadMonitor> ExceptionCollect::CreateThreadMonitor()
{
    return std::make_shared<CThreadMonitor>();
}

std::shared_ptr<ExceptionCollect::IThreadMonitorManager> ExceptionCollect::GetThreadMonitorManager()
{
    static std::shared_ptr<ExceptionCollect::IThreadMonitorManager> pInstance = std::make_shared<CThreadMonitorManager>();
    return pInstance;
}