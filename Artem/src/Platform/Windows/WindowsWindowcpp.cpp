#include "atpch.h"
#include "WindowsWindow.h"

#include "Artem/Event/ApplicationEvent.h"
#include "Artem/Event/KeyEvent.h"
#include "Artem/Event/MouseEvent.h"



namespace Artem
{
	WindowsWindow::WindowsWindow(const WindowProp& p_WindowProp)
	{
		Init(p_WindowProp);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	Window* Window::Create(const WindowProp& p_WindowProp)
	{
		return new WindowsWindow(p_WindowProp);
	}

	void WindowsWindow::Init(const WindowProp& p_WindowProp)
	{
		m_WindowData.Title = p_WindowProp.Title;
		m_WindowData.Width = p_WindowProp.Width;
		m_WindowData.Height = p_WindowProp.Height;

		AT_CORE_INFO("Creating window {0} ({1}, {2})", p_WindowProp.Title, p_WindowProp.Width, p_WindowProp.Height);

		int success = glfwInit();
		AT_ASSERT(success, "COULD NOT INIT GLFW!");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			AT_ASSERT(0, "FAIL TO CREATE WINDOW");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);//set user's void pointer to window data
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int p_Width, int p_Height)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = p_Width;
			data.Height = p_Height;

			WindowResizeEvent event(p_Width, p_Height);
			data.EventCallBack(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallBack(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scandcode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressEvent event(key, 0);
					data.EventCallBack(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.EventCallBack(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressEvent event(key, 1);
					data.EventCallBack(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data.EventCallBack(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.EventCallBack(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrollEvent event((float)xoffset, (float)yoffset);
			data.EventCallBack(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event((float)xpos, (float)ypos);
			data.EventCallBack(event);
		});

		glfwSetErrorCallback([](int error, const char* description) 
		{
			AT_CORE_ERROR("CODE: ({0})\nDESCRIPTION: {1}", error, description);
		});

	}


	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	unsigned int WindowsWindow::GetWidth() const
	{
		return m_WindowData.Width;
	}

	unsigned int WindowsWindow::GetHeight() const
	{
		return m_WindowData.Height;
	}

	void WindowsWindow::SetEventCallBack(const EventCallBackFnc& p_EventCallBack)
	{
		m_WindowData.EventCallBack = p_EventCallBack;
	}

	void WindowsWindow::SetVSync(bool enable)
	{
		if (enable)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
		m_WindowData.IsVSync = enable;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_WindowData.IsVSync;
	}
}

