#include "atpch.h"

#include "Application.h"
#include "GLFW/glfw3.h"

#include "Artem/Input/Input.h"
#include "Artem/Input/KeyCode.h"
namespace Artem
{
	Application* Application::s_AppInstance = nullptr;

	Application::Application()
	{
		m_Running = true;
		AT_ASSERT(!s_AppInstance, "Application already exists!");
		s_AppInstance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FNC(Application::OnEvent));
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	}

	Application::~Application()
	{

	}

	Window& Application::GetWindow() const
	{
		return *m_Window;
	}

	Application& Application::GetApplication()
	{
		return *s_AppInstance;
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FNC(Application::OnWindowClose));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(event);
			if (event.IsHandled())
			{
				break;
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			//Update: Submit things for render, etc.
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			
			//In render thread
			//Render ImGui layer from member ImGuiLayer and other layers
			m_ImGuiLayer->BeginImGuiRender();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->EndImGuiRender();


			m_Window->OnUpdate();
		}
	}
}
