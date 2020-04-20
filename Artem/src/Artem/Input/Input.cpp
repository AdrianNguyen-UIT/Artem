#include "atpch.h"
#include "Input.h"

namespace Artem
{

	bool Input::IsMouseButtonPressed(int button)
	{
		return s_InputInstance->IsMouseButtonPressedImpl(button);
	}

	bool Input::IsKeyPressed(int key)
	{
		return s_InputInstance->IsKeyPressedImpl(key);
	}

	std::pair<float, float> Input::GetMousePos()
	{
		return s_InputInstance->GetMousePosImpl();
	}

	float Input::GetMouseXPos()
	{
		return s_InputInstance->GetMouseXPosImpl();
	}

	float Input::GetMouseyPos()
	{
		return s_InputInstance->GetMouseYPosImpl();
	}
}