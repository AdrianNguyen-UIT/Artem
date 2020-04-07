#include "Log.h"

namespace Artem
{
	//Define static member prop
	std::shared_ptr<spdlog::logger> Log::s_ArtemLogger;

	Log::Log()
	{

	}

	Log::~Log()
	{

	}

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_ArtemLogger = spdlog::stdout_color_mt("ARTEM");
		s_ArtemLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger> Log::GetArtemLogger()
	{
		return Log::s_ArtemLogger;
	}
}