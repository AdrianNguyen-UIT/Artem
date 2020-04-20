#include <Artem.h>
#include "ImGui/imgui.h"
class ExampleLayer : public Artem::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{

	}

	void OnEvent(Artem::Event& event) override
	{
	}

	virtual void OnImGuiRender() override
	{
		bool open = true;
		ImGui::Begin("Example", &open);
		ImGui::Text("Here is ExampleLayer");
		ImGui::End();
	}
};


class Sandbox : public Artem::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Artem::Application* Artem::CreateApplication()
{
	return new Sandbox();
}