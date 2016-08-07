#pragma once
#include "DebugOutputTarget.h"
#include "../ILogTargetRef.h"


#ifndef __cplusplus_winrt
#error OutputDebugstring requires the /ZW compiler option.
#endif

namespace Wally
{
	namespace Utils
	{

		public ref class DebugOutputTarget sealed : public ILogTarget
		{
			std::unique_ptr<Wally::DebugOutputTarget> m_target;
		public:
			DebugOutputTarget() :
				m_target(new Wally::DebugOutputTarget())
			{
			}

			// Inherited via ILogTarget
			virtual MyIntPtr DebugOutputTarget::TransferTarget()
			{
				if (!m_target)
					throw ref new Platform::NullReferenceException(L"Target pointer already transfered");

				return (MyIntPtr)m_target.release();
			}
		};

	}
}
