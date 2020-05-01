#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h" //For logging custom Object

namespace Artem
{
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_AppLogger;

	public:
		Log();
		~Log();

		static void Init();
		static std::shared_ptr<spdlog::logger> GetCoreLogger();
		static std::shared_ptr<spdlog::logger> GetAppLogger();
	};
}

