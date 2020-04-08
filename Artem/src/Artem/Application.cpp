#include "Application.h"

#include "Event/ApplicationEvent.h"
#include "Event/MouseEvent.h"
#include "Event/KeyEvent.h"
#include "Log.h"

namespace Artem
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		MouseButtonPressEvent wre(2);
		AT_TRACE(wre);
		AT_TRACE(wre.IsInCategory(EventCategoryInput));
		AT_TRACE(wre.IsInCategory(EventCategoryApplication));
		AT_TRACE(wre.IsInCategory(EventCategoryKey));
		AT_TRACE(wre.IsInCategory(EventCategoryMouse));
		AT_TRACE(wre.IsInCategory(EventCategoryMouseButton));
		while (true);
	}
}
