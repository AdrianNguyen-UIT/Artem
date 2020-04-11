#pragma once
#include "atpch.h"
#include "Core.h"
#include "Event/Event.h"


namespace Artem
{
	struct WindowProp
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProp(const std::string& p_Title = "Artem",
			const unsigned int& p_Width = 1600,
			const unsigned int& p_Height = 900)
			: Title(p_Title), Width(p_Width), Height(p_Height)
		{
		}
	};

	//Window Interface
	class AT_API Window
	{
	public:
		using EventCallBackFnc = std::function<void(Event&)>;

		virtual ~Window() = default;
		
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallBack(const EventCallBackFnc& p_EventCallBack) = 0;
		virtual void SetVSync(bool) = 0;
		virtual bool IsVSync() const = 0;
		static Window* Create(const WindowProp& p_WindowProp = WindowProp());
	};
}
