#pragma once
#include "atpch.h"
#include "Core.h"
#include "Artem/Event/Event.h"

namespace Artem
{
	struct WindowProp
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProp(const std::string& p_Title = "Artem",
			const unsigned int& p_Width = 1280,
			const unsigned int& p_Height = 720)
			: Title(p_Title), Width(p_Width), Height(p_Height)
		{
		}
	};

	//Window Interface
	class AT_API Window
	{
	public:
		using EventCallbackFnc = std::function<void(Event&)>;

		virtual ~Window() = default;
		
		virtual void OnUpdate() = 0;

		virtual void* GetOriginalWindow() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFnc& p_EventCallback) = 0;
		virtual void SetVSync(bool) = 0;
		virtual bool IsVSync() const = 0;
		static Window* Create(const WindowProp& p_WindowProp = WindowProp());
	};
}
