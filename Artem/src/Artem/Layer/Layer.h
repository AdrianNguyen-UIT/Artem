#pragma once
#include "Artem/Core/Core.h"
#include "Artem/Event/Event.h"

namespace Artem
{
	class Layer
	{
	protected:
		std::string m_LayerName;

	public:
		Layer(const std::string& p_Name = "Layer");

		virtual ~Layer() = default;

		virtual void OnAttach();
		virtual void OnUpdate();
		virtual void OnDetach();
		virtual void OnImGuiRender();//For every layer to implement their own GUI
		virtual void OnEvent(Event& event);

		inline std::string GetName() const;
	};
}
