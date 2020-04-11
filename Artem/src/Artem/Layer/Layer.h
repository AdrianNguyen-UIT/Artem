#pragma once
#include "Artem/Core.h"
#include "Artem/Event/Event.h"

namespace Artem
{
	class AT_API Layer
	{
	protected:
		std::string m_LayerName;

	public:
		Layer(const std::string& p_Name = "Layer");

		virtual ~Layer() = default;

		virtual void OnAttach();
		virtual void OnUpdate();
		virtual void OnDetach();
		virtual void OnEvent(Event& event);

		inline std::string GetName() const;
	};
}
