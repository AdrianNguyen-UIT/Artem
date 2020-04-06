#include <Artem.h>

class Sandbox : public Artem::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Artem::Application* Artem::CreateApplication()
{
	return new Sandbox();
}