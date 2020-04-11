#include "atpch.h"
#include "Artem/Layer/Layer.h"

namespace Artem
{
	Layer::Layer(const std::string& p_Name)
		: m_LayerName(p_Name)
	{
	}

	void Layer::OnAttach()
	{
	}

	void Layer::OnUpdate()
	{

	}

	void Layer::OnDetach()
	{

	}

	void Layer::OnEvent(Event& event)
	{

	}

	inline std::string Layer::GetName() const
	{
		return m_LayerName;
	}
}