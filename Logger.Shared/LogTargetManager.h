#pragma once
#include <vector>
#include <mutex>
#include "ILogTarget.h"

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Wally
{
	class LogTargetManager
	{
		static std::vector<std::shared_ptr<ILogTarget>> m_targets;
		static std::mutex m_mtx;
	public:

		DLLEXPORT static void AddLogTarget(std::shared_ptr<ILogTarget> logTarget);

		DLLEXPORT static void WriteToAllTargets(const wchar_t * str);

		DLLEXPORT static void ReleaseAllTargets();
	};


}

