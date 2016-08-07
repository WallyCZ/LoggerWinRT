#pragma once

namespace Wally
{
	class ILogTarget
	{
	public:
		virtual ~ILogTarget() {};
		virtual void OutStringW(const wchar_t * str) = 0;

	};

}
