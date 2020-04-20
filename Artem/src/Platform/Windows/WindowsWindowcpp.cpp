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

		int status = glfwInit();
		AT_ASSERT(status, "FAIL TO INITIALIZE GLFW!");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);

		if (!m_Window)
		{
			AT_ASSERT(0, "FAIL TO CREATE WINDOW!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_Window);

		//glad: Load all OpenGL function pointers
		status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AT_ASSERT(status,"FAIL TO INITIALIZE GLAD!");
		//------------------------------------


		glfwSetWindowUserPointer(m_Window, &m_WindowData);//set user's void pointer to window data
		SetVSync(true);

		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int p_Width, int p_Height)
		{
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = p_Width;
			data.Height = p_Height;

			WindowResizeEvent event(p_Width, p_Height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scandcode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleaseEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleaseEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrollEvent event((float)xoffset, (float)yoffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMoveEvent event((float)xpos, (float)ypos);
			data.EventCallback(event);
		});

		glfwSetErrorCallback([](int error, const char* description) 
		{
			AT_CORE_ERROR("CODE: ({0})\nDESCRIPTION: {1}", error, description);
		});

	}


	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void* WindowsWindow::GetOriginalWindow() const
	{
		return m_Window;
	}

	unsigned int WindowsWindow::GetWidth() const
	{
		return m_WindowData.Width;
	}

	unsigned int WindowsWindow::GetHeight() const
	{
		return m_WindowData.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFnc& p_EventCallback)
	{
		m_WindowData.EventCallback = p_EventCallback;
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

