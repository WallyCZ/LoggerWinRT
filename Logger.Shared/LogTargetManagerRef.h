#pragma once
#include "ILogTarget.h"
#include "ILogTargetRef.h"
#include "LogTargetManager.h"

namespace Wally
{
	namespace Utils
	{
		public ref class LogTargetManager sealed
		{
		public:

			/*
			* Please note, that if you use this method, you can't use logTarget instance second time,
			* internal object in logTarget is transfered to C++ part and is no more avaiable for this method
			*/
			static void AddLogTarget(ILogTarget^ logTarget)
			{
				Wally::ILogTarget* obj = reinterpret_cast<Wally::ILogTarget*>((void*)logTarget->TransferTarget());


				Wally::LogTargetManager::AddLogTarget(std::shared_ptr<Wally::ILogTarget>(obj));
			}

			static void ReleaseAllTargets()
			{
				Wally::LogTargetManager::ReleaseAllTargets();
			}
		};
	}
}
