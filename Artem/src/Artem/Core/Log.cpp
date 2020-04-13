#include "atpch.h"
#include "Log.h"

namespace Artem
{
	//Define static member prop
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_AppLogger;

	Log::Log()
	{

	}

	Log::~Log()
	{

	}

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n->%l: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("CORE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_AppLogger = spdlog::stdout_color_mt("APPLICATION");
		s_AppLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger> Log::GetCoreLogger()
	{
		return Log::s_CoreLogger;
	}

	std::shared_ptr<spdlog::logger> Log::GetAppLogger()
	{
		return Log::s_AppLogger;
	}
}