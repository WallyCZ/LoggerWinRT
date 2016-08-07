#pragma once
#include <string>
#include <memory>
#include <cstdarg>

#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

namespace Wally
{

	enum LoggerLevel
	{
		LOGGER_LEVEL_FATAL,
		LOGGER_LEVEL_ERROR,
		LOGGER_LEVEL_WARN,
		LOGGER_LEVEL_INFO,
		LOGGER_LEVEL_DEBUG,
		LOGGER_LEVEL_TRACE
	};

	class Logger
	{
	private:
		Logger();
		std::string m_className;


		void WritePrefixW(Wally::LoggerLevel level, std::wstring& tmp);

		void OutStringA(const char* str);

		void OutStringW(const wchar_t* str);

	public:

		DLLEXPORT static std::unique_ptr<Logger> get(const std::string className)
		{
			std::unique_ptr<Logger> instance(new Logger());
			instance->m_className = className;
			return instance;
		}

		DLLEXPORT void WriteLine(Wally::LoggerLevel level, const std::wstring& str);

		DLLEXPORT void WriteLine(Wally::LoggerLevel level, const std::string& str);

		DLLEXPORT void WriteLine(Wally::LoggerLevel level, const char* str);

		DLLEXPORT void WriteLineFormat(Wally::LoggerLevel level, const std::wstring & format, ...);

		DLLEXPORT void WriteLineFormat(Wally::LoggerLevel level, const std::wstring & format, va_list args);

#define GEN_LOG_WRITE_METHOD(_method_name_ , _log_level_)\
		DLLEXPORT void _method_name_ (std::wstring& str)\
		{\
			WriteLine((_log_level_) , str);\
		};\
		DLLEXPORT void _method_name_(const std::string& str)\
		{\
			WriteLine((_log_level_), str); \
		};\
		DLLEXPORT void _method_name_( const char* str)\
		{\
			WriteLine((_log_level_), str); \
		}\
		DLLEXPORT void _method_name_ ## Format( const std::wstring& format, ...)\
		{\
			va_list args;\
			va_start(args, format);\
			WriteLineFormat((_log_level_), format, args);\
		}\
		DLLEXPORT void _method_name_ ## Format( const char* format, ...)\
		{\
			va_list args;\
			std::string fomatIn(format);\
			va_start(args, format);\
			WriteLineFormat((_log_level_), std::wstring(fomatIn.begin(), fomatIn.end()), args);\
		}\

		GEN_LOG_WRITE_METHOD(Trace, Wally::LoggerLevel::LOGGER_LEVEL_TRACE);
		GEN_LOG_WRITE_METHOD(Debug, Wally::LoggerLevel::LOGGER_LEVEL_DEBUG);
		GEN_LOG_WRITE_METHOD(Info, Wally::LoggerLevel::LOGGER_LEVEL_INFO);
		GEN_LOG_WRITE_METHOD(Warn, Wally::LoggerLevel::LOGGER_LEVEL_WARN);
		GEN_LOG_WRITE_METHOD(Error, Wally::LoggerLevel::LOGGER_LEVEL_ERROR);
		GEN_LOG_WRITE_METHOD(Fatal, Wally::LoggerLevel::LOGGER_LEVEL_FATAL);

#undef GEN_LOG_WRITE_METHOD

	};
}
