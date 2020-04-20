#pragma once

#include "Artem/Event/ApplicationEvent.h"
#include "Artem/Event/KeyEvent.h"
#include "Artem/Event/MouseEvent.h"

#include "Artem/Layer/LayerStack.h"
#include "Artem/Layer/ImGuiLayer/ImGuiLayer.h"
#include "Artem/Core/Window.h"

namespace Artem
{
	class AT_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;
		LayerStack m_LayerStack;
		static Application* s_AppInstance;

		void OnEvent(Event& e);
	public:
		Application();
		virtual ~Application();

		Window& GetWindow() const;
		static Application& GetApplication();

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		//Event fnc
		virtual bool OnWindowClose(WindowCloseEvent& event);
	};

	//To be defined in CLIENT APP
	Application* CreateApplication();

}