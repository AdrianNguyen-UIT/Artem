#pragma once
#include "Artem/Window.h"
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
			EventCallBackFnc EventCallBack;
		};

		WindowData m_WindowData;
		GLFWwindow* m_Window;

		void Init(const WindowProp&);
		void ShutDown();

	public:
		WindowsWindow(const WindowProp&);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual unsigned int GetWidth() const override;
		virtual unsigned int GetHeight() const override;

		virtual void SetEventCallBack(const EventCallBackFnc&) override;
		virtual void SetVSync(bool) override;
		virtual bool IsVSync() const override;
	};
}
