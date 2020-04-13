#pragma once

#include "Event.h"

namespace Artem
{
    class KeyEvent : public Event
    {
    protected:
        int m_KeyCode;

        KeyEvent(int p_KeyCode)
            : m_KeyCode(p_KeyCode)
        {
        }

    public:
        int GetKeyCode() const
        {
            return m_KeyCode;
        }

        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKey)
    };

    class KeyPressEvent : public KeyEvent
    {
    private:
        int m_RepeatCount;
    public:
        KeyPressEvent(int p_KeyCode, int p_RepeatCount)
            : KeyEvent(p_KeyCode), m_RepeatCount(p_RepeatCount)
        {
        }

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPress)
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        KeyReleaseEvent(int p_KeyCode)
            : KeyEvent(p_KeyCode)
        {
        }

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyRelease)
    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyType)
    };
};