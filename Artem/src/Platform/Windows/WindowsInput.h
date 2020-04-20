#pragma once

#include "Artem/Input/Input.h"

namespace Artem
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsMouseButtonPressedImpl(int button) const override;
		virtual bool IsKeyPressedImpl(int key) const override;
		virtual std::pair<float, float> GetMousePosImpl() const override;
		virtual float GetMouseXPosImpl() const override;
		virtual float GetMouseYPosImpl() const override;
	};
}
