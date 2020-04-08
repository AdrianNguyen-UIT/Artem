#pragma once

#include "Event.h"

namespace Artem
{
	class ApplicationEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class WindowResizeEvent : public ApplicationEvent
	{
	private:
		unsigned int m_Width;
		unsigned int m_Height;
	public:
		WindowResizeEvent(unsigned int p_Width, unsigned int p_Height)
			: m_Width(p_Width), m_Height(p_Height)
		{
		}

		unsigned int GetWidth() const
		{
			return m_Width;
		}

		unsigned int GetHeight() const
		{
			return m_Height;
		}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
	};

	class WindowCloseEvent : public ApplicationEvent
	{
	public:
		WindowCloseEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose);
	};

	class AppTickEvent : public ApplicationEvent
	{
	public:
		AppTickEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppTickEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppTick);
	};

	class AppUpdateEvent : public ApplicationEvent
	{
	public:
		AppUpdateEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppUpdateEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppUpdate);
	};

	class AppRenderEvent : public ApplicationEvent
	{
	public:
		AppRenderEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "AppRenderEvent";
			return ss.str();
		}

		EVENT_CLASS_TYPE(AppRender);
	};
}

