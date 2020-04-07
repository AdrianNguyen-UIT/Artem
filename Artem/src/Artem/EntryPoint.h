#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Artem::Application* Artem::CreateApplication();

int main(int argc, char** argv)
{
	Artem::Log::Init();
	int a = 3;
	std::string b = "artem";
	AT_TRACE("trace, var = {0}, string = {1}", a, b);
	AT_INFO("info");
	AT_WARN("warn");
	AT_ERROR("error");
	AT_CRITICAL("critical");
	AT_DEBUG("debug");


	auto app = Artem::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // AT_PLATFORM_WINDOWS
