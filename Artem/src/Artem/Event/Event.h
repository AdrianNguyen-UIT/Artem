#pragma once

#include "Artem/Core.h"
#include <string>
#include <sstream>


namespace Artem
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMove,
        AppTick, AppUpdate, AppRender,
        KeyPress, KeyRelease,
        MouseButtonPress, MouseButtonRelease, MouseMove, MouseScroll
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKey         = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    class Event
    {
    private:
        bool m_IsHandle = false;
    public:
        virtual EventType GetEventType() const = 0;
        virtual std::string ToString() const = 0;
        virtual int GetCategories() const = 0;
        bool IsInCategory(const EventCategory &p_Category)
        {
            return GetCategories() & p_Category;
        }

        bool IsHandled() const
        {
            return m_IsHandle;
        }
        
        void SetHandled(bool p_IsHandle)
        {
            m_IsHandle = p_IsHandle;
        }
    };
    
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                            virtual EventType GetEventType() const override { return GetStaticType(); }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategories() const override { return category; }

    class EventDispatcher
    {
    private:
        Event& m_Event;

    public:
        EventDispatcher(Event& p_Event)
            : m_Event(p_Event)
        {
        }


    };

    std::ostream& operator<<(std::ostream& out, const Event& event)
    {
        out << event.ToString();
        return out;
    }
}
