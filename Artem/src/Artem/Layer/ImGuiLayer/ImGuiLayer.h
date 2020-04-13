#pragma once
#include "Artem/Layer/Layer.h"


namespace Artem
{
	class AT_API ImGuiLayer : public Layer
	{
	private:
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;
	};
}

