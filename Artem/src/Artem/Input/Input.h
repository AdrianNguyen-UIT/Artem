#pragma once
#include "Artem/Core/Core.h"

namespace Artem
{
	class Input
	{
	private:
		static Input* s_InputInstance;

	protected:
		virtual bool IsMouseButtonPressedImpl(int button) const = 0;
		virtual bool IsKeyPressedImpl(int key) const = 0;
		virtual std::pair<float, float> GetMousePosImpl() const = 0;
		virtual float GetMouseXPosImpl() const = 0;
		virtual float GetMouseYPosImpl() const = 0;

	public:
		Input() = default;
		Input(const Input& p_Input) = delete;
		Input& operator=(const Input& p_Input) = delete;


		static bool IsMouseButtonPressed(int button);
		static bool IsKeyPressed(int key);
		static std::pair<float, float> GetMousePos();
		static float GetMouseXPos();
		static float GetMouseyPos();
	};
}
