#pragma once
#include"Core.h"

namespace Artem
{
	class AT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	//To be defined in CLIENT APP
	Application* CreateApplication();

}