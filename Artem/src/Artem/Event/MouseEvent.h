#pragma once

#include "Event.h"

namespace Artem
{
	class MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	};


	class MouseMoveEvent : public MouseEvent
	{
	private:
		float m_MouseX;
		float m_MouseY;
	public:
		MouseMoveEvent(float p_MouseX, float p_MouseY)
			: m_MouseX(p_MouseX), m_MouseY(p_MouseY)
		{
		}

		float GetMouseX() const
		{
			return m_MouseX;
		}

		float GetMouseY() const
		{
			return m_MouseY;
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMove)
	};

	class MouseScrollEvent : public MouseEvent
	{
	private:
		float m_XOffset;
		float m_YOffset;
	public:
		MouseScrollEvent(float p_XOffset, float p_YOffset)
			: m_XOffset(p_XOffset), m_YOffset(p_YOffset)
		{
		}

		float GetXOffset() const
		{
			return m_XOffset;
		}

		float GetYOffset() const
		{
			return m_YOffset;
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScroll)
	};

	class MouseButtonEvent : public MouseEvent
	{
	protected:
		int m_MouseButton;

		MouseButtonEvent(int p_MouseButton)
			: m_MouseButton(p_MouseButton)
		{
		}

	public:
		int GetMouseButton() const
		{
			return m_MouseButton;
		}

		EVENT_CLASS_CATEGORY(MouseEvent::GetCategories() | EventCategoryMouseButton)
	};

	class MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(int p_MouseButton)
			: MouseButtonEvent(p_MouseButton)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressEvent: "<< m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPress)
	};

	class MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(int p_MouseButton)
			: MouseButtonEvent(p_MouseButton)
		{
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleaseEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonRelease)
	};
}
