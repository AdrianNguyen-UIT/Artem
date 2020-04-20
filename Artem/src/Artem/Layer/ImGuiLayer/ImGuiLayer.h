#pragma once
#include "Artem/Layer/Layer.h"


namespace Artem
{
	class AT_API ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnUpdate() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& event) override;
		virtual void OnImGuiRender() override;

		void BeginImGuiRender();
		void EndImGuiRender();

	};
}

