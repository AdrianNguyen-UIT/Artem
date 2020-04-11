#include <Artem.h>

class ExampleLayer : public Artem::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//AT_APP_TRACE("Layer: {0} Is updating...", m_LayerName);
	}

	void OnEvent(Artem::Event& event) override
	{
		AT_APP_TRACE("Layer: {0} {1}", m_LayerName, event);
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