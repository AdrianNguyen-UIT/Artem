#include "atpch.h"
#include "WindowsInput.h"
#include "Artem/Core/Application.h"
#include "GLFW/glfw3.h"

namespace Artem
{
	Input* Input::s_InputInstance = new WindowsInput();

	bool WindowsInput::IsMouseButtonPressedImpl(int button) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetOriginalWindow());

		auto state = glfwGetMouseButton(window, button);
		return (state == GLFW_PRESS || state == GLFW_REPEAT);
	}

	bool WindowsInput::IsKeyPressedImpl(int key) const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetOriginalWindow());

		auto state = glfwGetKey(window, key);
		return (state == GLFW_PRESS);
	}

	std::pair<float, float> WindowsInput::GetMousePosImpl() const
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetApplication().GetWindow().GetOriginalWindow());

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::GetMouseXPosImpl() const
	{
		auto [xPos, yPos] = GetMousePosImpl();
		return xPos;
	}

	float WindowsInput::GetMouseYPosImpl() const
	{
		auto [xPos, yPos] = GetMousePosImpl();
		return yPos;
	}
}