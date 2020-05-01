#pragma once

#ifdef AT_PLATFORM_WINDOWS 
#else
	#error ARTEM only supports Windows
#endif // ARTEM_PLATFORM_WINDOWS


#ifdef AT_DEBUG
	#define AT_ENABLE_ASSERT
#endif

#ifdef AT_ENABLE_ASSERT
	#define AT_ASSERT(x, ...) { if(!(x)) { AT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AT_ASSERT(x, ...)
#endif


#define BIT(x) 1 << x

#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)

//Artem log macros
#define AT_CORE_TRACE(...)        Artem::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AT_CORE_INFO(...)         Artem::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AT_CORE_WARN(...)         Artem::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AT_CORE_ERROR(...)        Artem::Log::GetCoreLogger()->error(__VA_ARGS__)

#define AT_APP_TRACE(...)        Artem::Log::GetAppLogger()->trace(__VA_ARGS__)
#define AT_APP_INFO(...)         Artem::Log::GetAppLogger()->info(__VA_ARGS__)
#define AT_APP_WARN(...)         Artem::Log::GetAppLogger()->warn(__VA_ARGS__)
#define AT_APP_ERROR(...)        Artem::Log::GetAppLogger()->error(__VA_ARGS__)