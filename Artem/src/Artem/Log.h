#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h" //For logging custom Object
#include <memory>

namespace Artem
{
	class AT_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_ArtemLogger;

	public:
		Log();
		~Log();

		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetArtemLogger();
	};
}

//Artem log macros
#define AT_TRACE(...)        Artem::Log::GetArtemLogger()->trace(__VA_ARGS__)
#define AT_INFO(...)         Artem::Log::GetArtemLogger()->info(__VA_ARGS__)
#define AT_WARN(...)         Artem::Log::GetArtemLogger()->warn(__VA_ARGS__)
#define AT_ERROR(...)        Artem::Log::GetArtemLogger()->error(__VA_ARGS__)
#define AT_CRITICAL(...)     Artem::Log::GetArtemLogger()->critical(__VA_ARGS__)
#define AT_DEBUG(...)        Artem::Log::GetArtemLogger()->debug(__VA_ARGS__)