#pragma once

#ifdef AT_PLATFORM_WINDOWS

extern Artem::Application* Artem::CreateApplication();

int main(int argc, char** argv)
{
	Artem::Log::Init();
	auto app = Artem::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // AT_PLATFORM_WINDOWS
