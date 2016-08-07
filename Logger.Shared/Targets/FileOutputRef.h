#pragma once
#include "FileOutput.h"
#include "../ILogTargetRef.h"


#ifndef __cplusplus_winrt
#error OutputDebugstring requires the /ZW compiler option.
#endif

namespace Wally
{
	namespace Utils
	{

		public ref class FileOutput sealed : public ILogTarget
		{
			std::unique_ptr<Wally::FileOutput> m_target;
		public:
			FileOutput(Platform::String^ path, bool trunc) :
				m_target(std::make_unique<Wally::FileOutput>(path->Begin(), trunc))
			{

			}

			// Inherited via ILogTarget
			virtual MyIntPtr FileOutput::TransferTarget()
			{
				if (!m_target)
					throw ref new Platform::NullReferenceException(L"Target pointer already transfered");

				return (MyIntPtr)m_target.release();
			}

		};

	}
}
