#pragma once

#include <collection.h>
#include "Logger.h"


#ifndef __cplusplus_winrt
#error LoggerRef.h requires the /ZW compiler option.
#endif

namespace Wally
{
	namespace Utils
	{
		public enum class LoggerLevel
		{
			LOGGER_LEVEL_FATAL,
			LOGGER_LEVEL_ERROR,
			LOGGER_LEVEL_WARN,
			LOGGER_LEVEL_INFO,
			LOGGER_LEVEL_DEBUG,
			LOGGER_LEVEL_TRACE
		};

		public ref class Logger sealed
		{
		private:
			std::unique_ptr<Wally::Logger> m_logger;

			static std::string MarshalString(Platform::String ^ s)
			{
				std::wstring fooW(s->Begin());
				std::string fooA(fooW.begin(), fooW.end());
				return fooA;
			}

			Logger(Platform::String^ className) :
				m_logger(Wally::Logger::get(MarshalString(className)))
			{
			}

			Wally::LoggerLevel ConvertLevel(Wally::Utils::LoggerLevel level)
			{  
				switch (level)
				{
				case Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR: return Wally::LoggerLevel::LOGGER_LEVEL_ERROR; break;
				case Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN: return Wally::LoggerLevel::LOGGER_LEVEL_WARN; break;
				case Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO: return Wally::LoggerLevel::LOGGER_LEVEL_INFO; break;
				case Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG: return Wally::LoggerLevel::LOGGER_LEVEL_DEBUG; break;
				case Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE: return Wally::LoggerLevel::LOGGER_LEVEL_TRACE; break;
				}
				return Wally::LoggerLevel::LOGGER_LEVEL_FATAL;
			}

		public:

			static Logger^ GetLogger(Platform::String^ className)
			{
				Logger^ instance = ref new Logger(className);
				return instance;
			}

			void WriteLine(Wally::Utils::LoggerLevel level, Platform::String^ str);

			void WriteLine(Wally::Utils::LoggerLevel level, Platform::String^ str, Windows::Foundation::Collections::IVector<Platform::Object^>^ params);

			void Trace(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str);
			}

			void Trace(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str, params);
			}

			void Trace(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str, params);
			}

			void Trace(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str, params);
			}

			void Trace(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str, params);
			}

			void Trace(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4, Object^ param5)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				params->Append(param5);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_TRACE, str, params);
			}


			void Debug(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str);
			}

			void Debug(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str, params);
			}

			void Debug(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str, params);
			}

			void Debug(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str, params);
			}

			void Debug(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str, params);
			}

			void Debug(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4, Object^ param5)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				params->Append(param5);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_DEBUG, str, params);
			}

			void Info(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str);
			}

			void Info(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str, params);
			}

			void Info(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str, params);
			}

			void Info(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str, params);
			}

			void Info(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str, params);
			}

			void Info(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4, Object^ param5)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				params->Append(param5);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_INFO, str, params);
			}


			void Warn(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN, str);
			}

			void Warn(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN, str, params);
			}

			void Warn(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN, str, params);
			}

			void Warn(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN, str, params);
			}

			void Warn(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_WARN, str, params);
			}

			void Error(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR, str);
			}

			void Error(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR, str, params);
			}

			void Error(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR, str, params);
			}

			void Error(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR, str, params);
			}

			void Error(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_ERROR, str, params);
			}

			void Fatal(Platform::String^ str)
			{
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_FATAL, str);
			}

			void Fatal(Platform::String^ str, Object^ param1)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_FATAL, str, params);
			}

			void Fatal(Platform::String^ str, Object^ param1, Object^ param2)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_FATAL, str, params);
			}

			void Fatal(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_FATAL, str, params);
			}

			void Fatal(Platform::String^ str, Object^ param1, Object^ param2, Object^ param3, Object^ param4)
			{
				Platform::Collections::Vector<Platform::Object^>^ params = ref new Platform::Collections::Vector<Platform::Object^>();
				params->Append(param1);
				params->Append(param2);
				params->Append(param3);
				params->Append(param4);
				WriteLine(Wally::Utils::LoggerLevel::LOGGER_LEVEL_FATAL, str, params);
			}

		};
	};
}
