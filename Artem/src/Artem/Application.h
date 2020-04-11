#pragma once

#include "Artem/Event/ApplicationEvent.h"
#include "Artem/Event/KeyEvent.h"
#include "Artem/Event/MouseEvent.h"

#include "Layer/LayerStack.h"
#include "Window.h"
namespace Artem
{
	class AT_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;
		void OnEvent(Event& e);
		LayerStack m_LayerStack;

	public:
		Application();
		virtual ~Application();

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		//Event fnc
		virtual bool OnWindowClose(WindowCloseEvent& event);
	};

	//To be defined in CLIENT APP
	Application* CreateApplication();

}