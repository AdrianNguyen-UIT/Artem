#pragma once
#include "Artem/Core/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
namespace Artem
{
	class WindowsWindow : public Window
	{
	private:
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool IsVSync;
			EventCallbackFnc EventCallback;
		};

		WindowData m_WindowData;
		GLFWwindow* m_Window;

		void Init(const WindowProp&);
		void ShutDown();

	public:
		WindowsWindow(const WindowProp&);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual void* GetOriginalWindow() const override;
		virtual unsigned int GetWidth() const override;
		virtual unsigned int GetHeight() const override;

		virtual void SetEventCallback(const EventCallbackFnc&) override;
		virtual void SetVSync(bool) override;
		virtual bool IsVSync() const override;
	};
}
