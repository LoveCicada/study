
#pragma once

#include <memory>
#include <guiddef.h>

namespace ExceptionCollect
{
	struct IExceptionCollect
	{
		virtual ~IExceptionCollect() = default;


	};


	struct IThreadMonitor
	{
		struct Observer
		{
			virtual ~Observer() = default;

			virtual void Add(std::pair<GUID, std::weak_ptr<ExceptionCollect::IThreadMonitor>> pair) = 0;
			virtual void Del(GUID guid) = 0;
		};

		virtual ~IThreadMonitor() = default;

		virtual void SetObserver(std::shared_ptr<ExceptionCollect::IThreadMonitor::Observer> pObs) = 0;

		virtual void Add() = 0;

		virtual void Del() = 0;
	};

	struct IThreadMonitorManager
	{
		virtual ~IThreadMonitorManager() = default;

		virtual std::shared_ptr<IThreadMonitor::Observer> GetObserver() = 0;
	};

	std::shared_ptr<ExceptionCollect::IExceptionCollect> GetExceptionCollect();

	std::shared_ptr<ExceptionCollect::IThreadMonitor> CreateThreadMonitor();

	std::shared_ptr<ExceptionCollect::IThreadMonitorManager> GetThreadMonitorManager();

}